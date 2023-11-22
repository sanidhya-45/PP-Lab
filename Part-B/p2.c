#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
        MPI_Init(&argc, &argv);
        int wr;
        MPI_Comm_rank(MPI_COMM_WORLD, &wr);
//      int MPI_Comm_size(MPI_COMM_WORLD, &ws);
//      if(ws<2)
//      {
//              printf("Atleast 2 process should be there\n");
//              MPI_Finalize();
//      return 0;
        //}
        int n ;
        if(wr==0)
        {
                n=45;
                MPI_Ssend(&n, 1, MPI_INT,1,0,MPI_COMM_WORLD);
                MPI_Recv(&n,1,MPI_INT,1,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                printf("hi1");
        }
        else if(wr==1)
        {
                n=5;
                MPI_Ssend(&n,1,MPI_INT,0,0,MPI_COMM_WORLD);
                MPI_Recv(&n,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
                printf("hi2");
        }
        MPI_Finalize();
        return 0;
}