#include "AMS.h"

bool Ticket::Order(int Id, string LineNo, int amount, int diffday, bool ifqueue)
{
	//Calc date
	tm date;
	date.tm_year = CurTime->tm_year;
	date.tm_mon = CurTime->tm_mon;
	date.tm_mday = CurTime->tm_mday;
	if (diffday > 15)return false;
	date += diffday;
	int lineid = LineQuickFind[LineNo];
	//Compare
	if (AirlineInfoDatabase[lineid].RemainTickets < amount) {
		for (size_t i = 0; i < amount; i++)
			AirlineInfoDatabase[lineid].Inqueuelist[date].push(Id);
		return true;
	}
	else {
		//AirlineInfo Part
		//Initializes	
		AirlineInfoDatabase[lineid].Bookedlist.insert({ date,{} });
		//Add
		for (size_t i = 0; i < amount; i++)
			AirlineInfoDatabase[lineid].Bookedlist[date].emplace_back(Id);
		AirlineInfoDatabase[lineid].RemainTickets -= amount;
		//Passenger Part
		for (size_t i = 0; i < amount; i++)
			PassengerDatabase[Id].tickets.emplace_back(Ticket(Id, LineNo, CurTime,date));
		return true;
	}
}

bool Ticket::Order(int id, string LineNo, int amount, tm date, bool ifqueue)
{
	int lineid = LineQuickFind[LineNo];
	//Compare
	if (AirlineInfoDatabase[lineid].RemainTickets < amount) {
		for (size_t i = 0; i < amount; i++)
			AirlineInfoDatabase[lineid].Inqueuelist[date].push(Id);
		return true;
	}
	else {
		//AirlineInfo Part
		//Initializes	
		AirlineInfoDatabase[lineid].Bookedlist.insert({ date,{} });
		//Add
		for (size_t i = 0; i < amount; i++)
			AirlineInfoDatabase[lineid].Bookedlist[date].emplace_back(Id);
		AirlineInfoDatabase[lineid].RemainTickets -= amount;
		//Passenger Part
		for (size_t i = 0; i < amount; i++)
			PassengerDatabase[Id].tickets.emplace_back(Ticket(Id, LineNo, CurTime, date));
		return true;
	}
}

bool Ticket::Refund(Ticket ticket)
{
	auto it1 = find(PassengerDatabase[ticket.Id].tickets.begin(), PassengerDatabase[ticket.Id].tickets.end(), ticket);
	PassengerDatabase[ticket.Id].tickets.erase(it1);
	auto it2 = find(AirlineInfoDatabase[LineQuickFind[ticket.LineNo]].Bookedlist[ticket.FlightDate].begin(), AirlineInfoDatabase[LineQuickFind[ticket.LineNo]].Bookedlist[ticket.FlightDate].end(), ticket.Id);
	AirlineInfoDatabase[LineQuickFind[ticket.LineNo]].Bookedlist[ticket.FlightDate].erase(it2);
	AirlineInfoDatabase[LineQuickFind[ticket.LineNo]].QueueOut(ticket.FlightDate);
	return false;
}

size_t Ticket::TicketHash()
{
	auto end = high_resolution_clock::now();
	nano_type diff = end - start;
	std::hash<int>tichash;
	return size_t(tichash(diff.count()));
	
}


