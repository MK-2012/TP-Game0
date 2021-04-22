

#ifndef GAME_FIELD_CPP_STRUCTURETREASURE_H
#define GAME_FIELD_CPP_STRUCTURETREASURE_H

#include <set>
#include <vector>
#include "PlayerEnum.h"
class Structure;

struct StructureTreasury {
    std::set<Structure*> structures;
    StructureTreasury();
    ~StructureTreasury();
    static void set(PlayerEnum player, StructureTreasury* structure_treasury);
    static StructureTreasury& get(PlayerEnum player);
    static void erase(PlayerEnum player, Structure* structure);
private:
    static std::vector<StructureTreasury*> structure_treasures;
};


#endif //GAME_FIELD_CPP_STRUCTURETREASURE_H

#include "Structure.h"