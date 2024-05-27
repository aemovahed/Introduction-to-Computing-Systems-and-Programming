#include "circular.h"
// to execute some commands of the "start_card" function by giving the loop interval
int complement_start_card (int start_loop, int end_loop, int winner_index, int circular, int (*arr)[11], int (*player_card)[4]) {
    int i, flag = 0;
    while (1) {
        for (i = 0; i < 4; i++)
            if (i != circular)
                if (arr[i][start_loop] != 0) {
                    player_card[0][winner_index] = i;
                    player_card[1][winner_index] = arr[i][start_loop];
                    arr[i][start_loop] = 0;
                    flag = 1;
                    break;
                }
        if (flag == 1)
            break;
        start_loop > end_loop ? --start_loop : ++start_loop;
        if (start_loop == end_loop)
            break;
    }
    return flag;
}