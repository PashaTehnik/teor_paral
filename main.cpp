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
    for(int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            a[i][j] = (float)((int)(((float) rand() / (float)(RAND_MAX)) * 5) % 5);
        }
    }
    ///////////////////// print

    printf("\n");
    for(int j = 0; j <= N - 1; j++){
        printf("\n");
        for(int i = 0; i <= N - 1; i++) {
            printf("%f  ", a[i][j]);
        }
    }
    printf("\n\n\n");

    /////////////////////
#pragma acc kernels
    while ((iter<max_iters)&&(err > tol)){
        iter++;
        err = 0;
        for(int j = 1; j <= N - 2; j++){
            for(int i = 1; i <= N - 2; i++) {

                newa[i][j] = 0.25*(a[i+1][j] + a[i-1][j] + a[i][j+1] + a[i][j-1]);

                err = fmax(err, newa[i][j] - a[i][j]);

            }
        }

        for(int j = 1; j <= N - 2; j++){
            for(int i = 1; i <= N - 2; i++) {

                a[i][j] = newa[i][j];

            }
        }

    }

    ///////////////////// print
    printf("\n");
    for(int j = 0; j <= N - 1; j++){
        printf("\n");
        for(int i = 0; i <= N - 1; i++) {
            printf("%f  ", a[i][j]);
        }
    }
    printf("\n");

    return 0;
}
