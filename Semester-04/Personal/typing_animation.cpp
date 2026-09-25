#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <conio.h>

#define SHINY_GREEN "\033[1;92m"
#define RESET_COLOR "\033[0m"

void delay(int milliseconds) 
{
    clock_t start_time = clock();
    clock_t end_time = start_time + (milliseconds * CLOCKS_PER_SEC / 1000);
    while (clock() < end_time) {}
}

void type(const std::string& text, int delay_ms = 50) 
{
    for (char c : text) 
    {
        std::cout << SHINY_GREEN << c << RESET_COLOR;
        std::cout.flush();
        delay(delay_ms);
    }
}

int main()
{
    std::string ans;
    delay(3000)
    type("Hello");
    delay(1000);
    type("!");
    delay(2000);
    std:: cout << std::endl;
    type("How are you");
    delay(1000);
    type("?");
    std:: cout << std::endl;
    std::cin >> ans;
    if (ans == "Good" or "fine" or )
    {
        type("good too hear that!");
    }
    
    std:: cout << std::endl;
    delay(1000);
    type("lets play a game");
    std:: cout << std::endl;
    delay(1000);
    type("do you like games")
    delay(1000);
    type("?");
    cout << ans2 ;
    
    getch();
}