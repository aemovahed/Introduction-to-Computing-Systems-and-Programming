// To allocate memory for a new user
#include <stdlib.h>
#include "social_network.h"
user_info* NewUser(void) {
	user_info* new_user = (user_info *)malloc(sizeof(user_info));
	if (new_user == NULL) {
		error_malloc("new user");
		return NULL;
	}
	new_user->next = NULL;
	return new_user;
}