#pragma once

#include "UnitImages.h"
#include <iostream>
#include "PlayerEnum.h"
#include "BasicUnits.h"


class Archer: public Unit {
	const static UnitImages image_ = ArcherImage;
	uint16_t hp_ = 25;
	uint16_t damage_ = 20;
	uint16_t distance_ = 4;
	int num_of_motions = 0;
	int max_motions = 4;
public:
	const static std::string name_;
	const static uint16_t cost_ = 1;
	Archer(PlayerEnum player);

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
	~Archer() override = default;
};
