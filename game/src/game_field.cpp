#include "game_field.h"

UnitAttachingException::UnitAttachingException(std::string&& error):m_error(error) {}
UnitAttachingException::UnitAttachingException(const char* error): m_error(error) {}
UnitAttachingException::UnitAttachingException(std::string error): m_error(std::move(error)) {}

const char* UnitAttachingException::what() const noexcept {
	return m_error.c_str();
}


Cell::Cell(Field& field, int x, int y): x(x), y(y), field(field), located_unit(new NonExistentUnit(Nobody)), located_structure(new Grass(Nobody)) {};

bool Cell::isAllowedToGoIn() const {
	return !(located_unit -> existence()) && located_structure -> isAllowedToGoIn();
}


Field::Field(size_t x_size, size_t y_size): x_size(x_size), y_size(y_size), field(std::vector<std::vector<Cell*>>(x_size, std::vector<Cell*>(y_size, nullptr))) {
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



