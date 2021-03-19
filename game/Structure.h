//
// Created by val-de-mar on 08.03.2021.
//

#include "player.h"

#ifndef GAME_STRUCTURE_H
#define GAME_STRUCTURE_H

#endif //GAME_STRUCTURE_H


template<typename Cell>
class Structure_ {
public:
    Cell* place;
    virtual const std::string& image_placement() = 0;
    virtual ~Structure_() = default;
    virtual bool isAllowedToGoIn() = 0;
protected:
    explicit Structure_(Cell* place) : place(place) {}
};

template<typename Cell>
class Landscape_ : public Structure_<Cell> {
public:
    explicit Landscape_(Cell* place) : Structure_<Cell>(place) {}
    const std::string& image_placement() override = 0;
    bool isAllowedToGoIn() override = 0;
    ~Landscape_() override = default;
};


template<typename Cell>
class Grass_ : public Landscape_<Cell> {
    const static std::string image_placement_;
public:
    explicit Grass_(Cell* place) : Landscape_<Cell>(place) {}
    const std::string& image_placement() override {
        return image_placement_;
    }
    bool isAllowedToGoIn() override {
        return true;
    }
    ~Grass_() override = default;
};

template<typename Cell>
const std::string Grass_<Cell>::image_placement_ = "images/structures/Grass1.png";


template<typename Cell>
class River_ : public Landscape_<Cell> {
    const static std::string image_placement_;
public:
    explicit River_(Cell* place) : Landscape_<Cell>(place) {}
    const std::string& image_placement() override {
        return image_placement_;
    }
    bool isAllowedToGoIn() override {
        return false;
    }
    ~River_() override = default;
};

template<typename Cell>
const std::string River_<Cell>::image_placement_ = "images/structures/River5.png";

