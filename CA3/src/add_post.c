// To add a post to the end of the user's posts list
#include <stdio.h>
#include "social_network.h"
void add_post(post_info *head_of_posts, post_info *new_post) {
	post_info *previous = head_of_posts;
	post_info *current = head_of_posts->next;
	while (current != NULL) {
		previous = current;
		current = current->next;
	}
	previous->next = new_post;
}