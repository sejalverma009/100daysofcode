//Write a Program to take a sorted array arr[] and an integer x as input, find the index (0-based) of the smallest element in arr[] that is greater than or equal to x and print it. This element is called the ceil of x. If such an element does not exist, print -1. Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.
#include <stdio.h>
#include <stdlib.h>

int findCeilIndex(int *arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int ceilIndex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ceilIndex = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ceilIndex;
}

int main(void) {
    int n;
    int x;

    printf("Ahem, let us commence this procedure by specifying the size of our sorted collection.\n");
    printf("Pray tell, what is the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("That seems to be an invalid size, such a pity, program terminating now.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Oh dear, memory allocation failed, we cannot possibly proceed.\n");
        return 1;
    }

    printf("Right then, please input the %d sorted integers one by one:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Something went astray with the input, stopping prematurely now.\n");
            free(arr);
            return 1;
        }
    }

    int isSorted = 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i+1]) {
            isSorted = 0;
            break;
        }
    }

    if (!isSorted) {
        printf("\nSTOP! It is fundamentally necessary that the array is sorted.\n");
        printf("The elements you have entered are regrettably not in ascending order.\n");
        printf("The search approach absolutely requires sorted data; therefore, we must cease all operations.\n");
        free(arr);
        return 1;
    }


    printf("Excellent. Now, tell me, which integer are we attempting to find the ceil for? ");
    if (scanf("%d", &x) != 1) {
        printf("Unclear target input, aborting search immediately.\n");
        free(arr);
        return 1;
    }

    printf("\nVery well, initiating the highly specialized binary search to locate the ceil.\n");

    int ceilResult = findCeilIndex(arr, n, x);

    if (ceilResult != -1) {
        printf("The search has concluded successfully, and here is the crucial finding:\n");
        printf("The index of the smallest element greater than or equal to %d is: %d.\n", x, ceilResult);
        printf("That element itself is, in fact, %d.\n", arr[ceilResult]);
    } else {
        printf("Alas, the requested number, which was %d, is greater than every single element.\n", x);
        printf("As required by the problem statement, the output indicating absence is: %d\n", ceilResult);
    }

    free(arr);
    return 0;
}
