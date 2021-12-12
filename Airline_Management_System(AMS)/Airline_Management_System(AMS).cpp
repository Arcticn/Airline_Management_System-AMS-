
#include "AMS.h"

int main()
{
    cout << "正在初始化,请稍等...";
    File file = File();
    AirlineCreator airlinecreator=AirlineCreator();
    Menu menu = Menu();
    file.Read();
    //PassengerDatabase.reserve(100000);
    AirlineInfoDatabase.reserve(2000);
    airlinecreator.Creator();
    //SyncTime();
    thread(SyncTime).detach();
    this_thread::sleep_for(chrono::milliseconds(10));
    thread(RefreshLine).detach();
    this_thread::sleep_for(chrono::seconds(1));
    //airlinecreator.TicketCreator();
    thread(&AirlineCreator::TicketCreator, ref(airlinecreator)).detach();
    while (true) {
        if(!menu.StartMenu())break;
    }
}
