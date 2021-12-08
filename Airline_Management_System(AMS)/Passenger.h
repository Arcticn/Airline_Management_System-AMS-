#pragma once

class Passenger
{
public:
    Passenger() = default;
    Passenger(int id, vector<string>ticket) :
        Id(id), Ticket(ticket) {}
    Passenger(int id) :
        Id(id) {}
    int Id;
protected:
    vector<string>Ticket;
};