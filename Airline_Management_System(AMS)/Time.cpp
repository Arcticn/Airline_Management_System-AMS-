#include "AMS.h"

ostream &operator<<(ostream &os, const Time &time)
{
    os << time.weekday << " " << time.day << " " << time.time;
    return os;
}