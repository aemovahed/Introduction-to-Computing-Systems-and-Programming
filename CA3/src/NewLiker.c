// To allocate memory for a new liker
#include <stdlib.h>
#include "social_network.h"
liker* NewLiker(void) {
    liker *new_liker = (liker *)malloc(sizeof(liker));
    if (new_liker == NULL) {
        error_malloc("new liker");
        return NULL;
    }
    new_liker->username = " ";
    new_liker->next = NULL;
    return new_liker;
}