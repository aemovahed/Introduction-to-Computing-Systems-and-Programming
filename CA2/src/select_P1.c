#include <stdio.h>
#include "circular.h"
int select_P1 (int index, int winner_index, int (*arr)[11], int (*player_card)[4]) {
    int i, j, flag = 0, counter = -1;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 11; j++)
            if (arr[i][j] != 0) {
                ++counter;
                if (counter == index) {
                    player_card[0][0] = i;
                    player_card[1][0] = arr[i][j];
                    flag = 1;
                    break;
                } 
            }
        if (flag == 1)
            break;
    }
    flag = 0;
    i = player_card[0][winner_index];
    for (j = 0; j < 11; j++)
        if (arr[i][j] != 0)
            if (i != player_card[0][0]) {
                printf("error!\nYou still have a card with %c symbol!\n", ascii(i));
                player_card[0][0] = 32;
                player_card[1][0] = 32;
                flag = 1;
                break;
            }
    if (flag == 0) {
        i = player_card[0][0];
        j = player_card[1][0] - 1;
        arr[i][j] = 0;
    }
    return flag;
}