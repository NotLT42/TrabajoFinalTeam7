#pragma once
#include <string>

using namespace std;

class User
{
private:
	int id;
	string name;
	string login;
	string password;

public:
	User();
	User(int pid, string pname, string plogin, string ppassword);
	~User();

	int GetId();
	string GetName();
	string GetLogin();
	string GetPassword();

	void Show();

};

