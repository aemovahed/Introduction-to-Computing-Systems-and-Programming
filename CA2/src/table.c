#include <stdio.h>
#include "circular.h"
void table (int index, int (*arr)[11]) {
    int array[11] = {0};   // The reason for writing this array is the correct placement of the numbers below the table
    printf("\t  -----------------------------------------------\n");
    printf("   symbol |");
    int counter = -1;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 11; j++)
            if (arr[i][j] != 0) {
                ++counter;
                if (counter == index) {
                    printf(" - |");
                    ++counter;
                }
                array[counter] = arr[i][j];
                if (arr[i][j] > 9)
                    printf(" %c  |", ascii(i));
                else
                    printf(" %c |", ascii(i));
            }
    if (counter < 10)
        while (counter < 10) {
            printf(" - |");
            ++counter;
        }
    printf("\n");
    printf("\t  -----------------------------------------------\n");
    printf("   number |");
    counter = -1;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 11; j++)
            if (arr[i][j] != 0) {
                ++counter;
                if (counter == index) {
                    printf(" 0 |");
                    ++counter;
                }
                printf(" %d |", arr[i][j]);
            }
    if (counter < 10)
        while (counter < 10) {
            printf(" 0 |");
            ++counter;
        }
    printf("\n");
    printf("\t  -----------------------------------------------\n");
    printf("\t    ");
    for (int i = 0; i < 11; i++) {
        if (array[i] > 9)
            printf("%d    ", i);
        else
            printf("%d   ", i);
    }
    printf("\n");
}