#include "circular.h"
void start_card(int winner_index, char circular, int (*arr)[11], int (*player_card)[4]) {
    int i, j, flag = 0, temp = 0;
    temp = fourth_optional(arr);
    if (temp == 0)
        flag = complement_start_card(0, 11, winner_index, circular, arr, player_card);
    if (flag == 0 && temp == 1)
        flag = complement_start_card(10, -1, winner_index, circular, arr, player_card);
    if (flag == 0) {
        i = circular;
        for (j = 10; j >= 0; j--)
            if (arr[i][j] != 0) {
                player_card[0][winner_index] = i;
                player_card[1][winner_index] = arr[i][j];
                arr[i][j] = 0;
                break;
            }
    }
}