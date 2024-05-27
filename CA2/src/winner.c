#include "circular.h"
int winner(int winner_index, int circular, int (*player_card)[4]) {
    int i, flag = 0;
    int array[2][4] = {-1, -1, -1, -1, -1, -1, -1, -1};
    int temp[2][1];
    for (i = 0; i < 4; i++)
        if (player_card[0][i] == circular) {
            array[0][i] = player_card[0][i];
            array[1][i] = player_card[1][i];
            flag = 1;
        }
    if (flag == 0)
        for (i = 0; i < 4; i++)
            if(player_card[0][i] == player_card[0][winner_index]) {
                array[0][i] = player_card[0][i];
                array[1][i] = player_card[1][i];
            }
    for (i = 0; i < 3; i++)
        if (array[1][i] > array[1][i + 1]) {
            temp[0][0] = array[0][i];
            temp[1][0] = array[1][i];
            array[0][i] = array[0][i + 1];
            array[1][i] = array[1][i + 1];
            array[0][i + 1] = temp[0][0];
            array[1][i + 1] = temp[1][0];
        }
    for (i = 0; i < 4; i++)
        if (array[0][3] == player_card[0][i])
            if (array[1][3] == player_card[1][i])
                return i;
}