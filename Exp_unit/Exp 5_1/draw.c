#include<stdio.h>

int main() {
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            if((i <= 2 && j <= 2) || (i >= 4 && j >= 4) || (i <= 2 && j >= 4) || (i >= 4 && j <= 2))
                if((i + j == 4 || i + j == 6 || i + j == 8) && i != 5 && j != 5)
                    printf("*");
                else
                    printf(" ");

            else
                printf("*");
        }
        printf("\n");
    }
}
