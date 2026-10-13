
#include <stdio.h>

int main() {
    int a[5] = {50, 20, 40, 10, 30};
    int i, j, temp;

    printf("Before sorting: ");
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting: ");
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);

    return 0;
}
