//L� todas as linhas do arquivo computation.txt. Para cada linha lida, cria um novo ComputingProcess e o adiciona � fila. Depois, limpa o arquivo.
#ifndef READINGPROCESS_H
#define READINGPROCESS_H

#include <vector>
#include <string>
#include "ComputingProcess.h"

class ReadingProcess {
public:
    // Construtor recebe referência para o vetor de processos do sistema
    ReadingProcess(std::vector<ComputingProcess>& processosSistema);

    // Método para ler e carregar processos do arquivo
    void load(const std::string& filename = "computation.txt");

private:
    std::vector<ComputingProcess>& processos;
};

#endif

