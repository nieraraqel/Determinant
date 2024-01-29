#include <stdio.h>
#include <stdlib.h>

int AdditionalMinor(int const n, long int** matrix, int current_row, bool columns[]) {
    int add_minor = 0, minor_j = 0;

    if(current_row == n - 1) {
        for(int i = 0; i < n; i++) {
            if(!columns[i]) {
                return matrix[current_row][i];
            }
        }
    }
    for(int j = 0; j < n; j++) {
        if(columns[j]) {
            continue;
        }
        columns[j] = true;
        int matrix_current_element = matrix[current_row][j];
        int sub_det = AdditionalMinor(n, matrix, current_row + 1, columns);

        columns[j] = false;

        add_minor += ((minor_j % 2) * (-2) + 1) * sub_det * matrix_current_element;
        minor_j++;
    }

    return add_minor;
}
void MatrixInput(int const n, long int** matrix) {
    int  i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("[%d][%d]:", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void MatrixOutput(int const n, long int** matrix) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%ld ", matrix[i][j]);
        }
        printf("\n");
    }

}

int Result (int const n, long int** matrix) {
    bool columns[n] = {};

    return AdditionalMinor(n, matrix, 0, columns);
}

int main(void) {
    int n = 1;

    while(n < 2) {
        printf("Enter matrix size greater than one:\n");
        scanf("%d", &n);
    }
    long int** matrix = (long int**) malloc(n * sizeof(long int));
    for(int i = 0; i < n; i++) {
        matrix[i] = (long int*) malloc(n * sizeof(long int));
    }


    printf("Enter matrix elements:\n");
    MatrixInput(n, matrix);

    printf("\nYour matrix:\n");
    MatrixOutput(n, matrix);

    printf("\nThe determinant of this matrix is equal to:\n");
    printf("%d", Result(n, matrix));

    for (int i = 0; i < n; i++){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}