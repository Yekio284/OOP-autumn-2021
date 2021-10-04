#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int *genRandArray(int size, int maxValue) {
    srand(time(NULL));
    int *arr = new int[size+1];
    arr[0] = size;
    for(int i = 1; i <= size; i++)
        arr[i] = rand() % (maxValue); 

    return arr;
}

void print(int *arr) {
    cout << arr[0] << ": ";
    for(int i = 1; i <= arr[0]; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(NULL));
    int size = rand() % 10;
    int maxValue = 100;
    int *arr = genRandArray(size, maxValue);
    
    print(arr);
    
    delete[] arr;
    return 0;
}