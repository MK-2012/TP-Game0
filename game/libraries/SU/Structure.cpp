#pragma once
#include <string>

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






template<typename Cell>
Structure_<Cell>::Structure_(Cell *place) : place(place) {}




template<typename Cell>
Landscape_<Cell>::Landscape_(Cell *place) : Structure_<Cell>(place) {}




template<typename Cell>
const std::string Grass_<Cell>::image_placement_ = "images/structures/Grass1.png";

template<typename Cell>
Grass_<Cell>::Grass_(Cell *place) : Landscape_<Cell>(place) {}

template<typename Cell>
const std::string &Grass_<Cell>::image_placement() {
    return image_placement_;
}

template<typename Cell>
bool Grass_<Cell>::isAllowedToGoIn() {
    return true;
}



template<typename Cell>
const std::string River_<Cell>::image_placement_ = "images/structures/River5.png";

template<typename Cell>
River_<Cell>::River_(Cell *place) : Landscape_<Cell>(place) {}

template<typename Cell>
const std::string &River_<Cell>::image_placement() {
    return image_placement_;
}

template<typename Cell>
bool River_<Cell>::isAllowedToGoIn() {
    return false;
}


