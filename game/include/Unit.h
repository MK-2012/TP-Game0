#pragma once

#include "UnitImages.h"
#include <iostream>


class Unit {
public:

    virtual uint16_t hp() = 0;
    virtual uint16_t damage() = 0;
    virtual uint16_t distance() = 0;
    virtual UnitImages image() = 0;
    virtual ~Unit();
    virtual bool existence();

    virtual bool allowed_to_move() = 0;
    virtual bool allowedToMoveAim(int delta_x, int delta_y) = 0;
    virtual bool get_damage(uint16_t damage) = 0;
protected:
    Unit();
};


class NonExistentUnit : public Unit {
public:
    NonExistentUnit();
    const static UnitImages image_ = NonExistentUnitImage;

    bool existence () override;

    uint16_t hp() override;
    uint16_t damage() override;
    uint16_t distance() override;
    UnitImages image() override;


    bool allowed_to_move() override;;
    bool allowedToMoveAim(int delta_x, int delta_y) override;

    bool get_damage(uint16_t damage) override;;
    ~NonExistentUnit() override;
};


class Clubber: public Unit {
    const static UnitImages image_ = ClubberImage;
    uint16_t hp_ = 35;
    uint16_t damage_ = 15;
    uint16_t distance_ = 1;
public:
    Clubber() = default;

    uint16_t hp() override;;
    uint16_t damage() override;;
    uint16_t distance() override;
    UnitImages image() override;


    bool allowed_to_move() override;;
    bool allowedToMoveAim(int delta_x, int delta_y) override;

    bool get_damage(uint16_t damage) override;
    ~Clubber() override = default;
};


