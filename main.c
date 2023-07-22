#include "headers.h"

struct shared_data shared = {
    .decrementer = NULL,
    .incrementer = NULL,
    .writers = 0,
    .sum = 0
};

pthread_mutex_t w_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t w_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t r_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t r_cond = PTHREAD_COND_INITIALIZER;
int reader_count = 0;

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int n_incrementers = rand() % RAND_RANGE;
    int n_decrementers = rand() % RAND_RANGE;
    int n_readers = rand() % RAND_RANGE;

    //create incrementer threads
    pthread_t incrementers[n_incrementers];
    for (int i = 0; i < n_incrementers; i++) {
        writer_metadata md = {
            .id = i,
            .incdec = 1
        };
        pthread_create(&incrementers[i], NULL, writer, (void *)&md);
    }
    //create decrementer threads
    pthread_t decrementers[n_decrementers];
    for (int i = 0; i < n_decrementers; i++) {
        writer_metadata md = {
            .id = i,
            .incdec = -1
        };
        pthread_create(&decrementers[i], NULL, writer, (void *)&md);
    }
    //create reader threads
    pthread_t readers[n_readers];
    for (int i = 0; i < n_readers; i++) {
        pthread_create(&readers[i], NULL, reader, (void *)&i);
    }

    //join threads
    join_threads(incrementers, n_incrementers);
    join_threads(decrementers, n_decrementers);
    join_threads(readers, n_readers);

    printf("There were %d readers, %d incrementers, and %d decrementers\n",
            n_readers, n_incrementers, n_decrementers);
    printf("The final state of the data is:\n");
    printf("\tlast incrementer: %d\n", shared.incrementer);
    printf("\tlast decrementer: %d\n", shared.decrementer);
    printf("\ttotal writers: %d\n", shared.writers);
    printf("\tsum %d\n", shared.sum);

    return 0;   
}
