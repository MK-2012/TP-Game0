#pragma once

#include "UnitImages.h"
#include <iostream>
#include "PlayerEnum.h"


class Cavalery: public Unit {
	const static UnitImages image_ = CavaleryImage;
	uint16_t hp_ = 30;
	uint16_t damage_ = 20;
	uint16_t distance_ = 1;
	int num_of_motions = 0;
	int max_motions = 8;
	bool has_attacked = false;
public:
	const static std::string name_;
	const static uint16_t cost_ = 2;
	Cavalery(PlayerEnum player);

	uint16_t hp() override;
	uint16_t damage(PlayerEnum player) override;
	uint16_t distance() override;
	std::string name() override;
	void clearMotions() override;
	int cost() override;
	UnitImages image() override;


	bool allowed_to_move() override;
	bool allowedToMoveAim(int delta_x, int delta_y) override;

	bool get_damage(uint16_t damage) override;
	~Cavalery() override = default;
};
