//all ASCII
#include <iostream>
using namespace std;
int main(){
 
 for(char ch=-128;ch<127;ch++)
    cout<<"character: "<<ch
        <<"\tASCII code: "<<(int)ch<<"\n"
        <<"character: "<<ch<<"\tASCII Code: "<<endl;
        return 0;
}