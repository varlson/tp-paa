 #include <iostream>
 #include "header.hpp"
 using namespace std;



int main() {
    int n = 6;
    int W = 50;

    int val[] = {70, 120, 140, 55,80,150};
    int wt[] = {20, 30, 40, 50,60,70};

    // TESTE PARA BRANCH AND ABOUND
   
    qsort(val, n, sizeof(int), compare);
    int result = knapsackBranchAndBound(n, W, val, wt, 0, 0, 0);
    printf("O valor máximo branch and bound é %d\n\n", result);

    // TESTE PARA BRANCH AND ABOUND
    result = knapsackDP(W, wt, val, n);
    printf("O valor máximo prog dinamica %d\n\n", result);

   
    // TESTE PARA BRANCH AND ABOUND
    result = knapsackBacktracking(W, wt, val, n, n);
    printf("O valor máximo backtraking %d\n", result);
    return 0;
}


