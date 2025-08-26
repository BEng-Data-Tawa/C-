#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int y){
    int fact =1;
    for(int i = 1; i<=y; i++){
        fact *=i;
    }
    return fact;
}

int main(void){

    float term;
    float x;
    // updates term, increments.
    int n = 0;
    float sum = 1;
    float margin = 0.0001;

    printf("Enter an x value: \n");
    scanf("%f", &x);


    do{
        // increment n to update the term value
        n++;
        // use taylor series fomula to calculate the term:
        term = pow(x,n)/factorial(n);
        sum +=term;
        printf("%d: %f\n", n, term);

    
    }while(fabs(term) >= margin);
    printf("the total is: %f", sum);
    

}