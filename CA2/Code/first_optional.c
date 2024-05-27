#include <stdio.h>
#include "circular.h"
// this function is used in the "main" function
int first_optional (int *set_score) {
    int flag = 0;
        for (int i = 0; i < 2; i++)
            if (set_score[i] == 5) {
                printf("Team %d won this game\n", i + 1);
                flag = 1;
            }
        return flag;
}