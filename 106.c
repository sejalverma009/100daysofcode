//Write a program to take an array arr[] of integers as input, the task is to find the next greater element for each element of the array in order of their appearance in the array.Next greater element of an element in the array is the nearest element on the right which is greater than the current element. If there does not exist next greater of current element, then next greater element for current element is -1.

N.B:
- Print the output for each element in a comma separated fashion.
- Do not use Stack, use brute force approach (nested loop) to solve.
  #include <stdio.h>
#include <stdlib.h>

/**
 * @brief Finds the Next Greater Element (NGE) for each element in an array using the brute-force (nested loop) approach.
 *
 * The NGE of an element is the nearest element on the right which is strictly greater than the current element.
 * If no such element exists, the NGE is -1.
 *
 * @param arr The input integer array.
 * @param n The size of the array.
 */
void findNextGreaterElements(int arr[], int n) {
    if (n <= 0) {
        printf("The array is empty.\n");
        return;
    }

    printf("Next Greater Elements: ");

    // Outer loop iterates through each element of the array
    for (int i = 0; i < n; i++) {
        int next_greater = -1; // Default NGE is -1
        int current_element = arr[i];

        // Inner loop searches for the nearest greater element on the right
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > current_element) {
                // Found the nearest greater element
                next_greater = arr[j];
                break; // Found the NGE, so stop searching to the right
            }
        }

        // Print the result for the current element
        printf("%d", next_greater);

        // Print a comma separator if it's not the last element
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    // Test Case 1: [4, 5, 2, 25] -> NGEs should be [5, 25, 25, -1]
    int arr1[] = {4, 5, 2, 25};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Input Array 1 (size %d):\n", n1);
    for (int i = 0; i < n1; i++) {
        printf("%d%s", arr1[i], (i == n1 - 1 ? "" : ", "));
    }
    printf("\n");

    findNextGreaterElements(arr1, n1);


    // Test Case 2: [13, 7, 6, 12] -> NGEs should be [-1, 12, 12, -1]
    int arr2[] = {13, 7, 6, 12};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nInput Array 2 (size %d):\n", n2);
    for (int i = 0; i < n2; i++) {
        printf("%d%s", arr2[i], (i == n2 - 1 ? "" : ", "));
    }
    printf("\n");

    findNextGreaterElements(arr2, n2);

    return 0;
}
