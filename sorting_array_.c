#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 3

void bubble_array(char array[][50], int size);

int main(void){

    char names[SIZE][50] = {"Tawa", "SISA", "Ava"};

    // call the function: 

    bubble_array(names, SIZE);
    printf("\nIndex\tValues\n");
    for(int i = 0; i < SIZE; i++){
        printf("%d\t%s\n", i, names[i]);
    }
    

}

void bubble_array(char array[][50], int size){
    char temp[50];
    for(int i = 0; i < size; i++){
        for(int j =0; j < size - 1 -i; j++){
            if(strcmp(array[j], array[j+1]) > 0){
                // peform swap;
                strcpy(temp , array[j]);
                strcpy(array[j], array[j+1]);
                strcpy(array[j+1], temp);
            }
        }
    }
}

