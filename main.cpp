#include <iostream>
#include <math.h>

float arr[10000000];
float sum = 0;

int main() {

    for(int i = 0; i < 10000000; i++){
        arr[i] = sin(i);
    }

    for(auto i: arr){
        sum += i;
    }

    return 0;
}
