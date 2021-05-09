#include <random>
#include <vector>
#include <stdexcept>

using vvi = std::vector<std::vector<int>>;


class Rivers {
private:
	std::default_random_engine r_engine;
	std::uniform_int_distribution<size_t> uniform_dist;

	std::vector<std::pair<size_t , size_t>> resulting_river_cells;
	vvi map;
	unsigned int x_size;
	unsigned int y_size;

	void initialize_random();

	std::vector<std::pair<size_t , size_t>> come_to(size_t x, size_t y);

	void generate_main_river();
	void generate_offstream();
public:
	Rivers() = delete;
	Rivers(vvi& map_to_generate);
	~Rivers() = default;

	std::vector<std::pair<size_t , size_t>> generate_rivers(size_t count = 1);
};
