#include <iostream>
#include <math.h>

//double arr[10000000];
//double sum = 0;
//
//int main() {
//#pragma acc kernels
//    for(int i = 0; i < 10000000; i++){
//        arr[i] = sin((2*M_PI)/10000000*i);
//    }
//#pragma acc kernels
//    for(auto i: arr){
//        sum += i;
//    }
//    printf("\nsum = %f\n\n", sum);
//    return 0;
//}
// N, tol, max_iters

int main(int argc, char** argv){
    int N = 0, max_iters = 0;
    float tol = 0;
    if (argc != 4){
        printf("incorrect inputs");
        return 1;
    }

    N = std::stoi(argv[1]);
    tol = std::stof(argv[2]);
    max_iters = std::stoi(argv[3]);

    float arr[N][N];

    return 0;
}