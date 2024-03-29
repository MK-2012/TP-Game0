#include "Player.h"

Player::Player(Field &field, PlayerEnum number): control(field, number), number(number), treasury(number) {}

Player &Player::get(PlayerEnum player, Field &field) {
    if (created[playerNum(player)]) {
        return *(players[playerNum(player)]);
    } else {
        created[playerNum(player)] = true;
        players[playerNum(player)] = new Player(field, player);
        return *(players[playerNum(player)]);
    }
}

Player::Player(const Player &other) = default;

std::vector<bool> Player::created = std::vector<bool>(PlayersNum, false);
std::vector<Player*> Player::players = std::vector<Player*>(PlayersNum);



