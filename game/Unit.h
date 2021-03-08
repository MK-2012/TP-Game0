//
// Created by val-de-mar on 08.03.2021.
//

#ifndef GAME_UNIT_H
#define GAME_UNIT_H

#endif //GAME_UNIT_H


template<typename Cell>
class Unit_ {
public:
    Cell* place;
    virtual int unitTypeId() = 0;
    virtual uint16_t hp() = 0;
    virtual uint16_t damage() = 0;
    virtual const std::string& image_placement() = 0;
    virtual ~Unit_() = default;
    virtual bool existence() {
        return true;
    }
    virtual void move_up() {
        if (checkCorrectnessOfMovement(0, -1)) {
            if (allowed_to_move()) {
                 Cell* next_place = ((place -> current_field))[place -> x][place -> y - 1];
                 std::swap(place -> located_unit, next_place -> located_unit);
                 std::swap(place -> located_unit -> place, next_place -> located_unit -> place);

            }
        }

    };
    virtual void move_down() {
        if (checkCorrectnessOfMovement(0, 1)) {
            if (allowed_to_move()) {
                Cell* next_place = ((place -> current_field))[place -> x][place -> y + 1];
                std::swap(place -> located_unit, next_place -> located_unit);
                std::swap(place -> located_unit -> place, next_place -> located_unit -> place);

            }
        }
    };
    virtual void move_left() {
        if (checkCorrectnessOfMovement(-1, 0)) {
            if (allowed_to_move()) {
                Cell* next_place = ((place -> current_field))[place -> x - 1][place -> y];
                std::swap(place -> located_unit, next_place -> located_unit);
                std::swap(place -> located_unit -> place, next_place -> located_unit -> place);

            }
        }
    };
    virtual void move_right() {
        if (checkCorrectnessOfMovement(1, 0)) {
            if (allowed_to_move()) {
                Cell* next_place = ((place -> current_field))[place -> x + 1][place -> y];
                std::swap(place -> located_unit, next_place -> located_unit);
                std::swap(place -> located_unit -> place, next_place -> located_unit -> place);

            }
        }
    };
    virtual bool allowed_to_move() = 0;
    bool checkCorrectnessOfMovement(int delta_x, int delta_y) {
        int x_new = (place -> x) + delta_x;
        if (x_new < 0 || x_new >= place -> current_field.x_size) {
            return false;
        }
        int y_new = (place -> y) + delta_y;
        if (y_new < 0 || y_new >= place -> current_field.y_size) {
            return false;
        }
        if (((place -> current_field))[x_new][y_new] -> located_unit -> unitTypeId() != 0) {
            return false;
        }
        return true;
    }

protected:
    explicit Unit_(Cell* place) : place(place) {}
};

template<typename Cell>
class NonExistentUnit_ : public Unit_<Cell> {
public:
    explicit NonExistentUnit_(Cell* place) : Unit_<Cell>(place) {}
    const static std::string image_placement_;

    bool existence () override {
        return false;
    }

    int unitTypeId() override {
        return 0;
    };
    uint16_t hp() override {
        return 0;
    }
    uint16_t damage() override {
        return 0;
    };
    virtual const std::string& image_placement() {
        return image_placement_;
    }

    bool allowed_to_move() override {
        return true;
    };
    ~NonExistentUnit_() override = default;
};

template<typename Cell>
const std::string NonExistentUnit_<Cell>::image_placement_ = "images/units/non_existent.png";

template<typename Cell>
class Clubber_ : public Unit_<Cell> {
    const static std::string image_placement_;
    uint16_t hp_ = 35;
    uint16_t damage_ = 15;
public:
    explicit Clubber_(Cell* place) : Unit_<Cell>(place) {}

    int unitTypeId() override {
        return 1;
    };
    uint16_t hp() override {
        return hp_;
    };
    uint16_t damage() override {
        return damage_;
    };
    const std::string& image_placement() override {
        return image_placement_;
    }


    bool allowed_to_move() override {
        return true;
    };
    ~Clubber_() override = default;
};

template<typename Cell>
const std::string Clubber_<Cell>::image_placement_ = "images/units/clubber.png";

