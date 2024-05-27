// To add a user to the end of the list of users
#include <stdio.h>
#include "social_network.h"
void add_user(user_info *head_of_users, user_info *new_user) {
	user_info *previous = head_of_users;
	user_info *current = head_of_users->next;
	while (current != NULL) {
		previous = current;
		current = current->next;
	}
	previous->next = new_user;
}