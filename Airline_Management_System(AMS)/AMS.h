#pragma once

#include "Common.h"
#include "Time.h"
#include "QuickUse.h"
#include "Airport.h"
#include "Airplane.h"
#include "AirlineInfo.h"
#include "Ticket.h"
#include "Passenger.h"
#include "Login.h"
#include "Menu.h"
#include "SuperUserInterface.h"
#include "UserInterface.h"
#include "File.h"
#include "AirlineCreator.h"
#include "AirlineBoard.h"

typedef duration<int, std::nano> nano_type;
typedef duration<int, std::ratio<60 * 60 * 24>> days_type;

extern high_resolution_clock::time_point start; //高精度时钟，用于随机数
extern tm CurTime; //当前时间（tm）
extern time_t rawtime; //当前时间（time_t）
extern int User_ID;  //全局用户ID数
extern vector<string>Company; //航空公司列表
extern vector<Airplane>AirplaneDatabase; //飞机数据库
extern vector<Airport>AirportDatabase; //机场数据库
extern vector<AirlineInfo>AirlineInfoDatabase; //航线数据库
extern unordered_map<int, Passenger>PassengerDatabase; //客户ID -> ID对应的Passenger类型
extern unordered_map<string, int>UserToID; //用户账号的用户名 -> 客户ID
extern unordered_map<string, int>LineQuickFind; //航班号 -> AirlineInfoDatabase中对应的下标
extern map<string, string>Superuser; // 存储超级用户的用户名和密码
extern unordered_map<string, string>User; // 存储普通用户的用户名和密码

extern Ticket tic;
