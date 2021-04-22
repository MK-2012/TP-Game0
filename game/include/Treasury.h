#pragma once

#include "Unit.h"
#include "Structure.h"
#include "UnitTreasury.h"
#include "StructureTreasury.h"

class Treasury {
    int gold = 0;
    int required_memes_ = 0;
    int memes_limit_ = 4;
public:
    UnitTreasury units;
    StructureTreasury structures;
    explicit Treasury(PlayerEnum player);
    bool enoughMemes(int cost) const;
    int requiredMemes() const;
    int memesLimit() const;
    void checkArmy();
    void calcIncome();
    void insertUnit(Unit* unit);
    void insertStructure(Structure* structure);
    void refreshUnits();
    ~Treasury() = default;
};

