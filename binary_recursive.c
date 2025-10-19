#include <stdio.h>
#include <stdlib.h>

int search(int array[], int value, int left, int right, int size);
int recursive(int array[], int value, int left, int right, int size);

int main(void){
    
}

int search(int array[], int value, int left, int right, int size){
    left = 0;
    // end of the array;
    right = size - 1;
    int mid = (left + right)/2;

    while(left <= right){
        if(array[mid]== value){
            return mid;
        } else if(array[mid] < value){
            left = mid +1;

        } else{
            right = mid - 1;

        }

        }
    


    }

    int recursive(int array[], int value, int left, int right, int size){
        // base case 
        if(left > right){
            return -1;
        }

        // recursive implementation.
        int mid = (right + left) /2;

        if(array[mid] == value){
            return mid;
        } else if(array[mid] < value){

            return recursive(array, mid+1,value,size,right);

        } else{
            return recursive(array, mid-1,value,size,left);

        }
            
        
    }
