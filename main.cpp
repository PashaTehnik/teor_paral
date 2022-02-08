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


int main(int argc, char** argv){
    for(int i = 0; i < argc; i++)
        printf("%d : %s\n",i,argv[i]);
    return 0;
}