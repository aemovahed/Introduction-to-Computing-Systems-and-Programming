// To add a liker to the end of the list of likers
#include <stdio.h>
#include "social_network.h"
void add_liker(liker *head_of_likers, liker *new_liker) {
	liker *previous = head_of_likers;
	liker *current = head_of_likers->next;
	while (current != NULL) {
		previous = current;
		current = current->next;
	}
	previous->next = new_liker;
}