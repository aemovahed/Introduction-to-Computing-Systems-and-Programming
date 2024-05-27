#include <stdio.h>
#include "circular.h"
int select_card (int player_index, int winner_index, int circular, int (*arr)[11], int (*player_card)[4]) {
    int i, j, result, flag = 0, temp = 0;
    result = winner(winner_index, circular, player_card);
    if (player_index == 1 && result == 3)
        temp = 1;
    if (player_index == 2 && result == 0)
        temp = 1;
    if (player_index == 3 && result == 1)
        temp = 1;
    if (temp == 1)
        temp = third_optional(winner_index, player_index, circular, player_card, arr);
    if (temp == 0) {
        i = player_card[0][winner_index];
        for (j = 10; j >= 0; j--) {
            if (arr[i][j] != 0) {
                player_card[0][player_index] = i;
                player_card[1][player_index] = arr[i][j];
                arr[i][j] = 0;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            i = circular;
            for (j = 10; j >= 0; j--)
                if (arr[i][j] != 0) {
                    player_card[0][player_index] = i;
                    player_card[1][player_index] = arr[i][j];
                    arr[i][j] = 0;
                    flag = 1;
                    break;
                }
            if (flag == 0)
                for (j = 0; j < 11; j++) {
                    for (i = 0; i < 4; i++)
                        if (arr[i][j] != 0) {
                            player_card[0][player_index] = i;
                            player_card[1][player_index] = arr[i][j];
                            arr[i][j] = 0;
                            flag = 1;
                            break;
                        }
                    if (flag == 1)
                        break;
                }  
        }
    }
    return 0;
}