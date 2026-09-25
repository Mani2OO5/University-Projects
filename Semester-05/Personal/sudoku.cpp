#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void show(int Matrix[9][9])
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cout << Matrix[i][j] << " ";

      if (j == 2 or j == 5)
      {
        cout << "| ";
      }
    }
    if (i == 2 or i == 5)
    {
      cout << endl;
      cout << "---------------------";
    }
    cout << endl;
  }
}



void Intersection(int Array1[], int Array2[],int Array1_size, int Array2_size)
{
  //int Array1_size = sizeof(Array1) / sizeof(Array1[0]);
  //int Array2_size = sizeof(Array2) / sizeof(Array2[0]);
 
  int Array3_size;
  if (Array1_size < Array2_size)
  {
    Array3_size = Array1_size;
  }
  else
  {
    Array3_size = Array2_size;
  }

  int* Array3 = new int[Array3_size];
  for(int i = 0; i < Array3_size; i++)
  {
    for (int j = 0; j < Array1_size; j++)
    {
      if (Array3[i] == Array1[j])
        {
        }
      
    }
    for (int j = 0; j < Array2_size; j++)
      {
        if (Array3[i] == Array2[j])
        {
        }
      }
  }
  delete[] Array3;
}




int Generate()
{
  // create:
  int Sudoku[9][9];
  srand(time(0));

  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      Sudoku[i][j] = 1 + (rand() % 9);
    }
  }

  show(Sudoku);
  cout << endl;
}

int main()
{
  Generate();
}