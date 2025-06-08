// Uma classe abstrata que contem o metodo abstrato 'execute()'
#ifndef PROCESS_H
#define PROCESS_H
class Process
{
private:
    int pid;
public:
	// Construtor e destrutor
    Process(int pid);
    ~Process();

	// Getters
    int getPID();

	// Setters
    void setPID(int pid);

	// Metodos
    virtual void execute();
};

#endif
