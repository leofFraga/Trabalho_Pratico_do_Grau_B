#include "Process.h"
using namespace std;
Process::Process(int pid) {
    this->pid = pid;
}
Process::~Process() {}

<<<<<<< Updated upstream
int Process::getPID() {
=======
// Getters
int Process::getPID () const{
>>>>>>> Stashed changes
    return pid;
}

void Process::setPID(int pid) {
    this->pid = pid;
<<<<<<< Updated upstream
=======
}

// Metodos
void Process::execute() {
	// Este m�todo deve ser implementado nas classes derivadas
	cout << "Executando processo com PID: " << pid << endl;
>>>>>>> Stashed changes
}