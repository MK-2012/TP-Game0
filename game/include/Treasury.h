#pragma once

#include "Unit.h"
#include "Structure.h"
#include "UnitTreasury.h"

class Treasury {
    UnitTreasury units;
    int gold = 0;
    int required_memes_ = 0;
    int memes_limit_ = 4;
public:
    bool enoughMemes(int cost) const;
    int requiredMemes() const;
    int memesLimit() const;
    void checkArmy();
    void insertUnit(Unit* unit);
};

