#pragma once

#include "graphics.h"


bool aimControl(Player &player, PlayerPainter &paint, const std::string &command_line);

void playTurn(Player *player, PlayerPainter *paint, const std::string &command_line);

class CantBuild : public std::exception {
public:
    std::string what() {
        return text_;
    }

    explicit CantBuild(std::string &&text) : text_(std::move(text)) {}

    explicit CantBuild(const std::string &text) : text_(text) {}

    CantBuild &operator=(const CantBuild &other) {
        text_ = other.text_;
        return *this;
    }

private:
    std::string text_;
};

class NotConstructable : public std::exception {
public:
    std::string what() {
        return text_;
    }

    explicit NotConstructable(const std::string &text) : text_(text) {}

    explicit NotConstructable(std::string &&text) : text_(std::move(text)) {}

    NotConstructable &operator=(const NotConstructable &other) {
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
        std::cout << player.control.get_cell()->located_unit->name() << "\n" << cell->located_structure->name << "\n";
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
void demiurgeEmplaceStructure(Cell *cell) {
    delete cell->located_structure;
    cell->located_structure = new StructureType(Nobody);
}


class Application {
public:
    Application(Player *player, PlayerPainter *painter, Field &field) {
        painter_ = painter;
        player_ = player;
        field_ = &field;
        player_num = 1;
        player_ = &(Player::get(playerNum(player_num), *field_));
        painter_ = &PlayerPainter::get(playerNum(player_num), *field_);
        appl = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
        g_signal_connect (appl, "activate", G_CALLBACK(Application::activate), NULL);
        x = 0;
        y = 0;
    }

    static void activate(GtkApplication *app,
                         gpointer user_data) {
        painter_->allField();
        auto *to_write = cut();
        image = reinterpret_cast<GtkImage *>(gtk_image_new_from_surface(to_write));
        cairo_surface_destroy(to_write);
        grid = reinterpret_cast<GtkGrid *>(gtk_grid_new());
        window = reinterpret_cast<GtkWindow *>(gtk_application_window_new(app));
        buffer = gtk_entry_buffer_new("", 0);
        entry = reinterpret_cast<GtkEntry *>(gtk_entry_new_with_buffer(buffer));

        gtk_container_add(GTK_CONTAINER(window), reinterpret_cast<GtkWidget *>(grid));

        gtk_window_set_title(window, "Window");
        gtk_window_set_default_size(window, 200, 200);

        gtk_grid_attach(grid, reinterpret_cast<GtkWidget *> (entry), 1, 10, 1, 1);

        //buttons
        GtkButton *b_up, *b_down, *b_left, *b_right, *run_com, *next_turn, *action;
        b_up = reinterpret_cast<GtkButton *>(gtk_button_new_with_label("/\\"));
        b_down = reinterpret_cast<GtkButton *>(gtk_button_new_with_label("\\/"));
        b_left = reinterpret_cast<GtkButton *>(gtk_button_new_with_label("<-"));
        b_right = reinterpret_cast<GtkButton *>(gtk_button_new_with_label("->"));
        run_com = reinterpret_cast<GtkButton *>(gtk_button_new_with_label("go"));
        next_turn = reinterpret_cast<GtkButton *>(gtk_button_new_with_label("next\nturn"));
        action = reinterpret_cast<GtkButton *>(gtk_button_new_with_label("action"));
        g_signal_connect(b_up, "clicked", G_CALLBACK(Application::wind_up), nullptr);
        g_signal_connect(b_down, "clicked", G_CALLBACK(wind_down), nullptr);
        g_signal_connect(b_left, "clicked", G_CALLBACK(wind_left), nullptr);
        g_signal_connect(b_right, "clicked", G_CALLBACK(wind_right), nullptr);
        g_signal_connect(run_com, "clicked", G_CALLBACK(run_command), nullptr);
        g_signal_connect(next_turn, "clicked", G_CALLBACK(change_turn), nullptr);
        g_signal_connect(action, "clicked", G_CALLBACK(aim_swap), nullptr);
        gtk_grid_attach(grid, reinterpret_cast<GtkWidget *>(b_up), 0, 0, 1, 1);
        gtk_grid_attach(grid, reinterpret_cast<GtkWidget *>(b_down), 0, 1, 1, 1);
        gtk_grid_attach(grid, reinterpret_cast<GtkWidget *>(b_left), 0, 2, 1, 1);
        gtk_grid_attach(grid, reinterpret_cast<GtkWidget *>(b_right), 0, 3, 1, 1);
        gtk_grid_attach(grid, reinterpret_cast<GtkWidget *>(run_com), 0, 10, 1, 1);
        gtk_grid_attach(grid, reinterpret_cast<GtkWidget *>(next_turn), 0, 4, 1, 1);
        gtk_grid_attach(grid, reinterpret_cast<GtkWidget *>(action), 0, 5, 1, 1);
        //

        //gtk_container_add(GTK_CONTAINER(window), button);
        gtk_grid_attach(grid, reinterpret_cast<GtkWidget *>(image), 1, 0, 1, 10);

        gtk_widget_show_all(reinterpret_cast<GtkWidget *>(window));
    }

    static void wind_up(GtkWidget *button,
                        gpointer user_data) {
        -- --y;
        Application::show();
    }

    static void wind_down(GtkWidget *button,
                          gpointer user_data) {
        ++ ++y;
        Application::show();
    }

    static void wind_right(GtkWidget *button,
                           gpointer user_data) {
        ++ ++x;
        Application::show();
    }

    static void wind_left(GtkWidget *button,
                          gpointer user_data) {
        -- --x;
        Application::show();
    }

    static void run_command(GtkWidget *button,
                            gpointer user_data) {
        turn(gtk_entry_buffer_get_text(buffer));
        gtk_entry_buffer_delete_text(buffer, 0, gtk_entry_buffer_get_length(buffer));
        show();
    }

    static void change_turn(GtkWidget *button, gpointer) {
        player_num = 3 - player_num;
        player_ = &(Player::get(playerNum(player_num), *field_));
        painter_ = &PlayerPainter::get(playerNum(player_num), *field_);
        show();
    }

    static void next_im(GtkWidget *button,
                        gpointer user_data) {
        ++x;
        Application::show();
    }

    int run(int argc, char **argv) {
        int status;
        status = g_application_run(G_APPLICATION (appl), argc, argv);
        g_object_unref(appl);
        return status;
    }

    static void aim_swap(GtkWidget *button,
                         gpointer user_data) {
        if (player_->control.unit_attached) {
            aim_controll = !aim_controll;
            if(aim_controll) {
                player_->aim = new Aim(player_->control);
            }
            show();
        }
    }

    static cairo_surface_t *cut() {
        cairo_surface_t *to_write =
                cairo_surface_create_similar_image(painter_->surface, CAIRO_FORMAT_ARGB32, 15 * cell_size,
                                                   15 * cell_size);
        cairo_t *cr;
        cr = cairo_create(to_write);

        cairo_rectangle(cr, 0, 0, 15 * cell_size, 15 * cell_size);

        cairo_set_source_surface(cr, painter_->surface, (-x) * int(cell_size), (-y) * int(cell_size));
        cairo_fill(cr);
        cairo_destroy(cr);
        return to_write;
    }


    static void show() {
        painter_->allField();
        cairo_surface_t *to_write = cut();

        gtk_image_set_from_surface(image, to_write);
        cairo_surface_destroy(to_write);
        gtk_widget_show_all(reinterpret_cast<GtkWidget *>(window));
    }

    static void turn(const std::string &command) {
        if (aim_controll) {
            if(aimControl(*player_, *painter_, command)) {
                delete player_->aim;
                player_ ->aim = nullptr;
                aim_controll = !aim_controll;
            }
        } else {
            playTurn(player_, painter_, command);
        }
        show();
    }

    static GtkWindow *window;
    static GtkApplication *appl;
    static GtkGrid *grid;
    static GtkImage *image;
    static PlayerPainter *painter_;
    static Player *player_;
    static Field *field_;
    const static auto cell_size = 64;
    static int x;
    static int y;
    static GtkEntry *entry;
    static GtkEntryBuffer *buffer;
    static bool aim_controll;
    static int player_num;
private:
};

GtkWindow *Application::window = nullptr;
GtkApplication *Application::appl = nullptr;
GtkGrid *Application::grid = nullptr;
GtkImage *Application::image = nullptr;
GtkEntry *Application::entry = nullptr;
GtkEntryBuffer *Application::buffer = nullptr;
PlayerPainter *Application::painter_ = nullptr;
Player *Application::player_ = nullptr;
Field *Application::field_ = nullptr;
int Application::player_num = 1;
int Application::x = 0;
int Application::y = 0;
bool Application::aim_controll = false;


bool aimControl(Player &player, PlayerPainter &paint, const std::string &command_line) {

    char command;
    Aim &aim = *player.aim;
    bool quit = false;
    for (int i = 0; i < command_line.size(); ++i) {
        command = command_line[i];

        switch (command) {
            case 'q':
                return true;
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
                } catch (CantBuild exc) {
                    std::cout << exc.what();
                }
                quit = true;
                break;
            }
        }
    }
    return quit;
}

void playTurn(Player *player, PlayerPainter *paint, const std::string &command_line) {
    Cursor *cursor = &player->control;
    char command;
    for (int i = 0; i < command_line.size(); ++i) {
        bool quit = false;
        command = command_line[i];
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
                ++i;
                if (i == command_line.size()) {
                    break;
                }
                unit = command_line[i];
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
            case '\n':
                paint->allField();
                paint->show();
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
            default: {
                break;
            }
        }
    }
}
