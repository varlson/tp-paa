#ifndef  HEADER_H
#define HEADER_H

#include <vector>
#include <algorithm>
#include <chrono>
#include <queue>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;
using namespace chrono;


struct NohBB {
    int nivel;
    int peso;
    int valor;
    double bound;

    bool operator<(const NohBB& outro) const {
        return bound < outro.bound;
    }
};

struct Item {
    int peso;
    int valor;
};


double calculaBound(const vector<Item>& itens, int capacidade, int nivel, int peso, int valor);
int mochilaBacktracking(vector<Item>& itens, int capacidade);
void mochilaBacktrackingRec(vector<Item>& itens, int capacidade, int& melhorValor, int valorAtual, int pesoAtual, int index);
int mochilaDinamica(vector<Item>& itens, int capacidade);
void gerarInstanciaAleatoria(ofstream& arquivo, int n, int capacidade);
int mochilaBranchAndBound(vector<Item>& itens, int capacidade);

// nova versao
int mochilaBacktraking(std::vector<Item>& itens, int capacidade);
void backtrakingDriver (std::vector<Item>& itens, int capacidade);
void branchAndBoundDriver(vector<Item>& itens, int capacidade);
void dinamicaDriver(vector<Item>& itens, int capacidade);
void randomNItemGenerator(int n);
void randomWeightGenerator(int w);
vector<Item> fileReader (string fileName, int * capacidade);
#endif