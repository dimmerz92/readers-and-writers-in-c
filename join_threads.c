#include "headers.h"

void join_threads(pthread_t threads[], int length) {
    for (int i = 0; i < length; i++) {
        pthread_join(threads[i], NULL);
    }
}
