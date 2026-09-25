#include <iostream> 
#include <string>

using namespace std;

struct humans
{
    short int age;
    string sex;
    string first_name;
    string last_name;
    string job;
    
};
int main()
{
humans person[5];

person[0].age = 70 ;
person[0].sex = "female" ;
person[0].first_name = "eli" ;
person[0].last_name = "moon" ;
person[0].job = "lawyer";


person[1].age = 56 ;
person[1].sex = "male" ;
person[1].first_name = "ali" ;
person[1].last_name = "foo" ;
person[1].job = "worker";

person[2].age = 20 ;
person[2].sex = "female" ;
person[2].first_name = "sarah" ;
person[2].last_name = "moo" ;
person[2].job = "engineer";

person[3].age = 35 ;
person[3].sex = "male" ;
person[3].first_name = "bob" ;
person[3].last_name = "pink" ;
person[3].job = "doctor";

for (int i = 0 ; i < 5 ; ++i)
{
    if (person[i].age >= 50)
     cout << person[i].first_name << " " << person[i].last_name <<" is retired" << endl;


}

}

