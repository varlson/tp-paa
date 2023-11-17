// main.cpp

// BACKTRAKING COMENTADO, NÃO TA RODANDO

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "lib.hpp"

using namespace std;
using namespace chrono;

int main() {
    // Experimento 1: Variando n, mantendo W=100
    vector<Item> itens;
    // int capacidadeFixa = 100;
    int capacidade;
    cout << "Experimento 1" << endl;
    for (int n = 100; n <= 5000; n *= 2) {

        // GERANDO DADOS ALEATOORIOS

        // LENDO DADAOS DE ARQUIVO
        
        // EXECUTANDO ALGORITMO DINAMICO

        // EXECUTANDO ALGORITMO BACKTRAKING

        // EXECUTANDO ALGORITMO BRANCH AND BOUND


        // TESTES
        randomNItemGenerator(n);
        itens = fileReader("output/instance_"+to_string(n)+"/file_1.txt", &capacidade);
        dinamicaDriver(itens, capacidade);
        backtrakingDriver(itens, capacidade);
        branchAndBoundDriver(itens, capacidade);

        cout << "-----------------------------------------\n";
    }
    
    

    return 0;
}
