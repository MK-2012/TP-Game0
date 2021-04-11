#pragma once
#include "Cursor.h"
#include "Treasury.h"
#include <vector>
#include <map>

class Player {
public:
    Player(const Player& other);
    PlayerEnum number;
    Cursor control;
    Aim* aim = nullptr;
    Treasury treasury;

    static Player& get(PlayerEnum player, Field& field);
private:
    Player(Field& field, PlayerEnum number);
    static std::vector<bool> created;
    static std::vector<Player*> players;
};
