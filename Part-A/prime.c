#include <stdio.h>
#include <stdbool.h>
#include <omp.h>
// Function to check if a number is prime
bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    if (num <= 3)
    {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        
        }
    }
    return true;
}
int main()
{
    int n; // Change 'n' to the desired range
    scanf("%d", &n);
    // Serial execution
    double serial_start = omp_get_wtime();
    printf("Serial Prime Numbers:\n");
    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    double serial_end = omp_get_wtime();
    printf("Serial Execution Time: %f seconds\n", serial_end - serial_start);
    // Parallel execution
    double parallel_start = omp_get_wtime();


    printf("\nParallel Prime Numbers:\n");
    #pragma omp parallel for
    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    double parallel_end = omp_get_wtime();
    printf("Parallel Execution Time: %f seconds\n", parallel_end - parallel_start);
    return 0;
}