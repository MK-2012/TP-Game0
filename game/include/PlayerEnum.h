#pragma once

enum PlayerEnum  {
    Player1,
    Player2,
    Nobody
};
const int PlayersNum = 3;
int playerNum(PlayerEnum);
PlayerEnum playerNum(int);