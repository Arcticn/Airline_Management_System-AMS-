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
#include "Weather.h"
#include "File.h"

struct Time
{
    Time() = default;

    string weekday;
    string day;
    string time;
};



//Time aa = { "星期日","2021-11-30","20:30" };
//AirlineInfo a ( "东方航空","CA4563","上海","北京","C919",aa,aa,260,20 );

