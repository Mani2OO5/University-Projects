#include <iostream>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;

string FindIP(string Input)
{
  map <string , string> Link;
 
  Link["yahoo.com"]    = "74.6.231.20"    ;
  Link["youtube.com"]  = "142.251.35.174" ;
  Link["google.com"]   = "142.251.40.174" ;
  Link["facebook.com"] = "57.144.180.1"   ;
  Link["instagram.com"]= "157.240.19.174" ;
  Link["x.com"]        = "162.159.140.229";            

  if (Link.find(Input) != Link.end())
  {
    cout << "The IP Is : " << Link[Input] << endl;
    return Link[Input];
  }
  else if (Input == "|?") 
  { 
        cout << "to get IP : example.com" << endl
             << "to stop: exit" << endl;
        
        return "";
  }
  else if (Input == "exit") 
  {
    cout << "Program exited successfully." << endl;
    return "exit";
  }
  else
  {
    cout << "wrong input. TRY AGAIN" << endl;
  }
}

void open_link(string IP)
{
    if (IP.empty() or IP == "exit") return;
    string Ans;
    cout << "open IP?(YES or NO)" << endl; getline(cin, Ans);
    transform(Ans.begin(), Ans.end(), Ans.begin(), ::tolower);

    if (Ans == "yes")
    {
      string command = "start http://" + IP;
      system(command.c_str());
    }
    else if(Ans == "no")
    {
      return;
    }
    else
    {
      cout << "wrong input " << endl;
      open_link(IP);
    }

}

int main() 
{
 string Input;
 while(Input != "exit")
 {
  cout << "(|? for help)(Insert the link):"; getline(cin , Input);
  transform(Input.begin(), Input.end(), Input.begin(), ::tolower);
  string IpAddress = FindIP(Input);
  if (!IpAddress.empty())
   open_link(IpAddress);
 }
}
//add function
//remove function
//change fuction
