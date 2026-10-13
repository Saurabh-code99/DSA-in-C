
#include <stdio.h>

int main() {
    int a[] = {12, 24, 36, 48, 60, 72};
    int n = 6, key = 48;
    int left = 0, right = n - 1, mid;

    printf("Given array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nKey to search: %d\n", key);

    while (left <= right) {
        mid = (left + right) / 2;

        if (a[mid] == key) {
            printf("Found at position %d\n", mid + 1);
            break;
        } else if (key > a[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (left > right)
        printf("Key not found\n");

    return 0;
}
