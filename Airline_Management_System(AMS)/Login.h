#pragma once

class Login {
public:
	void UserRegister();
	void SuperLogin();
	void UserLogin();
	map<string, string>Superuser = { {"admin","admin"},{"user001","user001"} };
	unordered_map<string, string>User = { {"123","123"} };
};

