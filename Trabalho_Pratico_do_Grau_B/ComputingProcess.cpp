#include "ComputingProcess.h"
#include <iostream>
#include <iomanip> // para setar precisão de fracionarios
using namespace std;

// Construtor e destrutor
ComputingProcess::ComputingProcess(double val1, double val2, char operador)
	: Process(0) {
    this->val1 = val1;
    this->val2 = val2;
    this->operador = operador;
}
ComputingProcess::~ComputingProcess() {}

// Getters
double ComputingProcess::getVal1() {
    return val1;
}
double ComputingProcess::getVal2() {
    return val2;
}
char ComputingProcess::getOperador() {
    return operador;
}

// Setters
void ComputingProcess::setVal1(double val1) {
    this->val1 = val1;
}
void ComputingProcess::setVal2(double val2) {
    this->val2 = val2;
}
void ComputingProcess::setOperador(char operador) {
    this->operador = operador;
}

// Metodos

void ComputingProcess::soma() {
	std::cout << "Resultado: " << val1 + val2 << std::endl;
}
void ComputingProcess::subtracao() {
	std::cout << "Resultado: " << val1 - val2 << std::endl;
}
void ComputingProcess::multiplicacao() {
	std::cout << "Resultado: " << val1 * val2 << std::endl;
}
void ComputingProcess::divisao() {
	if (val2 != 0)
		std::cout << "Resultado: " << val1 / val2 << std::endl;
	else
		std::cout << "Erro: divisao por zero!" << std::endl;
}

void ComputingProcess::perguntaOperacao() {

    std::cout << std::fixed << std::setprecision(2); // define precisão para 2
    while (true) {
        std::cout << "Digite a expressao (ex: 5 + 3): ";
        std::cin >> val1 >> operador >> val2;  // lê val1, operador e val2 de uma vez

        switch (operador) {
        case '+':
            soma();
            return;
        case '-':
            subtracao();
            return;
        case '*':
            multiplicacao();
            return;
        case '/':
            divisao();
            return;
        default:
            std::cout << "Operador invalido!" << std::endl;
        }
    }
}
void ComputingProcess::execute() {
    cout << "Executando ReadingProcess..." << endl;
	perguntaOperacao();
}
