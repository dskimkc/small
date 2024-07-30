#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void nqueen(int n);
int place(int x[10], int k);
void main() {
    int n;
    printf("Enter the Number of Queens: ");
    scanf("%d", &n);
    if (n == 1 || n == 2 || n == 3) {
        printf("Solution is not possible\n");
    } else {
        nqueen(n);
    }
}
void nqueen(int n) {
    int x[10], k = 1, i, count = 0;
    x[k] = 0;
    while (k != 0) {
        x[k] = x[k] + 1;

        while (x[k] <= n && place(x, k) == 0) {
            x[k] = x[k] + 1;
        }
        if (x[k] <= n) {
            if (k == n) {
                count++;
                printf("\nSolution %d is:\n", count);
                for (i = 1; i <= n; i++) {
                    printf("%d\t", x[i]);
                }
                printf("\n");
            } else {
                k = k + 1;
                x[k] = 0;
            }
        } else {
            k--;
        }
    }
}
int place(int x[10], int k) {
    int i;
    for (i = 1; i <= k - 1; i++) {
        if (x[k] == x[i] || abs(x[k] - x[i]) == abs(i - k)) {
            return 0;
        }
    }
    return 1;
}
