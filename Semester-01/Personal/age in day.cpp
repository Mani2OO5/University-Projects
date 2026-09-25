//Date
#include <iostream>
#include <chrono>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int main(){
int BirthDay,BirthMonth,BirthYear;
int This_Day,This_Month,This_Year;
int Day, Dayss, Month, Year, Days  ;
    cout<<"please enter your birth Day: " ;
     cin>>BirthDay;
      cout<<"please enter your birth Month: " ;
       cin>>BirthMonth;
        cout<<"please enter your birth year: " ;
         cin>>BirthYear;
         system ('cls');
          cout<<"please enter This Day: " ;
            cin>>This_Day;
             cout<<"please enter This Month: " ;
              cin>>This_Month;
               cout<<"please enter This year: " ;
                cin>>This_Year; 

Year = This_Year - BirthYear;
Year = Year * 365 + Year/4 ;
Month = abs(This_Month - BirthMonth);
Month = Month * 30;
Day = abs(This_Day - BirthDay);
cout<<abs(Year -Month -Day);


    return 0;
}