#include "Structure.h"

Structure::Structure(PlayerEnum player, int hp): player_(player), hp_(hp){}
int Structure::hp() {
    return hp_;
}

const std::string Structure::name = "Structure";


int Structure::income() {
    return 0;
}

const std::string &Structure::get_name() {
    return name;
}

const bool Structure::isCity() {
	return false;
}


Landscape::Landscape(PlayerEnum player, int hp): Structure(player, hp){}

const std::string Landscape::name = "Landscape";

const std::string &Landscape::get_name() {
    return name;
}


Landscape::~Landscape() = default;

Grass::Grass(PlayerEnum player, int hp): Landscape(player, hp) {}
const StructureImages Grass::image_placement_ = GrassImage;

StructureImages Grass::image() {
    return image_placement_;
}

bool Grass::isAllowedToGoIn() {
    return true;
}

const std::string Grass::name = "Grass";

const std::string &Grass::get_name() {
    return name;
}


Grass::~Grass() = default;

const StructureImages River::image_placement_ = RiverImage;

StructureImages River::image() {
    return image_placement_;
}

bool River::isAllowedToGoIn() {
    return false;
}

River::~River() = default;

River::River(PlayerEnum player, int hp): Landscape(player, hp){}

const std::string River::name = "River";

const std::string &River::get_name() {
    return name;
}


const StructureImages Mountains::image_placement_ = MountainImage;

StructureImages Mountains::image() {
	return image_placement_;
}

bool Mountains::isAllowedToGoIn() {
	return false;
}

Mountains::~Mountains() = default;

Mountains::Mountains(PlayerEnum player, int hp): Landscape(player, hp){}

const std::string Mountains::name = "Mountains";

const std::string &Mountains::get_name() {
    return name;
}


MemeFabric::MemeFabric(PlayerEnum player, int hp): Grass(player, hp) {}
const StructureImages MemeFabric::image_placement_ = MemeFabricImage;

StructureImages MemeFabric::image() {
    return image_placement_;
}

bool MemeFabric::isAllowedToGoIn() {
    return true;
}

const std::string MemeFabric::name = "MemeFabric";


int MemeFabric::income() {
    return 5;
}

const std::string &MemeFabric::get_name() {
    return name;
}


MemeFabric::~MemeFabric() = default;


const StructureImages City::image_placement_ = CityImage;

StructureImages City::image() {
	return image_placement_;
}

bool City::isAllowedToGoIn() {
	return true;
}

City::~City() = default;

City::City(PlayerEnum player, int hp): Landscape(player, hp){}

const std::string City::name = "City";

const std::string& City::get_name() {
	return name;
}

const bool City::isCity() {
	return true;
}
