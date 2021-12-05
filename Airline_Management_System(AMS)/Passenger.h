#pragma once

class Passenger
{
public:
    Passenger()=default;
    Passenger(int id,string name,vector<string>ticket):
        Id(id),Name(name),Ticket(ticket) {}
    int Id;
    string Name;
private:
    vector<string>Ticket;
};