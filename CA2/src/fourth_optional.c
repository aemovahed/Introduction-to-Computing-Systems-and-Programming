#include "circular.h"
// this function is used in the "start_card" function
int fourth_optional(int (*arr)[11]) {
    int i, j, temp = 0;
    for (j = 10; j > 8; j--) {
        for (i = 0; i < 4; i++)
            if (arr[i][j] != 0) {
                temp = 1;
                break;
            }
        if (temp == 1)
            break;
    }
    return temp;
}