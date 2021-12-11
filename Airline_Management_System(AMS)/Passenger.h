#pragma once

class Passenger
{
public:
    Passenger() = default;
    Passenger(int id) :
        Id(id) {}
    Passenger(int id, vector<Ticket>ticket) :
        Id(id), tickets(ticket) {}
    int Id = 0;
    vector<Ticket>tickets = {};
};