#include <stdio.h>

void setZeroes(int matrix[200][200], int m, int n) {
    int firstRowZero = 0;
    int firstColZero = 0;

    // Check first column
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }

    // Check first row
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }

    // Mark rows and columns
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Zero rows
    for (int i = 1; i < m; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero columns
    for (int j = 1; j < n; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 1; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero first column
    if (firstColZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }

    // Zero first row
    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
}
