#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "game_field.h"





int main() {
    Field field(30,30);
    emplaceUnit<Clubber_<Cell>>(field[1][1]);
    Unit_<Cell>* unit = field[1][1]->located_unit;
    FieldPainter<Field> paint(field);
    paint.allField();
    paint.aim(1, 1);
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
    paint.clear_aim(1, 1);
    paint.show();
    return 0;

}