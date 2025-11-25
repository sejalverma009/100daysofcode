//Write a Program to take an array of integers as input, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right. If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array. Print the leftmost pivot index. If no such index exists, print -1.
#include <stdio.h>
#include <stdlib.h>

int findPivotIndex(int *nums, int n) {
    long long totalSum = 0;
    long long leftSum = 0;

    for (int i = 0; i < n; i++) {
        totalSum += nums[i];
    }

    for (int i = 0; i < n; i++) {
        long long rightSum = totalSum - leftSum - nums[i];

        if (leftSum == rightSum) {
            return i;
        }

        leftSum += nums[i];
    }

    return -1;
}

int main(void) {
    int n;

    printf("Well, we must first establish the size of the array for which we seek the pivot.\n");
    printf("Please specify the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("That array size seems quite unsuitable, we must terminate forthwith.\n");
        return 1;
    }

    int *nums = (int *)malloc(n * sizeof(int));
    if (nums == NULL) {
        printf("Oh dear, memory allocation failed, a severe operational failure.\n");
        return 1;
    }

    printf("Now, if you would be so kind as to enter the %d integer elements one by one:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        if (scanf("%d", &nums[i]) != 1) {
            printf("An error occurred during input, we cannot proceed with incomplete data.\n");
            free(nums);
            return 1;
        }
    }

    printf("\nExcellent. We shall now calculate the required pivot index with great care.\n");

    int pivotIndex = findPivotIndex(nums, n);

    if (pivotIndex != -1) {
        printf("The arduous search has concluded successfully, and the result is in:\n");
        printf("The leftmost pivot index is: %d.\n", pivotIndex);
    } else {
        printf("Alas, after meticulous examination, no index meets the strict pivot criteria.\n");
        printf("The required output for absence is: %d\n", pivotIndex);
    }

    free(nums);
    return 0;
}
