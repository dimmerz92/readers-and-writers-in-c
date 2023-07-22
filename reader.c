#include "headers.h"

void reader(int id) {
    pthread_mutex_lock(&r_mutex); //lock r_mutex
    reader_count++; //increment count
    //lock w_mutex if first
    if (reader_count == 1) pthread_mutex_lock(&w_mutex);
    pthread_mutex_unlock(&r_mutex); //unlock r_mutex
    printf("Reader %d got %d\n", id, shared.sum); //read sum
    pthread_mutex_lock(&r_mutex); //lock r_mutex
    reader_count--; //decrement count
    //unlock w_mutex if last
    if (reader_count == 0) pthread_mutex_unlock(&w_mutex);
    pthread_mutex_unlock(&r_mutex); //unlock r_mutex
}
