#include "AMS.h"

bool operator==(const Ticket &lhs, const Ticket &rhs)
{
	return lhs.TicketNo == rhs.TicketNo ;
}

bool Ticket::Order(int Id, string LineNo, int amount, int diffday, bool ifqueue)
{
	auto &line = AirlineInfoDatabase[LineQuickFind[LineNo]];
	//Calc date
	if (diffday > 15)return false;
	tm temp={0};
	temp.tm_year = CurTime.tm_year;
	temp.tm_mon = CurTime.tm_mon;
	temp.tm_mday = CurTime.tm_mday;
	temp =temp+ diffday;
	string date = to_string(temp.tm_year+1900) + to_string(temp.tm_mon+1) + to_string(temp.tm_mday);
	//Compare
	if (line.RemainTickets[date] < amount) {
		line.Inqueuelist.insert({ date,{} });
		for (size_t i = 0; i < amount; i++)
			line.Inqueuelist[date].emplace(Id);
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

bool Ticket::Order(int Id, string LineNo, int amount, string date, bool ifqueue)
{
	auto &line = AirlineInfoDatabase[LineQuickFind[LineNo]];
	//Compare
	if (line.RemainTickets[date] < amount) {
		line.Inqueuelist.insert({ date,{} });
		for (size_t i = 0; i < amount; i++)
			line.Inqueuelist[date].emplace(Id);
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
	return true;
}

size_t Ticket::TicketHash()
{
	auto end = high_resolution_clock::now();
	nano_type diff = end - start;
	std::hash<int>tichash;
	return size_t(tichash(diff.count()));
}


