#include <stdio.h>
#include "circular.h"
// Playground
void ground(int (*player_card)[4], int *team_score, int *set_score) {
    printf("\t\t\t\t  P3\t\t\t\t\tPOINTS  SETS\n");
    printf("\t----------------------------------------------------    Team 1:   %d      %d\n", team_score[0], set_score[0]);
    for (int temp = 1; temp < 18; ++temp) {
        switch (temp) {
            case 1 :
                printf("\t|\t\t\t  ");
                if (player_card[1][2] == 32)
                    printf("%c%c", player_card[0][2], player_card[1][2]);
                else
                    printf("%c%d", ascii(player_card[0][2]), player_card[1][2]);
                printf("\t\t\t    |\n");
                break;
            case 9 :
                printf("      P2|");
                if (player_card[1][1] == 32)
                    printf("%c%c", player_card[0][1], player_card[1][1]);
                else
                    printf("%c%d", ascii(player_card[0][1]), player_card[1][1]);
                if (player_card[1][3] > 9 && player_card[1][3] != 32)
                        printf("\t\t\t\t\t\t %c%d", ascii(player_card[0][3]), player_card[1][3]);
                else {
                    if (player_card[0][3] == 32)
                        printf("\t\t\t\t\t\t  %c%c", player_card[0][3], player_card[1][3]);
                    else
                        printf("\t\t\t\t\t\t  %c%d", ascii(player_card[0][3]), player_card[1][3]);
                }
                printf("|P4\n");
                break;
            case 17 :
                printf("\t|\t\t\t  ");
                if (player_card[1][0] == 32)
                    printf("%c%c", player_card[0][0], player_card[1][0]);
                else
                    printf("%c%d", ascii(player_card[0][0]), player_card[1][0]);
                printf("\t\t\t    |\n");
                break;
            default :
                printf("\t|\t\t\t\t\t\t    |    \n");
        }   
    }
    printf("\t----------------------------------------------------    Team 2:   %d      %d\n", team_score[1], set_score[1]);
    printf("\t\t\t\t  P1\n");
}