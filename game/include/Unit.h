#pragma once

#include "UnitImages.h"
#include <iostream>
#include "PlayerEnum.h"


class Unit {
public:
    PlayerEnum player_;

    virtual uint16_t hp() = 0;
    virtual uint16_t damage(PlayerEnum player) = 0;
    virtual int cost() = 0;
    virtual uint16_t distance() = 0;
    virtual UnitImages image() = 0;
    virtual std::string name() = 0;
    virtual void clearMotions() = 0;
    virtual ~Unit() = default;
    virtual bool existence();
    virtual bool canConstruct();

    virtual bool allowed_to_move() = 0;
    virtual bool allowedToMoveAim(int delta_x, int delta_y) = 0;
    virtual bool get_damage(uint16_t damage) = 0;
protected:
    Unit(PlayerEnum player);
};


class NonExistentUnit : public Unit {
public:
    const static std::string name_;
    NonExistentUnit(PlayerEnum player);
    const static UnitImages image_ = NonExistentUnitImage;

    bool existence () override;

    uint16_t hp() override;
    uint16_t damage(PlayerEnum player) override;
    uint16_t distance() override;
    std::string name() override;
    void clearMotions() override;
    int cost() override;
    virtual UnitImages image();


    bool allowed_to_move() override;
    bool allowedToMoveAim(int delta_x, int delta_y) override;

    bool get_damage(uint16_t damage) override;;
    ~NonExistentUnit() override = default;
};


class Clubber: public Unit {
    const static UnitImages image_ = ClubberImage;
    uint16_t hp_ = 35;
    uint16_t damage_ = 15;
    uint16_t distance_ = 1;
    int num_of_motions = 0;
    int max_motions = 3;
public:
    const static std::string name_;
    const static uint16_t cost_ = 1;
    Clubber(PlayerEnum player);

    uint16_t hp() override;
    uint16_t damage(PlayerEnum player) override;
    uint16_t distance() override;
    std::string name() override;
    void clearMotions() override;
    int cost() override;
    UnitImages image() override;



    bool allowed_to_move() override;
    bool allowedToMoveAim(int delta_x, int delta_y) override;

    bool get_damage(uint16_t damage) override;
    ~Clubber() override = default;
};


class Worker: public Unit {
    const static UnitImages image_ = WorkerImage;
    uint16_t hp_ = 35;
    uint16_t damage_ = 15;
    uint16_t distance_ = 1;
    int num_of_motions = 0;
    int max_motions = 3;
public:
    const static std::string name_;
    const static uint16_t cost_ = 1;
    Worker(PlayerEnum player);

    uint16_t hp() override;
    uint16_t damage(PlayerEnum player) override;
    uint16_t distance() override;
    std::string name() override;
    void clearMotions() override;
    int cost() override;
    UnitImages image() override;

    bool canConstruct() override;

    bool allowed_to_move() override;
    bool allowedToMoveAim(int delta_x, int delta_y) override;

    bool get_damage(uint16_t damage) override;
    ~Worker() override = default;
};


