#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
#define THREADS N

int B[N][N], C[N][N], A[N][N], TMP[N];
pthread_t threads[THREADS * 2];
sem_t empty, full;

typedef struct {
    int row;
} thread_args;

void *producer(void *arg) {
    int row = *((int *)arg);
    int j, k, sum;
    sem_wait(&empty);

    for (j = 0; j < N; j++) {
        sum = 0;
        for (k = 0; k < N; k++) {
            sum += B[row][k] * C[k][j];
        }
        TMP[j] = sum;
    }

    sem_post(&full);
    return NULL;
}

void *consumer(void *arg) {
    int row = *((int *)arg);
    sem_wait(&full);

    for (int j = 0; j < N; j++) {
        A[row][j] = TMP[j];
    }

    sem_post(&empty);

    return NULL;
}

int main() {
    int i, j;
    int thread_args[THREADS];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            B[i][j] = 1;
            C[i][j] = 1;
        }
    }

    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);

    for (i = 0; i < THREADS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, producer, &thread_args[i]);
        pthread_create(&threads[i], NULL, consumer, &thread_args[i]);
    }

    for (i = 0; i < THREADS * 2; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Matrix A:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
