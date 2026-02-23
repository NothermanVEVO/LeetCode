#include <stdio.h>

void rotate(int* nums, int numsSize, int k) {
    if (k <= 0 || numsSize <= 1 || k % numsSize == 0){
        return;
    }

    int index = 0;
    int previousValue = nums[index];
    int toIndex = 0;
    int lastSafeIndex = 0;

    while (index < numsSize){
        toIndex = (toIndex + k) % numsSize;

        int temp = nums[toIndex];
        nums[toIndex] = previousValue;
        previousValue = temp;

        index += 1;

        if(toIndex == lastSafeIndex){
            lastSafeIndex += 1;
            toIndex = lastSafeIndex;
            previousValue = nums[toIndex];
        }
    }
}

int main(){
    int array[] = {1,2};
    int numsSize = 2;
    rotate(array, numsSize, 4);

    printf("{");
    for(int i = 0; i < numsSize; i++){
        printf("%d", array[i]);
        if(i < numsSize - 1){
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}