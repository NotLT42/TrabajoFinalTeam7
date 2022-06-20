#pragma once
#include <string>

using namespace std;
class Planes
{
private:
	int idUser;
	long idPlan;
	string title;
	int day;
	int month;
	int year;
	string PalabraClave;

public:
	Planes(int pidUser, long pidPlan, string ptitle, int pday, int pmonth, int pyear, string ppalabraclave);
	~Planes();
	int GetIdUser();
	long GetIdPlan();
	string GetTitle();
	int GetDay();
	int GetMonth();
	int GetYear();
	string GetPalabraClave();

	void SetIdUser(int nuevo);
	void SetIdPlan(long nuevo);
	void SetTitle(string nuevo);
	void SetDay(int nuevo);
	void SetMonth(int nuevo);
	void SetYear(int nuevo);
	void SetPalabraClave(string nuevo);

	void Show();
};

