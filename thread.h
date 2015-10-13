#include <stdio.h>
#include <stdlib.h>
#include "q.h"


void start_thread(void(*function)(void));
void run();
void yield();

TCB_t *runQ = NULL;


void start_thread(void (*function)(void)) {
    TCB_t *item = create_node();
    void *stack = (void*)malloc(8192);
    init_TCB(item, function, stack, 8192);
    if (runQ == NULL)
    {
        InitQ(item);
        runQ = item;
    }
    else {
        printf("Wont print\n");
        AddQ(runQ, item);
    }
}

void run()
{   ucontext_t from, to, parent;
    parent = from;
    getcontext(&parent); // main's context
    if (runQ)
    {
        printf("runQ is not NULL, %u\n", sizeof(runQ));
    }
    to = runQ->context;
    swapcontext(&parent, &to);
}
void yield() // similar to run
{
    ucontext_t from, to;
    getcontext(&from);
    runQ->context = from;
    RotateQ(&runQ);
    to = runQ->context;
    swapcontext(&from, &to);

}
