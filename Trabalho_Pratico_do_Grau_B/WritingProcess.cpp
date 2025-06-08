#include "WritingProcess.h"
#include <string>
using namespace std;

// Construtor e destrutor
WritingProcess::WritingProcess() : Process(0) {}
WritingProcess::~WritingProcess() {}

void WritingProcess::escreveExpressao(const string& expressao) {
    // Abrir o arquivo no modo append para não sobrescrever
        ofstream file("computation.txt", ios::app);
        if(!file.is_open()) {
        // Tratar erro na abertura do arquivo, se necessário
            throw std::runtime_error("Nao foi possivel abrir computation.txt para escrita!");
        }
        // Escrever a expressão seguida de uma nova linha
        file << expressao << endl;
        // Fechar o arquivo após a escrita
        file.close();
}

void WritingProcess::execute() {
	cout << "Executando WritingProcess..." << endl;
}