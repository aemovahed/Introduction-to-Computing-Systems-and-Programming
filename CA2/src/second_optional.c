#include "circular.h"
// this function is used in "main" function
void second_optional (int i, int *set_score, int *team_score) {
    // "Reset to zero points in each set" is written at the beginning of the "main" function
    ++set_score[i];
    if (i == 0 && team_score[1] == 0)
        ++set_score[i];
    if (i == 1 && team_score[0] == 0)
        ++set_score[i];
}