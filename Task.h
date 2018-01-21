//
// Created by hadar on 21/01/18.
//

#ifndef SERVER_TASK_H
#define SERVER_TASK_H



class Task {
public:
    /**
     * constructor
     * @param func
     * @param arg
     */
    Task(void*(*func)(void *arg),void* arg):
            func(func),arg(arg){}
    /**
     * call func
     */
    void execute(){
        func(arg);

    }
/**
 *distructor
 */
    virtual ~Task(){}

private:
    void *(*func)(void *arg);
    void *arg;

};


#endif //SERVER_TASK_H
