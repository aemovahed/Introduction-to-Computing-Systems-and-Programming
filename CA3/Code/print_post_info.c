// Printing post information
#include <stdio.h>
#include "social_network.h"
void print_post_info(user_info *curr_user) {
	post_info *curr_post = curr_user->head_of_posts->next;
	while (curr_post != NULL) {
		printf("Post ID : %d\n", curr_post->post_ID);
		printf("The text of the post : %s\n", curr_post->post_text);
		printf("Number of likes : %d\n", curr_post->number_of_likes);
		printf("------------------------------------------\n");
		curr_post = curr_post->next;
	}
}