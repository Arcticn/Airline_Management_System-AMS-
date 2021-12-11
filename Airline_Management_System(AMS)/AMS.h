#pragma once

#include "Common.h"
#include "Time.h"
#include "QuickUse.h"
#include "Airport.h"
#include "Airplane.h"
#include "AirlineInfo.h"
#include "Ticket.h"
#include "Passenger.h"
#include "Login.h"
#include "Menu.h"
#include "SuperUserInterface.h"
#include "UserInterface.h"
#include "File.h"
#include "AirlineCreator.h"
#include "AirlineBoard.h"

typedef duration<int, std::nano> nano_type;
typedef duration<int, std::ratio<60 * 60 * 24>> days_type;

extern tm CurTime;
extern time_t rawtime;
extern int User_ID;
extern vector<string>Company;
extern vector<Airplane>AirplaneDatabase;
extern vector<Airport>AirportDatabase;
extern vector<AirlineInfo>AirlineInfoDatabase;
extern unordered_map<int, Passenger>PassengerDatabase;
extern unordered_map<string, int>UserToID;
extern unordered_map<string, int>LineQuickFind;
extern map<string, string>Superuser;
extern unordered_map<string, string>User;

//Time aa = { "星期日","2021-11-30","20:30" };
//AirlineInfo a ( "东方航空","CA4563","上海","北京","C919",aa,aa,260,20 );

