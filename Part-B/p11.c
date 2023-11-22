#include <mpi.h>
#include <stdio.h>

int main()
{
        MPI_Init(NULL, NULL);
        int wr,ws;
        MPI_Comm_size(MPI_COMM_WORLD, &ws);
        MPI_Comm_rank(MPI_COMM_WORLD, &wr);
        int data= wr;
        int maxval, minval, sum, product;
        MPI_Reduce(&data, &maxval, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
        MPI_Reduce(&data, &minval, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
        MPI_Reduce(&data, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        MPI_Reduce(&data, &product, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
        if(wr==0)
        {
                printf("Max value is: %d\n", maxval);
                printf("Min value is: %d\n", minval);
                printf("Sum value is: %d\n", sum);
                printf("Product value is: %d\n", product);
        }
        MPI_Finalize();
        return 0;
}
~       