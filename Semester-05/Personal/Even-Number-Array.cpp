#include <iostream>
using namespace std;

void Add(int Array[], int number, int &CurrentSize, int MaxSize)
{
    if (CurrentSize < MaxSize)
    {
        Array[CurrentSize] = number;
        CurrentSize++;
    }
    else
    {
        cout << "There is not enough space." << endl;
    }
}

void InsertionSort(int Array[], int ArraySize)
{
    for (int i = 1; i < ArraySize; i++)
    {
        int Key = Array[i];
        int j = i - 1;
        while (j >= 0 && Array[j] > Key)
        {
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = Key;
    }
}

int BinarySearch(int Array[], int Key, int Low, int High)
{
    if (High < Low)
        return -1;

    int Mid = (Low + High) / 2;

    if (Array[Mid] == Key)
        return Mid;
    else if (Key < Array[Mid])
        return BinarySearch(Array, Key, Low, Mid - 1);
    else
        return BinarySearch(Array, Key, Mid + 1, High);
}

{
    int number;
    cout << "Insert a number: ";
    cin >> number;

    int Status = BinarySearch(Data, number, 0, CurrentSize - 1);

    if (Status != -1)
    {
        cout << "The number already exists in array. It is even (by assumption)." << endl;
    }
    else
    {
        if (number % 2 == 0)
        {
            cout << "The number is even and added to the array." << endl;
            Add(Data, number, CurrentSize, MaxSize);
            InsertionSort(Data, CurrentSize);
        }
        else
        {
            cout << "The number is odd." << endl;
        }
    }
}

int main()
{
    const int DataSize = 100;
    int Data[DataSize];
    int CurrentSize = 0;
    for (int i = 0; i < 5; i++)
    {
        Odd_OR_Even(Data, CurrentSize, DataSize);
    }

    return 0;
}
