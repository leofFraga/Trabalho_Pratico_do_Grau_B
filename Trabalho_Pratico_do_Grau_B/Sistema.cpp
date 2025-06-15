#include "Sistema.h"
#include "ComputingProcess.h"
#include "WritingProcess.h"
#include "ReadingProcess.h"
#include "PrintingProcess.h"
#include <iostream>
#include <fstream>

using namespace std;

// Executar um processo específico por PID
void Sistema::executarEspecifico() {
    if (fila.empty()) {
        cout << "Fila vazia.\n";
        return;
    }
    
    int pid;
    cout << "Digite o PID a executar: ";
    cin >> pid;

    bool encontrado = false;
    for (size_t i = 0; i < fila.size(); ++i) {
        if (fila[i]->getPID() == pid) {
            fila[i]->execute();
            delete fila[i];
            fila.erase(fila.begin() + i);
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
        cout << "Processo com PID " << pid << " nao encontrado.\n";
}

// Salvar fila atual em arquivo
void Sistema::salvarFila() {
    ofstream file("fila.txt");
    if (!file) {
        cerr << "Erro ao salvar fila.\n";
        return;
    }

    for (auto p : fila) {
        file << p->getPID() << endl;
    }
    file.close();
    cout << "Fila salva com sucesso.\n";
}

// Carregar fila de arquivo
void Sistema::carregarFila() {
    ifstream file("fila.txt");
    if (!file) {
        cerr << "Erro ao abrir fila.txt.\n";
        return;
    }

    int pid;
    while (file >> pid) {
        fila.push_back(new PrintingProcess(pid, fila));
    }
    file.close();
    cout << "Fila carregada com sucesso.\n";
}

// Imprimir fila
void Sistema::imprimirFila() {
    if (fila.empty()) {
        cout << "Fila vazia.\n";
        return;
    }

    cout << "Fila atual de processos:\n";
    for (auto p : fila) {
        cout << "PID: " << p->getPID() << endl;
    }
}


void Sistema::menu() {
    int opcao;
    do {
        cout << "\n[1] Criar processo\n[2] Executar próximo\n[3] Executar específico\n[4] Salvar fila\n[5] Carregar fila\n[6] Imprimir fila\n[7] Sair\n";
        cin >> opcao;
        switch (opcao) {
            case 1: criarProcesso(); break;
            case 2: executarProximo(); break;
            case 3: executarEspecifico(); break;
            case 4: salvarFila(); break;
            case 5: carregarFila(); break;
            case 6: imprimirFila(); break;
            case 7: cout << "Encerrando...\n"; break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 7);
}