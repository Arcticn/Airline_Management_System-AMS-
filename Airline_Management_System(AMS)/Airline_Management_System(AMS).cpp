#include "AMS.h"

int main()
{
    File file = File();
    file.Read();
    Menu menu = Menu();
    AirlineCreator airlinecreator;airlinecreator.Creator();
    while (true) {
        if(!menu.StartMenu())break;
    }
}
