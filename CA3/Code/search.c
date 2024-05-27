// Searching for a specific username in the list of users
#include <stdio.h>
#include <string.h>
#include "social_network.h"
user_info* search(user_info* head_of_users, char* username) {
	user_info *previous = head_of_users;
	user_info *current = head_of_users->next;
	while (current != NULL) {
		if (strcmp(current->username, username)) {
			previous = current;
			current = current->next;
		}
		else 
			return current;
	}
	return previous;
}