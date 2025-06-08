//Executa o c�lculo de uma express�o e imprime o resultado do c�lculo.
#ifndef COMPUTINGPROCESS_H
#define COMPUTINGPROCESS_H
#include "Process.h"

class ComputingProcess : public Process
{
private:
    double val1, val2;
    char operador;
public:
	// Construtor e destrutor
    ComputingProcess(double val1, double val2, char operador);
    ~ComputingProcess();

	// Getters
    double getVal1();
    double getVal2();
    char getOperador();

	// Setters
    void setVal1(double val1);
    void setVal2(double val2);
    void setOperador(char operador);

    // Metodos
	void soma();
	void subtracao();
	void multiplicacao();
	void divisao();

    void perguntaOperacao();
    void execute() override;
};

#endif
