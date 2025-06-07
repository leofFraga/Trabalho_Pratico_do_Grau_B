#include "ReadingProcess.h"
#include <fstream>
#include <sstream>
#include <iostream>

ReadingProcess::ReadingProcess(std::vector<ComputingProcess>& processosSistema)
    : processos(processosSistema) {}

void ReadingProcess::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
        return;
    }

    std::string linha;
    while (std::getline(file, linha)) {
        if (linha.empty()) continue;

        double val1 = 0.0, val2 = 0.0;
        char operador = 0;

        std::istringstream iss(linha);
        if (!(iss >> val1 >> operador >> val2)) {
            std::cerr << "Formato inválido na linha: " << linha << std::endl;
            continue;
        }

        ComputingProcess proc(val1, val2, operador);
        processos.push_back(proc);
    }
    file.close();

    // Limpa o conteúdo do arquivo após a leitura
    std::ofstream ofs(filename, std::ios::trunc);
    if (!ofs.is_open()) {
        std::cerr << "Erro ao limpar o arquivo." << std::endl;
    }
    ofs.close();
}
