#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <queue>
#include "lib.hpp"

using namespace std;
using namespace chrono;



int mochilaDinamica(vector<Item>& itens, int capacidade) {
    int n = itens.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacidade + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacidade; ++w) {
            if (itens[i - 1].peso <= w) {
                dp[i][w] = max(dp[i - 1][w], itens[i - 1].valor + dp[i - 1][w - itens[i - 1].peso]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacidade];
}



void dinamicaDriver(vector<Item>& itens, int capacidade){
    
    auto start = high_resolution_clock::now();
    int resultadoPD = mochilaDinamica(itens, capacidade);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "PROG - DINAMICA - DURATION: " << duration.count() << " SIZE: "<< resultadoPD<< endl;

    //SAVE DURATION

}