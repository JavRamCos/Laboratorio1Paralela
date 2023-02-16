#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int N = 10e8;

    double factor = 1.0;
    double pi_approx, sum = 0.0;
    for (int k = 0; k < N; k++) {
        sum += factor/(2*k+1);
        factor = -factor;
    }
    pi_approx = 4.0*sum;
    
    printf("Pi: %.20f iterations %d \n", pi_approx, N);

    return 0;
}