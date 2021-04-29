#pragma once


#include "StructureImages.h"
#include "PlayerEnum.h"
#include <string>



class Structure {
    int hp_;
public:
    PlayerEnum player_;
    virtual int hp();
    //virtual bool getDamage();
    virtual StructureImages image() = 0;
    virtual ~Structure() = default;
    virtual bool isAllowedToGoIn() = 0;
    static const std::string name;
    virtual const std::string& get_name();
    virtual int income();
    static const bool constructable = false;
protected:
    Structure(PlayerEnum, int);
};


class Landscape: public Structure {
public:
    Landscape(PlayerEnum, int hp = 0);
    StructureImages image() override = 0;
    bool isAllowedToGoIn() override = 0;
    static const std::string name;
    static const bool constructable = false;
    const std::string& get_name() override;
    ~Landscape() override;
};



class Grass : public Landscape {
    const static StructureImages image_placement_;
public:
    Grass(PlayerEnum, int hp = 0);
    StructureImages image() override;
    bool isAllowedToGoIn() override;
    static const std::string name;
    const std::string& get_name() override;
    static const bool constructable = false;
    ~Grass() override;
};





class River : public Landscape {
    const static StructureImages image_placement_;
public:
    River(PlayerEnum, int hp = 0);
    StructureImages image() override;
    bool isAllowedToGoIn() override;
    static const std::string name;
    const std::string& get_name() override;
    static const bool constructable = false;
    ~River() override;
};


class Mountains : public Landscape {
	const static StructureImages image_placement_;
public:
	Mountains(PlayerEnum, int hp = 0);
	StructureImages image() override;
	bool isAllowedToGoIn() override;
    static const std::string name;
    const std::string& get_name() override;
    static const bool constructable = false;
	~Mountains() override;
};



class MemeFabric : public Grass {
    const static StructureImages image_placement_;
public:
    MemeFabric(PlayerEnum, int hp = 15);
    StructureImages image() override;
    bool isAllowedToGoIn() override;
    static const std::string name;
    const std::string& get_name() override;
    int income() override;
    static const bool constructable = true;
    ~MemeFabric() override;
};