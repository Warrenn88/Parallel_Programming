#include <stdlib.h>
#include <math.h>

#define Nx 5
#define Ny 8
#define numpoints 30

float partialSum[Nx][Ny];
float a, b, w, globalsum, answer;

float f(float t)
{
    return sqrt(4.0 - t * t);
}

int main()
{
    int i, j, k;
    a = 0.0;
    b = 2.0;
    globalsum = 0.0;
    w = (b - a) / (Nx * Ny * numpoints);

    forall i = 0 to Nx - 1 do {
        forall j = 0 to Ny - 1 do {
            float localsum = 0.0;
            float t = a + (i * Ny + j) * (b - a) / (Nx * Ny);
            int k2;
            for (k2 = 0; k2 < numpoints; k2++) {
                localsum += f(t);
                t += w;
            }
            partialSum[i][j] = localsum * w;
        }
    }

    forall i = 0 to Nx - 1 do {
        int col;
        for (col = 1; col < Ny; col++) {
            partialSum[i][col] += partialSum[i][col - 1];
        }
    }

    for (i = 1; i < Nx; i++) {
        partialSum[i][Ny - 1] += partialSum[i - 1][Ny - 1];
    }

    answer = partialSum[Nx - 1][Ny - 1] + (w / 2.0) * (f(b) - f(a));
    cout << answer << "\n";

    return 0;
}
