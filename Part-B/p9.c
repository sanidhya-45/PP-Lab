#include <mpi.h>
#include <stdio.h>

int main()
{
        MPI_Init(NULL, NULL);
        int wr, ws;
        MPI_Comm_size(MPI_COMM_WORLD, &ws);
        MPI_Comm_rank(MPI_COMM_WORLD, &wr);

        int data[ws*2];
        if(wr==0)
        {
                for(int i=0; i<ws; i++)
                {
                        data[i]=i+1;
                }
        }
        int recv_data;
        MPI_Scatter(data, 1, MPI_INT,&recv_data, 1,MPI_INT, 0, MPI_COMM_WORLD);
        printf("Process %d received data %d\n",wr,recv_data);
        //printf("Process %d received data %d\n",wr,recv_data);

        MPI_Finalize();
        return 0;
}