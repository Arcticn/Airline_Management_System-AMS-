#pragma once
#include "AMS.h"

class Ticket
{
public:
	Ticket() = default;
	Ticket(int Id, string LineNo, tm date, string tdate) :
		Id(Id), LineNo(LineNo), Date(date), FlightDate(tdate), TicketNo(TicketHash()) {}
	int Id=0;
	string LineNo;
	tm Date={0};  //购票时间
	string FlightDate;  //起飞时间
	size_t TicketNo=0;
	
	bool Order(int id,string LineNo,int amount,int diffday, bool ifqueue);
	bool Order(int id, string LineNo, int amount, string date/*起飞时间*/, bool ifqueue);
	bool Refund(Ticket ticket);
	size_t TicketHash();
};
bool operator==(const Ticket &lhs, const Ticket &rhs);