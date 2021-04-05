#include "include/graphics.h"

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
    explicit Unit_(Cell* place);
};


template<typename Cell>
class NonExistentUnit_ : public Unit_<Cell> {
public:
    explicit NonExistentUnit_(Cell* place);
    const static std::string image_placement_;

    bool existence () override;

    int unitTypeId() override;
    uint16_t hp() override;
    uint16_t damage() override;;
    uint16_t distance() override;
    virtual const std::string& image_placement();


    bool allowed_to_move() override;;
    bool allowedToMoveAim(size_t x, size_t y) override;

    bool get_damage(uint16_t damage) override;
    ~NonExistentUnit_() override = default;
};


template<typename Cell>
class Clubber_ : public Unit_<Cell> {
    const static std::string image_placement_;
    uint16_t hp_ = 35;
    uint16_t damage_ = 15;
    uint16_t distance_ = 1;
public:
    explicit Clubber_(Cell* place);

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
class Structure_ {
public:
    Cell* place;
    virtual const std::string& image_placement() = 0;
    virtual ~Structure_() = default;
    virtual bool isAllowedToGoIn() = 0;
protected:
    explicit Structure_(Cell* place);
};


template<typename Cell>
class Landscape_ : public Structure_<Cell> {
public:
    explicit Landscape_(Cell* place);
    const std::string& image_placement() override = 0;
    bool isAllowedToGoIn() override = 0;
    ~Landscape_() override = default;
};


template<typename Cell>
class Grass_ : public Landscape_<Cell> {
    const static std::string image_placement_;
public:
    explicit Grass_(Cell* place);
    const std::string& image_placement() override;
    bool isAllowedToGoIn() override;
    ~Grass_() override = default;
};





template<typename Cell>
class River_ : public Landscape_<Cell> {
    const static std::string image_placement_;
public:
    explicit River_(Cell* place);
    const std::string& image_placement() override;
    bool isAllowedToGoIn() override;
    ~River_() override = default;
};



