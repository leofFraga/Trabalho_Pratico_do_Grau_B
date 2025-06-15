#include "ComputingProcess.h"
#include <iostream>
#include <iomanip> // para setar precisão de fracionarios
using namespace std;

ComputingProcess::ComputingProcess(int pid, double val1, double val2, char operador)
: Process(pid), val1(val1), val2(val2), operador(operador) {}
ComputingProcess::~ComputingProcess() {}

double ComputingProcess::getVal1() {
    return val1;
}

double ComputingProcess::getVal2() {
    return val2;
}

void ComputingProcess::setVal1(double val1) {
    this->val1 = val1;
}

void ComputingProcess::setVal2(double val2) {
    this->val2 = val2;
}

char ComputingProcess::getOperador() {
    return operador;
}

void ComputingProcess::setOperador(char operador) {
    this->operador = operador;
}

void ComputingProcess::perguntaOperacao() {
    std::cout << "Digite a expressão (ex: 5 + 3): ";
    std::cin >> val1 >> operador >> val2;  // lê val1, operador e val2 de uma vez

    std::cout << std::fixed << std::setprecision(2); // define precisão para 2

    switch (operador) {
        case '+':
            std::cout << "Resultado: " << val1 + val2 << std::endl;
            break;
        case '-':
            std::cout << "Resultado: " << val1 - val2 << std::endl;
            break;
        case '*':
            std::cout << "Resultado: " << val1 * val2 << std::endl;
            break;
        case '/':
            if (val2 != 0)
                std::cout << "Resultado: " << val1 / val2 << std::endl;
            else
                std::cout << "Erro: divisao por zero!" << std::endl;
            break;
        default:
            std::cout << "Operador invalido!" << std::endl;
    }

}
void ComputingProcess::execute(){
    cout << "Executando ComputingProcess: ";
    perguntaOperacao();
}
