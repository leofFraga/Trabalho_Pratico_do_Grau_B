#include "PrintingProcess.h"
#include <iostream>

PrintingProcess::PrintingProcess(int pid, const std::vector<Process*> &fila)
: Process(pid), fila(fila) {}

void PrintingProcess::execute() {
    std::cout << "Fila atual:\n";
    for (auto p : fila) {
        std::cout << "PID: " << p->getPID() << std::endl;
    }
}
