#include "game_field.h"

using vvi = std::vector<std::vector<int>>;

UnitAttachingException::UnitAttachingException(std::string&& error):m_error(error) {}
UnitAttachingException::UnitAttachingException(const char* error): m_error(error) {}
UnitAttachingException::UnitAttachingException(std::string error): m_error(std::move(error)) {}

const char* UnitAttachingException::what() const noexcept {
	return m_error.c_str();
}


//0 - grass
//1 - river
//2 - mountains
Cell::Cell(Field& field, int x, int y, int cell_type): x(x), y(y), field(field), located_unit(new NonExistentUnit(Nobody)) {
	switch(cell_type) {
		case 0: {
			located_structure = new Grass(Nobody);
			break;
		}
		case 1: {
			located_structure = new River(Nobody);
			break;
		}
		case 2: {
			located_structure = new Mountains(Nobody);
			break;
		}
		default: {
			throw std::invalid_argument("Wrong cell type");
		}
	}
};

bool Cell::isAllowedToGoIn() const {
	return !(located_unit -> existence()) && located_structure -> isAllowedToGoIn();
}


void Field::generate_river(vvi& map_to_generate) {
	Rivers rivers(map_to_generate);
}

void Field::generate_mountains(vvi& map_to_generate) {

}

void Field::place_cities(vvi& map_to_generate) {

}

void Field::generate_map(vvi& map_to_generate) {
	for (int i = 0; i < 1; ++i) {
		generate_river(map_to_generate);
	}
	generate_mountains(map_to_generate);
	place_cities(map_to_generate);
}


Field::Field(size_t x_size, size_t y_size): x_size(x_size), y_size(y_size), field(std::vector<std::vector<Cell*>>(x_size, std::vector<Cell*>(y_size))) {
	vvi generated_map(y_size, std::vector<int>(x_size));
	//generate_map(generated_map);

	for (int i = 0; i < y_size; ++i) {
		for (int j = 0; j < x_size; ++j) {
			field[i][j] = new Cell(*this, i, j, generated_map[i][j]);
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



std::pair<size_t, size_t> standard_sizes = {30, 30};
vvi standard_map = {{2, 2, 2, 2, 2, 0, 0, 1, 0, 0, 0, 2, 2, 2, 2, 1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
					{0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 2, 0, 2, 0, 1, 0, 0, 0, 0, 2, 0, 2, 2, 2, 2, 0, 2, 2, 2},
					{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 1, 1, 1, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 2, 0},
					{0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 2, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0},
					{2, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 2, 0, 1, 1, 1, 0, 0, 0, 2, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2},
					{0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0},
					{2, 0, 2, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 2, 0, 0},
					{0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0},
					{0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
					{0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 2, 2, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
					{0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2},
					{0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 2, 2, 2, 0, 0, 0, 0, 0, 0, 2},
					{0, 0, 0, 2, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 2, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
					{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
					{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
					{2, 0, 0, 0, 0, 0, 0, 1, 1, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 2},
					{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
					{2, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 2},
					{2, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 2},
					{2, 0, 0, 0, 0, 1, 1, 1, 0, 2, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 2, 2},
					{0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2},
					{2, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
					{2, 2, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 2},
					{2, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 2, 2, 2, 1, 2, 2, 2, 2, 0, 2, 2},
					{2, 2, 2, 1, 2, 0, 0, 1, 0, 0, 0, 2, 2, 2, 2, 0, 1, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2},
					};


Field::Field(MapPresets preset) {
	vvi map_to_generate;
	switch (preset) {
		case standard: {
			y_size = standard_sizes.second;
			x_size = standard_sizes.first;
			field.resize(x_size);
			for (int i = 0; i < x_size; ++i) {
				field[i].resize(y_size);
			}
			map_to_generate = standard_map;
			break;
		}
	}
	for (int i = 0; i < x_size; ++i) {
		for (int j = 0; j < y_size; ++j) {
			Cell* temp = new Cell(*this, i, j, map_to_generate[j][i]);
			field[i][j] = temp;
		}
	}
}
