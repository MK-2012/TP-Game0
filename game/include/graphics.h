//
// Created by val-de-mar on 08.03.2021.
//

#ifndef GAME_GRAPHICS_H
#define GAME_GRAPHICS_H

#endif //GAME_GRAPHICS_H


#include <cairo/cairo.h>

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
public:
    FieldPainter(const Field& field_to_paint) : field(field_to_paint) {
        surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, field.x_size * 64, field.y_size * 64);
    }
    void operator () (const Cell* cell) {
        cairo_t *cr;
        cr = cairo_create(surface);

        cairo_pattern_t* pattern;
        pattern = cairo_pattern_create_rgba(0,0,0, 1);
        cairo_rectangle(cr, (cell -> x) * 64, (cell -> y) * 64, 64, 64);
        cairo_set_source(cr, pattern);
        cairo_fill(cr);
        cairo_pattern_destroy(pattern);

        cairo_surface_t *structure_image;
        structure_image = cairo_image_surface_create_from_png(cell -> located_structure -> image_placement().c_str());
        cairo_rectangle(cr, (cell -> x) * 64 + 2, (cell -> y) * 64 + 2, 60, 60);
        cairo_set_source_surface(cr, structure_image, (cell -> x) * 64, (cell -> y) * 64);
        cairo_fill(cr);
        cairo_surface_destroy(structure_image);

        if(cell->located_unit->existence()) {
            cairo_surface_t *unit_image;
            unit_image = cairo_image_surface_create_from_png(cell->located_unit->image_placement().c_str());
            cairo_rectangle(cr, (cell->x) * 64 + 6, (cell->y) * 64 + 6, 52, 52);
            cairo_set_source_surface(cr, unit_image, (cell->x) * 64, (cell->y) * 64);
            cairo_fill(cr);
            cairo_surface_destroy(unit_image);
        }
        cairo_destroy(cr);
    }
    void show() {
        cairo_surface_write_to_png(surface, "canvas.png");
    }
    void allField() {
        for (int i = 0; i < field.x_size; ++i) {
            for (int j = 0; j < field.y_size; ++j) {
                (*this)(field[i][j]);
            }
        }
        if (field.aim != nullptr) {
            aim(field.aim->x, field.aim->y);
        }
    }
    void aim(size_t x, size_t y) {
        cairo_t *cr;
        cr = cairo_create(surface);
        cairo_set_line_width(cr,2);
        cairo_set_source_rgb(cr, 1, 0, 0);

        cairo_move_to(cr, x * 64 + 0, y * 64 + 1);
        cairo_line_to(cr, x * 64 + 64, y * 64 + 1);

        cairo_move_to(cr, x * 64 + 63, y * 64 + 1);
        cairo_line_to(cr, x * 64 + 63, y * 64 + 64);

        cairo_move_to(cr, x * 64 + 64, y * 64 + 63);
        cairo_line_to(cr, x * 64 + 1, y * 64 + 63);

        cairo_move_to(cr, x * 64 + 1, y * 64 + 64);
        cairo_line_to(cr, x * 64 + 1, y * 64 + 1);

        cairo_stroke(cr);
        cairo_destroy(cr);
    }
//    void clear_aim(size_t x, size_t y) {
//        cairo_t *cr;
//        cr = cairo_create(surface);
//        cairo_set_line_width(cr,1);
//        cairo_set_source_rgb(cr, 0, 0, 0);
//
//        cairo_move_to(cr, x * 20 + 0.5, y * 20 + 0.5);
//        cairo_line_to(cr, x * 20 + 19.5, y * 20 + 0.5);
//
//        cairo_move_to(cr, x * 20 + 19.5, y * 20 + 0.5);
//        cairo_line_to(cr, x * 20 + 19.5, y * 20 + 19.5);
//
//        cairo_move_to(cr, x * 20 + 19.5, y * 20 + 19.5);
//        cairo_line_to(cr, x * 20 + 0.5, y * 20 + 19.5);
//
//        cairo_move_to(cr, x * 20 + 0.5, y * 20 + 19.5);
//        cairo_line_to(cr, x * 20 + 0.5, y * 20 + 0.5);
//
//        cairo_stroke(cr);
//        cairo_destroy(cr);
//    }
};