#include "AMS.h"

vector<string>Company;
vector<Airplane>AirplaneDatabase;
vector<Airport>AirportDatabase;
vector<AirlineInfo>AirlineInfoDatabase;

void File::Read() {
	ReadCompany();
	ReadAirport();
	ReadAirplane();
}

void File::ReadCompany() {
	ifstream in("Company.txt");
	string t;
	while (in >> t) {
		Company.emplace_back(t);
	}
}

void File::ReadAirport() {
	ifstream in("Airport.txt");
	string line;
	while (getline(in, line)) {
		Airport info; string City;
		istringstream record(line);
		record >> City;
		while (record >> info.AirportName >> info.AirportCode >> info.Latitude >> info.Longitude) {
			info.City = City;
			AirportDatabase.emplace_back(info);
		}
	}
}

void File::ReadAirplane()
{
	ifstream in("Airplane.txt");
	string line;
	while (getline(in, line)) {
		Airplane info; 
		istringstream record(line);
		record >> info.Model >> info.Speed >> info.Maxpassenger >> info.MaxRange;
		info.Speed *= Ma;//马赫速度转换，默认构造
		AirplaneDatabase.emplace_back(info);
	}
}
