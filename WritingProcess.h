// executa a grava��o de uma express�o em um arquivo de processos (chamado computation.txt)
#ifndef WRITINGPROCESS_H
#define WRITINGPROCESS_H
#include "Process.h"
#include <fstream>

class WritingProcess : public Process
{
private:
	std::string expressao;
public:

	// Construtor e destrutor
	WritingProcess(int pid, const std::string &expressao);
	~WritingProcess();

	// Metodos

    void escreveExpressao(const std::string& expressao);
    void execute() override;
};

#endif
