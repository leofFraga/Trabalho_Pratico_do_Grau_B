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
    ComputingProcess(int pid,double val1, double val2, char operador);
    ~ComputingProcess();
    double getVal1();
    void setVal1(double val1);
    double getVal2();
    void setVal2(double val2);
    char getOperador();
    void setOperador(char operador);
    void execute() override;
    void perguntaOperacao();
};

#endif
