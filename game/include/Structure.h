#pragma once


#include "StructureImages.h"




class Structure {
public:
    virtual StructureImages image() = 0;
    virtual ~Structure() = default;
    virtual bool isAllowedToGoIn() = 0;
protected:
    Structure();
};


class Landscape: public Structure {
public:
    Landscape();

    StructureImages image() override = 0;
    bool isAllowedToGoIn() override = 0;
    ~Landscape() override;
};



class Grass : public Landscape {
    const static StructureImages image_placement_;
public:
    Grass();
    StructureImages image() override;
    bool isAllowedToGoIn() override;
    ~Grass() override;
};





class River : public Landscape {
    const static StructureImages image_placement_;
public:
    River();
    StructureImages image() override;
    bool isAllowedToGoIn() override;
    ~River() override;
};

