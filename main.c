#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define RAND_RANGE 20

static pthread_mutex_t w_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t w_cond = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t r_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t r_cond = PTHREAD_COND_INITIALIZER;
static int readers = 0;
static int sum = 0;



void reader(void);
void writer(void);

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int n_incrementers = rand() % RAND_RANGE;
    int n_decrementers = rand() % RAND_RANGE;
    int n_readers = rand() % RAND_RANGE;

    //create incrementer threads
    for (int i = 0; i < n_incrementers; i++) {
        // throw threads
    }
    //create decrementer threads
    for (int i = 0; i < n_decrementers; i++) {
        //throw threads
    }
    //create reader threads
    for (int i = 0; i < n_readers; i++) {
        //throw threads
    }
    return 0;
}
