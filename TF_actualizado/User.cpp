#include "User.h"
#include <iostream>
//using namespace std;

User::User() { id = 0; }
User::User(int pid, string pname, string plogin, string ppassword) :id(pid), name(pname), login(plogin), password(ppassword) {}
User::~User() {}

int User::GetId() { return id; }
string User::GetName() { return name; }
string User::GetLogin() { return login; }
string User::GetPassword() { return password; }

void User::Show() {
	cout << "ID: " << id << "\n" << "Nombre: " << name << "\n" << "Login: " << login << "\n" << "Contraseña: " << password << "\n";
}