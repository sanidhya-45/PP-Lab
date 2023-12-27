#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    MPI_Init(NULL, NULL);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // The program requires at least two processes
    if (world_size < 2) {
        printf( "World size must be greater than 1\n");
        MPI_Finalize();
        return 0;
    }

    int send_number = world_rank;
    int recv_number;
    int target_rank = (world_rank + 1) % world_size;
    int source_rank = (world_rank - 1 + world_size) % world_size;

    MPI_Barrier(MPI_COMM_WORLD); // Synchronize before starting timing

    double start_time = MPI_Wtime();
    MPI_Sendrecv(&send_number, 1, MPI_INT, target_rank, 0, 
                 &recv_number, 1, MPI_INT, source_rank, 0, 
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    double end_time = MPI_Wtime();

    double time_taken = end_time - start_time; 
    int data_size = sizeof(int); 

    // Calculate bandwidth
    double bandwidth = (data_size / time_taken) / 1.0e6; 

    printf("Process %d sent %d to process %d and received %d from process %d\n", 
            world_rank, send_number, target_rank, recv_number, source_rank);
    printf("Time taken: %f seconds, Bandwidth: %f MB/s\n", time_taken, bandwidth);

    MPI_Finalize();
    return 0;
}