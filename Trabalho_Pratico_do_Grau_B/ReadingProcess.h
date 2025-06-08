//L� todas as linhas do arquivo computation.txt. Para cada linha lida, cria um novo ComputingProcess e o adiciona � fila. Depois, limpa o arquivo.
#ifndef READINGPROCESS_H
#define READINGPROCESS_H

#include <vector>
#include <string>
#include "ComputingProcess.h"
#include "Process.h" // Include the base class header

class ReadingProcess : public Process {
private:
    std::vector<ComputingProcess>& processos;
public:
    ReadingProcess(std::vector<ComputingProcess>& processosSistema);

    void load(const std::string& filename = "computation.txt");

    void execute() override;
};

#endif

