#include <stdio.h>
#define MAX 100

int m[MAX][MAX];
int s[MAX][MAX];

void printOptimalParens(int s[MAX][MAX], int i, int j) {
	if (i == j) {
		printf("A%d", i);
		return;
	}
	printf("(");
	printOptimalParens(s, i, s[i][j]);
	printOptimalParens(s, s[i][j] + 1, j);
	printf(")");
}
void printCostMatrix(int m[MAX][MAX], int n) {
    printf("Cost matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i > j)
                printf("     ");
            else
                printf("%5d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void matrixChainOrder(int p[], int n) {
    int i, j, k, L, cost;

    for (i = 1; i <= n; i++){
        m[i][i] = 0;
    }
    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = 999999;
            for (k = i; k <= j - 1; k++) {
                cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    printCostMatrix(m, n);
}
int main() {
    int n, p[MAX];
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    printf("Enter dimensions array (Length %d): ",n+1);
    for (int i = 0; i <= n; i++){
        scanf("%d", &p[i]);
    }
    matrixChainOrder(p, n);
    printf("Optimal Parenthesization: ");
    printOptimalParens(s, 1, n);
    printf("\n");
    return 0;
}

