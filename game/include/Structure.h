#pragma once


#include "StructureImages.h"
#include "PlayerEnum.h"
#include <string>



class Structure {
    int hp_;
public:
    PlayerEnum player_;
    virtual int hp();
    virtual bool getDamage(int damage);
    virtual StructureImages image() = 0;
    virtual ~Structure() = default;
    virtual bool isAllowedToGoIn() = 0;
    static const std::string name;
    virtual const std::string& get_name();
    virtual bool get_damage(int);
    virtual int income();
    static const bool constructable = false;

    virtual bool isConstructable();
    virtual const bool isCity();
    static std::string parent;

    virtual Structure * newParent();
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
    bool isConstructable() override;
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
    bool isConstructable() override;
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
    bool isConstructable() override;
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
    bool isConstructable() override;
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
    static std::string parent;
    bool isConstructable() override;
    ~MemeFabric() override;
    Structure * newParent() override;
};

class City: public Landscape {
	const static StructureImages image_placement_;
public:
	City(PlayerEnum, int hp = 0);
	StructureImages image() override;
	bool isAllowedToGoIn() override;
	static const std::string name;
	const std::string& get_name() override;

	static const bool constructable = false;

    bool isConstructable() override;
	const bool isCity() override;
	~City() override;
	Structure* newParent() override;
};

class Bridge : public River {
    const static StructureImages image_placement_;
public:
    Bridge(PlayerEnum, int hp = 15);
    StructureImages image() override;
    bool isAllowedToGoIn() override;
    static const std::string name;
    const std::string& get_name() override;
    int income() override;
    static const bool constructable = true;
    static std::string parent;
    bool isConstructable() override;
    ~Bridge() override;
    Structure * newParent() override;
};
