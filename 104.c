//Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.
#include <stdio.h>

long long get_sum_to_k(long long k) {
    if (k < 1) {
        return 0;
    }
    return k * (k + 1) / 2;
}

int findPivotInteger(int n) {
    long long totalSum = get_sum_to_k(n);
    long long low = 1;
    long long high = n;
    int pivot = -1;

    while (low <= high) {
        long long x = low + (high - low) / 2;
        long long sum1ToX = get_sum_to_k(x);
        long long sumXToN = totalSum - get_sum_to_k(x - 1);

        if (sum1ToX == sumXToN) {
            pivot = (int)x;
            return pivot;
        } else if (sum1ToX < sumXToN) {
            low = x + 1;
        } else {
            high = x - 1;
        }
    }

    return pivot;
}

int main(void) {
    int n;

    printf("Right, we must first obtain the maximum limit, n, for our sequence.\n");
    printf("Kindly enter a positive integer n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("That input is simply unacceptable for this task, terminating immediately.\n");
        return 1;
    }

    printf("\nExcellent. We shall now conduct the mathematical search for the pivot integer.\n");

    int pivotX = findPivotInteger(n);

    if (pivotX != -1) {
        printf("The arduous calculation has been completed, and the unique pivot integer is:\n");
        printf("Pivot Integer x: %d.\n", pivotX);

        // This is purely for demonstration and verification purposes
        long long leftSum = get_sum_to_k(pivotX);
        long long totalSum = get_sum_to_k(n);
        long long rightSum = totalSum - get_sum_to_k(pivotX - 1);
        printf("Where the sum (1 to x) is %lld and the sum (x to n) is %lld.\n", leftSum, rightSum);
    } else {
        printf("Regrettably, no such integer x could be discovered within the range 1 to %d.\n", n);
        printf("The required output for absence is: %d\n", pivotX);
    }

    return 0;
}
