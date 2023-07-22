#include "headers.h"

void writer(int id, int incdec) {
    //lock w mutex
    pthread_mutex_lock(&w_mutex);
    //increment or decrement
    shared.sum += incdec;
    if (incdec > 0) {
        shared.incrementer = id;
        printf("Incrementer %d set sum = %d\n", id, shared.sum);
    } else {
        shared.decrementer = id;
        printf("Decrementer %d set sum = %d\n", id, shared.sum);
    }
    //unlock w mutex
    pthread_mutex_unlock(&w_mutex);
}
