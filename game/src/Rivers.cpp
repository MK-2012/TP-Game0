#include "Rivers.h"

void Rivers::initialize_random() {
	std::random_device r;
	r_engine = std::default_random_engine(r());
	uniform_dist = std::uniform_int_distribution<size_t>(0, 100000);
}

std::vector<std::pair<size_t, size_t>> Rivers::come_to(size_t x, size_t y) {

}

Rivers::Rivers(vvi& map_to_generate): map(map_to_generate) {
	initialize_random();
	if (map.empty()) {
		throw std::invalid_argument("The map does not exist");
	}
	x_size = map.size();
	if (map[0].empty()) {
		throw std::invalid_argument("The map does not exist");
	}
	y_size = map[0].size();
}

std::vector<std::pair<size_t , size_t>> Rivers::generate_rivers(size_t count) {
	for (int i = 0; i < count; ++i) {
		generate_main_river();

	}
}

void Rivers::generate_main_river() {
	unsigned x_border_width = std::min(x_size / 3, 10u);

	size_t river_start = x_border_width + uniform_dist(r_engine) % (x_size - 2 * x_border_width);

	size_t river_end = x_border_width + uniform_dist(r_engine) % (x_size - 2 * x_border_width);

	std::vector<std::pair<size_t , size_t>> path = come_to(y_size, river_end);
}

void Rivers::generate_offstream() {

}


