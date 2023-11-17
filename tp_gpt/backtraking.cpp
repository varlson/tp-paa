#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <queue>
#include "lib.hpp"

using namespace std;
using namespace chrono;

int max(int a, int b) { return (a > b) ? a : b; }

int mochilaBacktraking(std::vector<Item>& itens, int capacidade) {
    int n = itens.size();

    // Inicializando a tabela de memoização
    std::vector<std::vector<int>> tabela(n + 1, std::vector<int>(capacidade + 1, 0));

    // Preenchendo a tabela de baixo para cima
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacidade; ++w) {
            if (itens[i - 1].peso <= w) {
                tabela[i][w] = std::max(itens[i - 1].valor + tabela[i - 1][w - itens[i - 1].peso], tabela[i - 1][w]);
            } else {
                tabela[i][w] = tabela[i - 1][w];
            }
        }
    }

    return tabela[n][capacidade];
}




Results backtrakingDriver (std::vector<Item>& itens, int capacidade){
        
        auto start = high_resolution_clock::now();
        int resultadoPD = mochilaBacktraking(itens, capacidade);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        // SAVE DURATION TIME


        Results res;
        res.duration = duration.count();
        res.instance = capacidade;

    // cout << "PROG - BACKTRAKING - DURATION: " << duration.count() << " SIZE: "<< resultadoPD<< endl;

    return res;
}

