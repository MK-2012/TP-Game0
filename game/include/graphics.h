#pragma once


#include <cairo/cairo.h>
#include "StructureImages.h"
#include "UnitImages.h"
#include "CursorImages.h"
#include "game_field.h"
#include "Cursor.h"
#include "Player.h"
#include <string>
#include <gtk/gtk.h>

std::string path_to_image(StructureImages image);
std::string path_to_image(UnitImages image);

namespace rmPointer {
    template<typename T>
    struct removePointer {
        using type = T;
    };
    template<typename T>
    struct removePointer<T*> {
        using type = typename removePointer<T>::type;
    };

}




class PlayerPainter {
    const Field& field;
    const Player& player_;
    const static uint64_t cell_size;
    const static uint64_t border_width;
    static std::vector<PlayerPainter*> painters;
    static std::vector<bool> created;
    PlayerPainter(const Player& player);
public:
    cairo_surface_t *surface;
    void operator () (const Cell* cell);
    void show();
    void allField();
    void cursorPaint(size_t x, size_t y, CursorImages image);
    static PlayerPainter& get(PlayerEnum player, Field& field);
};