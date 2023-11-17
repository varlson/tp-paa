#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <queue>
#include "lib.hpp"

using namespace std;
using namespace chrono;


double calculaBound(const vector<Item>& itens, int capacidade, int nivel, int peso, int valor) {
    double bound = valor;
    int pesoRestante = capacidade - peso;

    while (nivel < itens.size() && pesoRestante > 0) {
        if (itens[nivel].peso <= pesoRestante) {
            bound += itens[nivel].valor;
            pesoRestante -= itens[nivel].peso;
        } else {
            bound += (double)itens[nivel].valor / itens[nivel].peso * pesoRestante;
            pesoRestante = 0;
        }

        ++nivel;
    }

    return bound;
}

int mochilaBranchAndBound(vector<Item>& itens, int capacidade) {
    int n = itens.size();
    sort(itens.begin(), itens.end(), [](const Item& a, const Item& b) {
        return (double)a.valor / a.peso > (double)b.valor / b.peso;
    });

    priority_queue<NohBB> filaBB;
    NohBB nohInicial{0, 0, 0, calculaBound(itens, capacidade, 0, 0, 0)};
    filaBB.push(nohInicial);

    int melhorValor = 0;

    while (!filaBB.empty()) {
        NohBB nohAtual = filaBB.top();
        filaBB.pop();

        if (nohAtual.bound > melhorValor) {
            if (nohAtual.nivel < n) {
                // Inclui o próximo item
                if (nohAtual.peso + itens[nohAtual.nivel].peso <= capacidade) {
                    NohBB filhoIncluso{
                        nohAtual.nivel + 1,
                        nohAtual.peso + itens[nohAtual.nivel].peso,
                        nohAtual.valor + itens[nohAtual.nivel].valor,
                        calculaBound(itens, capacidade, nohAtual.nivel + 1, nohAtual.peso + itens[nohAtual.nivel].peso, nohAtual.valor + itens[nohAtual.nivel].valor)
                    };
                    filaBB.push(filhoIncluso);
                }

                // Exclui o próximo item
                NohBB filhoExcluido{
                    nohAtual.nivel + 1,
                    nohAtual.peso,
                    nohAtual.valor,
                    calculaBound(itens, capacidade, nohAtual.nivel + 1, nohAtual.peso, nohAtual.valor)
                };
                filaBB.push(filhoExcluido);
            } else {
                melhorValor = max(melhorValor, nohAtual.valor);
            }
        }
    }

    return melhorValor;
}



void branchAndBoundDriver(vector<Item>& itens, int capacidade){
    auto start = high_resolution_clock::now();
    int resultadoPD = mochilaBranchAndBound(itens, capacidade);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "PROG - BRANCH AND BOUND - DURATION: "<< duration.count() << " - SIZE: "<< resultadoPD<< endl;


    //SAVE DURATION
}