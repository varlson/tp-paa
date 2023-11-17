// // algoritmos.cpp

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <chrono>
// #include <queue>
// #include "lib.hpp"

// using namespace std;
// using namespace chrono;

// // Definição da estrutura de um item
// // struct Item {
// //     int peso;
// //     int valor;
// // };

// // Implementação do algoritmo de programação dinâmica
// int mochilaDinamica(vector<Item>& itens, int capacidade) {
//     int n = itens.size();
//     vector<vector<int>> dp(n + 1, vector<int>(capacidade + 1, 0));

//     for (int i = 1; i <= n; ++i) {
//         for (int w = 0; w <= capacidade; ++w) {
//             if (itens[i - 1].peso <= w) {
//                 dp[i][w] = max(dp[i - 1][w], itens[i - 1].valor + dp[i - 1][w - itens[i - 1].peso]);
//             } else {
//                 dp[i][w] = dp[i - 1][w];
//             }
//         }
//     }

//     return dp[n][capacidade];
// }

// // Implementação do algoritmo de backtracking
// void mochilaBacktrackingRec(vector<Item>& itens, int capacidade, int& melhorValor, int valorAtual, int pesoAtual, int index) {
//     if (index == itens.size() || pesoAtual >= capacidade) {
//         melhorValor = max(melhorValor, valorAtual);
//         return;
//     }

//     if (pesoAtual + itens[index].peso <= capacidade) {
//         mochilaBacktrackingRec(itens, capacidade, melhorValor, valorAtual + itens[index].valor, pesoAtual + itens[index].peso, index + 1);
//     }

//     mochilaBacktrackingRec(itens, capacidade, melhorValor, valorAtual, pesoAtual, index + 1);
// }

// int mochilaBacktracking(vector<Item>& itens, int capacidade) {
//     int melhorValor = 0;
//     mochilaBacktrackingRec(itens, capacidade, melhorValor, 0, 0, 0);
//     return melhorValor;
// }

// // Implementação do algoritmo de branch-and-bound (BB)
// // struct NohBB {
// //     int nivel;
// //     int peso;
// //     int valor;
// //     double bound;

// //     bool operator<(const NohBB& outro) const {
// //         return bound < outro.bound;
// //     }
// // };

// double calculaBound(const vector<Item>& itens, int capacidade, int nivel, int peso, int valor) {
//     double bound = valor;
//     int pesoRestante = capacidade - peso;

//     while (nivel < itens.size() && pesoRestante > 0) {
//         if (itens[nivel].peso <= pesoRestante) {
//             bound += itens[nivel].valor;
//             pesoRestante -= itens[nivel].peso;
//         } else {
//             bound += (double)itens[nivel].valor / itens[nivel].peso * pesoRestante;
//             pesoRestante = 0;
//         }

//         ++nivel;
//     }

//     return bound;
// }

// int mochilaBranchAndBound(vector<Item>& itens, int capacidade) {
//     int n = itens.size();
//     sort(itens.begin(), itens.end(), [](const Item& a, const Item& b) {
//         return (double)a.valor / a.peso > (double)b.valor / b.peso;
//     });

//     priority_queue<NohBB> filaBB;
//     NohBB nohInicial{0, 0, 0, calculaBound(itens, capacidade, 0, 0, 0)};
//     filaBB.push(nohInicial);

//     int melhorValor = 0;

//     while (!filaBB.empty()) {
//         NohBB nohAtual = filaBB.top();
//         filaBB.pop();

//         if (nohAtual.bound > melhorValor) {
//             if (nohAtual.nivel < n) {
//                 // Inclui o próximo item
//                 if (nohAtual.peso + itens[nohAtual.nivel].peso <= capacidade) {
//                     NohBB filhoIncluso{
//                         nohAtual.nivel + 1,
//                         nohAtual.peso + itens[nohAtual.nivel].peso,
//                         nohAtual.valor + itens[nohAtual.nivel].valor,
//                         calculaBound(itens, capacidade, nohAtual.nivel + 1, nohAtual.peso + itens[nohAtual.nivel].peso, nohAtual.valor + itens[nohAtual.nivel].valor)
//                     };
//                     filaBB.push(filhoIncluso);
//                 }

//                 // Exclui o próximo item
//                 NohBB filhoExcluido{
//                     nohAtual.nivel + 1,
//                     nohAtual.peso,
//                     nohAtual.valor,
//                     calculaBound(itens, capacidade, nohAtual.nivel + 1, nohAtual.peso, nohAtual.valor)
//                 };
//                 filaBB.push(filhoExcluido);
//             } else {
//                 melhorValor = max(melhorValor, nohAtual.valor);
//             }
//         }
//     }

//     return melhorValor;
// }



// // Função para gerar instâncias aleatórias
// void gerarInstanciaAleatoria(ofstream& arquivo, int n, int capacidade) {
//     arquivo << capacidade << "\n";

//     srand(static_cast<unsigned>(time(0)));

//     for (int i = 0; i < n; ++i) {
//         int peso = rand() % 30 + 1;
//         int valor = rand() % 100 + 1;
//         arquivo << peso << "\t" << valor << "\n";
//     }
// }

// //----------------


// int max(int a, int b) { return (a > b) ? a : b; }

// int knapSack(std::vector<Item>& itens, int capacidade) {
//     int n = itens.size();

//     // Inicializando a tabela de memoização
//     std::vector<std::vector<int>> tabela(n + 1, std::vector<int>(capacidade + 1, 0));

//     // Preenchendo a tabela de baixo para cima
//     for (int i = 1; i <= n; ++i) {
//         for (int w = 0; w <= capacidade; ++w) {
//             if (itens[i - 1].peso <= w) {
//                 tabela[i][w] = std::max(itens[i - 1].valor + tabela[i - 1][w - itens[i - 1].peso], tabela[i - 1][w]);
//             } else {
//                 tabela[i][w] = tabela[i - 1][w];
//             }
//         }
//     }

//     return tabela[n][capacidade];
// }


// vector<Item> fileReader (string fileName){
//     vector<Item> itens;
//     ifstream instancia(fileName);

//     int capacidade;
//     instancia >> capacidade;

//     int peso, valor;
//     while (instancia >> peso >> valor) {
//         itens.push_back({peso, valor});
//     }
//     return itens;
// }




// int main(){

//     vector<Item> itens;
//     itens = fileReader("output/instance_10/file_3.txt");
//     for(int i =0; i < itens.size(); i++){
//         cout << itens[i].peso << " "<< itens[i].valor <<endl;
//     }

//     return 0;
// }