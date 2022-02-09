#include <iostream>
#include <math.h>

// N, tol, max_iters

int main(int argc, char** argv){
    int N = 0, max_iters = 0, iter = 0;
    float tol = 0;
    if (argc != 4){
        printf("incorrect inputs\n");
        return 1;
    }

    N = std::stoi(argv[1]);
    tol = std::stof(argv[2]);
    max_iters = std::stoi(argv[3]);

    float a[N][N],
          newa[N][N],
          err = tol+1;
    for(int j = 1; j < N - 1; j++) {
        for (int i = 1; i < N - 1; i++) {
            //a[i][j] = (float)((int)(((float) rand() / (float)(RAND_MAX)) * 5) % 5);
            a[i][j]=0;
        }
    }
    a[0][0]=10;
    a[N-1][0]=20;
    a[0][N-1]=20;
    a[N-1][N-1]=30;
    float   d1=(a[0][N-1] - a[0][0])/N,
            d2=(a[N-1][0] - a[0][0])/N,
            d3=(a[N-1][N-1] - a[N-1][0])/N,
            d4=(a[N-1][N-1] - a[0][N-1])/N;
    for (int i = 1; i < N-1; i++){
        a[0][i]=a[0][i-1] + d1;

        a[i][0]=a[i-1][0] + d2;

        a[i][N-1]=a[i-1][N-1] + d3;

        a[N-1][i]=a[N-1][i-1] + d4;
    }

    ///////////////////// print

    printf("\n");
    for(int j = 0; j <= N - 1; j++){
        printf("\n");
        for(int i = 0; i <= N - 1; i++) {
            printf("%.2f  ", a[i][j]);
        }
    }
    printf("\n\n\n");
    /////////////////////

#pragma acc data copy(a[0:N][0:N]) create (newa[0:N][0:N])
    while ((iter<max_iters)&&(err > tol)){
        iter++;
        err = 0;
        #pragma acc data present(a, newa)
        #pragma acc parallel reduction(max:err)
        {
            #pragma acc loop independent
            for(int j = 1; j <= N - 2; j++){
                #pragma acc loop independent
                for(int i = 1; i <= N - 2; i++) {

                    newa[i][j] = 0.25*(a[i+1][j] + a[i-1][j] + a[i][j+1] + a[i][j-1]);

                    err = fmax(err, newa[i][j] - a[i][j]);

                }
            }

            #pragma acc loop independent
            for(int j = 1; j <= N - 2; j++){
                #pragma acc loop independent
                for(int i = 1; i <= N - 2; i++) {

                    a[i][j] = newa[i][j];

                }
            }
        }
    }

    ///////////////////// print
    printf("\n");
    for(int j = 0; j <= N - 1; j++){
        printf("\n");
        for(int i = 0; i <= N - 1; i++) {
            printf("%.2f  ", a[i][j]);
        }
    }
    printf("\n");

    return 0;
}
