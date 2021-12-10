#pragma once
#include "AirlineInfo.h"
#include "Passenger.h"

class Ticket:public AirlineInfo,public Passenger
{
public:
	std::chrono::high_resolution_clock::time_point start = high_resolution_clock::now();
	Ticket() = default;
	Ticket(int Id,string LineNo,tm* date):
		Passenger(Id),AirlineInfo(LineNo), date(date),tichash(TicketHash()) {}
	size_t tichash;
	tm* date;
	bool Order(int id,string LineNo,int number,int diffday, bool ifqueue);
	bool Refund(Ticket ticket);
	bool Refund(int id, string LineNo);
	size_t TicketHash();
};

