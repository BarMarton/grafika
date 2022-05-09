#include "matrix.h"

#include <stdio.h>
#include "math.h"
void multiply_matricies(float a[3][3], float b[3][3], float result[3][3]);

void rotate(float matrix[3][3], float angle, float result[3][3]){
    float rotation[3][3];
    rotation[0][0] = cos(angle); rotation[0][1] = -sin(angle); rotation[0][2] = 0;
    rotation[1][0] = sin(angle); rotation[1][1] = cos(angle); rotation[1][2] = 0;
    rotation[2][0] = 0; rotation[2][1] = 0; rotation[2][2] = 1;

    multiply_matricies(matrix, rotation, result);
}

void shift(float matrix[3][3], float shift[3]){
    int i, j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] += shift[j];
        }
    }
}

void scale(float matrix[3][3], float result[3][3], float scalar){
    int i, j;
    float scale[3][3];
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            if(i=j) matrix[i][j] = scalar;
            else matrix[i][j] = 0.0;
        }
    }

    multiply_matricies(scale, matrix, result);
}

void transform_point(float input[3], float matrix[3][3], float result[3]){
    int i, j;
    int temp;
    for(i = 0; i<3; i++){
        for(j = 0; j<3; j++){
            temp = temp + (input[j] * matrix[i][j]);
        }
        result[i] = temp;
    }
}

void multiply_matricies(float a[3][3], float b[3][3], float result[3][3]){
    int i, j, k;
    for(i=0;i< 3;i++)
    {
        for(j=0;j< 3;j++)
        {
            result[i][j] = 0;
            for(k=0;k< 3;k++)
            {
                result[i][j] = result[i][j] + a[i][k]*b[j][k];
            }
        }
    }
}

void matrix_scalar_multiplication(float matrix[3][3], float scalar){
    int i, j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = scalar * matrix[i][j];
        }
    }
}

void init_identity_matrix(float matrix[3][3]){
    int i, j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            if(i=j) matrix[i][j] = 1.0;
            else matrix[i][j] = 0.0;
        }
    }
}

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

