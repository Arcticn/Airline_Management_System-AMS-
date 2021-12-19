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

extern high_resolution_clock::time_point start; //�߾���ʱ�ӣ����������
extern tm CurTime; //��ǰʱ�䣨tm��
extern time_t rawtime; //��ǰʱ�䣨time_t��
extern int User_ID;  //ȫ���û�ID��
extern vector<string>Company; //���չ�˾�б�
extern vector<Airplane>AirplaneDatabase; //�ɻ����ݿ�
extern vector<Airport>AirportDatabase; //�������ݿ�
extern vector<AirlineInfo>AirlineInfoDatabase; //�������ݿ�
extern unordered_map<int, Passenger>PassengerDatabase; //�ͻ�ID -> ID��Ӧ��Passenger����
extern unordered_map<string, int>UserToID; //�û��˺ŵ��û��� -> �ͻ�ID
extern unordered_map<string, int>LineQuickFind; //����� -> AirlineInfoDatabase�ж�Ӧ���±�
extern map<string, string>Superuser; // �洢�����û����û���������
extern unordered_map<string, string>User; // �洢��ͨ�û����û���������

extern Ticket tic;
