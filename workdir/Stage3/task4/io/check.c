#include <stdio.h>

int main() {
    int i = 0;
    while (i < 5) {
        int j = i;
        i++;

        if (i == 2) continue;

        if (i == 4) break;
        
        printf("10\n");
        printf("%d\n", i);
        while (j < 5) {
            j++;

            if (j == 4) break;
            
            printf("11\n");
            printf("%d\n", j);
        }
    }
}