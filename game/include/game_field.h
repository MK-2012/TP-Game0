#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "Unit.h"
#include "Structure.h"

class Field;
class Cell;
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
    bool isAllowedToGoIn() const;
};



class Field {
private:
    std::vector<std::vector<Cell*>> field;
public:
    size_t x_size;
    size_t y_size;
    Field(size_t x_size, size_t y_size);
    std::vector<Cell*>& operator [] (size_t x);
    const std::vector<Cell*>& operator [] (size_t x) const;

    bool cellIsFree(int x, int y);
};




