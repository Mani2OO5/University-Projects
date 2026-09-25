#include <iostream>
#include <conio.h>
using namespace std;

const int DataSize = 100;
int Data[DataSize];
int CurrentSize = 0;

bool Add(int Array[], int number ,int &CurrentSize , int MaxSize)
{
  if (CurrentSize < MaxSize)
  {
   Array[CurrentSize] = number;
   CurrentSize++;
   return true;
  }
  else 
  { 
    cout << "There is not enough Space." << endl;
    return false;
  }
}

void InsertionSort(int Array[],int ArraySize)
{
  
  for (int i = 1 ; i < ArraySize ; i++)
  {
    int Key = Array[i];
    int j = i - 1;
    while(j >= 0 && Array[j] > Key)
    {
      Array[j + 1] = Array[j];
      j = j - 1;
    }
    Array[j + 1] = Key;
  }
}

int BinarySearch(int Array[] , int Key , int Low , int High )
{
  if (High < Low)  return -1;

  int Mid = (Low + High) / 2;
  
  if (Array[Mid] == Key) {return Mid;}

  else if( Key < Array[Mid])
  {
    return BinarySearch(Array,Key,Low,Mid);
  }

  else
  {
   return BinarySearch(Array,Key,Mid + 1,High);
  }
}

bool Odd_OR_Even(int Data[], int &CurrentSize, int MaxSize)
{
    

    int number;
    cout << "insert a number: "; cin >> number;
    
    int Status = BinarySearch(Data , number ,0, DataSize - 1);

    if (Status != -1)
    {
        cout << "the number is even" << endl;
        return true;
     
    }
    else
    {
    
      if(number % 2 == 0)
      {
        cout << "the number is even"  << endl;
      
        bool check = Add(Data,number,CurrentSize,DataSize);
        if(!check) return false;
        
        InsertionSort(Data,CurrentSize);
     
      }
      else
      {
        cout << "the number is Odd"  << endl;
        return true;
      }
    }
}


int main()
{
  bool Program = true;
  while(Program)
  {
     Program = Odd_OR_Even(Data, CurrentSize, DataSize); 
  }
}