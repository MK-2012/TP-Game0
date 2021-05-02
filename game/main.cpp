
#include "Application.cpp"



int main(int argc, char **argv) {
    Field field(standard);
    Player *player = &(Player::get(Player1, field));
    PlayerPainter *paint = &PlayerPainter::get(Player1, field);
    /*demiurgeEmplaceStructure<River>(field[5][5]);
    demiurgeEmplaceStructure<River>(field[4][5]);
    demiurgeEmplaceStructure<River>(field[3][5]);
    demiurgeEmplaceStructure<River>(field[2][5]); */
	//turn_on(argc, argv);
    Application app(player, paint, field);
    app.run(argc, argv);

    return 0;
}