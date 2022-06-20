#pragma once
#include <string>

using namespace std;

class Notes
{
private:
	int idUser;
	int idNote;
	string title;
	string description;
	//Label* l;

	int d_c;
	int d_e;
	int m_c;
	int m_e;
	int a_c;
	int a_e;

	string prioridad;
	int dias_restantes;
	int urgencia;

public:
	Notes(int pidUser, int pidNote, string ptitle, string pdescription, int pd_c, int pm_c, int pa_c, int pd_e, int pm_e, int pa_e, string pprioridad, int pdias_restantes, int purgencia);
	Notes();
	~Notes();
	int GetIdUser();
	int GetIdNote();
	string GetTitle();
	void SetTitle(string t);
	string GetDescription();
	void SetDescription(string d);
	void Show();

	int GetDc();
	int GetMc();
	int GetAc();
	void SetDc(int value);
	void SetMc(int value);
	void SetAc(int value);

	int GetDe();
	int GetMe();
	int GetAe();
	void SetDe(int value);
	void SetMe(int value);
	void SetAe(int value);

	string GetPrioridad();
	void SetPrioridad(string value);

	int GetUrgencia();
	int GetDiasRestantes();
};

