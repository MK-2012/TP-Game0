#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "Unit.h"
#include "Structure.h"
#include "CursorImages.h"

class Field;
class Cell;
class Cursor;
class Aim;



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
    bool isAllowedToGoIn() const;
};



class Field {
private:
    std::vector<std::vector<Cell*>> field;
public:
    std::vector<Cursor*> cursors;
    size_t x_size;
    size_t y_size;
    Field(size_t x_size, size_t y_size);
    std::vector<Cell*>& operator [] (size_t x);
    const std::vector<Cell*>& operator [] (size_t x) const;

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
    void move(int delta_x, int delta_y) override;
public:
    explicit Aim(const Cursor& cursor);

    CursorImages image() override;

    void attack();
    ~Aim();
};





template<typename UnitType>
void emplaceUnit(Cell* cell);
template<typename StructureType>
void emplaceStructure(Cell* cell);
