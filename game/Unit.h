//
// Created by val-de-mar on 08.03.2021.
//

#ifndef GAME_UNIT_H
#define GAME_UNIT_H

#endif //GAME_UNIT_H

#include "UnitImages.h"


class Unit {
public:

    virtual uint16_t hp() = 0;
    virtual uint16_t damage() = 0;
    virtual uint16_t distance() = 0;
    virtual UnitImages image() = 0;
    virtual ~Unit() = default;
    virtual bool existence() {
        return true;
    }

    virtual bool allowed_to_move() = 0;
    virtual bool allowedToMoveAim(int delta_x, int delta_y) = 0;
    virtual bool get_damage(uint16_t damage) = 0;
protected:
    explicit Unit() {}
};


class NonExistentUnit : public Unit {
public:
    explicit NonExistentUnit() : Unit() {}
    const static UnitImages image_ = NonExistentUnitImage;

    bool existence () override {
        return false;
    }

    uint16_t hp() override {
        return 0;
    }
    uint16_t damage() override {
        return 0;
    };
    uint16_t distance() override {
        return 0;
    }
    virtual UnitImages image() {
        return image_;
    }


    bool allowed_to_move() override {
        return true;
    };
    bool allowedToMoveAim(int delta_x, int delta_y) override {
        return false;
    }

    bool get_damage(uint16_t damage) override {
        return false;
    };
    ~NonExistentUnit() override = default;
};


class Clubber: public Unit {
    const static UnitImages image_ = ClubberImage;
    uint16_t hp_ = 35;
    uint16_t damage_ = 15;
    uint16_t distance_ = 1;
public:
    explicit Clubber() : Unit() {}

    uint16_t hp() override {
        return hp_;
    };
    uint16_t damage() override {
        return damage_;
    };
    uint16_t distance() override {
        return distance_;
    }
    UnitImages image() override {
        return image_;
    }


    bool allowed_to_move() override {
        return true;
    };
    bool allowedToMoveAim(int delta_x, int delta_y) override {
        return delta_x <= distance_ && delta_y <= distance_;
    }

    bool get_damage(uint16_t damage) override {
        if (hp_ < damage) {
            return true;
        } else {
            hp_ -= damage;
            return false;
        }
    }
    ~Clubber() override {};
};


