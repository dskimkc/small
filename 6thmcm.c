#include <stdio.h>
#define MAX 10 // Maximum number of matrices
void MCM(int p[], int n)
{
    int m[MAX][MAX];
    int i, j, k, L, q;
    // Initialize the diagonal of m[i][i] to 0
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    // Compute the minimum cost of matrix chain multiplication
    for (L = 2; L < n; L++) // Chain length from 2 to n-1
    {
        for (i = 1; i <= n - L; i++)
        {
            j = i + L - 1;
            m[i][j] = 30000; 
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    // Print the matrix of minimum costs
    printf("Minimum number of multiplications is:\n");
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
            if (i < j)
                printf("%d\t", m[i][j]);
            else
                printf("--\t");
        printf("\n");
    }
}
int main()
{
    int n;
    int arr[MAX + 1];

    printf("Enter the number of matrices (max %d):\n", MAX - 1);
    scanf("%d", &n);
    if (n > MAX - 1 || n < 1) {
        printf("Number of matrices must be between 1 and %d.\n", MAX - 1);
        return 1;
    }
    printf("Enter the dimensions of matrices (p0, p1, ...):\n");
    for (int i = 0; i <= n; i++)
        scanf("%d", &arr[i]);
    MCM(arr, n + 1);
    return 0;
}
