#include "Unit.h"
#include "Structure.h"
#include "graphics.h"

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
    std::vector<Cell*>& operator[](size_t x);
    const std::vector<Cell*>& operator[](size_t x) const;
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

template<typename UnitType>
void emplaceUnit(Cell* cell) {
    if (cell -> isAllowedToGoIn()) {
        delete cell->located_unit;
        //cell->located_unit = new UnitType(cell);
    }
}


template<typename StructureType>
void emplaceStructure(Cell* cell) {
    delete cell -> located_structure;
    //cell -> located_structure = new StructureType(cell);
}


