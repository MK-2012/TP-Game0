#include "Treasury.h"

void Treasury::checkArmy() {
    int army = 0;
    for (auto unit_ptr: units.units) {
        army += unit_ptr -> cost();
    }
    required_memes_ = army;
}

void Treasury::insertUnit(Unit *unit) {
    units.units.insert(unit);
}

bool Treasury::enoughMemes(int cost) const {
    return memes_limit_ >= required_memes_ + cost;
}

int Treasury::requiredMemes() const {
    return required_memes_;
}

int Treasury::memesLimit() const {
    return memes_limit_;
}

Treasury::Treasury(PlayerEnum player) {
    UnitTreasury::set(player, &units);
}

void Treasury::insertStructure(Structure *structure) {
    structures.structures.insert(structure);
}

void Treasury::calcIncome() {
    for (auto i: structures.structures) {
        gold += i -> income();
    }
}


