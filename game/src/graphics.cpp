#include "graphics.h"
#include "iostream"

std::string path_to_image(StructureImages image) {
	switch (image) {
		case GrassImage: {
			return std::string(IMAGE_DIR) + "structures/Grass1.png";
		}
		case RiverImage: {
			return std::string(IMAGE_DIR) + "structures/River5.png";
		}
		case MemeFabricImage: {
            return std::string(IMAGE_DIR) + "structures/memefabric.png";
		}
	}
}
std::string path_to_image(UnitImages image) {
	switch (image) {
		case NonExistentUnitImage: {
			return std::string(IMAGE_DIR) + "units/non_existent.png";
		}
		case ClubberImage: {
			return std::string(IMAGE_DIR) + "units/clubber.png";
		}
        case WorkerImage: {
            return std::string(IMAGE_DIR) + "units/worker.png";
        }
	}
}


const uint64_t PlayerPainter::cell_size = 64;

const uint64_t PlayerPainter::border_width = 2;

std::vector<bool> PlayerPainter::created = std::vector<bool>(PlayersNum, false);
std::vector<PlayerPainter*> PlayerPainter::painters = std::vector<PlayerPainter*>(PlayersNum);


PlayerPainter::PlayerPainter(const Player& player): field(player.control.field_), player_(player){
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, field.x_size * cell_size, field.y_size * cell_size);
}


void PlayerPainter::operator()(const Cell* cell) {
	cairo_t *cr;
	cr = cairo_create(surface);

	cairo_pattern_t *pattern;
	pattern = cairo_pattern_create_rgba(0, 0, 0, 1);
	cairo_rectangle(cr, (cell->x) * cell_size, (cell->y) * cell_size, cell_size, cell_size);
	cairo_set_source(cr, pattern);
	cairo_fill(cr);
	cairo_pattern_destroy(pattern);

	cairo_surface_t *structure_image;
	structure_image = cairo_image_surface_create_from_png(path_to_image(cell->located_structure->image()).c_str());
	cairo_rectangle(cr, (cell->x) * cell_size + border_width, (cell->y) * cell_size + border_width, cell_size - 2 * border_width, cell_size - 2 * border_width);
	cairo_set_source_surface(cr, structure_image, (cell->x) * cell_size, (cell->y) * cell_size);
	cairo_fill(cr);
	cairo_surface_destroy(structure_image);


	cairo_surface_t *unit_image;
	unit_image = cairo_image_surface_create_from_png(path_to_image(cell->located_unit->image()).c_str());
	cairo_rectangle(cr, (cell->x) * cell_size + 6, (cell->y) * cell_size + 6, cell_size - 2 * 6, cell_size - 2 * 6);
	cairo_set_source_surface(cr, unit_image, (cell->x) * cell_size, (cell->y) * cell_size);
	cairo_fill(cr);
	cairo_surface_destroy(unit_image);

	cairo_destroy(cr);
}

void PlayerPainter::show() {
	cairo_surface_write_to_png(surface, "canvas.png");
}

void PlayerPainter::allField() {
	for (int i = 0; i < field.x_size; ++i) {
		for (int j = 0; j < field.y_size; ++j) {
			(*this)(field[i][j]);
		}
	}

    cursorPaint(player_.control.x, player_.control.y, player_.control.image());
    if (player_.aim != nullptr) {
        cursorPaint(player_.aim->x, player_.aim->y, player_.aim->image());
    }

}

void PlayerPainter::cursorPaint(size_t x, size_t y, CursorImages image) {
	cairo_t *cr;
	cr = cairo_create(surface);
	cairo_set_line_width(cr,2);
	switch (image) {
		case CursorWithoutUnitImage:
			cairo_set_source_rgb(cr, 0, 0, 1);
			break;
		case CursorWithUnitImage:
			cairo_set_source_rgb(cr, 0, 1, 1);
			break;
		case AimImage:
			cairo_set_source_rgb(cr, 1, 0, 0);
			break;
	}

	cairo_move_to(cr, x * cell_size + 0, y * cell_size + 1);
	cairo_line_to(cr, x * cell_size + cell_size, y * cell_size + 1);

	cairo_move_to(cr, x * cell_size + cell_size - 1, y * cell_size + 1);
	cairo_line_to(cr, x * cell_size + cell_size - 1, y * cell_size + cell_size);

	cairo_move_to(cr, x * cell_size + cell_size, y * cell_size + cell_size - 1);
	cairo_line_to(cr, x * cell_size + 1, y * cell_size + cell_size - 1);

	cairo_move_to(cr, x * cell_size + 1, y * cell_size + cell_size);
	cairo_line_to(cr, x * cell_size + 1, y * cell_size + 1);

	cairo_stroke(cr);
	cairo_destroy(cr);
}

PlayerPainter &PlayerPainter::get(PlayerEnum player, Field& field) {
    int num = playerNum(player);
    // std::cout << "\n" << num << "\n";
    if(created[num]) {
        return *painters[num];
    } else {
        created[num] = true;
        painters[num] = new PlayerPainter(Player::get(player, field));
        return *painters[num];
    }
}
//	  template<typename Field>
//	  void PlayerPainter<Field>::cursorPaint(size_t x, size_t y, CursorImages image) {
//		  cairo_t *cr;
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
