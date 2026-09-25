#include <iostream>
#include <map>
using namespace std;



void voted_check(string name)
{
    map <string , int> voted;
    
    if(voted.find(name) != voted.end())
    {
        cout << "Kick Them Out" << endl;
    }
    else
    {
      voted[name] = 1;
      cout << "Let Them Vote!" << endl;
    }
}

int main() 
{
    string name;
    while(true)
    {
        cout << "enter the name (or type exit to stop): "; cin >> name;
        if (name == "exit")
          break;
        voted_check(name);
    }
    return 0;
}
