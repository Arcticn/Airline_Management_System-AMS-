#pragma once
#include "AirlineInfo.h"
#include "Passenger.h"

class Ticket:public Passenger,public AirlineInfo
{
public:
	Ticket() = default;
	Ticket(int id,string LineNo,tm date):
		Passenger(id),AirlineInfo(),date(date) {}
	tm date;
};

