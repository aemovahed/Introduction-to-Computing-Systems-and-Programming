// Printing an error message due to the inability to allocate memory 
#include <stdio.h>
#include "social_network.h"
void error_malloc(char* text) {
	printf("error!\nIt isn't possible to allocate memory for a %s!\n", text);
}