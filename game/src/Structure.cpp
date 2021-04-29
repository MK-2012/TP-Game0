#include "Structure.h"

Structure::Structure(PlayerEnum player, int hp): player_(player), hp_(hp){}
int Structure::hp() {
    return hp_;
}

std::string Structure::name() {
    return "Structure";
}

int Structure::income() {
    return 0;
}


Landscape::Landscape(PlayerEnum player, int hp): Structure(player, hp){}

std::string Landscape::name() {
    return "Landscape";
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

std::string Grass::name() {
    return "Grass";
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

std::string River::name() {
    return "River";
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

std::string Mountains::name() {
	return "Mountains";
}



MemeFabric::MemeFabric(PlayerEnum player, int hp): Grass(player, hp) {}
const StructureImages MemeFabric::image_placement_ = MemeFabricImage;

StructureImages MemeFabric::image() {
    return image_placement_;
}

bool MemeFabric::isAllowedToGoIn() {
    return true;
}

std::string MemeFabric::name() {
    return "MemeFabric";
}

int MemeFabric::income() {
    return 5;
}

MemeFabric::~MemeFabric() = default;
