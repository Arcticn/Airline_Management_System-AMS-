#pragma once
struct Time
{
    Time() = default;

    string weekday;
    string day;
    string time;
};

ostream &operator<<(ostream &os, const Time &time) 
{
    os << time.weekday << " " << time.day << " " << time.time;
    return os;
}