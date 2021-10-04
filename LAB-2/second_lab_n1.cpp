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

void right_diagonal(int **matrix, int *D, int N) {
    int i, j;
    int k = 0, g = 0;

    for(i = N - 1; i >= 0; i--, g = 0) {
        D[k] = matrix[g][i];
        k++;
        for(j = i + 1; j < N; j++) {
            g++;
            D[k] = matrix[g][j];
            k++;
        }
    }

    for(i = 1; i <= N - 1; i++, g = 0) {
        D[k] = matrix[i][g];
        k++;
        for(j = i + 1; j < N; j++) {
            g++;
            D[k] = matrix[j][g];
            k++;
        }
    }
}

void left_diagonal(int **matrix, int *D, int N) {
    int i, j;
    int k = 0, g = 0;

    for(i = 0; i <= N - 1; i++, g = 0) {
        D[k] = matrix[g][i];
        k++;
        for(j = N - i; j < N; j++) {
            g++;
            D[k] = matrix[g][N - j - 1];
            k++;
        }
    }

    for(i = 1; i <= N - 1; i++) {
        g = N - 1;
        D[k] = matrix[i][g];
        k++;
        for(j = i + 1; j < N; j++) {
            g--;
            D[k] = matrix[j][g];
            k++;
        }
    }
}

void center_spiral(int **matrix, int *D, int N) {
    int i;
    int k = (N - 1) / 2;
    int g = k;
    int limit = 0, count = 0;

    while(limit <= N) {
        limit++;
        for(i = 0; (i < limit) && (g < N) && (g >= 0) && (k < N) && (k >= 0); i++)
            D[count++] = matrix[k][g++];
        for(i = 0; (i < limit) && (g < N) && (g >= 0) && (k < N) && (k >= 0); i++)
            D[count++] = matrix[k++][g];
        limit++;
        for(i = 0; (i < limit) && (g < N) && (g >= 0) && (k < N) && (k >= 0); i++)
            D[count++] = matrix[k][g--];
        for(i = 0; (i < limit) && (g < N) && (g >= 0) && (k < N) && (k >= 0); i++)
            D[count++] = matrix[k--][g];
    }
}

void top_left_spiral(int **matrix, int *D, int N) {
    int i, j, k;
    int limit = N / 2;
    int count = 0;

    for(k = 0; k < limit; k++) {
        for(i = k; i < N - k; i++, count++)
            D[count] = matrix[i][k];
        for(j = k + 1; j < N - k; j++, count++)
            D[count] = matrix[i - 1][j];
        for(i = N - k - 2; i >= k; i--, count++) 
            D[count] = matrix[i][j - 1];
        for(j = N - k - 2; j >= k + 1; j--, count++)
            D[count] = matrix[i + 1][j];
    }

    if(N % 2 != 0)
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
    
    cout << "Right diagonal:" << endl;
    right_diagonal(matrix, D, N);
    printArray(D, N * N);

    cout << "Left diagonal:" << endl;
    left_diagonal(matrix, D, N);
    printArray(D, N * N);
    
    cout << "Spiral, starting from the top left angle:" << endl;
    top_left_spiral(matrix, D, N);
    printArray(D, N * N);

    cout << "Spiral, starting from the center:" << endl;
    center_spiral(matrix, D, N);
    printArray(D, N * N);

    for(int i = 0; i < N; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] D;
    
    return 0;
}