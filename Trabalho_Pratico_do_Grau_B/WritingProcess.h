// executa a grava��o de uma express�o em um arquivo de processos (chamado computation.txt)
#ifndef WRITINGPROCESS_H
#define WRITINGPROCESS_H
#include "Process.h"
#include <fstream>

class WritingProcess : public Process
{
public:
    void escreveExpressao(const std::string& expressao);
};

#endif