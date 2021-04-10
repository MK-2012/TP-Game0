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
