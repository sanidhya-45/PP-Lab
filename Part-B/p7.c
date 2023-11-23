#include <mpi.h>
#include <stdio.h>

int main()
{
        MPI_Init(NULL, NULL);

        int wr, ws;
        MPI_Comm_size(MPI_COMM_WORLD, &ws);
        MPI_Comm_rank(MPI_COMM_WORLD, &wr);

        if(ws<2){
                printf("Atleast 2 programs required\n");
                MPI_Finalize();
                return 0;
        }
        int n=45;
        if(wr==0)
        {
                printf("Sandex broadcasting %d to all processes\n", n);
        }
        MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
        printf("Process %d receiving %d from sandex\n", wr, n);

        MPI_Finalize();
        return 0;
}