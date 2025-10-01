#include <cstdio>
#include <chrono>
#include <iostream>
#include <numeric>
#include <omp.h>

void initialize(int **arr, int n) {
    for (int i = 0; i < n; i++){
        arr[i] = new int[n];
        for (int j = 0; j < n; j++){
            arr[i][j] = i + j;
        }
    }
}

void reduce(int **arr,int n, long &sum) {
    sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            sum += arr[i][j];
        }
    }
}

int main (int argc, char *argv[]) {
    long sum;
    const int size = 10000;
    int **ar = new int*[size];
    initialize(ar, size);
    auto ini = std::chrono::high_resolution_clock::now();
    reduce(ar, size, sum);
    auto fin = std::chrono::high_resolution_clock::now();
    auto r = std::chrono::duration<double>(fin - ini).count();
    printf("result = %ld\n", sum);
    printf("tiempo = %f\n", r);
    return 0;
}
