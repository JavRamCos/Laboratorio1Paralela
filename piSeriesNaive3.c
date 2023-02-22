#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int N = 10e8;
    int thread_count = 6;
    int block_size = 128;
    clock_t t;
    t = clock();

    double factor = 1.0;
    double sum, pi_approx = 0.0;
    
    #pragma omp parallel for num_threads(thread_count) private( factor, sum) schedule (dynamic, block_size)\
    reduction(+:sum)
    for (int k = 0; k < N; k++) {
        factor = (k % 2 == 0) ? 1.0 : - 1.0;
        sum += factor/(2*k+1);
    }
    pi_approx = 4.0*sum;

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("Pi: %.25f | iterations %d |THREADS: %d  | TIME TAKEN : %f | BLOCK SIZE: %d  \n", pi_approx, N, thread_count, time_taken, block_size);

    return 0;
}