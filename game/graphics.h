

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
    cairo_surface_t* surface;
    using Cell = typename Field::CellType;
    const static int cell_size_ = 64;
public:
    FieldPainter(const Field& field_to_paint) : field(field_to_paint) {
        surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, field.x_size * cell_size_, field.y_size * cell_size_);
    }
    void operator () (const Cell* cell) {
        cairo_t* cr;
        cr = cairo_create(surface);

        cairo_pattern_t* pattern;
        pattern = cairo_pattern_create_rgba(0,0,0, 1);
        cairo_rectangle(cr, (cell->x) * cell_size_, (cell->y) * cell_size_, cell_size_, cell_size_);
        cairo_set_source(cr, pattern);
        cairo_fill(cr);
        cairo_pattern_destroy(pattern);

        cairo_surface_t *structure_image;
        structure_image = cairo_image_surface_create_from_png(cell -> located_structure -> image_placement().c_str());
        cairo_rectangle(cr, (cell->x) * cell_size_ + 2, (cell->y) * cell_size_ + 2, 60, 60);
        cairo_set_source_surface(cr, structure_image, (cell->x) * cell_size_, (cell->y) * cell_size_);
        cairo_fill(cr);
        cairo_surface_destroy(structure_image);

        if(cell->located_unit->existence()) {
            cairo_surface_t *unit_image;
            unit_image = cairo_image_surface_create_from_png(cell->located_unit->image_placement().c_str());
            cairo_rectangle(cr, (cell->x) * cell_size_ + 6, (cell->y) * cell_size_ + 6, 52, 52);
            cairo_set_source_surface(cr, unit_image, (cell->x) * cell_size_, (cell->y) * cell_size_);
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
        cairo_t* cr;
        cr = cairo_create(surface);
        cairo_set_line_width(cr,2);
        cairo_set_source_rgb(cr, 1, 0, 0);

        cairo_move_to(cr, x * cell_size_ + 0, y * cell_size_ + 1);
        cairo_line_to(cr, x * cell_size_ + cell_size_, y * cell_size_ + 1);

        cairo_move_to(cr, x * cell_size_ + cell_size_ - 1, y * cell_size_ + 1);
        cairo_line_to(cr, x * cell_size_ + cell_size_ - 1, y * cell_size_ + cell_size_);

        cairo_move_to(cr, x * cell_size_ + cell_size_, y * cell_size_ + cell_size_ - 1);
        cairo_line_to(cr, x * cell_size_ + 1, y * cell_size_ + cell_size_ - 1);

        cairo_move_to(cr, x * cell_size_ + 1, y * cell_size_ + cell_size_);
        cairo_line_to(cr, x * cell_size_ + 1, y * cell_size_ + 1);

        cairo_stroke(cr);
        cairo_destroy(cr);
    }
};