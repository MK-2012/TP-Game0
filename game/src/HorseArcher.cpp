#include "HorseArcher.h"

uint16_t HorseArcher::hp() {
	return hp_;
}

uint16_t HorseArcher::damage(PlayerEnum player) {
	if(player == player_) {
		return 0;
	}
	if (allowed_to_move()) {
        return damage_;
    }
	return 0;
}

uint16_t HorseArcher::distance() {
	return distance_;
}

UnitImages HorseArcher::image() {
	return image_;
}

bool HorseArcher::allowed_to_move() {
	if (num_of_motions < max_motions) {
		++num_of_motions;
		return true;
	} else {
		return false;
	}
}

bool HorseArcher::allowedToMoveAim(int delta_x, int delta_y) {
	return std::abs(delta_x) <= distance_ && std::abs(delta_y) <= distance_;
}

bool HorseArcher::get_damage(uint16_t damage) {
	if (hp_ < damage) {
		return true;
	} else {
		hp_ -= damage;
		return false;
	}
}

HorseArcher::HorseArcher(PlayerEnum player) : Unit(player) {}

int HorseArcher::cost() {
	return cost_;
}
const std::string HorseArcher::name_ = "HorseArcher";

std::string HorseArcher::name() {
	return name_;
}

void HorseArcher::clearMotions() {
	num_of_motions = 0;
}
