//Write a program to take an integer array nums of size n, and print the majority element. The majority element is the element that appears strictly more than ⌊n / 2⌋ times. Print -1 if no such element exists. Note: Majority Element is not necessarily the element that is present most number of times.
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Finds the majority element in an integer array.
 * * The majority element is the element that appears strictly more than floor(n / 2) times.
 * This function uses the Boyer-Moore Voting Algorithm (two passes).
 * * @param nums The integer array.
 * @param n The size of the array.
 * @return The majority element, or -1 if no such element exists.
 */
int findMajorityElement(int* nums, int n) {
    if (n == 0) {
        return -1;
    }

    // --- Step 1: Find a Potential Candidate (Boyer-Moore Voting) ---
    int candidate = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            // Start tracking a new candidate
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            // If the current element matches the candidate, increment the count
            count++;
        } else {
            // If it does not match, decrement the count (they cancel each other out)
            count--;
        }
    }

    // --- Step 2: Verify the Candidate ---
    // The element found in Step 1 is the only possible majority element.
    // We must now verify if its frequency is strictly > floor(n / 2).

    int required_frequency = n / 2; // Integer division automatically calculates floor(n / 2)
    int actual_count = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate) {
            actual_count++;
        }
    }

    // Check if the actual count meets the strict majority requirement
    if (actual_count > required_frequency) {
        return candidate;
    } else {
        return -1;
    }
}

int main() {
    // Test Case: Majority element is 4 (appears 5 times, 5 > 9/2 = 4)
    int nums[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Input Array (size %d):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\nRequired frequency for majority element: strictly more than floor(%d/2) = %d.\n", n, n / 2);

    int majority = findMajorityElement(nums, n);

    printf("\nResult:\n");
    if (majority != -1) {
        printf("The majority element is: %d\n", majority);
    } else {
        printf("No majority element exists (-1).\n");
    }
    
    // Additional Test Case Example (No majority element: size 4, required > 2)
    // int nums_no_majority[] = {2, 2, 1, 1};
    // int n_no_majority = 4;
    // printf("\nTest 2 Result (No majority): %d\n", findMajorityElement(nums_no_majority, n_no_majority));
    
    return 0;
}
