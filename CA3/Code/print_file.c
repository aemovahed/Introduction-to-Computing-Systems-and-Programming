// Printing information in files 
#include <stdio.h>
#include "social_network.h"
void print_file(user_info *head_of_users) {
	FILE *accounts = fopen("accounts.txt", "w");
	FILE *posts = fopen("posts.txt", "w");
	user_info *prev_user = head_of_users;
	user_info *curr_user = head_of_users->next;
	while (curr_user != NULL) {
		fprintf(accounts, "%s ", curr_user->username);
		fprintf(accounts, "%s ", curr_user->password);
		fprintf(accounts, "%d\n", num_of_posts(curr_user->head_of_posts));
		post_info *curr_post = curr_user->head_of_posts->next;
		while (curr_post != NULL) {
			fprintf(posts, "%s ", curr_post->post_text);
			fprintf(posts, "%s ", curr_user->username);
			fprintf(posts, "%d\n", curr_post->number_of_likes);
			curr_post = curr_post->next;
		}
		prev_user = curr_user;
		curr_user = curr_user->next;
	}
	fclose(accounts);
	fclose(posts);
}