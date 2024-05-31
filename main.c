#include<stdio.h>
#include<math.h>

float f(float x) {
    return pow(x, 3) - 5 * pow(x, 2) + x + 9;
}

float f_prime(float x) {
    return 3 * pow(x, 2) - 10 * x + 1;
}

int main() {
    float x, x_new;

    printf("Enter the initial guess: ");
    scanf("%f", &x);

    while(1) {
        x_new = x - f(x) / f_prime(x);

        if(fabs(x_new - x) < 0.00001) {
            break;
        }

        x = x_new;
    }

    printf("The root of the equation is: %f\n", x_new);

    return 0;
}
