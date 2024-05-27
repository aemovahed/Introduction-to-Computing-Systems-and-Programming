#include <stdio.h>
int main() {
    int n, i, food_number, energy_received = 0;
    //getting the number of days
    scanf("%d", &n);
    //a loop with n iterations due to receiving n foods
    for (i = 1; i <= n; ++i) {
        //getting food number
        scanf("%d", &food_number);
        //determining energy received using food number and adding it to the total energy received
        switch (food_number) {
            case 1 :
                energy_received += 329;
                break;
            case 2 :
                energy_received += 127;
                break;
            case 3 :
                energy_received += 61;
                break;
            case 4 :
                energy_received += 83;
                break;
            case 5 :
                energy_received += 156;
                break;
            case 6 :
                energy_received += 296;
                break;
            case 7 :
                energy_received += 496;
                break;
            case 8 :
                energy_received += 73;
                break;
            case 9 :
                energy_received += 34;
                break;
            case 10 :
                energy_received += 16;
                break;
        }
    }
    //comparing the total energy required with the total energy received
    if (100 * n < energy_received)
        printf("chagh\n");
    else if (100 * n > energy_received)
        printf("laghar\n");
    else
        printf("bedoon taghir\n");
}