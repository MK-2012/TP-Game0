#pragma once
#include <string>


template<typename Cell>
class Unit_ {
public:

    Cell* place;
    virtual int unitTypeId() = 0;
    virtual uint16_t hp() = 0;
    virtual uint16_t damage() = 0;
    virtual uint16_t distance() = 0;
    virtual const std::string& image_placement() = 0;
    virtual ~Unit_() = default;
    virtual bool existence();
    virtual void move_up();
    virtual void move_down();
    virtual void move_left();
    virtual void move_right();
    virtual bool allowed_to_move() = 0;
    virtual bool allowedToMoveAim(size_t x, size_t y) = 0;
    uint16_t attack(Unit_<Cell> *aimed_unit);
    virtual bool get_damage(uint16_t damage) = 0;
protected:
    explicit Unit_(Cell* place) : place(place) {}
};


template<typename Cell>
class NonExistentUnit_ : public Unit_<Cell> {
public:
    explicit NonExistentUnit_(Cell* place) : Unit_<Cell>(place) {}
    const static std::string image_placement_;

    bool existence () override;

    int unitTypeId() override;
    uint16_t hp() override;
    uint16_t damage() override;;
    uint16_t distance() override;
    virtual const std::string& image_placement();


    bool allowed_to_move() override;;
    bool allowedToMoveAim(size_t x, size_t y) override;

    bool get_damage(uint16_t damage) override;;
    ~NonExistentUnit_() override = default;
};


template<typename Cell>
class Clubber_ : public Unit_<Cell> {
    const static std::string image_placement_;
    uint16_t hp_ = 35;
    uint16_t damage_ = 15;
    uint16_t distance_ = 1;
public:
    explicit Clubber_(Cell* place) : Unit_<Cell>(place) {}

    int unitTypeId() override;;
    uint16_t hp() override;;
    uint16_t damage() override;;
    uint16_t distance() override;
    const std::string& image_placement() override;


    bool allowed_to_move() override;;
    bool allowedToMoveAim(size_t x, size_t y) override;

    bool get_damage(uint16_t damage) override;
    ~Clubber_() override;;
};





template<typename Cell>
bool Unit_<Cell>::existence() {
    return true;
}

template<typename Cell>
void Unit_<Cell>::move_up() {
    if (place -> field.cellIsFree(place -> x, place -> y - 1)) {
        if (allowed_to_move()) {
            Cell* next_place = ((place -> field))[place -> x][place -> y - 1];
            std::swap(place -> located_unit, next_place -> located_unit);
            std::swap(place -> located_unit -> place, next_place -> located_unit -> place);

        }
    }

}

template<typename Cell>
void Unit_<Cell>::move_down() {
    if (place -> field.cellIsFree(place -> x, place -> y + 1)) {
        if (allowed_to_move()) {
            Cell* next_place = ((place -> field))[place -> x][place -> y + 1];
            std::swap(place -> located_unit, next_place -> located_unit);
            std::swap(place -> located_unit -> place, next_place -> located_unit -> place);

        }
    }
}

template<typename Cell>
void Unit_<Cell>::move_left() {
    if (place -> field.cellIsFree(place -> x - 1, place -> y)) {
        if (allowed_to_move()) {
            Cell* next_place = ((place -> field))[place -> x - 1][place -> y];
            std::swap(place -> located_unit, next_place -> located_unit);
            std::swap(place -> located_unit -> place, next_place -> located_unit -> place);

        }
    }
}

template<typename Cell>
void Unit_<Cell>::move_right() {
    if (place -> field.cellIsFree(place -> x + 1, place -> y)) {
        if (allowed_to_move()) {
            Cell* next_place = ((place -> field))[place -> x + 1][place -> y];
            std::swap(place -> located_unit, next_place -> located_unit);
            std::swap(place -> located_unit -> place, next_place -> located_unit -> place);

        }
    }
}

template<typename Cell>
uint16_t Unit_<Cell>::attack(Unit_<Cell> *aimed_unit) {
    if (aimed_unit != this) {
        return damage();
    }

}





template<typename Cell>
const std::string NonExistentUnit_<Cell>::image_placement_ = "images/units/non_existent.png";

template<typename Cell>
bool NonExistentUnit_<Cell>::existence() {
    return false;
}

template<typename Cell>
int NonExistentUnit_<Cell>::unitTypeId() {
    return 0;
}

template<typename Cell>
uint16_t NonExistentUnit_<Cell>::hp() {
    return 0;
}

template<typename Cell>
uint16_t NonExistentUnit_<Cell>::damage() {
    return 0;
}

template<typename Cell>
uint16_t NonExistentUnit_<Cell>::distance() {
    return 0;
}

template<typename Cell>
const std::string &NonExistentUnit_<Cell>::image_placement() {
    return image_placement_;
}

template<typename Cell>
bool NonExistentUnit_<Cell>::allowed_to_move() {
    return true;
}

template<typename Cell>
bool NonExistentUnit_<Cell>::allowedToMoveAim(size_t x, size_t y) {
    return false;
}

template<typename Cell>
bool NonExistentUnit_<Cell>::get_damage(uint16_t damage) {
    return false;
}





template<typename Cell>
const std::string Clubber_<Cell>::image_placement_ = "images/units/clubber.png";

template<typename Cell>
int Clubber_<Cell>::unitTypeId() {
    return 1;
}

template<typename Cell>
uint16_t Clubber_<Cell>::hp() {
    return hp_;
}

template<typename Cell>
uint16_t Clubber_<Cell>::damage() {
    return damage_;
}

template<typename Cell>
uint16_t Clubber_<Cell>::distance() {
    return distance_;
}

template<typename Cell>
const std::string &Clubber_<Cell>::image_placement() {
    return image_placement_;
}

template<typename Cell>
bool Clubber_<Cell>::allowed_to_move() {
    return true;
}

template<typename Cell>
bool Clubber_<Cell>::allowedToMoveAim(size_t x, size_t y) {
    return std::abs(static_cast<int>(x)  - static_cast<int>(Unit_<Cell>::place->x)) <= distance_ && std::abs(static_cast<int>(y) - static_cast<int>(Unit_<Cell>::place->y)) <= distance_;
}

template<typename Cell>
bool Clubber_<Cell>::get_damage(uint16_t damage) {
    if (hp_ < damage) {
        return true;
    } else {
        hp_ -= damage;
        return false;
    }
}

template<typename Cell>
Clubber_<Cell>::~Clubber_() {
    Unit_<Cell>::place -> located_unit = new NonExistentUnit_<Cell>(Unit_<Cell>::place);
}
