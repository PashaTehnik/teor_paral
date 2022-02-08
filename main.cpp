#include <iostream>
#include <math.h>

double arr[10000000];
double sum = 0;

int main() {
#pragma acc kernels
    for(int i = 0; i < 10000000; i++){
        arr[i] = sin(i);
    }
#pragma acc kernels
    for(auto i: arr){
        sum += i;
    }
    printf("\nsum = %f\n\n", sum);
    return 0;
}
