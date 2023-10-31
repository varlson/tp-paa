#include <stdio.h>
#include <stdlib.h>
#include "header.hpp"

// typedef struct Item {
//     int value;
//     int weight;
//     float ratio;
// } Item;

int compare(const void *a, const void *b) {
    return (((Item *)b)->ratio - ((Item *)a)->ratio);
}

int bound(int n, int W, Item items[], int i, int value, int weight) {
    if (weight >= W)
        return 0;
    
    int bound = value;
    int j = i;
    while (j < n && weight + items[j].weight <= W) {
        bound += items[j].value;
        weight += items[j].weight;
        j++;
    }
    if (j < n)
        bound += (W - weight) * items[j].ratio;
    
    return bound;
}

int knapsackBranchAndBound(int n, int W, Item items[]) {
    qsort(items, n, sizeof(Item), compare);
    
    int maxVal = 0;
    int value = 0;
    int weight = 0;
    int i = 0;
    
    while (i >= 0) {
        while (i < n && weight + items[i].weight <= W) {
            value += items[i].value;
            weight += items[i].weight;
            i++;
        }
        
        if (i >= n || weight >= W) {
            if (value > maxVal) {
                maxVal = value;
            }
            i--;
            if (i >= 0) {
                weight -= items[i].weight;
                value -= items[i].value;
            }
            i++;
        } else {
            int b = bound(n, W, items, i, value, weight);
            if (b <= maxVal) {
                i--;
                if (i >= 0) {
                    weight -= items[i].weight;
                    value -= items[i].value;
                }
                i++;
            }
        }
    }
    
    return maxVal;
}

int main() {
    int n = 3;
    int W = 50;
    Item items[] = {{60, 10, 6}, {100, 20, 5}, {120, 30, 4}};
    
    int result = knapsackBranchAndBound(n, W, items);
    printf("O valor máximo que pode ser colocado na mochila é %d\n", result);
    return 0;
}
