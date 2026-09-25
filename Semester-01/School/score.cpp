#include <iostream>
using namespace std;

int main()
{

int total = 0, win = 0, loose = 0, draw = 0, score;

  for (int i = 1; i <= 30; ++i)
  {
    cout << "please enter the score: "; cin >> score;
    
    switch(score)
    {
      case 0 :
         
         loose++;
         break;
        
      case 1 :
        
         draw++;
         total += score;
         break;
       
      case 3 :
         
         win++;
         total += score;
         break;

      default:
        
         --i;
         cout << "invalid input! " << endl
              << "Try again!" << endl;
           
    }

  }
 cout << "wins: " << win <<endl
      << "looses: " << loose <<endl
      << "draws: " << draw <<endl
      << "total: " << total <<endl;
}