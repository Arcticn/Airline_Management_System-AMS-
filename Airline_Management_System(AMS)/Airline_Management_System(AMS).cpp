#include "AMS.h"

void SyncTime() {
    time_t rawtime;
    while (true) {
        time(&rawtime);
        CurTime = localtime(&rawtime);
        this_thread::sleep_for(chrono::seconds(3));
    }
}

int main()
{
    cout << "正在初始化,请稍等...";
    File file = File();
    AirlineCreator airlinecreator=AirlineCreator();
    Menu menu = Menu();
    file.Read();
    airlinecreator.Creator();
    thread(SyncTime).detach();
    //thread(&AirlineCreator::TicketDestroyer, ref(airlinecreator)).detach();
    while (true) {
        if(!menu.StartMenu())break;
    }
}
