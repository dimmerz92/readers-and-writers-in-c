#ifndef MAIN_HEADER_FILE
#define MAIN_HEADER_FILE

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define RAND_RANGE 10

struct shared_data {
    int decrementer;
    int incrementer;
    int writers;
    int sum;
};

typedef struct {
    int id;
    int incdec;
} writer_metadata;

extern struct shared_data shared;
extern pthread_mutex_t w_mutex;
extern pthread_cond_t w_cond;
extern pthread_mutex_t r_mutex;
extern pthread_cond_t r_cond;
extern int reader_count;

void *writer(void *meta);
void *reader(void *tid);
void join_threads(pthread_t threads[], int length);

#endif
