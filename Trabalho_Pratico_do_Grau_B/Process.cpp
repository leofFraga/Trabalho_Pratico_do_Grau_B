#include "Process.h"
#include <iostream>
using namespace std;
// Construtor e destrutor
Process::Process(int pid) {
    this->pid = pid;
}
Process::~Process() {}

// Getters
int Process::getPID() {
    return pid;
}

// Setters
void Process::setPID(int pid) {
    this->pid = pid;
}

// Metodos
void Process::execute() {
	// Este método deve ser implementado nas classes derivadas
	cout << "Executando processo com PID: " << pid << endl;
}