#include "circular.h"
// to empty the "player_card" array
void empty (int (*player_card)[4]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
                player_card[i][j] = 32;
}