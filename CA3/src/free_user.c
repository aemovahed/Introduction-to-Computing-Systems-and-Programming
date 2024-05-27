// To releasa the user
#include <stdlib.h>
#include "social_network.h"
void free_user(user_info *curr_user) {
    post_info* curr_post = curr_user->head_of_posts;
    free(curr_post);
    curr_post = curr_post->next;
    while(curr_post != NULL){
        free_post(curr_post);
        curr_post = curr_post->next;
    }
    free(curr_user->username);
    free(curr_user->password);
    free(curr_user);
}