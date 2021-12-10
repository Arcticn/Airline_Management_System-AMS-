#pragma once
#include "AirlineInfo.h"
#include "Passenger.h"

class Ticket:public AirlineInfo,public Passenger
{
public:
	std::chrono::high_resolution_clock::time_point start = high_resolution_clock::now();
	Ticket() = default;
	Ticket(int Id,string LineNo,tm* date,tm tdate):
		Passenger(Id),AirlineInfo(LineNo), date(date),truedate(tdate), tichash(TicketHash()) {}
	tm* date;  //购票时间
	tm truedate;  //起飞时间
	size_t tichash;
	bool Order(int id,string LineNo,int number,int diffday, bool ifqueue);
	bool Refund(Ticket ticket);
	size_t TicketHash();
};
