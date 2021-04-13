

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
    virtual bool existence() {
        return true;
    }
    virtual void move(int delta_x, int delta_y) {
        if (place -> field.cellIsFree(place -> x + delta_x, place -> y + delta_y)) {
            if (allowed_to_move()) {
                Cell* next_place = ((place -> field))[place -> x + delta_x][place -> y + delta_y];
                std::swap(place -> located_unit, next_place -> located_unit);
                std::swap(place -> located_unit -> place, next_place -> located_unit -> place);

            }
        }
    }
    virtual void move_up() {
        move(0, -1);
    };
    virtual void move_down() {
        move(0, 1);
    };
    virtual void move_left() {
        move(-1, 0);
    };
    virtual void move_right() {
        move(1, 0);
    };
    virtual bool allowed_to_move() = 0;
    virtual bool allowedToMoveAim(size_t x, size_t y) = 0;
    uint16_t attack(Unit_<Cell> *aimed_unit) {
        if (aimed_unit != this) {
            return damage();
        }

    }
    virtual bool get_damage(uint16_t damage) = 0;
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
    uint16_t distance() override {
        return 0;
    }
    virtual const std::string& image_placement() {
        return image_placement_;
    }


    bool allowed_to_move() override {
        return true;
    };
    bool allowedToMoveAim(size_t x, size_t y) override {
        return false;
    }

    bool get_damage(uint16_t damage) override {
        return false;
    };
    ~NonExistentUnit_() override = default;
};

template<typename Cell>
const std::string NonExistentUnit_<Cell>::image_placement_ = std::string(IMAGE_DIR) + "units/non_existent.png";

template<typename Cell>
class Clubber_ : public Unit_<Cell> {
    const static std::string image_placement_;
    uint16_t hp_ = 35;
    uint16_t damage_ = 15;
    uint16_t distance_ = 1;
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
    uint16_t distance() override {
        return distance_;
    }
    const std::string& image_placement() override {
        return image_placement_;
    }


    bool allowed_to_move() override {
        return true;
    };
    bool allowedToMoveAim(size_t x, size_t y) override {
        return std::abs(static_cast<int>(x)  - static_cast<int>(Unit_<Cell>::place->x)) <= distance_ && std::abs(static_cast<int>(y) - static_cast<int>(Unit_<Cell>::place->y)) <= distance_;
    }

    bool get_damage(uint16_t damage) override {
        if (hp_ < damage) {
            return true;
        } else {
            hp_ -= damage;
            return false;
        }
    }
    ~Clubber_() override = default;
};

template<typename Cell>
const std::string Clubber_<Cell>::image_placement_ = std::string(IMAGE_DIR) + "units/clubber.png";

