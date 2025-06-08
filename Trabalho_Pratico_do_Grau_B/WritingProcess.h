// executa a grava��o de uma express�o em um arquivo de processos (chamado computation.txt)
#ifndef WRITINGPROCESS_H
#define WRITINGPROCESS_H
#include "Process.h"
#include <iostream> 
#include <fstream>

class WritingProcess : public Process
{
public:
	// Construtor e destrutor
	WritingProcess();
	~WritingProcess();

	// Metodos
    void escreveExpressao(const std::string& expressao);

	void execute() override;
};

#endif