#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int main(){

    // first lets just reverse the array

    //Use malloc to identitify

    // allocate memory for the name string:

    int length;
    char *name;
    char *original;

    

    printf("Enter the number of characters you wish to use: ");
    scanf("%d", &length);

    name = malloc((length + 1) * sizeof(char));

    if(name == NULL){
        printf("MALLOC FAILED");
    }

     original = malloc((length + 1)* sizeof(char));

    if(original == NULL){
        printf("MALLOC FAILED");
    }

    // FREE THE MALLOC 

    printf("Enter the string");
    scanf("%s", name);
    strcpy(original, name);
    // note the end of a char array comntains \0

    char *left = name;
    char *right = name + strlen(name) - 1;
    char temp;

    while(left < right){
        // peform a swap
        temp = *left;
        *left = *right;
        *right = temp;
        right--;
        left++;

        
    }
    printf("reversed: %s", name);

    if(strcmp(original,name) == 0){
        printf("Word is a palindrome.");
    } else {
        printf("Word is not a palindrome.");
    }

    free(name);
    name = NULL;

    free(original);
    original = NULL;
}