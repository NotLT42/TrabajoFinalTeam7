#pragma once
#include "Header.h"

/*	Models es el manejador de datos 	*/

//Variables globales
#pragma region Variables Globales

ListaSimple<User> lstUsers;
ListaDoble<Notes> lstNotes;
Pila<Planes> listPila; 
BST<Planes> listPlanes;
Planes** ArrMergeSort = new Planes * [50000];
ifstream readFile;
ofstream writeFile;
User* userActive;
HashTable<FastNotes> HT;

long* aleatoriedad = new long[50000];
int cant = 0;

#pragma endregion

#pragma region Manejador de archivos

void LoadListUsers() {
	User* user;
	string aux, v2, v3, v4, text, separator = "|";
	int v1;

	readFile.open("users.txt", ios::in);
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			getline(readFile, text);

			int start = 0, end = text.find(separator);

			for (int i = 0; i < 3; i++)
			{
				switch (i)
				{
				case 0:
					aux = text.substr(start, end - start);
					v1 = stoi(aux);
					break;
				case 1:
					v2 = text.substr(start, end - start);
					break;
				case 2:
					v3 = text.substr(start, end - start);
				default:
					break;
				}
				//cout << text.substr(start, end - start) << endl;
				start = end + separator.size();
				end = text.find(separator, start);
			}
			v4 = text.substr(start, end - start);
			user = new User(v1, v2, v3, v4);
			lstUsers.Append(*user);
		}
		readFile.close();
	}
}

void SaveListUsers() {
	writeFile.open("users.txt", ios::out);
	if (writeFile.is_open())
	{
		lstUsers.resetSelected();
		User user = lstUsers.selected->data;
		int stop = lstUsers.GetCount();
		for (int i = 0; i < stop; i++)
		{
			if (i == stop - 1)
				writeFile << user.GetId() << "|" << user.GetName() << "|" << user.GetLogin() << "|" << user.GetPassword();
			else
				writeFile << user.GetId() << "|" << user.GetName() << "|" << user.GetLogin() << "|" << user.GetPassword() << "\n";

			lstUsers.Sgt();
			user = lstUsers.selected->data;
		}
		lstUsers.resetSelected();
		writeFile.close();
	}
}

void LoadListNotes() {
	Notes* note;
	string text, separator = "|";
	int v1, v2;
	string aux, v3, v4;
	int v5, v6, v7, v8, v9, v10;
	string v11;
	int v12, v13;

	readFile.open("notes.txt", ios::in);
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			getline(readFile, text);

			int start = 0;
			int end = text.find(separator);

			for (int i = 0; i < 12; i++)
			{
				switch (i)
				{
				case 0:
					aux = text.substr(start, end - start);
					v1 = stoi(aux);
					break;
				case 1:
					aux = text.substr(start, end - start);
					v2 = stoi(aux);
					break;
				case 2:
					v3 = text.substr(start, end - start);
					break;
				case 3:
					v4 = text.substr(start, end - start);
					break;
				case 4:
					aux = text.substr(start, end - start);
					v5 = stoi(aux);
					break;
				case 5:
					aux = text.substr(start, end - start);
					v6 = stoi(aux);
					break;
				case 6:
					aux = text.substr(start, end - start);
					v7 = stoi(aux);
					break;
				case 7:
					aux = text.substr(start, end - start);
					v8 = stoi(aux);
					break;
				case 8:
					aux = text.substr(start, end - start);
					v9 = stoi(aux);
					break;
				case 9:
					aux = text.substr(start, end - start);
					v10 = stoi(aux);
					break;
				case 10:
					v11 = text.substr(start, end - start);
					break;
				case 11:
					aux = text.substr(start, end - start);
					v12 = stoi(aux);
					break;
				default:
					break;
				}
				//cout << text.substr(start, end - start) << endl;
				start = end + separator.size();
				end = text.find(separator, start);
			}

			aux = text.substr(start, end - start);
			v13 = stoi(aux);

			note = new Notes(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13);
			lstNotes.append(*note);

		}
		readFile.close();
	}
}

