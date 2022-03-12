/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/*
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded.
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    int i,j,k,l;
    int temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8;

    if(M == 32 && N == 32)
    {
        for(i = 0; i < M; i += 8)
        {
            for(j = 0; j < N; j++)
            {
                temp1 = A[j][i];
                temp2 = A[j][i+1];
                temp3 = A[j][i+2];
                temp4 = A[j][i+3];
                temp5 = A[j][i+4];
                temp6 = A[j][i+5];
                temp7 = A[j][i+6];
                temp8 = A[j][i+7];

                B[i][j] = temp1;
                B[i+1][j] = temp2;
                B[i+2][j] = temp3;
                B[i+3][j] = temp4;
                B[i+4][j] = temp5;
                B[i+5][j] = temp6;
                B[i+6][j] = temp7;
                B[i+7][j] = temp8;
            }
        }
    }

    if(M == 64 && N == 64)
    {
        for (i = 0; i < N; i += 8)
        {
            for (j = 0; j < M; j += 8)
            {
                for (k = i; k < i + 4; k++)
                {
                    temp1 = A[k][j];
                    temp2 = A[k][j + 1];
                    temp3 = A[k][j + 2];
                    temp4 = A[k][j + 3];
                    temp5 = A[k][j + 4];
                    temp6 = A[k][j + 5];
                    temp7 = A[k][j + 6];
                    temp8 = A[k][j + 7];

                    B[j][k] = temp1;
                    B[j + 1][k] = temp2;
                    B[j + 2][k] = temp3;
                    B[j + 3][k] = temp4;
                    B[j][k + 4] = temp5;
                    B[j + 1][k + 4] = temp6;
                    B[j + 2][k + 4] = temp7;
                    B[j + 3][k + 4] = temp8;
                }
                for (l = j + 4; l < j + 8; l++)
                {
                    temp5 = A[i + 4][l - 4];
                    temp6 = A[i + 5][l - 4];
                    temp7 = A[i + 6][l - 4];
                    temp8 = A[i + 7][l - 4];
                    temp1 = B[l - 4][i + 4];
                    temp2 = B[l - 4][i + 5];
                    temp3 = B[l - 4][i + 6];
                    temp4 = B[l - 4][i + 7];

                    B[l - 4][i + 4] = temp5;
                    B[l - 4][i + 5] = temp6;
                    B[l - 4][i + 6] = temp7;
                    B[l - 4][i + 7] = temp8;
                    B[l][i] = temp1;
                    B[l][i + 1] = temp2;
                    B[l][i + 2] = temp3;
                    B[l][i + 3] = temp4;

                    temp1 = A[i + 4][l];
                    temp2 = A[i + 5][l];
                    temp3 = A[i + 6][l];
                    temp4 = A[i + 7][l];

                    B[l][i + 4] = temp1;
                    B[l][i + 5] = temp2;
                    B[l][i + 6] = temp3;
                    B[l][i + 7] = temp4;
                }
            }
        }
    }

    if(M == 61 && N == 67)
    {
        for (i = 0; i < N; i += 17)
        {
            for (j = 0; j < M; j += 17)
            {
                for(k = i; k < i + 17 && k < N; k++)
                {
                    for(l = j; l < j + 17 && l < M; l++)
                    {
                        temp1 = A[k][l];
                        B[l][k] = temp1;
                    }
                }
            }
        }
    }
}

/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

/*
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);

}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; ++j)
        {
            if (A[i][j] != B[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}

