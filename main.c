#include "headers.h"

struct shared_data shared = {
    .decrementer = 0,
    .incrementer = 0,
    .writers = 0,
    .sum = 0
};

pthread_mutex_t w_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t r_mutex = PTHREAD_MUTEX_INITIALIZER;
int reader_count = 0;

int main(void) {
    srand(time(NULL));
    int n_incrementers = rand() % RAND_RANGE + 1;
    int n_decrementers = rand() % RAND_RANGE + 1;
    int n_readers = rand() % RAND_RANGE + 1;

    //create incrementer threads
    pthread_t incrementers[n_incrementers];
    writer_metadata imd[n_incrementers];
    for (int i = 0; i < n_incrementers; i++) {
        imd[i].id = i;
        imd[i].incdec = 1;
        pthread_create(&incrementers[i], NULL, writer, (void *)&imd[i]);
    }
    //create decrementer threads
    pthread_t decrementers[n_decrementers];
    writer_metadata dmd[n_decrementers];
    for (int i = 0; i < n_decrementers; i++) {
        dmd[i].id = i;
        dmd[i].incdec = -1;
        pthread_create(&decrementers[i], NULL, writer, (void *)&dmd[i]);
    }
    //create reader threads
    pthread_t readers[n_readers];
    for (int i = 0; i < n_readers; i++) {
        int *id = (int *)malloc(sizeof(int));
        *id = i;
        pthread_create(&readers[i], NULL, reader, (void *)id);
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
