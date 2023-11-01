#ifndef  HEADER_H
#define HEADER_H

typedef struct Item {
    int value;
    int weight;
    float ratio;
} Item;


int knapsackBacktracking(int W, int wt[], int val[], int n, int i);
int knapsackBranchAndBound(int n, int W, int val[], int wt[], int i, int value, int weight);
int knapsackDP(int W, int wt[], int val[], int n);
int max(int a, int b);
int compare(const void *a, const void *b);


#endif