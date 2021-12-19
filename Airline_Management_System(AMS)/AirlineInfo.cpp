#include "AMS.h"

vector<string> AirlineInfo::SearchLine(string depart, string desti)
{
	vector<string>ans;
	for (auto &c : AirlineInfoDatabase) {
		if (c.Destination == desti)
			if (c.Departure == depart)
				ans.emplace_back(c.LineNo);
	}
	return ans;
}

vector<vector<string>> AirlineInfo::SearchIndirectLine(string depart, string desti)
{
	vector<string> first;
	vector<vector<string>>ans;
	vector<string>temp;
	for (auto &c : AirlineInfoDatabase) {
		if (c.Departure == depart && c.Destination != desti)
			first.emplace_back(c.LineNo);
	}
	for (auto &c : first) {
		string t = SearchDesti(c);
		vector<string>tt(SearchLine(t, desti));
		for (auto &d : tt) {
			temp.clear();
			temp.emplace_back(c);
			temp.emplace_back(d);
			ans.emplace_back(temp);
		}
	}
	return ans;
}

string AirlineInfo::SearchDepart(string LineNo)
{
	return AirlineInfoDatabase[LineQuickFind[LineNo]].Departure;
}

string AirlineInfo::SearchDesti(string LineNo)
{
	return AirlineInfoDatabase[LineQuickFind[LineNo]].Destination;
}

string AirlineInfo::SearchCompany(string LineNo)
{
	return AirlineInfoDatabase[LineQuickFind[LineNo]].Company;
}

string AirlineInfo::SearchAirplane(string LineNo)
{
	return AirlineInfoDatabase[LineQuickFind[LineNo]].Airplane;
}

double AirlineInfo::SearchDistance(string LineNo)
{
	return AirlineInfoDatabase[LineQuickFind[LineNo]].Distance;
}

int AirlineInfo::SearchRemainTicket(string date,string LineNo)
{
	return AirlineInfoDatabase[LineQuickFind[LineNo]].RemainTickets[date];
}

tm AirlineInfo::SearchDeparTime(string LineNo)
{
	return AirlineInfoDatabase[LineQuickFind[LineNo]].DepartureTime;
}

tm AirlineInfo::SearchDesTime(string LineNo)
{
	return AirlineInfoDatabase[LineQuickFind[LineNo]].estDestinationTime;
}

void AirlineInfo::QueueOut(string date)
{
	int id=Inqueuelist[date].front();
	tic.Order(id, this->LineNo, 1, date, 1);
	Inqueuelist[date].pop();
}

void AirlineInfo::RefreshLine()
{
	auto it1 = AirportDatabase.begin();
	for (; it1 != AirportDatabase.end(); ++it1) {
		if ((*it1).AirportName == this->Departure)break;
	}
	auto it2 = AirportDatabase.begin();
	for (; it2 != AirportDatabase.end(); ++it2) {
		if ((*it2).AirportName == this->Destination)break;
	}
	double distance = DistanceCalc((*it1).Latitude, (*it1).Longitude, (*it2).Latitude, (*it2).Longitude);
	this->Distance = distance;
	//Calculate the ESTdestinationTime
	auto it3 = AirplaneDatabase.begin();
	for (; it3 != AirplaneDatabase.end(); ++it3) {
		if ((*it3).Model == this->Airplane)break;
	}
	tm DesTime = this->DepartureTime;
	int diff = static_cast<int>(distance / (*it3).Speed * 60);
	DesTime.tm_min += diff;
	DesTime.tm_hour += (DesTime.tm_min / 60);
	while (DesTime.tm_hour >= 24) {
		DesTime.tm_hour -= 24;
	}
	DesTime.tm_min %= 60;
	this->estDestinationTime = DesTime;
	this->Inqueuelist.clear();
	//Initialize Remainlists
	tm temp = CurTime;
	for (size_t i = 0; i <= 15; i++)
	{
		string date = to_string(temp.tm_year + 1900) + to_string(temp.tm_mon + 1) + to_string(temp.tm_mday);
		this->RemainTickets[date] = (*it3).Maxpassenger;
		for (auto c : this->Bookedlist[date]) {
			for (auto d : PassengerDatabase[c].tickets) {
				if (d.LineNo == this->LineNo)tic.Refund(d);
			}
		}
		Bookedlist[date].clear();
		temp = temp + 1;
	}
}
