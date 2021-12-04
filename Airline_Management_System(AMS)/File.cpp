#include "AMS.h"

void File::ReadCompany() {
	ifstream in("Company.txt");
	string t;
	while (in >> t) {
		Company.push_back(t);
	}
}

void File::ReadAirport() {
	ifstream in("Airport.txt");
	string t;
	while (getline(in,t)) {
		
	}
}

void File::ReadAirplane()
{

}
