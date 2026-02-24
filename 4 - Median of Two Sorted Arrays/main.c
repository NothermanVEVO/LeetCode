#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int resultSize = nums1Size + nums2Size;
    int middleIndex = resultSize / 2;

    int* result = (int*) malloc(resultSize * sizeof(int));
    int i = 0;
    int j = 0;
    int index = 0;

    while(i < nums1Size && j < nums2Size){
        if(nums1[i] < nums2[j]){
            result[index] = nums1[i];
            i++;
        } else{
            result[index] = nums2[j];
            j++;
        }
        if(index == middleIndex){
            if(resultSize % 2 == 0){
                return (result[middleIndex - 1] + result[middleIndex]) / 2.0;
            } else{
                return result[middleIndex];
            }
        }
        index++;
    }
    while(i < nums1Size){
        result[index] = nums1[i];
        i++;
        if(index == middleIndex){
            if(resultSize % 2 == 0){
                return (result[middleIndex - 1] + result[middleIndex]) / 2.0;
            } else{
                return result[middleIndex];
            }
        }
        index++;
    }
    while(j < nums2Size){
        result[index] = nums2[j];
        j++;
        if(index == middleIndex){
            if(resultSize % 2 == 0){
                return (result[middleIndex - 1] + result[middleIndex]) / 2.0;
            } else{
                return result[middleIndex];
            }
        }
        index++;
    }

    if(resultSize % 2 == 0){
        return (result[middleIndex - 1] + result[middleIndex]) / 2.0;
    } else{
        return result[middleIndex];
    }

}

int main(){

    int array1[] = {1, 2};
    int array2[] = {3, 4};

    printf("%f", findMedianSortedArrays(array1, 2, array2, 2));

    return 0;

}