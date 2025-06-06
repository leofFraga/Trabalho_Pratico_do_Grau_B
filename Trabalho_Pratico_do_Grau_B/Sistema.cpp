#include "Sistema.h"
#include <iostream>
using namespace std;

Sistema::Sistema() {};
Sistema::~Sistema() {};

void Sistema::imprime_menu() {
    cout << "Menu Principal" << endl;
    cout << "1. Criar Processo\n2. Executar proximo\n3. Executar processo especifico\n4. Salvar a fila em arquivo\n5. Carregar a fila de um arquivo" << endl;    
}