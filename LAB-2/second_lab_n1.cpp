#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int **genRandMatrix(int N, int maxValue) {
    srand(time(NULL));
    int **matrix = new int* [N];
    int i, j;
    
    for(i = 0; i < N; i++) {
        matrix[i] = new int[N];
        for(j = 0; j < N; j++)
            matrix[i][j] = rand() % maxValue;
    }
    return matrix;
}

void printMatrix(int **matrix, int N) {
    cout << "Our Matrix:" << endl;
    int i, j;

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++)
            cout << setw(4) << matrix[i][j]; 
        cout << endl;
    }
}



void printArray(int *D, int N) {
    cout << "Our Array:" << endl;
    
    for(int i = 0; i < N; i++)
        cout << setw(4) << D[i];
    cout << endl;
}

int *up_left_spiral(int **matrix, int *D, int N); //d

int main() {
    srand(time(NULL));
    int N = rand() % 6;
    int maxValue = 100;
    int **matrix = genRandMatrix(N, maxValue); 
    int *D = new int[N * N];
    
    printMatrix(matrix, N);

    for(int i = 0; i < N; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] D;
    return 0;
}