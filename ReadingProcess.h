//L� todas as linhas do arquivo computation.txt. Para cada linha lida, cria um novo ComputingProcess e o adiciona � fila. Depois, limpa o arquivo.
#ifndef READINGPROCESS_H
#define READINGPROCESS_H

#include "Process.h"
#include <vector>
#include <string>
#include "ComputingProcess.h"

class ReadingProcess : public Process{
private:
    std::vector<Process*>& fila;
public:

    // Construtor recebe referência para o vetor de processos do sistema
    ReadingProcess(int pid, std::vector<Process*>& fila);

    // Método para ler e carregar processos do arquivo
    void execute() override;


};

#endif

