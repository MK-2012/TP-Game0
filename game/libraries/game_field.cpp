

#include <vector>
#include <string>
#include "../include/graphics.h"
#include "../include/Unit.h"
#include "../include/Structure.h"

class Field;
class Cell;
class Aim;




class Cell {
public:
    size_t x;
    size_t y;
    Field& field;
    Unit_<Cell>* located_unit;
    Structure_<Cell>* located_structure;
    Cell(Field &field, int x, int y);
    friend void emplaceUnit(Cell* cell);
    bool isAllowedToGoIn();
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
    Field(size_t x_size, size_t y_size);;
    std::vector<Cell*>& operator [] (size_t x);
    const std::vector<Cell*>& operator [] (size_t x) const;
    void print();

    bool cellIsFree(int x, int y);
};




class Aim {
    Unit_<Cell>* unit;
    size_t x_size;
    size_t y_size;
    void move(int delta_x, int delta_y);
public:
    size_t x;
    size_t y;
    explicit Aim(Unit_<Cell>* unit);
    void move_up();;
    void move_down();;
    void move_left();;
    void move_right();;
    void attack();
    ~Aim();
};



using Unit = Unit_<Cell>;
using Structure = Structure_<Cell>;
using NonExistentUnit = NonExistentUnit_<Cell>;
using Clubber = Clubber_<Cell>;
using Landscape = Landscape_<Cell>;
using Grass = Grass_<Cell>;
using River = River_<Cell>;




Cell::Cell(Field &field, int x, int y) : x(x), y(y), field(field), located_unit(new NonExistentUnit_<Cell>(this)), located_structure(new Grass_<Cell>(this)){}

bool Cell::isAllowedToGoIn() {
    return located_unit -> unitTypeId() == 0 && located_structure -> isAllowedToGoIn();
}




Field::Field(size_t x_size, size_t y_size) : x_size(x_size), y_size(y_size), field(std::vector<std::vector<Cell*>>(x_size, std::vector<Cell*>(y_size, nullptr))), paint(*this) {
    for (int i = 0; i < field.size(); ++i) {
        for (int j = 0; j < field[i].size(); ++j) {
            field[i][j] = new Cell(*this, i, j);
        }
    }
}

std::vector<Cell *> &Field::operator[](size_t x) {
    return field[x];
}

const std::vector<Cell *> &Field::operator[](size_t x) const {
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



void Aim::move(int delta_x, int delta_y) {
    if((delta_x + x) >= 0 && (delta_y + y) >= 0 && (delta_x + x) < x_size && (delta_y + y) < y_size) {
        if (unit -> allowedToMoveAim(x + delta_x, y + delta_y)) {
            x += delta_x;
            y += delta_y;
        }
    }
}

Aim::Aim(Unit_<Cell> *unit) : unit(unit), x(unit -> place -> x), y(unit -> place -> y), x_size(unit -> place ->field.x_size), y_size(unit -> place -> field.y_size) {
    unit -> place -> field.aim = this;
}

void Aim::move_up() {
    move(0, -1);
}

void Aim::move_down() {
    move(0, 1);
}

void Aim::move_left() {
    move(-1, 0);
}

void Aim::move_right() {
    move(1, 0);
}

void Aim::attack() {
    auto aimed_unit = unit -> place -> field[x][y] -> located_unit;
    if(aimed_unit -> get_damage(unit -> damage())){
        aimed_unit -> ~Unit_<Cell>();
    }
}

Aim::~Aim() {
    unit -> place -> field.aim = nullptr;
}
