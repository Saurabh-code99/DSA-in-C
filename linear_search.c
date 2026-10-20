#include <stdio.h>

int main(){
    int arr[10] = { 43,4565,32,65,38,556,23,675,321,6454};
    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    int found = 0;

    for (int i = 0; i < 10; i++){
        if (arr[i] == target){
            found = 1;
            break;
        }
    }


    if (found == 1){
        printf("Element found.\n");
    }
    else{
        printf("Element not found.\n");
    }

return 0;
}
