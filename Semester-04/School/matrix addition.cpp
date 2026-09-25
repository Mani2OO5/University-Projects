#include <iostream>
using namespace std;

class Matrix
{
private:
    int m[2][2];

public:
    Matrix(int n11, int n12, int n21, int n22) : m{{n11, n12}, {n21, n22}} {}

    void show()
    {
        cout << "Matrix:" << endl;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << m[i][j] << "\t";
            }
            cout << endl;
        }
    }

    int get(int row, int col)
    {
        return m[row - 1][col - 1];
    }

    void set(int row, int col, int num)
    {
        m[row - 1][col - 1] = num;
    }
};

class MatrixOp
{
private:
    Matrix mate1;
    Matrix mate2;

public:
    MatrixOp(Matrix m1, Matrix m2) : mate1(m1), mate2(m2) {}

    Matrix operator +()
    {
        Matrix result(mate1.get(1, 1) + mate2.get(1, 1),
                      mate1.get(1, 2) + mate2.get(1, 2),
                      mate1.get(2, 1) + mate2.get(2, 1),
                      mate1.get(2, 2) + mate2.get(2, 2));
        return result;
    }

    Matrix operator -()
    {
        Matrix result(mate1.get(1, 1) - mate2.get(1, 1),
                      mate1.get(1, 2) - mate2.get(1, 2),
                      mate1.get(2, 1) - mate2.get(2, 1),
                      mate1.get(2, 2) - mate2.get(2, 2));
        return result;
    }
};

int main()
{
    Matrix mat1(1, 2, 3, 4);
    Matrix mat2(5, 6, 7, 8);

    cout << "Matrix 1:" << endl;
    mat1.show();
    cout << "Matrix 2:" << endl;
    mat2.show();

    MatrixOp op(mat1, mat2);

    cout << "Result of matrix addition:" << endl;
    Matrix result_add = +op;
    result_add.show();

    cout << "Result of matrix subtraction:" << endl;
    Matrix result_sub = -op;
    result_sub.show();

    return 0;
}
