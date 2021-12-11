#pragma once

#include "Common.h"
#include "AirlineInfo.h"
#include "AirlineCreator.h"
#include "AirlineBoard.h"
#include "Airport.h"
#include "Airplane.h"
#include "Passenger.h"
#include "Login.h"
#include "Menu.h"
#include "SuperUserInterface.h"
#include "UserInterface.h"
#include "Time.h"
#include "Weather.h"
#include "File.h"
#include "QuickUse.h"
#include "Ticket.h"
typedef duration<int, std::nano> nano_type;
typedef duration<int, std::ratio<60 * 60 * 24>> days_type;

tm CurDate;
tm *CurTime;
time_t rawtime;
extern vector<string>Company;
extern vector<Airplane>AirplaneDatabase;
extern vector<Airport>AirportDatabase;
extern vector<AirlineInfo>AirlineInfoDatabase;
extern unordered_map<int, Passenger>PassengerDatabase;
extern unordered_map<string, int>LineQuickFind;

//Time aa = { "星期日","2021-11-30","20:30" };
//AirlineInfo a ( "东方航空","CA4563","上海","北京","C919",aa,aa,260,20 );

