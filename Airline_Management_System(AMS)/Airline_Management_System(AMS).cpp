#include "AMS.h"

map<string, string>Superuser = { {"admin","admin"},{"user001","user001"} };
unordered_map<string, string>User = { {"123","123"} };

int main()
{
    while (true) {
        if(!Menu())break;
    }
}
