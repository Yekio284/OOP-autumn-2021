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

void up_left_spiral(int **matrix, int *D, int N) {
    int i, j, k;
    int limit = N / 2;
    int count = 0;

    for (k = 0; k < limit; k++) {
        for (i = k; i < N - k; i++, count++)
            D[count] = matrix[i][k];
        for (j = k + 1; j < N - k; j++, count++)
            D[count] = matrix[i - 1][j];
        for (i = N - k - 2; i >= k; i--, count++) 
            D[count] = matrix[i][j - 1];
        for (j = N - k - 2; j >= k + 1; j--, count++)
            D[count] = matrix[i + 1][j];
    }

    if (N % 2 != 0)
        D[count] = matrix[limit][limit];
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
    for(int i = 0; i < N; i++)
        cout << setw(4) << D[i];
    cout << endl;
}

int main() {
    srand(time(NULL));
    int N = rand() % 6;
    int maxValue = 100;
    int **matrix = genRandMatrix(N, maxValue); 
    int *D = new int[N * N];
    
    printMatrix(matrix, N);
    up_left_spiral(matrix, D, N);
    cout << "Up-left spiral:" << endl;
    printArray(D, N * N);

    for(int i = 0; i < N; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] D;
    return 0;
}