#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 20
#define Max(a,b) ((a>b) ? a : b)

typedef struct SparseMatrixTerm{
    int row;
    int col;
    int val;
}sparse_term;

typedef struct Sparsematrix
{
    int NoT;
    int row_degree;
    int col_degree;
    sparse_term item[MAX_DEGREE];
}sparse_matrix;

sparse_matrix* createSparseMatrix(int N, int R, int C, sparse_term item[]){
    sparse_matrix* SM = (sparse_matrix*)malloc(sizeof(sparse_matrix));
    if (SM != NULL)
    {
        SM->NoT = N; SM->row_degree = R; SM->col_degree = C;
        for (int i = 0; i < SM->NoT; i++)
        {
            SM->item[i].row = item[i].row; SM->item[i].col = item[i].col; SM->item[i].val = item[i].val;
        }
    }
    return SM;    
}

void printSparseMatrix_1(sparse_matrix* SM){
    int count = SM->NoT;
    for (int i = 0; i < count; i++)
    {
        printf("%d %d %d\n",SM->item[i].row, SM->item[i].col, SM->item[i].val);
    }
}
void printSparseMatrix_2(sparse_matrix* SM){
    int idx=0, cnt = 0;
    for (int i = 0; i < SM->row_degree; i++)
    {
        for (int j = 0; j < SM->col_degree; j++)
        {
            if (cnt == (SM->item[idx].row)*SM->col_degree + SM->item[idx].col) //일반 행렬일 경우 순서 계산
            {
                printf("%3d ", SM->item[idx].val);
                idx++;
                cnt++;
            }
            else
            {
                printf("  0 ");
                cnt++;
            }
        }
        printf("\n");
    }
}

sparse_matrix* addSparseMatrix(sparse_matrix* sparse1, sparse_matrix* sparse2){
    if (sparse1->row_degree!=sparse2->row_degree && sparse1->col_degree!=sparse2->col_degree)
    {
        exit(1);
    }
    sparse_matrix* sparse3 = (sparse_matrix*)malloc(sizeof(sparse_matrix));
    if (sparse3 != NULL){
        int index_1=0, index_2=0, index_3=0;
        sparse3->row_degree = sparse1->row_degree, sparse3->col_degree= sparse1->col_degree;
        while (index_1 < sparse1->NoT || index_2 < sparse2->NoT)
        {   
            if(index_2 == sparse2->NoT && index_1 != sparse1->NoT)
            {
                sparse3->item[index_3].row =  sparse1->item[index_1].row;
                sparse3->item[index_3].col =  sparse1->item[index_1].col;
                sparse3->item[index_3++].val = sparse1->item[index_1++].val;
            }
            else if(index_2 != sparse2->NoT && index_1 == sparse1->NoT)
            {
                sparse3->item[index_3].row =  sparse2->item[index_2].row;
                sparse3->item[index_3].col =  sparse2->item[index_2].col;
                sparse3->item[index_3++].val = sparse2->item[index_2++].val;
            }
            if (sparse1->item[index_1].row == sparse2->item[index_2].row) //행이 같을 때
            {
                if (sparse1->item[index_1].col == sparse2->item[index_2].col) //행 같고 열 같을 때
                {
                    sparse3->item[index_3].row =  sparse1->item[index_1].row;
                    sparse3->item[index_3].col =  sparse1->item[index_1].col;
                    sparse3->item[index_3++].val = sparse1->item[index_1++].val + sparse2->item[index_2++].val;
                }
                
                else if (sparse1->item[index_1].col < sparse2->item[index_2].col) // 행은 같고 sparse1 열이 더 작을 때
                {
                    sparse3->item[index_3].row =  sparse1->item[index_1].row;
                    sparse3->item[index_3].col =  sparse1->item[index_1].col;
                    sparse3->item[index_3++].val = sparse1->item[index_1++].val;
                }
                else { // 행은 같고 sparse2 열이 더 작을 때
                    sparse3->item[index_3].row =  sparse2->item[index_2].row;
                    sparse3->item[index_3].col =  sparse2->item[index_2].col;
                    sparse3->item[index_3++].val = sparse2->item[index_2++].val;
                }
            }
            else if (sparse1->item[index_1].row < sparse2->item[index_2].row) // sparse1의 행이 더 작을 때
            {
                sparse3->item[index_3].row =  sparse1->item[index_1].row;
                sparse3->item[index_3].col =  sparse1->item[index_1].col;
                sparse3->item[index_3++].val = sparse1->item[index_1++].val;
            }
            else // sparse2의 행이 더 작을 때
            {
                sparse3->item[index_3].row =  sparse2->item[index_2].row;
                sparse3->item[index_3].col =  sparse2->item[index_2].col;
                sparse3->item[index_3++].val = sparse2->item[index_2++].val;
            }
        }
        sparse3->NoT = index_3;
    }
    return sparse3;
}

