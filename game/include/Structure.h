//
// Created by val-de-mar on 08.03.2021.
//

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



