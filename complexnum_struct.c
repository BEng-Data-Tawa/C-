#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex addComplex(Complex n1, Complex n2);

int main(void){
    Complex number1, number2;
    
    printf("For the first complex number: \n");
    printf("Enter the real part: \n");
    scanf("%f", &number1.real);
    printf("Enter the imaginary part: \n");
    scanf("%f", &number1.imag);


    printf("For the second complex number: \n");
    printf("Enter the real part: \n");
    scanf("%f", &number2.real);
    printf("Enter the imaginary part: \n");
    scanf("%f", &number2.imag);

    // call function

    Complex result = addComplex(number1, number2);
    printf("(%.1f + %fi) + (%.1f + %.1fi) = %.1f + %.1fi", number1.real, number1.imag, number2.real, number2.imag, result.real, result.imag);

}

Complex addComplex(Complex n1, Complex n2){
    Complex result;

    result.real = n1.real + n2.real;
    result.imag = n1.imag + n2.imag;

    return result;
}

