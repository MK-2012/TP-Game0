#include "Catapult.h"

uint16_t Catapult::hp() {
	return hp_;
}

uint16_t Catapult::damage(PlayerEnum player) {
	if(player == player_) {
		return 0;
	}
	return damage_;
}

uint16_t Catapult::distance() {
	return distance_;
}

UnitImages Catapult::image() {
	return image_;
}

bool Catapult::allowed_to_move() {
	if (num_of_motions < max_motions) {
		++num_of_motions;
		return true;
	} else {
		return false;
	}
}

bool Catapult::allowedToMoveAim(int delta_x, int delta_y) {
	return std::abs(delta_x) <= distance_ && std::abs(delta_y) <= distance_;
}

bool Catapult::get_damage(uint16_t damage) {
	if (hp_ < damage) {
		return true;
	} else {
		hp_ -= damage;
		return false;
	}
}

Catapult::Catapult(PlayerEnum player) : Unit(player) {}

int Catapult::cost() {
	return cost_;
}
const std::string Catapult::name_ = "Catapult";

std::string Catapult::name() {
	return name_;
}

void Catapult::clearMotions() {
	num_of_motions = 0;
}
