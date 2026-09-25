#include <iostream>

void fibonacci(int n)
{
  if (n <= 0 )  return; 

  int *arr = new int[n];

  *arr  = 0;
  *(arr + 1) = 1;

  std::cout << *arr << " " << *(arr + 1) << " ";
  for (int i = 2 ; i < n ; i++)
  {
    *(arr + i ) = *(arr + (i - 1) ) + *(arr + (i - 2));
    std::cout << *(arr + i ) << " ";
  } 

  delete[] arr;
}


int main()
{
  fibonacci(47);
}