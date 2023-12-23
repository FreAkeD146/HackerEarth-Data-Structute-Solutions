/* Steps to implement:

1. Include necessary header files (stdio.h, stdlib.h).
2. Declare the function sort1 to find the length of the contiguous differing subarray.
3. Allocate memory for the vector (v) using malloc.
4. Check for memory allocation failure.
5. Traverse the arrays to find differences and store the indices in the vector.
6. Calculate the result based on the differences.
7. Free the allocated memory.
8. Input the number of test cases (T).
9. Process each test case.
10. Input the size of the arrays (N).
11. Input elements of array A.
12. Input elements of array B.
13. Print the result for the current test case.
14. Return 0, indicating successful execution.

This program calculates and prints the length of the contiguous differing subarray for each test case. */



#include <stdio.h>
#include <stdlib.h>

int sort1(long int A[], long int B[], long int N) {
    long int count = 0;
    long int *v = NULL;

    // Allocate memory for the vector
    v = (long int *)malloc(N * sizeof(long int));

    // Check for memory allocation failure
    if (v == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Traverse the arrays to find differences
    for (long int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            v[count++] = i;
        }
    }

    // Calculate the result based on the differences
    long int result = (count > 0) ? (v[count - 1] - v[0] + 1) : 0;

    // Free allocated memory
    free(v);

    return result;
}

int main() {
    int T;
    long int N;

    // Input the number of test cases
    scanf("%d", &T);

    // Process each test case
    while (T--) {
        // Input the size of the arrays
        scanf("%ld", &N);

        long int A[N], B[N];

        // Input elements of array A
        for (long int i = 0; i < N; i++) {
            scanf("%ld", &A[i]);
        }

        // Input elements of array B
        for (long int i = 0; i < N; i++) {
            scanf("%ld", &B[i]);
        }

        // Print the result for the current test case
        printf("%d\n", sort1(A, B, N));
    }

    return 0;
}
