#include "AMS.h"

void AirlineCreator::Creator() {
	for (size_t i = 0, length = AirportDatabase.size(); i < length; i++)
	{
		vector<int>Destination(DestinationCreator(static_cast<int>(i), 30));
		for (size_t j = 0; j < 30; j++)
		{
			int planeid = AirplaneCreator();
			//Calculate the distance
			double distance = DistanceCalc(AirportDatabase[i].Latitude, AirportDatabase[i].Longitude, AirportDatabase[Destination[j]].Latitude, AirportDatabase[Destination[j]].Longitude);
			//Ensure the Maxrange is enough
			while (AirplaneDatabase[planeid].MaxRange < distance) {
				planeid = AirplaneCreator();
				double distance = DistanceCalc(AirportDatabase[i].Latitude, AirportDatabase[i].Longitude, AirportDatabase[Destination[j]].Latitude, AirportDatabase[Destination[j]].Longitude);
			}
			//Calculate the ESTdestinationTime
			tm DepTime = TimeCreator();
			tm DesTime = DepTime;
			int diff = static_cast<int>(distance / AirplaneDatabase[planeid].Speed*60);
			DesTime.tm_min += diff;
			DesTime.tm_hour += (DesTime.tm_min / 60);
			DesTime.tm_min %= 60;
			AirlineInfoDatabase.emplace_back(AirlineInfo(CompanyCreator(), LineNoCreator(), AirportDatabase[i].AirportName, AirportDatabase[Destination[j]].AirportName, AirplaneDatabase[planeid].Model, DepTime,DesTime, AirplaneDatabase[planeid].Maxpassenger));
		}
	}
	return;
}

//LineNo Creator
string AirlineCreator::LineNoCreator() {
	auto end = high_resolution_clock::now();
	string LineNo;
	default_random_engine e;
	nano_type diff = end - start;
	uniform_int_distribution<unsigned> u(65, 90);
	for (size_t i = 0; i < 2; i++)
	{
		end = high_resolution_clock::now();
		diff = end - start;
		e.seed(diff.count());
		this_thread::sleep_for(chrono::nanoseconds(3));
		char temp = u(e);
		LineNo += temp;
	}
	uniform_int_distribution<unsigned> u1(0, 9);
	for (size_t i = 0; i < 4; i++)
	{
		end = high_resolution_clock::now();
		diff = end - start;
		e.seed(diff.count());
		this_thread::sleep_for(chrono::nanoseconds(3));
		LineNo += to_string(u1(e));
	}
	return LineNo;
}

string AirlineCreator::CompanyCreator() {
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, static_cast<int>(Company.size()) - 1);
	auto end = high_resolution_clock::now();
	nano_type diff = end - start;
	e.seed(diff.count());
	return Company[u(e)];
}

tm AirlineCreator::TimeCreator()
{
	tm timeinfo = tm();
	default_random_engine e;
	uniform_int_distribution<unsigned> u1(0, 23);
	auto end = high_resolution_clock::now();
	nano_type diff = end - start;
	e.seed(diff.count());
	timeinfo.tm_hour = u1(e);
	uniform_int_distribution<unsigned> u2(0, 59);
	end = high_resolution_clock::now();
	diff = end - start;
	e.seed(diff.count());
	timeinfo.tm_min = u2(e);
	return timeinfo;
}

int AirlineCreator::AirplaneCreator() {
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, static_cast<int>(AirplaneDatabase.size()) - 1);
	auto end = high_resolution_clock::now();
	nano_type diff = end - start;
	e.seed(diff.count());
	return u(e);
}

vector<int> AirlineCreator::DestinationCreator(int depart, int number) {
	set<int>DesId = { depart };
	vector<int>Destination;
	default_random_engine e;
	auto end = high_resolution_clock::now();
	uniform_int_distribution<unsigned> u(0, static_cast<int>(AirportDatabase.size()) - 1);
	nano_type diff = end - start;
	int cnt = 0, ran = 0;
	while (cnt != number) {
		end = high_resolution_clock::now();
		diff = end - start;
		e.seed(diff.count());
		ran = u(e);
		if (!DesId.count(ran)) {
			Destination.emplace_back(ran);
			++cnt;
		}
	}
	return Destination;
}


