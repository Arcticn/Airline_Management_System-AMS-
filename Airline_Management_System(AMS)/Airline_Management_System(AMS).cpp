#include "AMS.h"

int main()
{
    Menu menu;
    AirlineCreator airlinecreator;
    airlinecreator.Creator();
    while (true) {
        if(!menu.StartMenu())break;
    }
}
