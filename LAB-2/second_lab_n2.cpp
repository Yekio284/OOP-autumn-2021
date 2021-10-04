#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

int **genRandMatrix(int size, int maxValue) {
    srand(time(NULL));
    int **matrix = new int* [size + 1];
    int i, j;
    matrix[0] = new int[1];
    matrix[0][0] = size;
    
    for(i = 1; i <= matrix[0][0]; i++) {
        j = 0;
        int k = rand() % 10;
        matrix[i] = new int[k + 1];
        matrix[i][j] = k;
        
        for(j = 1; j <= matrix[i][0]; j++) {
            matrix[i][j] = rand() % maxValue;
        }
    }
    return matrix;
}

void printMatrix(int **matrix) {
    int i, j;
    cout << "Our Matrix:" << endl;
    for(i = 1; i <= matrix[0][0]; i++) {
        for(j = 1; j <= matrix[i][0]; j++) {
            if(j == 1)
                cout << matrix[i][j]; 
            else
                cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    srand(time(NULL));
    int size = rand() % 10;
    int maxValue = 100;
    int **matrix = genRandMatrix(size, maxValue);
    
    printMatrix(matrix);

    for(int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;
    
    return 0;
}