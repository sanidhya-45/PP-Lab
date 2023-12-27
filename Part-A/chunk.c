// Write an OpenMP program that divides the Iterations into chunks containing 2 iterations,
// respectively (OMP_SCHEDULE=static,2).
// Its input should be the number of iterations, and its output should be which iterations of a
// parallelized for loop are executed by which thread.
// For example, if there are two threads and four iterations, the output might be the following:
// Thread 0 : Iterations 0 −− 1
// Thread 1 : Iterations 2 −− 3
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(){
int n; //max_iteration
scanf("%d",&n);
#pragma omp parallel
{
int i;
#pragma omp for schedule(static,2)
for(i=0;i<n;i++){
printf("Thread No:- %d Iteration No:- %d\n",omp_get_thread_num(),i);
}
}
return 0;
}
// Output:-
// 10
// Thread No:- 3 Iteration No:- 6
// Thread No:- 3 Iteration No:- 7
// Thread No:- 2 Iteration No:- 4
// Thread No:- 2 Iteration No:- 5
// Thread No:- 1 Iteration No:- 2
// Thread No:- 1 Iteration No:- 3
// Thread No:- 0 Iteration No:- 0
// Thread No:- 0 Iteration No:- 1
// Thread No:- 4 Iteration No:- 8
// Thread No:- 4 Iteration No:- 9