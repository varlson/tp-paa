#include <stdio.h>
#include "header.hpp"
#include <math.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// knapsack Backtracking
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


// Problema da mochila (Knapsack problem) 
// PROGRAMAÇÃO DINAMICA

int knapsackDP(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][W];
}


// knapsackBranchAndBound

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return ((int *)b)[0] - ((int *)a)[0];
}

int bound(int n, int W, int val[], int wt[], int i, int value, int weight) {
    if (weight >= W || i >= n) {
        return 0;
    }

    int bound = value;
    int j = i;

    while (j < n && weight + wt[j] <= W) {
        bound += val[j];
        weight += wt[j];
        j++;
    }

    if (j < n) {
        bound += (W - weight) * val[j] / wt[j];
    }

    return bound;
}

int knapsackBranchAndBound(int n, int W, int val[], int wt[], int i, int value, int weight) {
    if (i >= n) {
        return value;
    }

    if (weight + wt[i] <= W) {
        // Include the current item
        int include = knapsackBranchAndBound(n, W, val, wt, i + 1, value + val[i], weight + wt[i]);
        int exclude = knapsackBranchAndBound(n, W, val, wt, i + 1, value, weight);
        return (include > exclude) ? include : exclude;
    } else {
        // Skip the current item
        return knapsackBranchAndBound(n, W, val, wt, i + 1, value, weight);
    }
}




