#pragma once
#include "AMS.h"

class Ticket:public AirlineInfo
{
public:
	Ticket() = default;
	Ticket(int Id, string LineNo, tm date, string tdate) :
		Id(Id), AirlineInfo(LineNo), Date(date), FlightDate(tdate), TicketNo(TicketHash()) {}
	std::chrono::high_resolution_clock::time_point start = high_resolution_clock::now();
	int Id=0;
	tm Date={0};  //��Ʊʱ��
	string FlightDate;  //���ʱ��
	size_t TicketNo=0;
	
	bool Order(int id,string LineNo,int amount,int diffday, bool ifqueue);
	bool Order(int id, string LineNo, int amount, string date/*���ʱ��*/, bool ifqueue);
	bool Refund(Ticket ticket);
	size_t TicketHash();
};
bool operator==(const Ticket &lhs, const Ticket &rhs);