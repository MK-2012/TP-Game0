//
// Created by val-de-mar on 08.03.2021.
//

#ifndef GAME_GRAPHICS_H
#define GAME_GRAPHICS_H

#endif //GAME_GRAPHICS_H


#include <cairo/cairo.h>
#include "StructureImages.h"
#include "UnitImages.h"
#include "CursorImages.h"

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



template<typename Field>
class FieldPainter {
    const Field& field;
    cairo_surface_t *surface;
    using Cell = typename Field::CellType;
    const static uint64_t cell_size;
    const static uint64_t border_width;
public:
    FieldPainter(const Field& field_to_paint);
    void operator () (const Cell* cell);
    void show();
    void allField();
    void aim(size_t x, size_t y, CursorImages image);
//  void clear_aim(size_t x, size_t y); {
};