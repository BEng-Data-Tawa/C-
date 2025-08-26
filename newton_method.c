#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double function_1(double x){
    return 1.2 * pow(x, 2) - 2.5 * x - 7;
}

double derrivative_1(double x){
    return 2.4 * x - 2.5;
}

int main(){

    float attempt;
    float error_margin;
    int max_tries;
    int counter = 0;
    float value_obtained;

    printf("Enter start value (greater than 4):\n ");
    scanf("%f", &attempt);

    printf("Enter an error margin: \n");
    scanf("%f", &error_margin);

    printf("Enter max iterations: \n");
    scanf("%d", &max_tries);

    value_obtained = fabs(function_1(attempt));

    do {
        do {
            double f = function_1(attempt);
            double df = derrivative_1(attempt);

            if(df == 0){
                printf("Derivative zero, stopping.\n");
                return 0;
            }

            attempt = attempt - f/df;
            value_obtained = fabs(function_1(attempt));
            counter++;

            if(counter >= max_tries){
                printf("Reached max iterations.\n");
                break;
            }

        } while(value_obtained > error_margin);
        
        // This outer loop can be removed or used if you want to do something else before repeating.
        // But here it will just break after one run because inner loop ends on condition.
        break;

    } while(value_obtained < error_margin);  // Note: condition here makes little sense; typically you want outer loop to stop if error small enough

    printf("I took %d tries\n", counter);
    printf("Final closest root = %f\n", attempt);

    return 0;
}
