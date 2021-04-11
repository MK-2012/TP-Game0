#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "game_field.h"
#include "graphics.h"
#include "Structure.h"
#include "Unit.h"
#include "Cursor.h"
#include <unistd.h>


template<typename UnitType>
void emplaceUnit(Player &player) {
    player.treasury.checkArmy();
    if (player.treasury.enoughMemes(UnitType::cost_)) {
        if (!player.control.unit_attached) {
            Cell *cell = player.control.get_cell();
            if (cell->isAllowedToGoIn()) {
                delete cell->located_unit;
                cell->located_unit = new UnitType(player.number);
                player.treasury.insertUnit(cell->located_unit);
            }
        }
    } else {
        std::cout << "\n you have " << player.treasury.memesLimit() << "TB of memes and you have already used "
                  << player.treasury.requiredMemes() << "TB of memes and "<< UnitType::name_ <<" costs " << UnitType::cost_
                  << "TB of memes";
    }
}


template<typename StructureType>
void emplaceStructure(Player &player) {
    Cell *cell = player.control.get_cell();
    if (cell->located_unit -> canConstruct()) {
        if (cell->located_structure->name() == "Grass") {
            delete cell->located_structure;
            cell->located_structure = new StructureType(player.number);
            player.treasury.insertStructure(cell -> located_structure);
        }
    }
}

template<typename StructureType>
void demiurgeEmplaceStructure(Cell *cell) {
    delete cell->located_structure;
    cell->located_structure = new StructureType(Nobody);
}

class Stream {
public:
    std::string str = "";
    size_t place = 0;

    Stream &operator>>(char &c) {
        if (place >= str.size()) {
            place = 0;
            std::cin >> str;
            str.push_back('\n');
        }
        c = str[place];
        ++place;
        return *this;
    }
    Stream &operator>>(int &c) {
        if (place >= str.size()) {
            place = 0;
            std::cin >> str;
            str.push_back('\n');
        }
        c = str[place] - '0';
        ++place;
        return *this;
    }
};

void aimControl(Player &player, PlayerPainter &paint, Stream &input) {

    char command;
    Aim &aim = *player.aim;


    //paint.allField();
    //paint.show();
    while (true) {
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
            player.aim = nullptr;
            break;
        }
    }

}

void playTurn(Player* player, Stream& input, PlayerPainter* paint ,Field& field) {
    Cursor* cursor = &player -> control;
    char command;
    while (true) {
        bool quit = false;
        input >> command;
//        std::cout << "cursor " << cursor->x << " " << cursor->y << "\n";
//        std::cout << "player " << player->control.x <<  " " << player->control.y << "\n";
        switch (command) {
            case 'q':
                throw 0;
            case 'w':
                cursor -> move_up();
                break;
            case 'a':
                cursor -> move_left();
                break;
            case 's':
                cursor -> move_down();
                break;
            case 'd':
                cursor -> move_right();
                break;
            case 'n': {
                char unit;
                input >> unit;
                switch (unit) {
                    case 'c':
                        emplaceUnit<Clubber>(*player);
                        break;
                    case 'w':
                        emplaceUnit<Worker>(*player);
                        break;
                    case 'a':
                        emplaceUnit<Archer>(*player);
                        break;
                    case 'v':
                        emplaceUnit<Cavalery>(*player);
                        break;
                    case 'h':
                        emplaceUnit<HorseArcher>(*player);
                        break;
                }
                break;
            }
            case 'e': {
                if (cursor -> unit_attached) {
                    cursor -> detachUnit();
                } else {
                    try {
                        cursor->attachUnit();
                    } catch (UnitAttachingException error) {
                        std::cout << error.what();
                    }
                }
                break;
            }
            case 'f':
                if (cursor->unit_attached) {
                    Aim aim(*cursor);
                    player -> aim = &aim;
                    aimControl(*player, *paint, input);
                }
                break;
            case '\n':
                paint->allField();
                paint->show();
                break;
            case 'm':
                int num;
                input >> num;
                if(num < PlayersNum && num > 0) {
                    std::cout << "\n" << num << "\n";
                    player = &Player::get(playerNum(num), field);
                    cursor = &(player -> control);
                    paint = &PlayerPainter::get(playerNum(num), field);
                } else {
                    std::cout << "\n you have only " << PlayersNum << " players";
                }
                break;
            case 'l':
                for (auto i: player->treasury.units.units) {
                    std::cout << " " << i->name() << " ";
                }
                break;
            case 'c':
                emplaceStructure<MemeFabric>(*player);
                std::cout << " constr";
                break;
            case 'g':
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
    Field field(10, 10);
    Cursor *cursor = &((Player::get(Player1, field)).control);
    Player *player = &(Player::get(Player1, field));
    PlayerPainter *paint = &PlayerPainter::get(Player1, field);
    demiurgeEmplaceStructure<River>(field[5][5]);
    demiurgeEmplaceStructure<River>(field[4][5]);
    demiurgeEmplaceStructure<River>(field[3][5]);
    demiurgeEmplaceStructure<River>(field[2][5]);
    int player_num = 1;
    try {
        while (true) {
            playTurn(player, input, paint, field);
            player_num = 3 - player_num;
            player = &(Player::get(playerNum(player_num), field));
            cursor = &(player -> control);
            paint = &PlayerPainter::get(playerNum(player_num), field);
        }
    } catch (int) {

    }

    paint -> allField();
    //paint.cursorPaint(1, 1);
    paint -> show();
    char command;

    //paint.clear_aim(1, 1);
    paint->show();
    return 0;

}