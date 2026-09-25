#include <fstream>
#include <iostream>
using namespace std;

int main() {
    fstream file("data.txt", ios::in | ios::out | ios::app);
    file  << 2;
    cout << "DONE!";
    file.close();
}
