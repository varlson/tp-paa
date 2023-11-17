// // main.cpp

// // BACKTRAKING COMENTADO, NÃO TA RODANDO

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// #include <chrono>
// #include "lib.hpp"
// // #include "algoritmos.cpp"

// using namespace std;
// using namespace chrono;

// int main() {
//     // Experimento 1: Variando n, mantendo W=100
//     int capacidadeFixa = 100;

//     cout << "Experimento 1" << endl;

//     for (int n = 100; n <= 25600; n *= 2) {
//         ofstream arquivo("output/instancia_n_" + to_string(n) + "_W_" + to_string(capacidadeFixa) + ".txt");
//         for(int i = 0; i < 20; ++i)
//             gerarInstanciaAleatoria(arquivo, n, capacidadeFixa);
//         arquivo.close();

//         vector<Item> itens;
//         ifstream instancia("output/instancia_n_" + to_string(n) + "_W_" + to_string(capacidadeFixa) + ".txt");

//         int capacidade;
//         instancia >> capacidade;

//         int peso, valor;
//         while (instancia >> peso >> valor) {
//             itens.push_back({peso, valor});
//         }
//         instancia.close();

//         // Executar e medir tempo para os algoritmos
//         auto start = high_resolution_clock::now();
//         int resultadoPD = mochilaDinamica(itens, capacidade);
//         auto stop = high_resolution_clock::now();
//         auto duration = duration_cast<milliseconds>(stop - start);
//         cout << "Programação Dinâmica - Instância n=" << n << ": " << resultadoPD << " (tempo: " << duration.count() << "ms)\n";

//         start = high_resolution_clock::now();
//         resultadoPD = knapSack(itens, capacidade);
//         stop = high_resolution_clock::now();
//         duration = duration_cast<milliseconds>(stop - start);
//         cout << "Programação Backtraking - Instância n=" << n << ": " << resultadoPD << " (tempo: " << duration.count() << "ms)\n";

        



//         /*start = high_resolution_clock::now();
//         int resultadoBT = mochilaBacktracking(itens, capacidade);
//         stop = high_resolution_clock::now();
//         duration = duration_cast<milliseconds>(stop - start);
//         cout << "Backtracking - Instância n=" << n << ": " << resultadoBT << " (tempo: " << duration.count() << "ms)\n";
//         */
//         start = high_resolution_clock::now();
//         int resultadoBB = mochilaBranchAndBound(itens, capacidade);
//         stop = high_resolution_clock::now();
//         duration = duration_cast<milliseconds>(stop - start);
//         cout << "Branch-and-Bound - Instância n=" << n << ": " << resultadoBB << " (tempo: " << duration.count() << "ms)\n";
//     }

//     // Experimento 2: Mantendo n=400, variando W
//     /*int nFixo = 400;

//     cout << "Experimento 2" << endl;

//     for (int capacidade = 100; capacidade <= 25600; capacidade *= 2) {
//         ofstream arquivo("instancia_n_" + to_string(nFixo) + "_W_" + to_string(capacidade) + ".txt");
//         for(int i = 0; i < 20; ++i)
//             gerarInstanciaAleatoria(arquivo, nFixo, capacidade);
//         arquivo.close();

//         vector<Item> itens;
//         ifstream instancia("instancia_n_" + to_string(nFixo) + "_W_" + to_string(capacidade) + ".txt");

//         int capacidadeLida;
//         instancia >> capacidadeLida;

//         int peso, valor;
//         while (instancia >> peso >> valor) {
//             itens.push_back({peso, valor});
//         }
//         instancia.close();

//         // Executar e medir tempo para os algoritmos
//         auto start = high_resolution_clock::now();
//         int resultadoPD = mochilaDinamica(itens, capacidadeLida);
//         auto stop = high_resolution_clock::now();
//         auto duration = duration_cast<milliseconds>(stop - start);
//         cout << "Programação Dinâmica - Instância W=" << capacidade << ": " << resultadoPD << " (tempo: " << duration.count() << "ms)\n";

//         start = high_resolution_clock::now();
//         int resultadoBT = mochilaBacktracking(itens, capacidadeLida);
//         stop = high_resolution_clock::now();
//         duration = duration_cast<milliseconds>(stop - start);
//         cout << "Backtracking - Instância W=" << capacidade << ": " << resultadoBT << " (tempo: " << duration.count() << "ms)\n";
        
//         start = high_resolution_clock::now();
//         int resultadoBB = mochilaBranchAndBound(itens, capacidadeLida);
//         stop = high_resolution_clock::now();
//         duration = duration_cast<milliseconds>(stop - start);
//         cout << "Branch-and-Bound - Instância W=" << capacidade << ": " << resultadoBB << " (tempo: " << duration.count() << "ms)\n";
//     }*/

//     return 0;
// }
