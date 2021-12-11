#include "AMS.h"

bool Ticket::Order(int Id, string LineNo, int amount, int diffday, bool ifqueue)
{
	auto &line = AirlineInfoDatabase[LineQuickFind[LineNo]];
	//Calc date
	tm date;
	date.tm_year = CurTime->tm_year;
	date.tm_mon = CurTime->tm_mon;
	date.tm_mday = CurTime->tm_mday;
	if (diffday > 15)return false;
	date += diffday;
	//Compare
	if (line.RemainTickets[date] < amount) {
		for (size_t i = 0; i < amount; i++)
			line.Inqueuelist[date].push(Id);
		return true;
	}
	else {
		//AirlineInfo Part
		//Initializes	
		line.Bookedlist.insert({ date,{} });
		//Add
		for (size_t i = 0; i < amount; i++)
			line.Bookedlist[date].emplace_back(Id);
		line.RemainTickets[date] -= amount;
		//Passenger Part
		for (size_t i = 0; i < amount; i++)
			PassengerDatabase[Id].tickets.emplace_back(Ticket(Id, LineNo, CurTime,date));
		return true;
	}
}

bool Ticket::Order(int Id, string LineNo, int amount, tm date, bool ifqueue)
{
	auto &line = AirlineInfoDatabase[LineQuickFind[LineNo]];
	//Compare
	if (line.RemainTickets[date] < amount) {
		for (size_t i = 0; i < amount; i++)
			line.Inqueuelist[date].push(Id);
		return true;
	}
	else {
		//AirlineInfo Part
		//Initializes	
		line.Bookedlist.insert({ date,{} });
		//Add
		for (size_t i = 0; i < amount; i++)
			line.Bookedlist[date].emplace_back(Id);
		line.RemainTickets[date] -= amount;
		//Passenger Part
		for (size_t i = 0; i < amount; i++)
			PassengerDatabase[Id].tickets.emplace_back(Ticket(Id, LineNo, CurTime, date));
		return true;
	}
}

bool Ticket::Refund(Ticket ticket)
{

	auto &line = AirlineInfoDatabase[LineQuickFind[ticket.LineNo]];
	auto it1 = find(PassengerDatabase[ticket.Id].tickets.begin(), PassengerDatabase[ticket.Id].tickets.end(), ticket);
	PassengerDatabase[ticket.Id].tickets.erase(it1);
	auto it2 = find(line.Bookedlist[ticket.FlightDate].begin(), line.Bookedlist[ticket.FlightDate].end(), ticket.Id);
	line.Bookedlist[ticket.FlightDate].erase(it2);
	if (line.Inqueuelist[ticket.FlightDate].empty()) line.RemainTickets[ticket.FlightDate] += 1;
	else line.QueueOut(ticket.FlightDate);
	return false;
}

size_t Ticket::TicketHash()
{
	auto end = high_resolution_clock::now();
	nano_type diff = end - start;
	std::hash<int>tichash;
	return size_t(tichash(diff.count()));
}


