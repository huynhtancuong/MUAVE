#include <stdio.h>

FILE *input, *output;
int n, A[1000], B[1000], C[1000];

int readData() {
    fscanf(input, "%d", &n);
    for (int i = 1; i <= n; i++) {
        fscanf(input, "%d %d %d", &A[i], &B[i], &C[i]);
    }
    return 1;
}

int _3min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int _2min(int a, int b) {
    if (a < b) return a;
    return b;
}

int findMin(int k) {
    if (k < 1) return 0;
    if (k == 1) return A[1];
    if (k == 2) return _2min(A[2]+findMin(1), B[1]);
    return _3min(A[k] + findMin(k-1), B[k-1] + findMin(k-2), C[k-2] + findMin(k-3));

}

int main() {
    input = fopen("MUAVE.INP", "r");
    output = fopen("MUAVE.OUT", "w");
    readData();
    fprintf(output, "%d\n", findMin(n));
    fclose(output);
    fclose(input);
}