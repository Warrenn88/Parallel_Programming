#include <stdlib.h>
#include <math.h>

#define SIZE 16
float array[SIZE][SIZE];

float random_float_range(float min, float max) {
    return min + ((float)rand()) / (float)RAND_MAX * (max - min);
}

void ArrayGenerator() {
    int i, j;
    float a[16][16];
  
    cout.precision(4);
  
    for (i = 0; i < 16; i++) {
      for (j = 0; j < 16; j++) {
        a[i][j] = ((float) rand() / (float) RAND_MAX) * 255.0;
      }
    }
  
    for (i = 0; i < 16; i++) {
      for (j = 0; j < 16; j++) {
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
  }

float main(){
    ArrayGenerator();
    return 0;
}