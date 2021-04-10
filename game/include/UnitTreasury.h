#ifndef UNITTREASURY_H
#define UNITTREASURY_H

#include <set>
#include <vector>
#include "PlayerEnum.h"


class Unit;

struct UnitTreasury {
    std::set<Unit*> units;
    UnitTreasury();
    ~UnitTreasury();
    static void set(PlayerEnum player, UnitTreasury* unit_treasury);
    static UnitTreasury& get(PlayerEnum player);
    static void erase(PlayerEnum player, Unit* unit);
private:
    static std::vector<UnitTreasury*> unit_treasures;
};
#endif

#include "Unit.h"
