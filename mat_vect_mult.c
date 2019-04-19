#include <mpi.h>
void Mat_vect_mult(
    double A[],
    double x[],
    double y[],
    int local_m,
    int n,
    int local_n,
    MPI_Comm comm){
        double *x;
        int local_i,j;

        x = malloc(n * sizeof(double));

        MPI_Allgather(local_x,local_n,MPI_DOUBLE,x,local_n,MPI_DOUBLE,comm);

        for(local_i = 0;local_i < local_m;local_i++){
            local_y[local_i] = 0.0;
            for(j = 0;j<n;j++)
            local_y[local_i] += local_A[local_i * n + j] * x[j];
        }

        free(x);
}