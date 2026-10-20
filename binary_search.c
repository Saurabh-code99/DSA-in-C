#include <stdio.h>

int main()
{
    int n = 10;
    int arr[10] = {12, 23, 3, 20, 30, 41, 55, 70, 80, 90};
    int target;

    printf("Enter the target value: ");
    scanf("%d", &target);

    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            printf("Target found.");
            return 0;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
    }

    printf("Element not found");

    return 0;
}

