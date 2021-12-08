#pragma once
#include "AirlineInfo.h"
#include "Passenger.h"

class Ticket:public Passenger
{
public:
	Ticket() = default;
	Ticket(int id,string LineNo,tm date):
		Passenger(id),LineNo(LineNo), date(date) {}
	tm date;
	string LineNo;
	void Order(int id,string LineNo,tm date);
};

