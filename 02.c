#include <stdio.h>

#define MAX 10

int main() {
    int a[MAX][MAX] = {0}, b[MAX][MAX] = {0}, sum[MAX][MAX] = {0};
    int row, col, n1, n2, count = 0;
    int r, c, val;

    printf("Enter the total rows and columns: ");
    scanf("%d%d", &row, &col);

    printf("Enter the number of non-zero elements in matrix 1: ");
    scanf("%d", &n1);

    printf("Enter the row, column, and values for non-zero elements in matrix 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d%d%d", &r, &c, &val);
        a[r][c] = val;
    }

    printf("Enter the number of non-zero elements in matrix 2: ");
    scanf("%d", &n2);

    printf("Enter the row, column, and values for non-zero elements in matrix 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d%d%d", &r, &c, &val);
        b[r][c] = val;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            if (sum[i][j] != 0){
                count++;
            }
        }
    }

    printf("\nSum Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    printf("\nCompact Form (row col value):\n");
    printf("%d %d %d\n", row, col, count);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (sum[i][j] != 0) {
                printf("%d %d %d\n", i, j, sum[i][j]);
            }
        }
    }

    printf("\nTranspose Matrix:\n");
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", sum[j][i]);
        }
        printf("\n");
    }
}
