#pragma once
class AirlineCreator {
public:
	void Creator();
	void TicketCreator();
private:
	string LineNoCreator();
	string CompanyCreator();
	void PassengerCreator();
	tm TimeCreator();
	int AirplaneCreator(); //�±�
	vector<int>DestinationCreator(int depart, int number);
};