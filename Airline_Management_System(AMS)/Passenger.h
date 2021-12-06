#pragma once

class Passenger
{
public:
    Passenger() = default;
    Passenger(int id, vector<string>ticket) :
        Id(id), Ticket(ticket) {}
    Passenger(int id) :
        Id(id) {}
protected:
    int Id;
private:
    vector<string>Ticket;
};