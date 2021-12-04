#include "AMS.h"

int main()
{
    File file;
    file.Read();
    Menu menu;
    AirlineCreator airlinecreator;
    airlinecreator.Creator();
    while (true) {
        if(!menu.StartMenu())break;
    }
}
