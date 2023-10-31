 #include <iostream>
 #include "header.hpp"
 using namespace std;



 int main(){

//knapsackBacktracking
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    int result = knapsackBacktracking(W, wt, val, n, n);
    printf("O valor máximo que pode ser colocado na mochila é %d\n\n", result);
   

    //knapsackBranchAndBound

    // n = 3;
    // W = 50;
    // Item items[] = {{60, 10, 6}, {100, 20, 5}, {120, 30, 4}};
    // result = knapsackBranchAndBound(n, W, items);
    // printf("O valor máximo que pode ser colocado na mochila é %d\n\n", result);

    // //knapsackDP

    int val2[] = {60, 100, 120};
    int wt2[] = {10, 20, 30};
    W = 50;
    n = sizeof(val2) / sizeof(val2[0]);
    
     result = knapsackDP(W, wt2, val2, n);
    printf("O valor máximo que pode ser colocado na mochila é %d\n\n", result);
    return 0;
 }

