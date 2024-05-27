#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "circular.h"
void shuffle_card(int* card) {
    int i, r, temp;
    for (temp = 0, i = 0; temp < 44; i++, temp++)
        card[temp] = i;
    srand(time(NULL));
    for (i = 43; i > 0; i--) {
        r = rand() % i;
        temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
}
int main() {
    int set_score[2] = {0};
    while (1) {
        int index, circular, flag, winner_index = 0, player_flag = 0;
        int card[44], cards[4][11], team_score[2] = {0};
        int arr0[4][11] = {0}, arr1[4][11] = {0}, arr2[4][11] = {0}, arr3[4][11] = {0};
        int player_card[2][4] = {32, 32, 32, 32, 32, 32, 32, 32};
        char input;
        system("cls");
        ground(player_card, team_score, set_score);
        table(-1, arr0);
        flag = first_optional(set_score);
        if (flag == 1) {
            getch();
            system("cls");
            ground(player_card, team_score, set_score);
            table(-1, arr0);
            break; 
        }
        printf("Start of a new set!\n");
        getch();
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 11; j++)
                cards[i][j] = j + 1;
        shuffle_card(card);
        for (int temp = 0; temp < 5; temp++) {
            int i = card[temp] / 11;
            int j = card[temp] % 11;
            arr0[i][j] = cards[i][j];
        }
        while (1) {
            flag = 0;
            system("cls");
            ground(player_card, team_score, set_score);
            table(-1, arr0);
            printf("Enter the circular:\n");
            scanf("%c", &input);
            fflush(stdin);
            circular = (int) input - 65;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 11; j++)
                    if (arr0[i][j] != 0)
                        if (circular == i) {
                            flag = 1;
                            break;
                        }
                if (flag == 1)
                    break;
            }
            if (flag == 1)
                break;
            else {
                printf("error!\nEnter one of the symbols on your five cards!\n");
                getch();
            }
        }
        system("cls");
        ground(player_card, team_score, set_score);
        table(-1, arr0);
        printf("The circular is %c\n", ascii(circular));
        getch();
        give_card(card, cards, arr0, arr1, arr2, arr3, 0, 5);
        give_card(card, cards, arr0, arr1, arr2, arr3, 20, 4);
        give_card(card, cards, arr0, arr1, arr2, arr3, 36, 2);
        while (1) {
            while (1) {
                int counter = -1;
                index = -1;
                system("cls");
                ground(player_card, team_score, set_score);
                table(-1, arr0);
                printf("Which card do you want to play?\n");
                scanf("%d", &index);
                fflush(stdin);
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 11; j++)
                        if (arr0[i][j] != 0)
                            ++counter;
                if (index < 0 || index > counter) {
                    printf("error!\nEnter a number between 0 and %d!\n", counter);
                    getch();
                }
                else
                    break;
            }
            flag = select_P1(index, winner_index, arr0, player_card);
            if (flag == 1) {
                getch();
                continue;
            }
            system("cls");
            ground(player_card, team_score, set_score);
            table(index, arr0);
            printf("You choose %c%d\n", ascii(player_card[0][0]), player_card[1][0]);
            getch();
            system("cls");
            switch (player_flag) {
                case 0 :
                    select_card(1, 0, circular, arr1, player_card);
                    select_card(2, 0, circular, arr2, player_card);
                    select_card(3, 0, circular, arr3, player_card);
                    break;
                case 2 :
                    select_card(1, 2, circular, arr1, player_card);
                    break;
                case 3 :
                    select_card(1, 3, circular, arr1, player_card);
                    select_card(2, 3, circular, arr2, player_card);
            }
            if (player_flag != 1) {
                ground(player_card, team_score, set_score);
                table(-1, arr0);
                printf("It's not your turn!\n");
                getch();
                system("cls");
            }
            winner_index = winner(winner_index, circular, player_card);
            switch (winner_index) {
                case 0 :
                case 2 :
                    ++team_score[0];
                    break; 
                case 1 :
                case 3 :
                    ++team_score[1];
            }
            empty(player_card);
            ground(player_card, team_score, set_score);
            table(-1, arr0);
            switch (winner_index) {
                case 0 :
                case 2 :
                    printf("Team 1 got 1 point!\n");
                    break;
                case 1 :
                case 3 :
                    printf("Team 2 got 1 point!\n");
            }
            getch();
            flag = 0;
            for (int i = 0; i < 2; i++)
                if (team_score[i] == 6) {
                    system("cls");
                    ground(player_card, team_score, set_score);
                    table(-1, arr0);
                    printf("Team %d won this set!\n", i + 1);
                    getch();
                    second_optional(i, set_score, team_score); 
                    flag = 1;
                    break;
                }
            if (flag == 1)
                break;
            switch (winner_index) {
                case 0 :
                    player_flag = 0;
                    break;
                case 1 :
                    start_card(1, circular, arr1, player_card);
                    system("cls");
                    ground(player_card, team_score, set_score);
                    table(-1, arr0);
                    printf("It's not your turn!\n");
                    getch();
                    select_card(2, 1, circular, arr2, player_card);
                    select_card(3, 1, circular, arr3, player_card);
                    player_flag = 1;
                    break;
                case 2 :
                    start_card(2, circular, arr2, player_card);
                    system("cls");
                    ground(player_card, team_score, set_score);
                    table(-1, arr0);
                    printf("It's not your turn!\n");
                    getch();
                    select_card(3, 2, circular, arr3, player_card);
                    player_flag = 2;
                    break;
                case 3 :
                    start_card(3, circular, arr3, player_card);
                    player_flag = 3;
                    break;
            }
        }
    }
    printf("End Game!\n");
    getch();
}