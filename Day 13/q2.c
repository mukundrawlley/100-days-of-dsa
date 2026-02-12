int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        returnSize = 0;
        return NULL;
    }

    int m = matrixSize;
    int n = matrixColSize[0];
    int result = (int*)malloc(sizeof(int) * m * n);
    int index = 0;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            result[index++] = matrix[top][i];
        top++;

        for (int i = top; i <= bottom; i++)
            result[index++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result[index++] = matrix[bottom][i];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[index++] = matrix[i][left];
            left++;
        }
    }

    *returnSize = index;
    return result;
}
