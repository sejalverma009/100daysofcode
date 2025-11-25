//Write a Program to take a sorted array(say nums[]) and an integer (say target) as inputs. The elements in the sorted array might be repeated. You need to print the first and last occurrence of the target and print the index of first and last occurrence. Print -1, -1 if the target is not present.
#include <stdio.h>
#include <stdlib.h>

int findFirstOccurrence(int *arrayData, int arrayLength, int desiredValue) {
    int begin = 0;
    int end = arrayLength - 1;
    int firstIndex = -1;

    while (begin <= end) {
        int middle = begin + (end - begin) / 2;

        if (arrayData[middle] == desiredValue) {
            firstIndex = middle;
            end = middle - 1;
        } else if (arrayData[middle] < desiredValue) {
            begin = middle + 1;
        } else {
            end = middle - 1;
        }
    }

    return firstIndex;
}

int findLastOccurrence(int *arrayData, int arrayLength, int desiredValue) {
    int begin = 0;
    int end = arrayLength - 1;
    int lastIndex = -1;

    while (begin <= end) {
        int middle = begin + (end - begin) / 2;

        if (arrayData[middle] == desiredValue) {
            lastIndex = middle;
            begin = middle + 1;
        } else if (arrayData[middle] < desiredValue) {
            begin = middle + 1;
        } else {
            end = middle - 1;
        }
    }

    return lastIndex;
}

int main(void) {
    int totalElements;
    int targetToFind;

    printf("Ahem, we need to begin by determining the array's capacity.\n");
    printf("Kindly enter the number of elements for your sorted array: ");
    if (scanf("%d", &totalElements) != 1 || totalElements <= 0) {
        printf("That seems to be an invalid size, program terminating now.\n");
        return 1;
    }

    int *someNumbers = (int *)malloc(totalElements * sizeof(int));
    if (someNumbers == NULL) {
        printf("Oh dear, memory allocation failed, we cannot proceed.\n");
        return 1;
    }

    printf("Right, please enter the %d sorted integers one by one:\n", totalElements);
    for (int i = 0; i < totalElements; i++) {
        printf("Element %d: ", i);
        if (scanf("%d", &someNumbers[i]) != 1) {
            printf("Something went wrong with the input, stopping prematurely.\n");
            free(someNumbers);
            return 1;
        }
    }

    // --- NEW VALIDATION CHECK ---
    int isSorted = 1;
    for (int i = 0; i < totalElements - 1; i++) {
        if (someNumbers[i] > someNumbers[i+1]) {
            isSorted = 0;
            break;
        }
    }

    if (!isSorted) {
        printf("\nSTOP! It is critically important that the array is sorted.\n");
        printf("The elements you entered are regrettably not in ascending order.\n");
        printf("The binary search approach requires sorted data; therefore, we must cease execution.\n");
        free(someNumbers);
        return 1;
    }
    // --- END NEW VALIDATION CHECK ---


    printf("Excellent. Now, tell me, which integer are we diligently searching for? ");
    if (scanf("%d", &targetToFind) != 1) {
        printf("Unclear target input, aborting search.\n");
        free(someNumbers);
        return 1;
    }

    printf("\nVery well, initiating the swift binary search algorithm.\n");

    int firstResult = findFirstOccurrence(someNumbers, totalElements, targetToFind);
    int lastResult = findLastOccurrence(someNumbers, totalElements, targetToFind);

    if (firstResult != -1) {
        printf("The search has concluded successfully, and here are the vital statistics:\n");
        printf("The index of the initial sighting is: %d.\n", firstResult);
        printf("The index of the final sighting is: %d.\n", lastResult);
    } else {
        printf("Alas, the requested number, which was %d, appears to be entirely absent.\n", targetToFind);
        printf("As required, the output indicating absence is: %d, %d\n", firstResult, lastResult);
    }

    free(someNumbers);
    return 0;
}
