#pragma once

class File
{
public:
	void Read();
private:
	void ReadCompany();
	void ReadAirport();
	void ReadAirplane();
	vector<string>Company;
};

