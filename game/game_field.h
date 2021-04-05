#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "graphics.h"
#include "Unit.h"
#include "Structure.h"
#include "CursorImages.h"

class Field;
class Cell;
class Cursor;
class Aim;

template<typename UnitType>
void emplaceUnit(Cell* cell);


class UnitAttachingException: public std::exception {
private:
    std::string m_error;

public:
    explicit UnitAttachingException(std::string&& error) : m_error(error) {}
    explicit UnitAttachingException(const char* error) : m_error(error) {}

    explicit UnitAttachingException(std::string error) : m_error(std::move(error)) {}

    const char* what() const noexcept override {
        return m_error.c_str();
    }
};


class Cell {
public:
    size_t x;
    size_t y;
    Field& field;
    Unit* located_unit;
    Structure* located_structure;
    Cell(Field &field, int x, int y) : x(x), y(y), field(field), located_unit(new NonExistentUnit()), located_structure(new Grass()){}
    friend void emplaceUnit(Cell* cell);
    bool isAllowedToGoIn() {
        return !(located_unit -> existence()) && located_structure -> isAllowedToGoIn();
    }
};



class Field {
    friend FieldPainter<Field>;
private:
    using CellType = Cell;
    std::vector<std::vector<CellType*>> field;
    FieldPainter<Field> paint;
public:
    std::vector<Cursor*> cursors;
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


class Cursor {
protected:

    virtual void move(int delta_x, int delta_y) {
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

    Field& field_;
public:
    bool unit_attached{};
    size_t x;
    size_t y;
    explicit Cursor(Field& field, size_t x = 0, size_t y = 0) : field_(field), x(x), y(y), unit_attached(false) {
        field_.cursors.push_back(this);
    }
    Cursor(const Cursor& other) : field_(other.field_), x(other.x), y(other.y), unit_attached(other.unit_attached) {
        field_.cursors.push_back(this);
    }

    virtual CursorImages image() {
        if (unit_attached){
            return CursorWithUnitImage;
        } else {
            return CursorWithoutUnitImage;
        }
    }

    virtual void move_up() {
        move(0, -1);
    };

    virtual void move_down() {
        move(0, 1);
    };

    virtual void move_left() {
        move(-1, 0);
    };

    virtual void move_right() {
        move(1, 0);
    };
    void attachUnit() {
        if (unit_attached) {
            throw UnitAttachingException("unit already attached");
        }
        if (!(field_[x][y] -> located_unit-> existence())){
            throw UnitAttachingException("You can't attach non existent unit");
        } else {
            unit_attached = true;
        }
    }
    void detachUnit() {
        if (!unit_attached) {
            throw UnitAttachingException("there is no attached units");
        } else {
            unit_attached = false;
        }
    }

    ~Cursor(){
        field_.cursors.pop_back();
    }


};

class Aim : public Cursor {
    const Cursor& creator;
    void move(int delta_x, int delta_y) override {
        int new_x = static_cast<int>(x)+ delta_x;
        int new_y = static_cast<int>(y) + delta_y;
        if(new_x >= 0 && new_y >= 0 && new_x < field_.x_size && new_y < field_.y_size) {
            if (field_[creator.x][creator.y]->located_unit -> allowedToMoveAim(new_x - static_cast<int>(creator.x), new_y - static_cast<int>(creator.y))) {
                x = new_x;
                y = new_y;
            }
        }
    }

public:
    explicit Aim(const Cursor& cursor) : Cursor(cursor), creator(cursor){}

    CursorImages image() override {
        return AimImage;
    }

    void attack(){
        if (field_[x][y] -> located_unit != field_[creator.x][creator.y] -> located_unit) {
            if (field_[x][y]->located_unit->get_damage(field_[creator.x][creator.y] -> located_unit ->damage())) {
                delete field_[x][y]->located_unit;
                field_[x][y]->located_unit = new NonExistentUnit;
            }
        }
    }
    ~Aim(){

    }
};





template<typename UnitType>
void emplaceUnit(Cell* cell) {
    if (cell -> isAllowedToGoIn()) {
        delete cell->located_unit;
        cell->located_unit = new UnitType();
    }
}
template<typename StructureType>
void emplaceStructure(Cell* cell) {
    delete cell -> located_structure;
    cell -> located_structure = new StructureType();
}