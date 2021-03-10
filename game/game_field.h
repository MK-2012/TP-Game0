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
class Aim;

template<typename UnitType>
void emplaceUnit(Cell* cell);



class Cell {
public:
    size_t x;
    size_t y;
    Field& field;
    Unit_<Cell>* located_unit;
    Structure_<Cell>* located_structure;
    Cell(Field &field, int x, int y) : x(x), y(y), field(field), located_unit(new NonExistentUnit_<Cell>(this)), located_structure(new Grass_<Cell>(this)){}
    friend void emplaceUnit(Cell* cell);
    bool isAllowedToGoIn() {
        return located_unit -> unitTypeId() == 0 && located_structure -> isAllowedToGoIn();
    }
};



class Field {
    friend FieldPainter<Field>;
private:
    using CellType = Cell;
    std::vector<std::vector<CellType*>> field;
    FieldPainter<Field> paint;
public:
    Aim* aim = nullptr;
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

    bool cellIsFree(int x, int y) {
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
};


class Aim {
    Unit_<Cell>* unit;
    size_t x_size;
    size_t y_size;
    void move(int delta_x, int delta_y) {
        if((delta_x + x) >= 0 && (delta_y + y) >= 0 && (delta_x + x) < x_size && (delta_y + y) < y_size) {
            if (unit -> allowedToMoveAim(x + delta_x, y + delta_y)) {
                x += delta_x;
                y += delta_y;
            }
        }
    }
public:
    size_t x;
    size_t y;
    explicit Aim(Unit_<Cell>* unit) : unit(unit), x(unit -> place -> x), y(unit -> place -> y), x_size(unit -> place ->field.x_size), y_size(unit -> place -> field.y_size) {
        unit -> place -> field.aim = this;
    }
    void move_up() {
        move(0, -1);
    };
    void move_down() {
        move(0, 1);
    };
    void move_left() {
        move(-1, 0);
    };
    void move_right() {
        move(1, 0);
    };
    ~Aim(){
        unit -> place -> field.aim = nullptr;
    }
};





using Unit = Unit_<Cell>;
using Structure = Structure_<Cell>;
using NonExistentUnit = NonExistentUnit_<Cell>;
using Clubber = Clubber_<Cell>;
using Landscape = Landscape_<Cell>;
using Grass = Grass_<Cell>;
using River = River_<Cell>;

template<typename UnitType>
void emplaceUnit(Cell* cell) {
    if (cell -> isAllowedToGoIn()) {
        delete cell->located_unit;
        cell->located_unit = new UnitType(cell);
    }
}
template<typename StructureType>
void emplaceStructure(Cell* cell) {
    delete cell -> located_structure;
    cell -> located_structure = new StructureType(cell);
}