#include <mpi.h>
#include <stdio.h>

int main()
{
        MPI_Init(NULL, NULL);
        int wr,ws;
        MPI_Comm_size(MPI_COMM_WORLD, &wr);
        MPI_Comm_rank(MPI_COMM_WORLD, &ws);

        int sd=wr;
        int rd[ws];

        MPI_Gather(&sd, 1, MPI_INT, rd, 1, MPI_INT, 0, MPI_COMM_WORLD);

        if(wr==0)
        {
                printf("Gathered data at root\n");
                for(int i=0; i<ws; i++)
                {
                        printf("%d", rd[i]);
                }printf("\n");
        }
        MPI_Finalize();
        return 0;
}