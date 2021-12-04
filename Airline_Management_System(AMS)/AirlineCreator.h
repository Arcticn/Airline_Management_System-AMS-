#pragma once


class AirlineCreator {
public:
	typedef std::chrono::duration<int, std::nano> nano_type;
	std::chrono::high_resolution_clock::time_point start = high_resolution_clock::now();
	AirlineInfo Creator();
private:
	string LineNoCreator();
	string CompanyCreator();
	int AirplaneCreator(); //об╠Й
	string DestinationCreator(int depart);


};