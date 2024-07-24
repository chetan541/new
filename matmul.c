#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N_MAX 1000 // Define maximum matrix size

int N;
int A[N_MAX][N_MAX];
int B[N_MAX][N_MAX];
int C[N_MAX][N_MAX];
int n;

void *multiply(void *arg) {
    int thread_id = *(int *)arg;
    
    int num_elements = N * N;
    int base_chunk_size = num_elements / n;
    int extra_elements = num_elements % n;

    // Calculate the chunk size for this thread
    int chunk_size = base_chunk_size + (thread_id <= extra_elements ? 1 : 0);

    // Calculate the starting and ending indices for this thread
    int start_index = (thread_id - 1) * base_chunk_size + (thread_id <= extra_elements ? (thread_id - 1) : extra_elements);
    int end_index = start_index + chunk_size;

    // Compute matrix multiplication for elements assigned to this thread
    for (int index = start_index; index < end_index; ++index) {
        int i = index / N;
        int j = index % N;
        C[i][j] = 0;
        for (int k = 0; k < N; ++k) {
            C[i][j] += A[i][k] * B[k][j];
        }
    }

    pthread_exit(NULL);
}

void input_matrix(int matrix[N_MAX][N_MAX], int size) {
    printf("Enter elements of the matrix (%d x %d):\n", size, size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // printf("Enter element [%d][%d]: ", i, j);
            // scanf("%d", &matrix[i][j]);
            matrix[i][j]=i+j;
        }
    }
}

void display_matrix(int matrix[N_MAX][N_MAX], int size) {
    printf("Resultant Matrix (%d x %d):\n", size, size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter size of square matrices (N <= %d): ", N_MAX);
    scanf("%d", &N);

    if (N <= 0 || N > N_MAX) {
        printf("Invalid matrix size. Exiting...\n");
        return 1;
    }

    input_matrix(A, N);
    input_matrix(B, N);
    
    clock_t start, end;
    double cpu_time_used;
    int optimal_thread=0;
    double optimal_time=-1;
    for (int num_threads = 1; num_threads <= N*N; ++num_threads) {
        pthread_t threads[num_threads];
        int thread_args[num_threads];

        start = clock();

        for (int i = 0; i < num_threads; ++i) {
            n=num_threads;
            thread_args[i] = i+1;
            pthread_create(&threads[i], NULL, multiply, &thread_args[i]);
        }

        // Wait for threads to finish
        for (int i = 0; i < num_threads; ++i) {
            pthread_join(threads[i], NULL);
        }

        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Execution time with %d threads: %f seconds\n", num_threads, cpu_time_used);
        if(optimal_time==-1 || optimal_time>cpu_time_used){
        	optimal_thread=num_threads;
        	optimal_time=cpu_time_used;
        }
    }
    printf("\nOptimal no. of threads are: %d with execution time: %f\n",optimal_thread,optimal_time);

    // Display the resulting matrix after the last multiplication
    // display_matrix(C, N);

    return 0;
}

