#include <iostream>
using namespace std;

struct Element 
{
    int row;
    int col;
    int value;
};

void addSparseMatrices(const Element matrix1[], int size1, const Element matrix2[], int size2, Element result[], int& resultSize) 
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) 
    {
        if (matrix1[i].row < matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col))
        {
            result[k++] = matrix1[i++];
        }
        else if (matrix1[i].row > matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col > matrix2[j].col)) 
        {
            result[k++] = matrix2[j++];
        }
        else 
        {
            int sum = matrix1[i].value + matrix2[j].value;
            if (sum != 0) 
            {
                result[k++] = {matrix1[i].row, matrix1[i].col, sum};
            }
            i++;
            j++;
        }
    }

    while (i < size1) 
    {
        result[k++] = matrix1[i++];
    }

    while (j < size2) 
    {
        result[k++] = matrix2[j++];
    }

    resultSize = k;
}

void printSparseMatrix(const Element matrix[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << "| " << matrix[i].row << "  " << matrix[i].col << "  " << matrix[i].value << " |" << endl;
    }
}

int main() 
{
    const int size1 = 4;
    Element matrix1[size1] = 
    {
        {0, 0, 3},    
        {0, 3, 5},   
        {1, 1, 2},   
        {2, 2, 6} 
       
    };
    const int size2 = 4;
    Element matrix2[size2] = 
    {
        {0, 1, 4},  
        {0, 3,-5},  
        {1, 1, 3},  
        {3, 3, 7}    
    };

    const int maxSize = size1 + size2;
    Element result[maxSize];
    int resultSize = 0;

    addSparseMatrices(matrix1, size1, matrix2, size2, result, resultSize);
    cout << "result:" << endl;
    printSparseMatrix(result, resultSize);

    return 0;
}
