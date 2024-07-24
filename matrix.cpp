#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define NUM_THREADS 100
#define MATRIX_SIZE 2000 // Define the size of the matrices

// Define matrices A, B, and C
int A[MATRIX_SIZE][MATRIX_SIZE];
int B[MATRIX_SIZE][MATRIX_SIZE];
int C[MATRIX_SIZE][MATRIX_SIZE];

// Define thread data structure
typedef struct {
    int start_row;
    int end_row;
} ThreadData;

// Function to perform matrix multiplication on a portion of the matrices
void *multiply(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int i, j, k;

    // Perform matrix multiplication
    for (i = data->start_row; i < data->end_row; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            C[i][j] = 0;
            for (k = 0; k < MATRIX_SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    int i, thread, row_per_thread;
    struct timeval start_time, end_time;
    double execution_time;

    // Initialize matrices A and B
    // (for simplicity, we're filling them with random values)
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Calculate number of rows per thread
    row_per_thread = MATRIX_SIZE / NUM_THREADS;

    // Start timing
    gettimeofday(&start_time, NULL);

    // Create threads and distribute matrix multiplication task
    for (thread = 0; thread < NUM_THREADS; thread++) {
        thread_data[thread].start_row = thread * row_per_thread;
        thread_data[thread].end_row = (thread + 1) * row_per_thread;
        if (thread == NUM_THREADS - 1) {
            // Make sure the last thread takes care of remaining rows
            thread_data[thread].end_row = MATRIX_SIZE;
        }
        pthread_create(&threads[thread], NULL, multiply, (void *)&thread_data[thread]);
    }

    // Wait for all threads to finish
    for (thread = 0; thread < NUM_THREADS; thread++) {
        pthread_join(threads[thread], NULL);
    }

    // End timing
    gettimeofday(&end_time, NULL);

    // Calculate execution time in seconds
    execution_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

    // Print execution time
    printf("Execution time with %d threads is: %f seconds\n", NUM_THREADS, execution_time);

    // Print the result matrix C (for testing)
    // Uncomment this section if you want to print the result matrix
    /*
    // for (i = 0; i < MATRIX_SIZE; i++) {
    //     for (int j = 0; j < MATRIX_SIZE; j++) {
    //         printf("%d ", C[i][j]);
    //     }
    //     printf("\n");
    // }
    */

    return 0;
}