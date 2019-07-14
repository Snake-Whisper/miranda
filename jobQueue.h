#ifndef JOBQUEUE_H_INCLUDED
#define JOBQUEUE_H_INCLUDED


typedef struct Job {
    unsigned int jobID;
    char* operation;
    struct Job *left;
    struct Job *right;
} Job;

Job root;

static unsigned long nextJobID();
static void insert(Job*, Job*);
void test();



#endif // JOBQUEUE_H_INCLUDED
