#include "headers.h"

void *writer(void *meta) {
    writer_metadata md = *(writer_metadata *)meta; //cast arg back to struct
    pthread_mutex_lock(&w_mutex); //lock w mutex
    //increment or decrement
    shared.sum += md.incdec;
    shared.writers++;
    if (md.incdec > 0) {
        shared.incrementer = md.id;
        printf("Incrementer %d set sum = %d\n", md.id, shared.sum);
    } else {
        shared.decrementer = md.id;
        printf("Decrementer %d set sum = %d\n", md.id, shared.sum);
    }
    pthread_mutex_unlock(&w_mutex); //unlock w mutex
}
