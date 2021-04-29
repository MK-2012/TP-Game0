#include "Archer.h"

uint16_t Archer::hp() {
	return hp_;
}

uint16_t Archer::damage(PlayerEnum player) {
	if(player == player_) {
		return 0;
	}
	return damage_;
}

uint16_t Archer::distance() {
	return distance_;
}

UnitImages Archer::image() {
	return image_;
}

bool Archer::allowed_to_move() {
	if (num_of_motions < max_motions) {
		++num_of_motions;
		return true;
	} else {
		return false;
	}
}

bool Archer::allowedToMoveAim(int delta_x, int delta_y) {
	return std::abs(delta_x) <= distance_ && std::abs(delta_y) <= distance_;
}

bool Archer::get_damage(uint16_t damage) {
	if (hp_ < damage) {
		return true;
	} else {
		hp_ -= damage;
		return false;
	}
}

Archer::Archer(PlayerEnum player) : Unit(player) {}

int Archer::cost() {
	return cost_;
}
const std::string Archer::name_ = "Archer";

std::string Archer::name() {
	return name_;
}

void Archer::clearMotions() {
	num_of_motions = 0;
}
