#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "game_field.h"
#include <unistd.h>

class Stream {
public:
    std::string str = "";
    size_t place = 0;
    Stream& operator >> (char& c) {
        if(place >= str.size()){
            place = 0;
            std::cin >> str;
            str.push_back('\n');
        }
        c = str[place];
        ++ place;
        return *this;
    }
};

void aimControl (Field& field ,Aim& aim, FieldPainter<Field>& paint, Stream& input) {

    char command;

    //paint.allField();
    //paint.show();
    while(true) {
        bool quit = false;
        input >> command;

        switch (command) {
            case 'q':
                quit = true;
                break;
            case 'w':
                aim.move_up();
                break;
            case 'a':
                aim.move_left();
                break;
            case 's':
                aim.move_down();
                break;
            case 'd':
                aim.move_right();
                break;
            case '\n':
                paint.allField();
                paint.show();
                break;
            case 'f':
                aim.attack();
                quit = true;
                break;
        }
        if (quit) {
            break;
        }


    }

}



int main() {
    Stream input;
    Field field(10,10);
    emplaceUnit<Clubber>(field[1][1]);
    emplaceStructure<River>(field[5][5]);
    emplaceStructure<River>(field[4][5]);
    emplaceStructure<River>(field[3][5]);
    emplaceStructure<River>(field[2][5]);
    Cursor cursor(field);
    FieldPainter<Field> paint(field);
    paint.allField();
    //paint.aim(1, 1);
    paint.show();
    char command;
    while(true) {
        bool quit = false;
        input >> command;

        switch (command) {
            case 'q':
                quit = true;
                break;
            case 'w':
                cursor.move_up();
                break;
            case 'a':
                cursor.move_left();
                break;
            case 's':
                cursor.move_down();
                break;
            case 'd':
                cursor.move_right();
                break;
            case 'n':
                emplaceUnit<Clubber>(field[1][1]);
                break;
            case 'e': {
                if (cursor.unit_attached) {
                    cursor.detachUnit();
                } else {
                    try {
                        cursor.attachUnit();
                    } catch (UnitAttachingException error) {
                        std::cout << error.what();
                    }
                }
                break;
            }
            case 'f':
                if(cursor.unit_attached) {
                    Aim aim(cursor);
                    aimControl(field, aim, paint, input);
                }
                break;
            case '\n':
                paint.allField();
                paint.show();
                break;
            case 'm':
//                int x, y;
//                std::cin >> x >> y;
//                Unit *n_unit = (field[x][y]->located_unit);
//                if (n_unit->existence()) {
//                    unit = n_unit;
//                    std::cout << "changed";
//                } else {
//                    std::cout << "can't change";
//                }
                break;
        }
        if (quit) {
            break;
        }
    }
    //paint.clear_aim(1, 1);
    paint.show();
    return 0;

}