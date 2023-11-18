// main.cpp

// BACKTRAKING COMENTADO, NÃO TA RODANDO

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "lib.hpp"
#define MAX 5000000

using namespace std;
using namespace chrono;

int main() {
    // Experimento 1: Variando n, mantendo W=100
    vector<Item> itens;
    // int capacidadeFixa = 100;
    int capacidade;
    cout << "Experimento 1" << endl;

    ofstream dinamyc("results/n_increasing/dinamyc.txt"); 
    ofstream backtraking("results/n_increasing/backtraking.txt"); 
    ofstream branchAndAbound("results/n_increasing/branchAndAbound.txt"); 

    for (int n = 100; n <= MAX; n *= 2) {
        
        cout << "Experimento - 1 - Instance " << n << endl;


        // GERANDO DADOS ALEATOORIOS

        // LENDO DADAOS DE ARQUIVO
        
        // EXECUTANDO ALGORITMO DINAMICO

        // EXECUTANDO ALGORITMO BACKTRAKING

        // EXECUTANDO ALGORITMO BRANCH AND BOUND


        randomNItemGenerator(n);
        vector<Results> dinamicResults, backtrakingResults, branchAndBoundResults;

        for(int i=0; i<20; i++){
            itens = fileReader("output/n_increasing/instance_"+to_string(n)+"/file_"+to_string(i+1)+".txt", &capacidade);
            dinamicResults.push_back(dinamicaDriver(itens, capacidade));
            backtrakingResults.push_back(backtrakingDriver(itens, capacidade));
            branchAndBoundResults.push_back(branchAndBoundDriver(itens, capacidade));
        }


        saveResults(dinamicResults, dinamyc, n);
        saveResults(backtrakingResults, backtraking, n);
        saveResults(branchAndBoundResults, branchAndAbound, n);

    }
    

    dinamyc.close();
    backtraking.close();
    branchAndAbound.close();


    cout << "Experimento 2" << endl;

    dinamyc.open("results/w_increasing/dinamyc.txt"); 
    backtraking.open("results/w_increasing/backtraking.txt"); 
    branchAndAbound.open("results/w_increasing/branchAndAbound.txt"); 

    for (int n = 100; n <= MAX; n *= 2) {
        
        cout << "Experimento - 2 - Instance " << n << endl;


        // GERANDO DADOS ALEATOORIOS

        // LENDO DADAOS DE ARQUIVO
        
        // EXECUTANDO ALGORITMO DINAMICO

        // EXECUTANDO ALGORITMO BACKTRAKING

        // EXECUTANDO ALGORITMO BRANCH AND BOUND


        randomWeightGenerator(n);
        vector<Results> dinamicResults, backtrakingResults, branchAndBoundResults;

        for(int i=0; i<20; i++){
            itens = fileReader("output/w_increasing/weight_"+to_string(n)+"/file_"+to_string(i+1)+".txt", &capacidade);
            dinamicResults.push_back(dinamicaDriver(itens, capacidade));
            backtrakingResults.push_back(backtrakingDriver(itens, capacidade));
            branchAndBoundResults.push_back(branchAndBoundDriver(itens, capacidade));


            // cout<<"Size of "<< itens.size()<<endl;

            // for(int j=0; j<20; j++){
            //     cout << itens[j].peso << itens[j].valor << "\n";
            //  }

        }
        saveResults(dinamicResults, dinamyc, n);
        saveResults(backtrakingResults, backtraking, n);
        saveResults(branchAndBoundResults, branchAndAbound, n);

    }
    

    dinamyc.close();
    backtraking.close();
    branchAndAbound.close();

    return 0;
}
