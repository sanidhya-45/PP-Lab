#include <mpi.h>
#include <stdio.h>
int main()
{
        MPI_Init(NULL, NULL);
        int wr;
        MPI_Comm_rank(MPI_COMM_WORLD, &wr);

//      Each process uses its rank as its data
        int data= wr;
        int maxval, minval, sum, product;

        MPI_Allreduce(&data, &maxval, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
        MPI_Allreduce(&data, &minval, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);
        MPI_Allreduce(&data, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
        MPI_Allreduce(&data, &product, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);

        printf("Process %d -Max: %d, Min: %d, Sum: %d, Product: %d\n", wr,maxval,minval, sum,product);
        MPI_Finalize();
        return 0;
}