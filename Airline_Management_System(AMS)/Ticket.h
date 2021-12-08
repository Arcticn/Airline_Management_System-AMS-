#pragma once
#include "AirlineInfo.h"
#include "Passenger.h"

class Ticket:public AirlineInfo,public Passenger
{
public:
	Ticket() = default;
	Ticket(int id,string LineNo,tm date):
		Id(id),LineNo(LineNo), date(date) {}
	int Id;
	string LineNo;
	tm date;
	bool Order(int id,string LineNo,int number,int diffday, bool ifqueue);
};

