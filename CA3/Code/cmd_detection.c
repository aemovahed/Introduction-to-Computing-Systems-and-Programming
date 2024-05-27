// Determining the type of input command 
#include <string.h>
#include "social_network.h"
#define MAX_CMD_SIZE 10
#define NUM_OF_CMDS 8
int cmd_detection (char *cmd_type) {
	char cmds[NUM_OF_CMDS][MAX_CMD_SIZE] = 
		{"signup", "login", "post", "like", "logout", "delete", "info", "find_user"};
	int i = ZERO;
	for (i = ZERO; i < NUM_OF_CMDS; i++)
		if (strcmp(cmd_type, cmds[i]) == ZERO) {
			return i;
		}
	return -1;
}