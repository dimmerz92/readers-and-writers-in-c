#include "headers.h"

void writer(writer_metadata md) {
    //lock w mutex
    pthread_mutex_lock(&w_mutex);
    //increment or decrement
    shared.sum += md.incdec;
    if (md.incdec > 0) {
        shared.incrementer = md.id;
        printf("Incrementer %d set sum = %d\n", md.id, shared.sum);
    } else {
        shared.decrementer = md.id;
        printf("Decrementer %d set sum = %d\n", md.id, shared.sum);
    }
    //unlock w mutex
    pthread_mutex_unlock(&w_mutex);
}
