#include <stdio.h>
int main () {
    double a, b, c, x, prior_x, y, error, largest;
    int integer_x, integer_prior_x, count = 0, i = 0;
    //getting coefficients and error
    scanf("%lf %lf %lf %lf", &a, &b, &c, &error);
    //determining the largest coefficient
    if (a > b && a > c)
        largest = a;
    else if (b > a && b > c)
        largest = b;
    else
        largest = c;
    //a loop with the interval between the negative and positive square of the largest coefficient 
    for (x = -largest * largest; x <= largest * largest; x += error * 0.1) {
        y = x * x * x + a * x * x + b * x + c;
        if (y < 0)
            y = -y;
        if (y <= error) {
            //because the duplicate number is not displayed
            integer_x = (int) x / error;
            integer_prior_x = (int) prior_x / error;
            if (integer_x != integer_prior_x) {
                printf("%lf\n", x);
                prior_x = x;
                ++count;
            }
        }
    }
    //to displsy "bedoon rishe" 
    if (count < 3)
        while (i + count < 3) {
            printf("bedoon rishe\n");
            ++i;
        }
}