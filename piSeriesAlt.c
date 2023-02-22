#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main(int argc,char* argv[]) {
    double factor = 1.0, sum = 0.0, pi_approx = 0.0;
    long int k, num_thds = 1, n = 10e8;
    clock_t t;
    t = clock();
    if(argc >= 2) {
        num_thds = strtol(argv[1],NULL,10);
    } else {
        printf("Debe haber un input para hilos y un input para n\n");
        return EXIT_FAILURE;
    }

    #pragma omp parallel for num_threads(num_thds) reduction(+: sum)
    for (k = 0; k < n; k++) {
        sum += (k % 2) == 0 ? (double)1/(2*k+1) : (double)-1/(2*k+1);
    }
    pi_approx = 4.0*sum;
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Pi: %.25lf | THREADS: %ld | TIME TAKEN: %lf\n",pi_approx,num_thds,time_taken);
    return EXIT_SUCCESS;
}

