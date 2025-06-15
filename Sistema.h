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
#include <vector>
#include "Process.h"

class Sistema {
private:
    std::vector<Process*> fila;
    int pidCounter;
public:
    Sistema();
    ~Sistema();
    void criarProcesso();
    void executarProximo();
    void executarEspecifico();
    void salvarFila();
    void carregarFila();
    void imprimirFila();
    void menu();
};
#endif
