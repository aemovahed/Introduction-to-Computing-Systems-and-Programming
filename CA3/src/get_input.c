// Receiving input from the user
#include <stdio.h>
#include <stdlib.h>
#include "social_network.h"
char* get_input(int flag) {
	int i = 0;
	char c;
	char *str = (char *)malloc(i + 1);
	char *temp;
	str[i++] = '\0';
	while ((c = getchar()) != '\n') {
		switch (flag) {
			case ZERO :
				if (c == ' ') {
					flag = 2;
					break;
				}
			case ONE :
				temp = (char *)realloc(str, i + 1);
				if (temp == NULL) {
					error_malloc("new string");
					return NULL;
				}
				str = temp;
				str[i - 1] = c;
				str[i++] = '\0';
		}
		if (flag == 2)
			break;
	}
	return str;
}