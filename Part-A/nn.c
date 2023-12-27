#include <omp.h>
#include <stdio.h>

int main()
{
        int n;
        scanf("%d", &n);
        int sum=0;

        #pragma omp parallel for
                for(int i=1; i<=n; i++){
                        #pragma omp critical
                        sum+=i;

        }

        printf("Sum of numbers %d numbers is %d\t",n,sum);
        return 0;
}