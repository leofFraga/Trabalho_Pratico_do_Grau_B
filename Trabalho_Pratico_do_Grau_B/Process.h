// Uma classe abstrata que contem o metodo abstrato 'execute()'
#ifndef PROCESS_H
#define PROCESS_H
class Process
{
private:
    int pid;
public:
    Process(int pid);
    ~Process();
<<<<<<< Updated upstream
    void execute();
    int getPID();
    void setPID(int pid);
=======

	// Getters
    int getPID() const;

	// Setters
    void setPID(int pid);

	// Metodos
    virtual void execute() = 0;
>>>>>>> Stashed changes
};

#endif
