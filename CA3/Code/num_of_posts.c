// Counting the number of user posts
#include <stdio.h>
#include "social_network.h"
int num_of_posts(post_info* head_of_posts) {
	int num = ZERO;
	post_info* current = head_of_posts;
	while (current->next != NULL) {
		++num;
		current = current->next;
	}
	return num;
}