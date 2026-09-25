 int Array_size3 = 9;
  int Array1_size = sizeof(Array1) / sizeof(Array1[0]);
  int Array2_size = sizeof(Array2) / sizeof(Array2[0]);
  int Array3_size;
  if (Array1_size > Array2_size)
  {
    Array3_size = Array1_size;
  }
  else
  {
    Array3_size = Array2_size;
  }
  int Array3[Array3_size];