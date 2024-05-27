// "social network" program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "social_network.h"
int main() {
	int post_ID;
	char *cmd_type, *username;
	char* logged_username = NULL;
	liker *new_liker, *curr_liker;
	post_info *new_post, *prev_post, *curr_post;
	user_info *new_user, *curr_user;
	user_info *head_of_users = NewUser();
	if (head_of_users == NULL) {
		getch();
		return ZERO;
	}
	while (1) {
		fflush(stdin);
		if ((cmd_type = get_input(ZERO)) == NULL) {
			getch();
			return ZERO;
		}
		int cmd_number = cmd_detection(cmd_type);
		switch (cmd_number) {
			case 0 ... 1 :
				new_user = NewUser();
				new_user->username = get_input(ZERO);
				new_user->password = get_input(ZERO);
				if (new_user->password == NULL)
					free(new_user->username);
				if (new_user->username == NULL || new_user->password == NULL)
					free(new_user);
				if (new_user == NULL || new_user->username == NULL || new_user->password == NULL) {
					free(cmd_type);
					error_malloc("new user");
					getch();
					return ZERO;
				}
				break;
			case 2 ... 7 :
				if (logged_username == NULL) {
					printf("error!\nlog in first!\n");
					continue;
				}
		}
		switch (cmd_number) {
			case 0 :
				if (logged_username == NULL) {
					curr_user = search(head_of_users, new_user->username);
					if(!strcmp(curr_user->username, new_user->username))
						printf("error!\nThis username is already registered!\n");
					else {
						new_user->head_of_posts = NewPost();
						if (new_user->head_of_posts != NULL) {
							add_user(head_of_users, new_user);
							break;
						}
						else
							free(new_user->head_of_posts);
					}
				}
				else
					printf("error!\nlog out first!\n");
				free(new_user->username);
				free(new_user->password);
				free(new_user);
				break;
			case 1 :
				if (logged_username == NULL) {
					curr_user = search(head_of_users, new_user->username);
					if (strcmp(curr_user->username, new_user->username)) {
						printf("error!\nsign up first!\n");
					}
					else {
						if (strcmp(curr_user->password, new_user->password)) {
							printf("error!\nThe password entered isn't correct!\n");
						}
						else
							logged_username = curr_user->username;
					}
				}
				else
					printf("error!\nlog out first!\n");
				free(new_user->username);
				free(new_user->password);
				free(new_user);
				break;
			case 2 :
				if ((new_post = NewPost()) == NULL)
					break;
				if ((new_post->post_text = get_input(ONE)) == NULL) {
					free(new_post);
					break;
				}
				new_post->number_of_likes = ZERO;
				curr_user = search(head_of_users, logged_username);
				new_post->post_ID = num_of_posts(curr_user->head_of_posts) + ONE;
				if ((new_post->head_of_likers = NewLiker()) == NULL)
					break;
				add_post(curr_user->head_of_posts, new_post);
				break;
			case 3 :
				if ((username = get_input(ZERO)) == NULL)
					break;
				scanf("%d", &post_ID);
				fflush(stdin);
				curr_user = search(head_of_users, username);
				if (strcmp(curr_user->username, username)) {
					printf("error!\nThis username was not found!\n");
				}
				else {
					curr_post = curr_user->head_of_posts;
					while (curr_post->post_ID != post_ID && curr_post->next != NULL)
						curr_post = curr_post->next;
					if (curr_post->post_ID == post_ID) {
						curr_liker = curr_post->head_of_likers;
						while (strcmp(curr_liker->username, logged_username) && curr_liker->next != NULL)
							curr_liker = curr_liker->next;
						if (strcmp(curr_liker->username, logged_username)) {
							++curr_post->number_of_likes;
							if ((new_liker = NewLiker()) == NULL)
								break;
							new_liker->username = logged_username;
							add_liker(curr_post->head_of_likers, new_liker);	
						}
						else
							printf("error!\nYou already like this post!\n");
					} 
					else
						printf("error!\nThis username has no posts with this post ID!\n");
				}
				free(username);
				break;
			case 4 :
				logged_username = NULL;
				break;
			case 5 :
				scanf("%d", &post_ID);
				fflush(stdin);
				curr_user = search(head_of_users, logged_username);
				curr_post = curr_user->head_of_posts;
				while (curr_post->post_ID != post_ID && curr_post->next != NULL) {
					prev_post = curr_post;
					curr_post = curr_post->next;
				}
				if (curr_post->post_ID == post_ID) {
					prev_post->next = curr_post->next;
					free_post(curr_post);
				}
				else
					printf("error!\nThis username has no posts with this post ID!\n");
				break;
			case 6 :
				curr_user = search(head_of_users, logged_username);
				printf("Username : %s\n", curr_user->username);
				printf("Password : %s\n", curr_user->password);
				print_post_info(curr_user);
				break;
			case 7 :
				if ((username = get_input(ZERO)) == NULL)
					break;
				curr_user = search(head_of_users, username);
				if (!strcmp(curr_user->username, username)) {
					printf("Username : %s\n", username);
					print_post_info(curr_user);
				}
				else
					printf("error!\nThis username was not found!\n");
				break;
			default :
				printf("error!\nEnter a command!\n");
				break;
		}
		free(cmd_type);
		print_file(head_of_users);
	}
	free_users(head_of_users);
}			