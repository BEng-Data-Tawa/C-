#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

void reverse(char array[], int size);

int main(void){

    char array[SIZE] = {"Tawanda"};
    // call function on the char;
    reverse(array,SIZE);

    printf("%s\n", array);
}

void reverse(char array[], int size){
    // 2 pointers 
    int left =0;
    // because last char in end of the string is "\0" so look for the end then - 1
    int right = size - 2;
   // while 2 pointers have not met each other
    while(left < right){
        // swapping the arrays
        char temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }
}
