#include "StructureTreasury.h"

StructureTreasury::StructureTreasury() = default;

StructureTreasury::~StructureTreasury() = default;

std::vector<StructureTreasury*> StructureTreasury::structure_treasures = std::vector<StructureTreasury*>(PlayersNum);

void StructureTreasury::set(PlayerEnum player, StructureTreasury *structure_treasury) {
    structure_treasures[playerNum(player)] = structure_treasury;
}

StructureTreasury &StructureTreasury::get(PlayerEnum player) {
    return *(structure_treasures[playerNum(player)]);
}

void StructureTreasury::erase(PlayerEnum player, Structure *structure) {
    StructureTreasury& tr = StructureTreasury::get(player);
    tr.structures.erase(structure);
}
