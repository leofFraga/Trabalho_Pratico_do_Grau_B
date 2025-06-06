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
    void execute();
    int getPID();
    void setPID(int pid);
};

#endif
