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
protected:
    explicit Structure_(Cell* place) : place(place) {}
};

template<typename Cell>
class NonExistentStructure_ : public Structure_<Cell> {
    const static std::string image_placement_;
public:
    explicit NonExistentStructure_(Cell* place) : Structure_<Cell>(place) {}
    virtual const std::string& image_placement() {
        return image_placement_;
    }
    ~NonExistentStructure_() override = default;
};

template<typename Cell>
const std::string NonExistentStructure_<Cell>::image_placement_ = "images/structures/non_existent.png";



