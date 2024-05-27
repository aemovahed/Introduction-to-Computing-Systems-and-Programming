// To releasa the post
#include <stdlib.h>
#include "social_network.h"
void free_post(post_info *curr_post) {
    liker* curr_liker = curr_post->head_of_likers;
    while(curr_liker != NULL) {
        free(curr_liker);
        curr_liker = curr_liker->next;
    }
    free(curr_post->post_text);
    free(curr_post);
}