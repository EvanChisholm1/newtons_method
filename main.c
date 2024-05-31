#include<stdio.h>
#include<math.h>
#include<malloc.h>

double poly(double *coefficients, int degree, double x) {
    double result = 0;

    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, degree - i);
    }

    return result;
}

double poly_prime(double *coefficients, int degree, double x) {
    double result = 0;

    for (int i = 0; i < degree; i++) {
        result += coefficients[i] * (degree - i) * pow(x, degree - i - 1);
    }

    return result;
}

int print_eqn(double *coefficients, int degree) {
    for (int i = 0; i <= degree; i++) {
        if(coefficients[i] == 0.0) continue;
        else if(degree - i == 0) {
            printf("+ %lf", coefficients[i]);
        } else if(i == 0) {
            printf("%lfx^%d ", coefficients[i], (degree - i));
        } else {
            printf("+ %lfx^%d ", coefficients[i], (degree - i));
        }
    }

    printf("\n");
}

int main() {
    int degree;
    printf("Enter degree of the polynomial: ");
    scanf("%d", &degree);

    double *coefficients = (double *)malloc(sizeof(double) * (degree + 1));

    for(int i = 0; i <= degree; i++) {
        printf("Enter the coefficint for the %dth term of the polynomial: ", (degree - i));
        scanf("%lf", &coefficients[i]);
    }


    print_eqn(coefficients, degree);


    double x, x_new;

    printf("Enter the initial guess: ");
    scanf("%lf", &x);

    while(1) {
        x_new = x - poly(coefficients, degree, x) / poly_prime(coefficients, degree, x);

        printf("%lf\n", x_new);

        if(fabs(x_new - x) < 0.00001) {
            break;
        }

        x = x_new;
    }

    printf("The root of the equation is: %lf\n", x_new);

    return 0;
}
