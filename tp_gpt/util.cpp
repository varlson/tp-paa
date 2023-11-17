#include "lib.hpp"
#include <filesystem>
namespace fs = std::filesystem;



void randomNItemGenerator(int n){

    string folder = "output/instance_"+to_string(n);
    fs::create_directory(folder);
    
    for(int i=0; i<20;i++){
        string filePath = folder+"/file_"+to_string(i+1)+".txt";
        ofstream arquivo(filePath);

        arquivo << "100\n";

        for(int j=0; j<n;j++){
            int peso = rand() % 30 + 1;
            int valor = rand() % 100 + 1;
            arquivo << peso << "\t" << valor << "\n";
        }
        arquivo.close();
    }
}



void randomWeightGenerator(int w){

    string folder = "output/weight_"+to_string(w);
    fs::create_directory(folder);
    
    for(int i=0; i<20;i++){
        string filePath = folder+"/file_"+to_string(i+1)+".txt";
        ofstream arquivo(filePath);

        arquivo << to_string(w)+"\n";

        for(int j=0; j<400;j++){
            int peso = rand() % 30 + 1;
            int valor = rand() % 100 + 1;
            arquivo << peso << "\t" << valor << "\n";
        }
        arquivo.close();
    }
}


vector<Item> fileReader (string fileName, int * capacidade){
    vector<Item> itens;
    ifstream instancia(fileName);

    instancia >> (*capacidade);

    int peso, valor;
    while (instancia >> peso >> valor) {
        itens.push_back({peso, valor});
    }
    return itens;
}





// int main(){
//     // randomNItemGenerator(10);
//     randomWeightGenerator(400);
//     return 0;
// }