#include "game_field.h"

UnitAttachingException::UnitAttachingException(std::string&& error):m_error(error) {}
UnitAttachingException::UnitAttachingException(const char* error): m_error(error) {}
UnitAttachingException::UnitAttachingException(std::string error): m_error(std::move(error)) {}

const char* UnitAttachingException::what() const noexcept {
	return m_error.c_str();
}


Cell::Cell(Field& field, int x, int y): x(x), y(y), field(field), located_unit(new NonExistentUnit()), located_structure(new Grass()) {};

bool Cell::isAllowedToGoIn() {
	return !(located_unit -> existence()) && located_structure -> isAllowedToGoIn();
}


Field::Field(size_t x_size, size_t y_size): x_size(x_size), y_size(y_size), field(std::vector<std::vector<Cell*>>(x_size, std::vector<Cell*>(y_size, nullptr))), paint(*this) {
	for (int i = 0; i < field.size(); ++i) {
		for (int j = 0; j < field[i].size(); ++j) {
			field[i][j] = new Cell(*this, i, j);
		}
	}
}

std::vector<Cell *> & Field::operator[](size_t x) {
	return field[x];
}
const std::vector<Cell *> & Field::operator[](size_t x) const {
	return field[x];
}
void Field::print() {
	for (int i = 0; i < field.size(); ++i) {
		for (int j = 0; j < field[i].size(); ++j) {
			paint(field[i][j]);
		}
	}
}
bool Field::cellIsFree(int x, int y) {
	if (x < 0 || x >= x_size) {
		return false;
	}
	if (y < 0 || y >= y_size) {
		return false;
	}
	if (field[x][y] -> isAllowedToGoIn()) {
		return true;
	}
	return false;
}


void Cursor::move(int delta_x, int delta_y) {
	if (!unit_attached) {
		if ((delta_x + x) >= 0 && (delta_y + y) >= 0 && (delta_x + x) < field_.x_size &&
			(delta_y + y) < field_.y_size) {
			x += delta_x;
			y += delta_y;
		}
	} else {
		if (field_.cellIsFree(static_cast<int>(x) + delta_x, static_cast<int>(y)  + delta_y)) {
			if (field_[x][y] -> located_unit -> allowed_to_move()) {
				Cell* next_place = field_[static_cast<int>(x) + delta_x][static_cast<int>(y) + delta_y];
				std::swap(field_[x][y] -> located_unit, next_place -> located_unit);
				x += delta_x;
				y += delta_y;
			}
		}
	}
}

Cursor::Cursor(Field& field, size_t x, size_t y): field_(field), x(x), y(y), unit_attached(false) {
	field_.cursors.push_back(this);
}
Cursor::Cursor(const Cursor& other): field_(other.field_), x(other.x), y(other.y), unit_attached(other.unit_attached) {
	field_.cursors.push_back(this);
}
Cursor::~Cursor() {
	field_.cursors.pop_back();
}

CursorImages Cursor::image() {
	if (unit_attached){
		return CursorWithUnitImage;
	} else {
		return CursorWithoutUnitImage;
	}
}
void Cursor::move_up() {
	move(0, -1);
};
void Cursor::move_down() {
	move(0, 1);
};
void Cursor::move_left() {
	move(-1, 0);
};
void Cursor::move_right() {
	move(1, 0);
};
void Cursor::attachUnit() {
	if (unit_attached) {
		throw UnitAttachingException("unit already attached");
	}
	if (!(field_[x][y] -> located_unit-> existence())){
		throw UnitAttachingException("You can't attach non existent unit");
	} else {
		unit_attached = true;
	}
}
void Cursor::detachUnit() {
	if (!unit_attached) {
		throw UnitAttachingException("there is no attached units");
	} else {
		unit_attached = false;
	}
}

