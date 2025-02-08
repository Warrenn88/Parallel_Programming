#include <stdlib.h>
#include <math.h>

#define SIZE 16
#define numiter 10

float A[SIZE][SIZE], B[SIZE][SIZE];

float random_float_range(float min, float max) {
    return min + ((float)rand()) / (float)RAND_MAX * (max - min);
}

void ArrayGenerator() {
    int i, j;
    cout.precision(4);
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            A[i][j] = random_float_range(0.0, 255.0);
        }
    }
    
    cout << "Generated Array:" << endl;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void JacobiSmoothing() {
    int i, j, k;
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            B[i][j] = A[i][j];
        }
    }
    
    for (k = 1; k <= numiter; k++) {
        forall i = 1 to (SIZE - 2) do {
            forall j = 1 to (SIZE - 2) do {
                B[i][j] = ( A[i-1][j-1] + A[i-1][j] + A[i-1][j+1] +
                            A[i][j-1]               + A[i][j+1] +
                            A[i+1][j-1] + A[i+1][j] + A[i+1][j+1] ) / 8;
            }
        }
        
        forall i = 1 to (SIZE - 2) do {
            forall j = 1 to (SIZE - 2) do {
                A[i][j] = B[i][j];
            }
        }
    }
}

int main() {
    ArrayGenerator();   
    JacobiSmoothing();  
    
    cout << "\nSmoothed Array:" << endl;
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}