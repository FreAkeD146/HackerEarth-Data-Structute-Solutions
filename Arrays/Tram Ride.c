/* Steps to implement:

1. Include necessary header files (stdio.h, stdlib.h).
2. Declare the function solve to calculate the minimum cost.
3. Declare variables for N, start, and finish.
4. Input values for N, start, and finish.
5. Declare an array Ticket_cost to store ticket costs.
6. Input Ticket_cost array elements.
7. Call the solve function and print the result.
8. Return 0, indicating successful execution.

This program calculates the minimum cost to travel from the start to the finish using the given ticket costs.*/

#include <stdio.h>
#include <stdlib.h>

long long solve(int N, int start, int finish, int Ticket_cost[]) {
    // Write your code here
    if (start == finish)
        return 0;

    int tmp = start - 1;
    long long int sum = 0;

    // Calculate sum from start to finish
    while (tmp != finish - 1) {
        sum += Ticket_cost[tmp];
        tmp = (tmp + 1) % N;
    }

    tmp = (finish - 1) % N;
    long long int sum2 = 0;

    // Calculate sum from finish to start
    while (tmp != (start - 1)) {
        sum2 += Ticket_cost[tmp];
        tmp = (tmp + 1) % N;
    }

    // Return the minimum of the two sums
    return (sum < sum2) ? sum : sum2;
}

int main() {
    int N, start, finish;

    // Input values for N, start, and finish
    scanf("%d %d %d", &N, &start, &finish);

    int Ticket_cost[N];

    // Input Ticket_cost array elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &Ticket_cost[i]);
    }

    // Call the solve function and print the result
    printf("%lld\n", solve(N, start, finish, Ticket_cost));

    return 0;
}
