#include <stdio.h>
#include <stdlib.h>

int main() {
    int h, q, m, year;
    
    printf("Enter day: \n");
    scanf("%d", &q);
    
    printf("Enter month: \n");
    scanf("%d", &m);
    
    printf("Enter year: \n");
    scanf("%d", &year);
    
    // Adjust month and year for Jan/Feb
    if (m == 1) {      // January
        m = 13;
        year--;
    } else if (m == 2) { // February
        m = 14;
        year--;
    }
    
    int K = year % 100;   // year of the century
    int J = year / 100;   // zero-based century
    
    // Zeller's formula
    h = (q + 13*(m+1)/5 + K + K/4 + J/4 + 5*J) % 7;
    
    switch(h){
        case 0: printf("It's a Saturday\n"); break;
        case 1: printf("It's a Sunday\n"); break;
        case 2: printf("It's a Monday\n"); break;
        case 3: printf("It's a Tuesday\n"); break;
        case 4: printf("It's a Wednesday\n"); break;
        case 5: printf("It's a Thursday\n"); break;
        case 6: printf("It's a Friday\n"); break;
        default: printf("Error calculating day\n");
    }
    
    return 0;
}
