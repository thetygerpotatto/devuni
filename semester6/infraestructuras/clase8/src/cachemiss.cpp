#include <cstdio>
#include <chrono>

void initialize(int **arr, int n) {
    for (int i = 0; i < n; i++){
        arr[i] = new int[n];
        for (int j = 0; j < n; j++){
            arr[i][j] = 0;
        }
    }
}

int main (int argc, char *argv[]) {
    const int size = 10000;
    int **ar = new int*[size];

    initialize(ar, size);
    printf("%d\n", ar[0][0]);
    return 0;
}
