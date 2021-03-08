#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "game_field.h"

void aimControl (Unit* unit, FieldPainter<Field>& paint) {
    Field &field = unit -> place ->field;
    Aim* aim(new Aim(unit));
    std::string command;

    paint.allField();
    paint.show();
    while(true) {
        bool quit = false;
        std::cin >> command;

        for (char c : command) {
            switch (c) {
                case 'q':
                    quit = true;
                    break;
                case 'w':
                    aim -> move_up();
                    break;
                case 'a':
                    aim -> move_left();
                    break;
                case 's':
                    aim -> move_down();
                    break;
                case 'd':
                    aim -> move_right();
                    break;
                case 'f':
                    quit = true;
                    delete aim;
                    break;
            }
            paint.allField();
            paint.show();
            if (quit) {
                break;
            }
        }
        if (quit) {
            break;
        }
    }

}



int main() {
    Field field(10,10);
    emplaceUnit<Clubber_<Cell>>(field[1][1]);
    emplaceStructure<River>(field[5][5]);
    emplaceStructure<River>(field[4][5]);
    emplaceStructure<River>(field[3][5]);
    emplaceStructure<River>(field[2][5]);
    Unit_<Cell>* unit = field[1][1]->located_unit;
    FieldPainter<Field> paint(field);
    paint.allField();
    //paint.aim(1, 1);
    paint.show();
    std::string command;
    while(true) {
        bool quit = false;
        std::cin >> command;

        for (char c : command) {
            switch (c) {
                case 'q':
                    quit = true;
                    break;
                case 'w':
                    unit->move_up();
                    break;
                case 'a':
                    unit->move_left();
                    break;
                case 's':
                    unit->move_down();
                    break;
                case 'd':
                    unit->move_right();
                    break;
                case 'n':
                    emplaceUnit<Clubber>(field[1][1]);
                    break;
                case 'f':
                    aimControl(unit, paint);
                    break;
                case 'm':
                    int x, y;
                    std::cin >> x >> y;
                    Unit* n_unit = (field[x][y] -> located_unit);
                    if (n_unit -> existence()) {
                        unit = n_unit;
                        std::cout << "changed";
                    } else {
                        std::cout << "can't change";
                    }
                    break;
            }
            if (quit) {
                break;
            }
            paint.allField();
            paint.show();
        }
        if (quit) {
            break;
        }
    }
    //paint.clear_aim(1, 1);
    paint.show();
    return 0;

}