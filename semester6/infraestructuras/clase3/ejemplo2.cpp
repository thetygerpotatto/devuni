#include <ratio>
#include <cstdio>
#include <chrono>
#include <tbb/tbb.h>
#include <tbb/parallel_for.h>
#include <tbb/parallel_reduce.h>
#include <vector>

using std::vector;


int SIZE = 2e8;
vector<int> v(SIZE);

void initialize_vector(int ini, int fin, vector<int>&v, int val) {
    for (int i = ini; i != fin; ++i) {
        v[i] = i;
    }
}


void suma_vector(int ini, int fin, vector<int>&v, long &suma) {
    for (int i = ini; i != fin; ++i) {
        suma +=v[i];
    }
}

int main (int argc, char *argv[]) {
    long acum = 0;
    std::chrono::high_resolution_clock::time_point start, finish;
    start = std::chrono::high_resolution_clock::now();
    //Fill vector
    initialize_vector(0, SIZE, v, 2);
    suma_vector(0, SIZE, v, acum);
    finish = std::chrono::high_resolution_clock::now();
    double runtime = std::chrono::duration<double, std::milli>(finish - start).count();
    printf("Un thread Time: %f\n", runtime);

    long suma1 = 0, suma2 = 0;
    std::thread h1, h2;
    start = std::chrono::high_resolution_clock::now();
    h1 = std::thread(suma_vector, 0, SIZE/2, std::ref(v), std::ref(suma1));
    h2 = std::thread(suma_vector, SIZE/2 , SIZE, std::ref(v), std::ref(suma2));
    h1.join(); h2.join();
    long suma = suma1 + suma2;
    finish = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration<double, std::milli>(finish - start).count();
    printf("dos thread Time: %f\n", runtime);
    return 0;
}
