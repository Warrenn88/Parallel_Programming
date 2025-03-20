#include <stdlib.h>
#include <math.h>

#define n 2000            
#define m 100            
#define bucket_number 10 

int inputArray[n+1], finalArray[n];
int buckets[bucket_number][n+1];

void mySort(int arr[]) {
    int j, k, maximumVal, maxIndex, tempVal;
    for (j = arr[0]; j > 1; j--) {
        maximumVal = arr[j];
        maxIndex   = j;
        for (k = 1; k < j; k++) {
            if (arr[k] > maximumVal) {
                maximumVal = arr[k];
                maxIndex   = k;
            }
        }
        tempVal       = arr[j];
        arr[j]        = arr[maxIndex];
        arr[maxIndex] = tempVal;
    }
    return;
}

int atomicInc(int *counter) {
    int oldVal = *counter;
    (*counter)++;
    return oldVal;
}

int main() {
    int i, j, k, val, bucketIndex, posInBucket;
    int prefixOffsets[bucket_number];

    for (i = 1; i <= n; i++) {
        inputArray[i] = rand() % m;
    }

    for (i = 0; i < bucket_number; i++) {
        buckets[i][0] = 0;
    }

    forall i = 1 to n do {
        int localVal         = inputArray[i];
        int localBucketIndex = (int)(localVal / 10.0);
        int localPos         = atomicInc(&buckets[localBucketIndex][0]) + 1;
        buckets[localBucketIndex][localPos] = localVal;
    }

    forall i = 0 to bucket_number - 1 do {
        mySort(buckets[i]);
    }

    prefixOffsets[0] = 0;
    for (i = 1; i < bucket_number; i++) {
        prefixOffsets[i] = prefixOffsets[i-1] + buckets[i-1][0];
    }

    forall i = 0 to bucket_number - 1 do {
        int localStart = prefixOffsets[i];
        int count      = buckets[i][0];  
        int j;                              
        for (j = 1; j <= count; j++) {
            finalArray[localStart + j - 1] = buckets[i][j];
        }
    }

    k = 0;
    for (i = 0; i < n; i++) {
        cout << "d[" << k++ << "]=" << finalArray[i] << endl;
    }

    return 0;
}
