#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc,char* argv[]) {
    double factor = 1.0, sum = 0.0, pi_approx = 0.0;
    long int k, num_thds = 1, n = 10e8;
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

    printf("Pi: %.25lf threads %ld\n",pi_approx,num_thds);
    return EXIT_SUCCESS;
}

