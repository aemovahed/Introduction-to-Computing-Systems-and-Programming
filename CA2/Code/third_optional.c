#include "circular.h"
// this function is used in "select_card" function
int third_optional (int winner_index, int player_index, int circular, int (*player_card)[4], int (*arr)[11]) {
    int i, j, temp = 0;
    i = player_card[0][winner_index];
    for (j = 0; j < 11; j++)
        if (arr[i][j] != 0) {
            player_card[0][player_index] = i;
            player_card[1][player_index] = arr[i][j];
            arr[i][j] = 0;
            temp = 1;
            break;
        }
    if (temp == 0)
        for (j = 0; j < 11; j++) {
            for (i = 0; i < 4; i++)
                if (i != circular)
                    if (arr[i][j] != 0) {
                        player_card[0][player_index] = i;
                        player_card[1][player_index] = arr[i][j];
                        arr[i][j] = 0;
                        temp = 1;
                        break;
                    }
            if (temp == 1)
                break;
        }
    if (temp == 0) {
        i = circular;
        for (j = 0; j < 11; j++)
            if (arr[i][j] != 0) {
                player_card[0][player_index] = i;
                player_card[1][player_index] = arr[i][j];
                arr[i][j] = 0;
                temp = 1;
                break;
            }
    }
    return temp;
}