void SaveListNotes() {
	writeFile.open("notes.txt", ios::out);
	if (writeFile.is_open())
	{
		lstNotes.resetSelected();
		Notes note = lstNotes.selected->data;
		int stop = lstNotes.getCount();
		for (int i = 0; i < stop; i++)
		{
			if (i == stop - 1)
				writeFile << note.GetIdNote() << "|" << note.GetIdUser() << "|" << note.GetTitle() << "|" << note.GetDescription() << "|" << note.GetDc() << "|" << note.GetMc() << "|" << note.GetAc() << "|" << note.GetDe() << "|" << note.GetMe() << "|" << note.GetAe() << "|" << note.GetPrioridad() << "|" << note.GetDiasRestantes() << "|" << note.GetUrgencia();
			else
				writeFile << note.GetIdNote() << "|" << note.GetIdUser() << "|" << note.GetTitle() << "|" << note.GetDescription() << "|" << note.GetDc() << "|" << note.GetMc() << "|" << note.GetAc() << "|" << note.GetDe() << "|" << note.GetMe() << "|" << note.GetAe() << "|" << note.GetPrioridad() << "|" << note.GetDiasRestantes() << "|" << note.GetUrgencia() << "\n";

			lstNotes.sgt();
			note = lstNotes.selected->data;
		}
		lstNotes.resetSelected();
		writeFile.close();
	}
}

void LoadListPlanes() {
	string text, separator = "|";
	int v1, v4, v5, v6;
	long v2;
	string aux, v3, v7;

	readFile.open("Planes.txt", ios::in);
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			getline(readFile, text);

			int start = 0;
			int end = text.find(separator);
			for (int i = 0; i < 6; i++)
			{
				switch (i)
				{
				case 0:
					aux = text.substr(start, end - start);
					v1 = stoi(aux);
					break;
				case 1:
					aux = text.substr(start, end - start);
					v2 = stoi(aux);
					break;
				case 2:
					v3 = text.substr(start, end - start);
					break;
				case 3:
					aux = text.substr(start, end - start);
					v4 = stoi(aux);
					break;
				case 4:
					aux = text.substr(start, end - start);
					v5 = stoi(aux);
					break;
				case 5:
					aux = text.substr(start, end - start);
					v6 = stoi(aux);
					break;
				default:
					break;
				}
				start = end + separator.size();
				end = text.find(separator, start);
			}
			v7 = text.substr(start, end - start);
			listPlanes.insertacion(new Planes(v1, v2, v3, v4, v5, v6, v7));
			aleatoriedad[cant] = v2;
			ArrMergeSort[cant] = new Planes(v1, v2, v3, v4, v5, v6, v7);
			cant++;
		}
		readFile.close();
	}
}

void SaveListPlanes() {
	writeFile.open("Planes.txt", ios::out);
	if (writeFile.is_open())
	{
		Planes* plan;
		listPlanes.counts();
		int stop = listPlanes.GetCount();
		for (int i = 0; i < stop; i++)
		{
			plan = listPlanes.BuscarIndice(aleatoriedad[i]);
			if (i == stop - 1)
				writeFile << plan->GetIdUser() << "|" << plan->GetIdPlan() << "|" << plan->GetTitle() << "|" << plan->GetDay() << "|" << plan->GetMonth() << "|" << plan->GetYear() << "|" << plan->GetPalabraClave();
			else
				writeFile << plan->GetIdUser() << "|" << plan->GetIdPlan() << "|" << plan->GetTitle() << "|" << plan->GetDay() << "|" << plan->GetMonth() << "|" << plan->GetYear() << "|" << plan->GetPalabraClave() << "\n";
		}
		writeFile.close();
	}
}

void LoadListFastNotes() {
	FastNotes* FN;
	string text, separator = "|";
	//int v1;
	string aux, v2, v3, v4, v1;

	readFile.open("fastnotes.txt", ios::in);
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			getline(readFile, text);

			int start = 0;
			int end = text.find(separator);
			for (int i = 0; i < 2; i++)
			{
				switch (i)
				{
				case 0:
					v1 = text.substr(start, end - start);
					break;
				case 1:
					v2 = text.substr(start, end - start);
					break;
				default:
					break;
				}
				start = end + separator.size();
				end = text.find(separator, start);
			}
			//aux = text.substr(start, end - start);
			v3 = text.substr(start, end - start);
			FN = new FastNotes(v1, v2, v3);
			HT.insertItem(v1, *FN);

		}
		readFile.close();
	}
}

void SaveListFastNotes() {

	ofstream arch;
	arch.open("fastnotes.txt", ios::out);

	if (arch.is_open())
	{
		FastNotes FN = HT.getValue();

			arch << FN.getMateria() << "|" << FN.getDescripcion() << "|" << FN.getEstado() << "\n";

			FN = HT.getValue();

		arch.close();
	}
}

#pragma endregion
