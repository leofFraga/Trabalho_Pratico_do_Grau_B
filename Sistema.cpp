#include "Sistema.h"
#include "ComputingProcess.h"
#include "WritingProcess.h"
#include "ReadingProcess.h"
#include "PrintingProcess.h"
#include <iostream>
#include <fstream>
using namespace std;

// Construtor
Sistema::Sistema() {
    pidCounter = 1;
}

// Destrutor
Sistema::~Sistema() {
    for (auto p : fila)
        delete p;
    fila.clear();
}

// Criar processo
void Sistema::criarProcesso() {
    int tipo;
    cout << "Tipo de processo:\n[1] Writing\n[2] Reading\n[3] Printing\n[4] Computing\nEscolha: ";
    cin >> tipo;

    switch (tipo) {
        case 1: {
            string expressao;
            cin.ignore(); // limpa o buffer
            cout << "Digite a expressao (ex: 5 + 3): ";
            getline(cin, expressao);
            fila.push_back(new WritingProcess(pidCounter++, expressao));
            break;
        }
        case 2: {
            Process* p = new ReadingProcess(pidCounter++, fila);  // passar fila principal
            fila.push_back(p);  // adiciona à fila para execução posterior
            break;
        }
        case 3:
            fila.push_back(new PrintingProcess(pidCounter++, fila));
            break;
        case 4: {
            double v1, v2;
            char op;
            cout << "Digite a expressao (ex: 5 + 3): ";
            cin >> v1 >> op >> v2;
            fila.push_back(new ComputingProcess(pidCounter++, v1, v2, op));
            break;
        }
        default:
            cout << "Tipo invalido.\n";
    }
}

// Executar próximo processo da fila
void Sistema::executarProximo() {
    if (fila.empty()) {
        cout << "Fila vazia.\n";
        return;
    }

    Process* p = fila.front();
    p->execute();
    delete p;
    fila.erase(fila.begin());
}

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

// Menu de opções
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
