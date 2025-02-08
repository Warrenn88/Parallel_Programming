
#define n 4           
#define numiter 1   

float A[n][n], B[n][n];
int i, j, k;

main() {
    cout << "Enter " << n << " x " << n << " floating-point numbers for array A:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            B[i][j] = A[i][j];
        }
    }
    
    for (k = 1; k <= numiter; k++) {
        forall i = 1 to (n-2) do {
            forall j = 1 to (n-2) do {
                B[i][j] = ( A[i-1][j-1] + A[i-1][j] + A[i-1][j+1] +
                            A[i][j-1]               + A[i][j+1] +
                            A[i+1][j-1] + A[i+1][j] + A[i+1][j+1] ) / 8;
            }
        }
        
        forall i = 1 to (n-2) do {
            forall j = 1 to (n-2) do {
                A[i][j] = B[i][j];
            }
        }
    }
    
    cout << "\nThe final array A is:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}