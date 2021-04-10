#include "Player.h"

Player::Player(Field &field, PlayerEnum number): control(field, number), number(number) {}

Player &Player::get(PlayerEnum player, Field &field) {
    // std::cout << "\n " << playerNum(player) <<" player " << playerNum(player);
    if (created[playerNum(player)]) {
        // std::cout << " " << (players[playerNum(player)]) << "\n";
        return *(players[playerNum(player)]);
    } else {
        created[playerNum(player)] = true;
        players[playerNum(player)] = new Player(field, player);
        // std::cout << " " << (players[playerNum(player)]) << "\n";
        return *(players[playerNum(player)]);
    }
}

Player::Player(const Player &other) = default;

std::vector<bool> Player::created = std::vector<bool>(PlayersNum, false);
std::vector<Player*> Player::players = std::vector<Player*>(PlayersNum);



