#pragma once
#include "AMS.h"

class Ticket:public AirlineInfo
{
public:
	Ticket() = default;
	Ticket(int Id, string LineNo, tm date, tm tdate) :
		Id(Id), AirlineInfo(LineNo), Date(date), FlightDate(tdate), TicketNo(TicketHash()) {}
	std::chrono::high_resolution_clock::time_point start = high_resolution_clock::now();
	int Id;
	tm Date;  //购票时间
	tm FlightDate;  //起飞时间
	size_t TicketNo;
	

	bool Order(int id,string LineNo,int amount,int diffday, bool ifqueue);
	bool Order(int id, string LineNo, int amount, tm date/*起飞时间*/, bool ifqueue);
	bool Refund(Ticket ticket);
	size_t TicketHash();
};
bool operator==(const Ticket &lhs, const Ticket &rhs);