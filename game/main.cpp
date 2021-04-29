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
#include <gtk/gtk.h>


//GtkApplication* app_;
int status;

class CantBuild: public std::exception {
public:
    std::string what() {
        return text_;
    }
    explicit CantBuild(std::string&& text) : text_(std::move(text)) {}
    explicit CantBuild(const std::string& text) : text_(text) {}
    CantBuild& operator=(const CantBuild& other){
        text_ = other.text_;
        return *this;
    }
private:
    std::string text_;
};

class NotConstructable: public std::exception {
public:
    std::string what() {
        return text_;
    }
    explicit NotConstructable(const std::string& text) : text_(text) {}
    explicit NotConstructable(std::string&& text) : text_(std::move(text)) {}
    NotConstructable& operator=(const NotConstructable& other){
        text_ = other.text_;
        return *this;
    }
private:
    std::string text_;
};

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
                  << player.treasury.requiredMemes() << "TB of memes and " << UnitType::name_ << " costs "
                  << UnitType::cost_
                  << "TB of memes";
    }
}


template<typename StructureType>
void emplaceStructure(Player &player) {
    if constexpr(StructureType::constructable) {
        if (player.aim == nullptr) {
            throw std::invalid_argument("this unit has no aim");
        }
        Cell *cell = player.aim->get_cell();
        std::cout << player.control.get_cell()->located_unit->name() << "\n" << cell->located_structure->name << std::endl;
        if (player.control.get_cell()->located_unit->canConstruct()) {
            if (cell->located_structure->get_name() == "Grass") {
                delete cell->located_structure;
                cell->located_structure = new StructureType(player.number);
                player.treasury.insertStructure(cell->located_structure);
            }
        } else {
            throw CantBuild(player.control.get_cell()->located_unit->name() + " can`t construct");
        }
    } else {
        throw NotConstructable("you can`t construct " + StructureType::name);
    }
}

template<typename StructureType>
void demiurgeEmplaceStructure(Cell* cell) {
    delete cell->located_structure;
    cell->located_structure = new StructureType(Nobody);
}

class Stream {
public:
    std::string str;
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
            case 'c': {
                try {
                    emplaceStructure<MemeFabric>(player);
                    std::cout << " constr";
                } catch(CantBuild exc) {
                    std::cout << exc.what();
                }
                quit = true;
                break;
            }
			default: {
				break;
			}
        }
        if (quit) {
            player.aim = nullptr;
            break;
        }
    }

}

void playTurn(Player *player, Stream &input, PlayerPainter *paint, Field &field) {
    Cursor *cursor = &player->control;
    char command;
    while (true) {
        bool quit = false;
        input >> command;
        switch (command) {
            case 'q':
				//g_object_unref (app_);
                throw 0;
            case 'w':
                cursor->move_up();
                break;
            case 'a':
                cursor->move_left();
                break;
            case 's':
                cursor->move_down();
                break;
            case 'd':
                cursor->move_right();
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
					default: {
						break;
					}
                }
                break;
            }
            case 'e': {
                if (cursor->unit_attached) {
                    cursor->detachUnit();
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
                    player->aim = &aim;
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
                if (num < PlayersNum && num > 0) {
                    std::cout << "\n" << num << "\n";
                    player = &Player::get(playerNum(num), field);
                    cursor = &(player->control);
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
            case 'i': {
                auto *unit = cursor->get_cell()->located_unit;
                auto *structure = cursor->get_cell()->located_structure;
                std::cout << "Unit:\t\t" << unit->name() << "\n";
                std::cout << "\t\t" << unit->hp() << "\n\n";
                std::cout << "Structure:\t" << structure->name << "\n";
                std::cout << "\t\t" << structure->hp() << "\n\n";
            }
                break;
            case 'g':
                quit = true;
                break;
			default: {
				break;
			}
        }
        if (quit) {
            break;
        }
    }
}


/*static void activate (GtkApplication* app, gpointer user_data) {
	static const int window_width = 800;
	static const int window_height = 600;
	GtkWidget* window;


	window = gtk_application_window_new(app);
	gtk_window_set_title (GTK_WINDOW(window), "Main window");
	gtk_window_set_default_size (GTK_WINDOW(window), window_width, window_height);

	gtk_window_present(GTK_WINDOW(window));
}

static void turn_on(int argc, char **argv) {
	app_ = gtk_application_new("strategy.main", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app_, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION(app_), argc, argv);

	g_object_unref (app_);
} */

int main(int argc, char **argv) {
    Stream input;
    //Field field(30, 30);
    Field field(standard);
    Cursor *cursor = &((Player::get(Player1, field)).control);
    Player *player = &(Player::get(Player1, field));
    PlayerPainter *paint = &PlayerPainter::get(Player1, field);
    /*demiurgeEmplaceStructure<River>(field[5][5]);
    demiurgeEmplaceStructure<River>(field[4][5]);
    demiurgeEmplaceStructure<River>(field[3][5]);
    demiurgeEmplaceStructure<River>(field[2][5]); */
	//turn_on(argc, argv);
    int player_num = 1;
    try {
        while (true) {
            playTurn(player, input, paint, field);
            player_num = 3 - player_num;
            player = &(Player::get(playerNum(player_num), field));
            cursor = &(player->control);
            paint = &PlayerPainter::get(playerNum(player_num), field);
        }
    } catch (int) {
		//return status;
    }


    paint->allField();
    paint->show();
    char command;

    paint->show();
    return status;
}