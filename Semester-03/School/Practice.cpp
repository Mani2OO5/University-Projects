#include <iostream>
using namespace std;
const int SIZE = 3;


void transpose(int bs[SIZE][SIZE], int bt[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            bt[j][i] = bs[i][j];  
        }
    }
}

int main() 
{
    
    int first[SIZE][SIZE] = 
    {
        {1, 2, 4},
        {3, 1, 1},
        {0, 0, 5}
    };

    int second[SIZE][SIZE];

    transpose(first, );

    cout << "Original matrix:\n"; 

    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << bs[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nTranspose matrix:\n"; 

    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            cout << bt[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
