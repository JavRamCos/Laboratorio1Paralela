#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
    int N = 10e6;
    int thread_count = 1;

    double factor = 1.0;
    double sum, pi_approx = 0.0;
    #pragma omp parallel for num_threads(thread_count) \
    reduction(+:sum)
    for (int k = 0; k < N; k++) {
        factor = (k % 2 == 0) ? 1.0 : - 1.0;
        sum += factor/(2*k+1);
    }
    pi_approx = 4.0*sum;


    printf("Pi: %.25f iterations %d \n", pi_approx, N);

    return 0;
}