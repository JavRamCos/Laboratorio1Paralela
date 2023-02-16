#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
    int N = 10e8;
    int thread_count = 100;

    double factor = 1.0;
    double sum, pi_approx = 0.0;
    #pragma omp parallel for num_threads(thread_count) \
    reduction(+:sum)
    for (int k = 0; k < N; k++) {
        sum += factor/(2*k+1);
        factor = -factor;
    }
    pi_approx = 4.0*sum;


    printf("Pi: %.25f threads %d \n", pi_approx, thread_count);

    return 0;
}