// Estimate the value of pi using Monte Carlo Method. Parallelize the code by removing loop carried
// dependency
// and record both serial and parallel execution times.
#include <stdio.h>
#include <omp.h>
#define NUM_THREADS 8
static long num_steps = 100000;
double step;
int main() {
int i;
double x, pi, sum[NUM_THREADS];
double start_time, end_time;
// Calculate the step size
step = 1.0 / (double)num_steps;
// Serial execution
start_time = omp_get_wtime();
printf("Serial Monte Carlo Method:\n");
for (i = 0; i < num_steps; i++) {
x = (i + 0.5) * step;
sum[0] += 4.0 / (1.0 + x * x);
}
pi = sum[0] / num_steps;
end_time = omp_get_wtime();
printf("Approximation of pi (Serial): %f\n", pi);
printf("Serial Execution Time: %f seconds\n", end_time - start_time);
// Parallel execution
start_time = omp_get_wtime();
printf("\nParallel Monte Carlo Method:\n");
// We are using private(i,x) in order to provide separate (i,x) for each threads(Avoid race
// condition)
#pragma omp parallel private(i, x)
{
int id = omp_get_thread_num();
// Each thread calculates a portion of the sum
for (i = id, sum[id] = 0.0; i < num_steps; i += NUM_THREADS) {
x = (i + 0.5) * step;
sum[id] += 4.0 / (1.0 + x * x);
}
}
// Combine partial sums from all threads
for (i = 1; i < NUM_THREADS; i++)
sum[0] += sum[i];
pi = sum[0] / num_steps;
end_time = omp_get_wtime();
printf("Approximation of pi (Parallel): %f\n", pi);
printf("Parallel Execution Time: %f seconds\n", end_time - start_time);
return 0;
}
// Output:-
// Serial Monte Carlo Method:
// Approximation of pi (Serial): 3.141593
// Serial Execution Time: 0.000592 seconds
// Parallel Monte Carlo Method:
// Approximation of pi (Parallel): 3.141593
// Parallel Execution Time: 0.001357 seconds