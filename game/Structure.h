#pragma once


#include "StructureImages.h"




class Structure {
public:
    virtual StructureImages image() = 0;
    virtual ~Structure() = default;
    virtual bool isAllowedToGoIn() = 0;
protected:
    explicit Structure();
};


class Landscape: public Structure {
public:
    explicit Landscape();

    StructureImages image() override = 0;
    bool isAllowedToGoIn() override = 0;
    ~Landscape() override;
};



class Grass : public Landscape {
    const static StructureImages image_placement_ = GrassImage;
public:
    explicit Grass() : Landscape() {}
    StructureImages image() override {
        return image_placement_;
    }
    bool isAllowedToGoIn() override {
        return true;
    }
    ~Grass() override = default;
};





class River : public Landscape {
    const static StructureImages image_placement_ = RiverImage;
public:
    explicit River() : Landscape() {}
    StructureImages image() override {
        return image_placement_;
    }
    bool isAllowedToGoIn() override {
        return false;
    }
    ~River() override = default;
};

