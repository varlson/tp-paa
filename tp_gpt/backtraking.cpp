#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <queue>
#include "lib.hpp"

using namespace std;
using namespace chrono;

int max(int a, int b) { return (a > b) ? a : b; }

void mochilaBacktraking(std::vector<Item>& itens, int capacidade, int& melhorValor, int valorAtual, int pesoAtual, int index) {
    if (index == itens.size() || pesoAtual >= capacidade) {
        melhorValor = max(melhorValor, valorAtual);
        return;
    }

    if (pesoAtual + itens[index].peso <= capacidade) {
        mochilaBacktraking(itens, capacidade, melhorValor, valorAtual + itens[index].valor, pesoAtual + itens[index].peso, index + 1);
    }

    mochilaBacktraking(itens, capacidade, melhorValor, valorAtual, pesoAtual, index + 1);
}

Results backtrakingDriver (std::vector<Item>& itens, int capacidade){
        int resultadoPD = 0;

        auto start = high_resolution_clock::now();
        mochilaBacktraking(itens, capacidade, resultadoPD, 0, 0, 0);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        // SAVE DURATION TIME


        Results res;
        res.duration = duration.count();
        res.instance = capacidade;

    cout << "PROG - BACKTRAKING - DURATION: " << duration.count() << " SIZE: "<< resultadoPD<< endl;

    return res;
}

/**

// Implementação do algoritmo de backtracking
void mochilaBacktrackingRec(vector<Item>& itens, int capacidade, int& melhorValor, int valorAtual, int pesoAtual, int index) {
    if (index == itens.size() || pesoAtual >= capacidade) {
        melhorValor = max(melhorValor, valorAtual);
        return;
    }

    if (pesoAtual + itens[index].peso <= capacidade) {
        mochilaBacktrackingRec(itens, capacidade, melhorValor, valorAtual + itens[index].valor, pesoAtual + itens[index].peso, index + 1);
    }

    mochilaBacktrackingRec(itens, capacidade, melhorValor, valorAtual, pesoAtual, index + 1);
}

int mochilaBacktracking(vector<Item>& itens, int capacidade) {
    int melhorValor = 0;
    mochilaBacktrackingRec(itens, capacidade, melhorValor, 0, 0, 0);
    return melhorValor;
}

*/
