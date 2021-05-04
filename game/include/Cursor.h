#pragma once
#include "game_field.h"
#include "UnitTreasury.h"
#include "StructureTreasury.h"
#include "CursorImages.h"



class Cursor {
protected:
    virtual void move(int delta_x, int delta_y);
    PlayerEnum player_;
public:
    bool unit_attached;
    size_t x;
    size_t y;
    explicit Cursor(Field& field, PlayerEnum player, size_t x = 0, size_t y = 0);
    Cursor(const Cursor& other);

    virtual CursorImages image() const;

    virtual void move_up();

    virtual void move_down();

    virtual void move_left();

    virtual void move_right();
    void attachUnit();
    void detachUnit();
    Cell* get_cell();

    ~Cursor();

    Field& field_;
};

class Aim : public Cursor {
    const Cursor& creator;
    void move(int delta_x, int delta_y) override;
public:
    explicit Aim(const Cursor& cursor);

    CursorImages image() const override;

    void attack();
    void attackStructure();
    ~Aim();
};
