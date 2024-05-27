// To allocate memory for a new post
#include <stdlib.h>
#include "social_network.h"
post_info* NewPost(void) {
	post_info* new_post = (post_info *)malloc(sizeof(post_info));
	if (new_post == NULL) {
		error_malloc("new post");
		return NULL;
	}
	new_post->next = NULL;
	return new_post;
}