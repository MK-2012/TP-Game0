#include "UnitTreasury.h"



UnitTreasury::UnitTreasury() = default;

UnitTreasury::~UnitTreasury() = default;

std::vector<UnitTreasury*> UnitTreasury::unit_treasures = std::vector<UnitTreasury*>(PlayersNum);

void UnitTreasury::set(PlayerEnum player, UnitTreasury* unit_treasury) {
    unit_treasures[playerNum(player)] = unit_treasury;
}

UnitTreasury &UnitTreasury::get(PlayerEnum player) {
    return *(unit_treasures[playerNum(player)]);
}

void UnitTreasury::erase(PlayerEnum player, Unit *unit) {
    UnitTreasury& tr = UnitTreasury::get(player);
    tr.units.erase(unit);
}


