#include "Process.h"
using namespace std;
Process::Process(int pid) {
    this->pid = pid;
}
Process::~Process() {}

int Process::getPID() {
    return pid;
}

void Process::setPID(int pid) {
    this->pid = pid;
}