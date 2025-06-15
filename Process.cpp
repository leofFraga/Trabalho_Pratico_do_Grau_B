#include "Process.h"
#include <iostream>

using namespace std;

Process::Process(int pid) {
    this->pid = pid;
}
Process::~Process() {}

int Process::getPID () const{
    return pid;
}
void Process::setPID(int pid) {
    this->pid = pid;
}

// Metodos
void Process::execute() {
	// Este m�todo deve ser implementado nas classes derivadas
	cout << "Executando processo com PID: " << pid << endl;

}
