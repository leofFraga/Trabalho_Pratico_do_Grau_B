//para gerenciar a fila de processos e implementar o menu.
//Menu de op��es:
//
//Criar processo
//Executar pr�ximo
//Executar processo espec�fico
//Salvar a fila de processos em arquivo
//Carregar a fila de processos de um arquivo
#ifndef SISTEMA_H
#define SISTEMA_H
#include <list>

class Sistema
{
private:
//std::list<typename T> processos;
public:
    Sistema();
    ~Sistema();
    void imprime_menu();
};

#endif
