#include "lib.hpp"
#include <filesystem>
namespace fs = std::filesystem;

void randomNItemGenerator(int n){

    string folder = "output/n_increasing/instance_"+to_string(n);
    creteFolder(folder);
    
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

    string folder = "output/w_increasing/weight_"+to_string(w);
    creteFolder(folder);
    
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
    instancia.close();
    return itens;
}




bool creteFolder(string filePath){

  if (!fs::exists(filePath)) {
        // Tentar criar o diretório
        if (fs::create_directory(filePath)) {
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }



    fs::create_directory(filePath);
}


void saveResults(std::vector<Results> &res, ofstream& arquivo, int instanceSize){
    int sum=0;
    for(int i=0; i<20; i++){
        sum += res[i].duration;
    }
    float mean = sum/20;

    arquivo << mean << "\t" << instanceSize << "\n"; 
}   