#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
   
   while(true)
  {
    
    cout << "*";
    
    if(kbhit())
    {
      char key = getch();
        if(key == 'c' or key == 'C')
         break;

    }
  }

return 0;
}
