int first_optional (int *set_score);
void second_optional (int i, int *set_score, int *team_score);
int third_optional (int winner_index, int player_index, int circular, int (*player_card)[4], int (*arr)[11]);
int fourth_optional(int (*arr)[11]);
char ascii (int number);
void empty (int (*player_card)[4]);
int winner(int winner_index, int circular, int (*player_card)[4]);
int select_card (int player_index, int winner_index, int circular, int (*arr)[11], int (*player_card)[4]);
void table (int index, int (*arr)[11]);
void ground(int (*player_card)[4], int *team_score, int *set_score);
int select_P1 (int index, int winner_index, int (*arr)[11], int (*player_card)[4]);
void give_card(int *card, int (*cards)[11], int (*arr0)[11], int (*arr1)[11], int (*arr2)[11], int (*arr3)[11], int index, int scale);
void start_card(int winner_index, char circular, int (*arr)[11], int (*player_card)[4]);
int complement_start_card (int first_value, int second_value, int winner_index, int circular, int (*arr)[11], int (*player_card)[4]);