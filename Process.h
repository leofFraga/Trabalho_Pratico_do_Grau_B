// Uma classe abstrata que contem o metodo abstrato 'execute()'
#ifndef PROCESS_H
#define PROCESS_H
class Process
{
protected:
    int pid;
public:
    Process(int pid);
    virtual ~Process();

	// Getters
    int getPID() const;

	// Setters
    void setPID(int pid);

	// Metodos
    virtual void execute() = 0;

};

#endif
