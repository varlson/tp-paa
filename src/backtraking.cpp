#include <stdio.h>
#include "header.hpp"


// int max(int a, int b) {
//     return (a > b) ? a : b;
// }

int knapsackBacktracking(int W, int wt[], int val[], int n, int i) {
    if (i == 0 || W == 0) {
        return 0;
    }

    if (wt[i - 1] > W) {
        return knapsackBacktracking(W, wt, val, n, i - 1);
    } else {
        return max(val[i - 1] + knapsackBacktracking(W - wt[i - 1], wt, val, n, i - 1),
                   knapsackBacktracking(W, wt, val, n, i - 1));
    }
}

// int main() {
//     int val[] = {60, 100, 120};
//     int wt[] = {10, 20, 30};
//     int W = 50;
//     int n = sizeof(val) / sizeof(val[0]);
    
//     int result = knapsackBacktracking(W, wt, val, n, n);
//     printf("O valor máximo que pode ser colocado na mochila é %d\n", result);
//     return 0;
// }
