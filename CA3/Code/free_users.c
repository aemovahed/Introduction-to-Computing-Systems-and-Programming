// To releasa users
#include <stdlib.h>
#include "social_network.h"
void free_users(user_info *head_of_users) {
    user_info* curr_user = head_of_users;
    free(curr_user);
    curr_user = curr_user->next;
    while(curr_user != NULL) {
        free_user(curr_user);
        curr_user = curr_user->next;
    }
}