#include "PlayerEnum.h"

int playerNum(PlayerEnum player) {
    switch (player) {
        case Nobody:
            return 0;
        case Player1:
            return 1;
        case Player2:
            return 2;
    }
}

PlayerEnum playerNum(int player) {
    switch (player) {
        case 0:
            return Nobody;
        case 1:
            return Player1;
        case 2:
            return Player2;
    }
}