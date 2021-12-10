#pragma once

class Passenger
{
public:
    Passenger() = default;
    Passenger(int id, vector<Ticket>ticket) :
        Id(id), tickets(ticket) {}
    Passenger(int id) :
        Id(id) {}
    int Id;
    vector<Ticket>tickets;
};