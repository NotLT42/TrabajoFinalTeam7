#include "Notes.h"
#include <iostream>

using namespace std;

Notes::Notes(int pidNote, int pidUser, string ptitle, string pdescription, int pd_c, int pm_c, int pa_c, int pd_e, int pm_e, int pa_e, string pprioridad, int pdias_restantes, int purgencia) {
	idNote = pidNote;
	idUser = pidUser;
	title = ptitle;
	description = pdescription;

	d_c = pd_c;
	m_c = pm_c;
	a_c = pa_c;
	d_e = pd_e;
	m_e = pm_e;
	a_e = pa_e;

	prioridad = pprioridad;
	dias_restantes = pdias_restantes;
	urgencia = purgencia;

}
Notes::Notes() {
	idNote = 0;
}
Notes::~Notes() {}

int Notes::GetIdUser() { return idUser; }
int Notes::GetIdNote() { return idNote; }
string Notes::GetTitle() { return title; }
void Notes::SetTitle(string t) { title = t; }
string Notes::GetDescription() { return description; }
void Notes::SetDescription(string d) { description = d; }

int Notes::GetDc() { return d_c; }
int Notes::GetMc() { return m_c; }
int Notes::GetAc() { return a_c; }
void Notes::SetDc(int value) { d_c = value; }
void Notes::SetMc(int value) { m_c = value; }
void Notes::SetAc(int value) { a_c = value; }

int Notes::GetDe() { return d_e; }
int Notes::GetMe() { return m_e; }
int Notes::GetAe() { return a_e; }
void Notes::SetDe(int value) { d_e = value; }
void Notes::SetMe(int value) { m_e = value; }
void Notes::SetAe(int value) { a_e = value; }

string Notes::GetPrioridad() { return prioridad; }
void Notes::SetPrioridad(string value) { prioridad = value; }

int Notes::GetUrgencia() { return urgencia; }
int Notes::GetDiasRestantes() { return dias_restantes; }


void Notes::Show() {
	//cout << "ID Nota: " << idNote << "\n" << "Usuario: " << idUser << "\n" << "Titulo: " << title << "\n" << "Contenido: " << description << "\n";
	cout << "ID Nota: " << idNote << "\n" << "Titulo: " << title << "\n" << "Contenido: " << description << "\n" << "Fecha de creacion: " << d_c << "/" << m_c << "/" << a_c << "\n" << "Fecha de entrega: " << d_e << "/" << m_e << "/" << a_e << "\n" << "Prioridad: " << prioridad << "\n" << "Dias restantes: " << dias_restantes << "\n" << "Urgencia: " << urgencia << "\n";
}