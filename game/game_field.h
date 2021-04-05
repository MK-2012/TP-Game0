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
    std::vector<Cursor*> cursors;
    size_t x_size;
    size_t y_size;
    Field(size_t x_size, size_t y_size);
    std::vector<Cell*>& operator [] (size_t x);
    const std::vector<Cell*>& operator [] (size_t x) const;
    void print();

    bool cellIsFree(int x, int y);
};


class Cursor {
protected:

    virtual void move(int delta_x, int delta_y);

    Field& field_;
public:
    bool unit_attached{};
    size_t x;
    size_t y;
    explicit Cursor(Field& field, size_t x = 0, size_t y = 0);
    Cursor(const Cursor& other);

    virtual CursorImages image();

    virtual void move_up();

    virtual void move_down();

    virtual void move_left();

    virtual void move_right();
    void attachUnit();
    void detachUnit();

    ~Cursor();

};

class Aim : public Cursor {
    const Cursor& creator;
    void move(int delta_x, int delta_y) override {
        if((delta_x + x) >= 0 && (delta_y + y) >= 0 && (delta_x + x) < field_.x_size && (delta_y + y) < field_.y_size) {
            if (field_[x][y]->located_unit -> allowedToMoveAim(delta_x, delta_y)) {
                x += delta_x;
                y += delta_y;
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