#include "Cavalery.h"

const uint16_t damage_multiplier = 2;

uint16_t Cavalery::hp() {
	return hp_;
}

uint16_t Cavalery::damage(PlayerEnum player) {
	if(player == player_) {
		return 0;
	}
	if (!has_attacked) {
		has_attacked = true;
		return damage_ + num_of_motions * damage_multiplier;
	} else {
		return damage_;
	}
}

uint16_t Cavalery::distance() {
	return distance_;
}

UnitImages Cavalery::image() {
	return image_;
}

bool Cavalery::allowed_to_move() {
	if (num_of_motions < max_motions) {
		++num_of_motions;
		return true;
	} else {
		return false;
	}
}

bool Cavalery::allowedToMoveAim(int delta_x, int delta_y) {
	return std::abs(delta_x) <= distance_ && std::abs(delta_y) <= distance_;
}

bool Cavalery::get_damage(uint16_t damage) {
	if (hp_ < damage) {
		return true;
	} else {
		hp_ -= damage;
		return false;
	}
}

Cavalery::Cavalery(PlayerEnum player) : Unit(player) {}

int Cavalery::cost() {
	return cost_;
}
const std::string Cavalery::name_ = "Cavalery";

std::string Cavalery::name() {
	return name_;
}

void Cavalery::clearMotions() {
	num_of_motions = 0;
	has_attacked = false;
}
