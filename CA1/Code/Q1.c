#include <stdio.h>
int main () {
    int room_number, floor_number, min_height, times = 2;
    double initial_jump;
    //getting the room number and initial jump value from the user
    scanf("%d %lf", &room_number, &initial_jump);
    //the result of dividing the room number by 100 is equal to the floor number
    floor_number = room_number / 100;
    //the remainder of dividing the room number by 100 is equal to the room number inside each floor
    room_number %= 100;
    //determining the area of the room
    switch (room_number) {
        case 1 ... 4 :
            printf("1\n");
            break;
        case 5 ... 8 :
            printf("2\n");
            break;
        case 9 ... 12 :
            printf("3\n");
            break;
        case 13 ... 16 :
            printf("4\n");
            break;
    }
    //the relationship between the minimum required height and the floor number 
    min_height = 2 * floor_number + 1;
    //the relationship between the number of jumps, the initial jump value and the minimum required height
    while (1) {
        if ((times + 1) * initial_jump / 2 >= min_height)
            break;
        ++times; 
    }
    //decreasing one unit of "times" due to the first time
    printf("%d\n", times - 1);
}