#include <stdio.h>
#include <string.h>
#define MAX 100

void printArrows(char arrow[MAX][MAX], int m, int n) {
    printf("Arrow directions:\n");
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (arrow[i][j] == 'D')
                printf(" dia ");
            else if (arrow[i][j] == 'U')
                printf(" up  ");
            else if (arrow[i][j] == 'L')
                printf(" left");
            else
                printf("     ");
        }
        printf("\n");
    }
    printf("\n");
}

void printMatrix(int L[MAX][MAX], int m, int n) {
    printf("LCS length matrix:\n");
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%3d ", L[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printLCS(char arrow[MAX][MAX], char *X, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (arrow[i][j] == 'D') {
        printLCS(arrow, X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    } else if (arrow[i][j] == 'U') {
        printLCS(arrow, X, i - 1, j);
    } else {
        printLCS(arrow, X, i, j - 1);
    }
}

int lcs_with_arrows(char *X, char *Y, int m, int n) {
    int L[MAX][MAX];
    char arrow[MAX][MAX];

    for (int i = 0; i <= m; i++) {
        L[i][0] = 0;
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                L[0][j] = 0;
            arrow[i][j] = ' ';
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
                arrow[i][j] = 'D'; 
            } else if (L[i - 1][j] >= L[i][j - 1]) {
                L[i][j] = L[i - 1][j];
                arrow[i][j] = 'U';
            } else {
                L[i][j] = L[i][j - 1];
                arrow[i][j] = 'L';
            }
        }
    }
    printMatrix(L, m, n);
    printArrows(arrow, m, n);

    printf("LCS sequence: ");
    printLCS(arrow, X, m, n);
    printf("\n");

    return L[m][n];
}

int main() {
    char X[MAX], Y[MAX];

    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    int length = lcs_with_arrows(X, Y, m, n);
    printf("Length of LCS: %d\n", length);

    return 0;
}
