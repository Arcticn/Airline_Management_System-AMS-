#include "AMS.h"

int main()
{
    cout << "正在初始化,请稍等...";
    File file = File();
    AirlineCreator airlinecreator=AirlineCreator();
    Menu menu = Menu();
    file.Read();
    airlinecreator.Creator();
    //thread(&AirlineCreator::TicketDestroyer, ref(airlinecreator)).detach();
    while (true) {
        if(!menu.StartMenu())break;
    }
}
