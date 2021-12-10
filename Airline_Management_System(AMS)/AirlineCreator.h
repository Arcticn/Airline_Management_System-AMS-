#pragma once


class AirlineCreator {
public:
	std::chrono::high_resolution_clock::time_point start = high_resolution_clock::now();
	void Creator();
	void TicketDestroyer();
private:
	string LineNoCreator();
	string CompanyCreator();
	void PassengerCreator();
	tm TimeCreator();
	int AirplaneCreator(); //об╠Й
	vector<int>DestinationCreator(int depart, int number);
};