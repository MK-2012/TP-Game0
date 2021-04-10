#pragma once


#include "StructureImages.h"
#include "PlayerEnum.h"
#include <string>



class Structure {
public:
    PlayerEnum player_;

    virtual StructureImages image() = 0;
    virtual ~Structure() = default;
    virtual bool isAllowedToGoIn() = 0;
    virtual std::string name();
    virtual int income();
protected:
    Structure(PlayerEnum);
};


class Landscape: public Structure {
public:
    Landscape(PlayerEnum);

    StructureImages image() override = 0;
    bool isAllowedToGoIn() override = 0;
    std::string name() override;
    ~Landscape() override;
};



class Grass : public Landscape {
    const static StructureImages image_placement_;
public:
    Grass(PlayerEnum);
    StructureImages image() override;
    bool isAllowedToGoIn() override;
    std::string name() override;
    ~Grass() override;
};





class River : public Landscape {
    const static StructureImages image_placement_;
public:
    River(PlayerEnum);
    StructureImages image() override;
    bool isAllowedToGoIn() override;
    std::string name() override;
    ~River() override;
};

class MemeFabric : public Grass {
    const static StructureImages image_placement_;
public:
    MemeFabric(PlayerEnum);
    StructureImages image() override;
    bool isAllowedToGoIn() override;
    std::string name() override;
    int income() override;
    ~MemeFabric() override;
};