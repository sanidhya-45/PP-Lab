#include <mpi.h>
#include <stdio.h>

int main()
{

                MPI_Init(NULL, NULL);
                int wr, ws;
                MPI_Comm_rank(MPI_COMM_WORLD, &wr);
                MPI_Comm_size(MPI_COMM_WORLD, &ws);

                printf("Process %d in phase 1\n",wr);

                MPI_Barrier(MPI_COMM_WORLD);

                printf("Process %d in phase 2\n", wr);

                MPI_Finalize();
                return 0;
}
~      