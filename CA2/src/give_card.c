#include "circular.h"
// to give cards to players
void give_card(int *card, int (*cards)[11], int (*arr0)[11], int (*arr1)[11], int (*arr2)[11], int (*arr3)[11], int index, int scale) {
    int first_temp, counter = 0;
    if (scale == 5)
        first_temp = 1;
    else
        first_temp = 0;
    for (first_temp; first_temp < 4; first_temp++)
        for (int second_temp = index; second_temp < index + scale; second_temp++) {
            int i = card[scale * first_temp + second_temp] / 11;
            int j = card[scale * first_temp + second_temp] % 11;
            ++counter;
            if (scale == 5) {
                if (counter <= scale)
                    arr1[i][j] = cards[i][j];
                else if (counter <= 2 * scale)
                    arr2[i][j] = cards[i][j];
                else
                    arr3[i][j] = cards[i][j];
            }
            else {
                if (counter <= scale)
                    arr0[i][j] = cards[i][j];
                else if (counter <= 2 * scale)
                    arr1[i][j] = cards[i][j];
                else if (counter <= 3 * scale)
                    arr2[i][j] = cards[i][j];
                else
                    arr3[i][j] = cards[i][j];
            }
        }
}