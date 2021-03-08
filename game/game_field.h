//
// Created by val-de-mar on 07.03.2021.
//

#ifndef GAME_GAME_FIELD_H
#define GAME_GAME_FIELD_H

#endif //GAME_GAME_FIELD_H

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "graphics.h"
#include "Unit.h"
#include "Structure.h"

class Field;
class Cell;

template<typename UnitType>
void emplaceUnit(Cell* cell);



class Cell {
public:
    size_t x;
    size_t y;
    Field& current_field;
    Unit_<Cell>* located_unit;
    Structure_<Cell>* located_structure;
    Cell(Field &field, int x, int y) : x(x), y(y), current_field(field), located_unit(new NonExistentUnit_<Cell>(this)), located_structure(new NonExistentStructure_<Cell>(this)){}
    friend void emplaceUnit(Cell* cell);
};



class Field {
    friend FieldPainter<Field>;
private:
    using CellType = Cell;

    std::vector<std::vector<CellType*>> field;
    FieldPainter<Field> paint;
public:
    size_t x_size;
    size_t y_size;
    Field(size_t x_size, size_t y_size) : x_size(x_size), y_size(y_size), field(std::vector<std::vector<Cell*>>(x_size, std::vector<Cell*>(y_size, nullptr))), paint(*this) {
        for (int i = 0; i < field.size(); ++i) {
            for (int j = 0; j < field[i].size(); ++j) {
                field[i][j] = new Cell(*this, i, j);
            }
        }
    };
    std::vector<Cell*>& operator [] (size_t x) {
        return field[x];
    }
    const std::vector<Cell*>& operator [] (size_t x) const {
        return field[x];
    }
    void print() {
        for (int i = 0; i < field.size(); ++i) {
            for (int j = 0; j < field[i].size(); ++j) {
                paint(field[i][j]);
            }
        }
    }

};





using Unit = Unit_<Cell>;
using Structure = Structure_<Cell>;
using NonExistentUnit = NonExistentUnit_<Cell>;
using Clubber = Clubber_<Cell>;
using NonExistentStructure = NonExistentStructure_<Cell>;

template<typename UnitType>
void emplaceUnit(Cell* cell) {
    delete cell -> located_unit;
    cell -> located_unit = new UnitType(cell);
}
template<typename StructureType>
void emplaceStructure(Cell* cell) {
    delete cell -> located_unit;
    cell -> located_unit = new StructureType(cell);
}