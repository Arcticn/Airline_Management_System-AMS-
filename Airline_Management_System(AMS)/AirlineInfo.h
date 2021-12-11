#pragma once
class AirlineInfo
{
public:
    AirlineInfo() = default;
    AirlineInfo(const string &comp, const string &line, const string &dep, const string &dest, const string &airp, double distance, tm deptime, tm destime, int maxp) :
        Company(comp), LineNo(line), Departure(dep), Destination(dest), Airplane(airp), Distance(distance), DepartureTime(deptime), estDestinationTime(destime), Maxpassenger(maxp) {}
    AirlineInfo(const string &line) :
        LineNo(line) {}
    string Company;
    string LineNo;
    string Departure;
    string Destination;
    string Airplane;
    double Distance=0;
    tm DepartureTime={0};
    tm estDestinationTime={0};
    int Maxpassenger=0;
    tm* temp = { 0 };
    unordered_map<tm*, int> RemainTickets = { {temp,{}} };
    unordered_map<tm*, vector<int>>Bookedlist = { {temp,{}} }; //tm, vector id
    //vector<queue<int>>a;
    unordered_map<tm*, queue<int>>Inqueuelist{ {temp,{}} }; //tm, queue id

    vector<string> SearchLine(string depart, string desti);
    vector<vector<string>> SearchIndirectLine(string depart, string desti);
    string SearchDepart(string LineNo);
    string SearchDesti(string LinNo);
    double SearchDistance(string LineNo);
    int SearchRemainTicket(string LineNo);
    void QueueOut(tm date);
private:

};
