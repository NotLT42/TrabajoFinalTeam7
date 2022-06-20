#include "Planes.h"
#include <iostream>

using namespace std;

Planes::Planes(int pidUser, long pidPlan, string ptitle, int pday, int pmonth, int pyear, string ppalabraclave) {
	idUser = pidUser;
	idPlan = pidPlan;
	title = ptitle;
	day = pday;
	month = pmonth;
	year = pyear;
	PalabraClave = ppalabraclave;
}

Planes::~Planes() {}

int Planes::GetIdUser() { return idUser; }
long Planes::GetIdPlan() { return idPlan; }
string Planes::GetTitle() { return title; }
int Planes::GetDay() { return day; }
int Planes::GetMonth() { return month; }
int Planes::GetYear() { return year; }
string Planes::GetPalabraClave() { return PalabraClave; }

void Planes::Show() {
	cout << "Palabra Clave: " << PalabraClave << "\n";
	cout << "Titulo: " << title << "\n" << "Fecha del plan: " << day << "/" << month << "/" << year << "\n";
	cout << "ID de plan: " << idPlan << "\n";
}

void Planes::SetIdUser(int nuevo) { idUser = nuevo; }
void Planes::SetIdPlan(long nuevo) { idPlan = nuevo; }
void Planes::SetTitle(string nuevo) { title = nuevo; }
void Planes::SetDay(int nuevo) { day = nuevo; }
void Planes::SetMonth(int nuevo) { month = nuevo; }
void Planes::SetYear(int nuevo) { year = nuevo; }
void Planes::SetPalabraClave(string nuevo) { PalabraClave = nuevo; }