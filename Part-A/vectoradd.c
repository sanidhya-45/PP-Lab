#include <omp.h>
#include <stdio.h>

int main()
{
        int n;
        scanf("%d", &n);
        int a[n], b[n], res[n];

        for(int i=0; i<n; i++)
        {
                a[i]= rand() %1000;
                b[i]= rand() %100;
        }

        double st= omp_get_wtime();
        for(int i=0; i<n; i++)
                res[i]= a[i] + b[i];
        double et= omp_get_wtime();
        printf("Serial version time :%f ", et-st);

        st=omp_get_wtime();
        #pragma omp parallel for
        for(int i=0; i<n; i++)
        {
                res[i]= a[i] + b[i];
        }
        et= omp_get_wtime();
        printf(" \nParallel time :%f", et-st);
return 0;
}