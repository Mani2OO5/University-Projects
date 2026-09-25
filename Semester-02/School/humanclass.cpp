#include <iostream>
#include <string>
using namespace std;

class Human
{
    private: 
     string walk = "I Can Walk!";
     string talk = "I Can Talk!";
     string  eat = "I Can Eat!";
    public:
     void walking() {cout << walk << endl;}
     void talking() {cout << talk<< endl;}
     void eating()  {cout << eat<< endl;}


};
class Teacher : public Human
{
   private:
    string teach = "I Can Teach!";
    public:
    void Teaching(){ cout << teach << endl;}
};
class SportMan : public Human
{
  private:
    string Exercise = "I Can Exercise!";
 public:
  void Exercising(){ cout << Exercise << endl;}
};
class BuisnessMan : public Human
{
  private:
    string Work = "I Can Work!";
  public:
   void Working(){ cout << Work << endl;}
};

class FootBallPlayer : public SportMan
{
   private:
    string Play = "I Can Play FootBall!";

  public:
  void Playing() { cout << Play << endl;}
    
    
};
int main()
{
    Teacher Frank;
    Frank.walking();
    FootBallPlay Max;
    Max.talking();
}
