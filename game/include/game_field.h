#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "Unit.h"
#include "Structure.h"
#include "Rivers.h"
#include <random>

class Field;
class Cell;
class Aim;


using vvi = std::vector<std::vector<int>>;


enum MapPresets {
	standard
};



class UnitAttachingException: public std::exception {
private:
    std::string m_error;

public:
    explicit UnitAttachingException(std::string&& error);
    explicit UnitAttachingException(const char* error);

    explicit UnitAttachingException(std::string error);

    const char* what() const noexcept override;
};


class Cell {
public:
    size_t x;
    size_t y;
    Field& field;
    Unit* located_unit;
    Structure* located_structure;
    Cell(Field &field, int x, int y, int cell_type);
    bool isAllowedToGoIn() const;
};



class Field {
private:
    std::vector<std::vector<Cell*>> field;

	void generate_preset(MapPresets preset, vvi& map_to_generate);

    void generate_map(vvi& map_to_generate);
    void generate_river(vvi& map_to_generate);
    void generate_mountains(vvi& map_to_generate);
    void place_cities(vvi& map_to_generate);
public:
    size_t x_size;
    size_t y_size;
    Field(size_t x_size, size_t y_size);
    Field(MapPresets preset);
    std::vector<Cell*>& operator [] (size_t x);
    const std::vector<Cell*>& operator [] (size_t x) const;

    bool cellIsFree(int x, int y);
};




