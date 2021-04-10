

#include <cairo/cairo.h>
#include "StructureImages.h"
#include "UnitImages.h"
#include "CursorImages.h"
#include "game_field.h"
#include <string>

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




class FieldPainter {
    const Field& field;
    cairo_surface_t *surface;
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