#pragma once


class AirlineCreator {
public:
	typedef std::chrono::duration<int, std::nano> nano_type;
	std::chrono::high_resolution_clock::time_point start = high_resolution_clock::now();
	void Creator();
	void TicketDestroyer();
private:
	string LineNoCreator();
	string CompanyCreator();
	tm TimeCreator();
	int AirplaneCreator(); //об╠Й
	vector<int>DestinationCreator(int depart, int number);
};