sparse_matrix* addSparseMatrix2(sparse_matrix* sparse1, sparse_matrix* sparse2){
    if (sparse1->row_degree!=sparse2->row_degree && sparse1->col_degree!=sparse2->col_degree)
    {
        exit(1);
    }
    sparse_matrix* sparse3 = (sparse_matrix*)malloc(sizeof(sparse_matrix));
    if (sparse3 != NULL){
        int index_1=0, index_2=0;
        int element_1=0, element_2=0, element_3=0;
        int elementCnt=0;

        sparse3->row_degree = sparse1->row_degree, sparse3->col_degree= sparse1->col_degree;

        while (element_1 < sparse1->NoT && element_2 < sparse2->NoT)
        {   
            index_1 = sparse1->item[element_1].row * sparse1->col_degree + sparse1->item[element_1].col;
            index_2 = sparse2->item[element_2].row * sparse2->col_degree + sparse2->item[element_2].col;
            if (index_1 < index_2)
            {
                sparse3->item[element_3++] = sparse1->item[element_1++];
                elementCnt++;
            }

            else if (index_1 == index_2)
            {
                if (sparse1->item[element_1].val + sparse2->item[element_2].val != 0)
                {
                    sparse3->item[element_3].row =  sparse1->item[element_1].row;
                    sparse3->item[element_3].col =  sparse1->item[element_1].col;
                    sparse3->item[element_3++].val = sparse1->item[element_1++].val + sparse2->item[element_2++].val;
                    elementCnt++;
                }
                else
                {
                    element_1++;
                    element_2++;
                }
            }
            else
            {
                sparse3->item[element_3++] = sparse2->item[element_2++];
                elementCnt++;
            }
        }    
        
        for (int i = element_1; i < sparse1->NoT; i++)
        {
            sparse3->item[element_3++] = sparse1->item[i];
            elementCnt++;
        }
        for (int i = element_2; i < sparse2->NoT; i++)
        {
            sparse3->item[element_3++] = sparse2->item[i];
            elementCnt++;
        }
        sparse3->NoT = elementCnt;
    }
    return sparse3;
}

int main(){
    sparse_term itemA[] = { {0, 2, 2}, {0, 6, 12}, {1, 4, 7}, {2, 0, 23}, {3, 3, 31},
                            {4, 1, 14}, {4, 5, 25}, {5, 6, 6}, {6, 0, 52}, {7, 4, 11}   };
    sparse_matrix* SA = createSparseMatrix(10, 8, 7, itemA);
    sparse_term itemB[] = { {0, 2, 23}, {0, 6, 52}, {1, 4, 14}, {2, 0, 2}, {3, 3, 31},
                            {4, 1, 7}, {4, 7, 11}, {5, 4, 25}, {6, 0, 12}, {6, 5, 6}   };
    sparse_matrix* SB = createSparseMatrix(10, 8, 7, itemB);
    sparse_matrix* SC = addSparseMatrix2(SA, SB);
    
    printf("\n\n");
    printSparseMatrix_2(SA);
    printf("\n\n");
    printSparseMatrix_2(SB);
    printf("\n\n");
    printSparseMatrix_1(SC);
    printf("\n\n");
    printSparseMatrix_2(SC);

    free(SA);
    free(SB);
    free(SC);
    return 0;
}