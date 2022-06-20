#pragma once
#include "Header.h"
#include "Models.h"

void MenuNotes();
void MenuPlanes();
void MenuPrincipal();


/*	Funcionalidades	*/
void Nav() {
	system("CLS");
	cout << "******  MIS NOTAS UPC  *******" << endl;
	cout << "Usuario: " << userActive->GetName() << "." << endl << endl;
}
void Redireccionar() {
	cout << endl << endl << "En segundos, se le redireccionara al menu principal!";
	_sleep(3500);
}
#pragma region NOTES
void ShowMyNotes(bool c) {
	system("CLS");
	Nav();
	lstNotes.resetSelected();
	int stop = lstNotes.getCount();
	for (int i = 0; i < stop; i++) {
		if (lstNotes.selected->data.GetIdUser() == userActive->GetId()) {
			lstNotes.selected->data.Show();
			cout << "------------------------------------------------------------" << endl;
		}
		lstNotes.sgt();
	}
	if (c)
	{
		cout << endl << endl << "Presione cualquier tecla para regresar al menu...";
		_getch();
	}
}


/*---------------------------------------*/
int  Cant_diasRestantes(int d_c, int d_e, int m_c, int m_e) {
	int restante;
	const int DIAS_REFERENCIA = 31;
	int residuo;

	if (m_e - m_c == 0) {
		return restante = d_e - d_c;
	}
	else if (m_e - m_c == 1) {
		return restante = (DIAS_REFERENCIA + d_e) - d_c;
	}

	else if (m_e - m_c > 1) {
		residuo = (m_e - m_c) * DIAS_REFERENCIA;
		return restante = ((residuo + d_e) - d_c) - 1;
	}
	//restante;
}
int Valor_urgencia(int dias_restantes) {

	// URGENCIA: Rojo = 1, Amarillo = 2, Verde = 3
	if (dias_restantes == 0) {
		return 1;
	}
	else if (dias_restantes > 0 && dias_restantes <= 3) {
		return 2;
	}
	else if (dias_restantes > 3) {
		return 3;
	}
}
void CreateNewNote() {
	Nav();
	string titulo, contenido;
	int dc, mc, ac;
	int de, me, ae;
	string prioridad;

	cout << endl << "Asigna un titulo a tu nota: ";
	cin.ignore();
	getline(cin, titulo);
	cout << endl << "Escribe tu nota: ";
	cin.ignore();
	getline(cin, contenido);

	cout << "Prioridad: ";
	cin.ignore();
	getline(cin, prioridad);

	cout << endl << "Fecha recibida: "; cin >> dc >> mc >> ac;
	cout << "Fecha de entrega: "; cin >> de >> me >> ae;


	Notes* note = new Notes(lstNotes.getCount() + 1, userActive->GetId(), titulo, contenido, dc, mc, ac, de, me, ae, prioridad, Cant_diasRestantes(dc, de, mc, me), Valor_urgencia(Cant_diasRestantes(dc, de, mc, me)));
	lstNotes.append(*note);
	SaveListNotes();
	cout << endl << "Se ha registrado satisfactoriamente!!";
	Redireccionar();
}
void EditNotes() {
	ShowMyNotes(false);
	int idNote = 0;
	cout << "\nIngrese el ID de nota a modificar: ";
	cin >> idNote;

	lstNotes.resetSelected();
	while (lstNotes.selected != nullptr)
	{
		if (lstNotes.selected->data.GetIdNote() == idNote && lstNotes.selected->data.GetIdUser() == userActive->GetId())
		{
			string titulo, contenido;
			cout << ".: Si no desea modificar un elemento digite 0 :.\n";
			cout << endl << "Cambia el titulo de tu nota: ";
			cin.ignore();
			getline(cin, titulo);
			cout << endl << "Cambia tu nota: ";
			cin.ignore();
			getline(cin, contenido);

			lstNotes.selected->data.SetTitle(titulo);
			lstNotes.selected->data.SetDescription(contenido);

			SaveListNotes();
			cout << endl << "Se ha registrado satisfactoriamente!!";
			break;
		}
		lstNotes.sgt();
	}
	if (lstNotes.selected == nullptr)
	{
		cout << "\nEl ID ingresado no existe. \n";
	}

	Redireccionar();
}

void CreateFastNotes() {
	Nav();
	string curso, descripcion, estado;

	cout << endl << "Curso: ";
	cin.ignore();
	getline(cin, curso);
	cout << endl << "Contenido de la nota: ";
	cin.ignore();
	getline(cin, descripcion);

	cout << endl << "Estado: ";
	cin.ignore();
	getline(cin, estado);

	FastNotes* fn = new FastNotes(curso, descripcion, estado);
	HT.setValue(*fn);
	HT.insertItem(fn->getMateria(), *fn);
	SaveListFastNotes();
	cout << endl << "Se ha registrado satisfactoriamente!!";
	Redireccionar();
}

void showMyFastNotes() {
	system("CLS");

	HT.getValue().show();
	cout << "------------------------------------------------------------" << endl;
	cout << endl << endl << "Presione cualquier tecla para regresar al menu...";
	_getch();
}
/*---------------------------------------*/
/*		MENUS		*/
void MenuRegistrarse() {
	system("CLS");
	cout << "******  MIS NOTAS UPC  *******" << endl << endl;
	string name, login, pass;
	cout << endl << "Ingrese su nombre: ";
	cin.ignore();
	getline(cin, name);
	cout << endl << "Ingrese su correo: ";
	cin >> login;
	cout << endl << "Ingrese su contraseña: ";
	cin >> pass;

	User* u = new User(lstUsers.GetCount() + 1, name, login, pass);
	lstUsers.Append(*u);
	SaveListUsers();//Guardamos en el txt 
	//ordenar
	Redireccionar();
}


/*---------------------------------------*/
/*FUNCIONES EXTRA*/
void actividades_hoy(bool c) {
	system("CLS");
	Nav();
	lstNotes.resetSelected();
	int stop = lstNotes.getCount();

	cout << "Actividad encontrada :)" << endl;

	for (int i = 0; i < stop; i++) {
		if (lstNotes.selected->data.GetIdUser() == userActive->GetId() && lstNotes.selected->data.GetDiasRestantes() == 0) {
			lstNotes.selected->data.Show();
			cout << "------------------------------------------------------------" << endl;
		}
		lstNotes.sgt();
	}
	if (c)
	{
		cout << endl << endl << "Presione cualquier tecla para regresar al menu...";
		_getch();
	}
}
void actividades_1_14_dias(bool c) {
	system("CLS");
	Nav();
	lstNotes.resetSelected();
	int stop = lstNotes.getCount();

	cout << "Actividad encontrada :)" << endl;

	for (int i = 0; i < stop; i++) {
		if (lstNotes.selected->data.GetIdUser() == userActive->GetId() && lstNotes.selected->data.GetDiasRestantes() >= 1 && lstNotes.selected->data.GetDiasRestantes() <= 14) {
			lstNotes.selected->data.Show();
			cout << "------------------------------------------------------------" << endl;
		}
		lstNotes.sgt();
	}
	if (c)
	{
		cout << endl << endl << "Presione cualquier tecla para regresar al menu...";
		_getch();
	}
}
void actividades_15_30_dias(bool c) {
	system("CLS");
	Nav();
	lstNotes.resetSelected();
	int stop = lstNotes.getCount();

	cout << "Actividad encontrada :)" << endl;

	for (int i = 0; i < stop; i++) {
		if (lstNotes.selected->data.GetIdUser() == userActive->GetId() && lstNotes.selected->data.GetDiasRestantes() >= 15 && lstNotes.selected->data.GetDiasRestantes() <= 30) {
			lstNotes.selected->data.Show();
			cout << "------------------------------------------------------------" << endl;
		}
		lstNotes.sgt();
	}
	if (c)
	{
		cout << endl << endl << "Presione cualquier tecla para regresar al menu...";
		_getch();
	}
}
void actividades_mas_de_30_dias(bool c) {
	system("CLS");
	Nav();
	lstNotes.resetSelected();
	int stop = lstNotes.getCount();

	cout << "Actividad encontrada :)" << endl;

	for (int i = 0; i < stop; i++) {
		if (lstNotes.selected->data.GetIdUser() == userActive->GetId() && lstNotes.selected->data.GetDiasRestantes() > 30) {
			lstNotes.selected->data.Show();
			cout << "------------------------------------------------------------" << endl;
		}
		lstNotes.sgt();
	}
	if (c)
	{
		cout << endl << endl << "Presione cualquier tecla para regresar al menu...";
		_getch();
	}
}


/*---------------------------------------*/
void MenuNotes() {
	int opt;
	do
	{
		Nav();
		cout << "\t** MENU **" << endl << endl;
		cout << "[ 1 ] Crear nueva nota." << endl;
		cout << "[ 2 ] Mostrar mis notas." << endl;
		cout << "[ 3 ] Editar nota." << endl;
		cout << "[ 4 ] Actividades de Hoy." << endl;
		cout << "[ 5 ] Actividades de 1-14 dias." << endl;
		cout << "[ 6 ] Actividades de 15-30 dias." << endl;
		cout << "[ 7 ] Actividades de + Mes." << endl;
		cout << "[ 8 ] Crear nota rapida" << endl;
		cout << "[ 9 ] Mostrar notas rapidas" << endl;
		cout << "[ 10 ] Cerrar sesion." << endl << endl;

		cout << "Ingrese su opcion: ";
		cin >> opt;

		if (opt == 1) CreateNewNote();
		if (opt == 2) ShowMyNotes(true);
		if (opt == 3) EditNotes();
		if (opt == 4) actividades_hoy(true);
		if (opt == 5) actividades_1_14_dias(true);
		if (opt == 6) actividades_15_30_dias(true);
		if (opt == 7) actividades_mas_de_30_dias(true);
		if (opt == 8) CreateFastNotes();
		if (opt == 9) showMyFastNotes();

	} while (opt != 10);

	MenuPrincipal();
}
#pragma endregion
#pragma region PLANES
void OrdenarPilas() {
	listPila.resetselect();
	int aux_cont = listPila.cantPila();
	int arrday[100], arrmonth[100], arryear[100], arrIDUser[100];
	string arrtitulo[100];
	int datoarreglo = 0;
	for (int i = 0; i < aux_cont; i++)
	{
		arrday[datoarreglo] = listPila.select->data.GetDay();
		arrmonth[datoarreglo] = listPila.select->data.GetMonth();
		arryear[datoarreglo] = listPila.select->data.GetYear();
		arrIDUser[datoarreglo] = listPila.select->data.GetIdUser();
		arrtitulo[datoarreglo] = listPila.select->data.GetTitle();
		listPila.sgt();
		datoarreglo++;
	}
	int min, auxY, auxM, auxD, auxID;
	string auxiliarT;

	for (int i = 0; i < aux_cont; i++) {
		min = i;
		for (int j = i + 1; j < aux_cont; j++) {
			if (arryear[j] < arryear[min]) {
				min = j;
			}
			else if (arryear[j] == arryear[min]) {
				if (arrmonth[j] < arrmonth[min]) {
					min = j;
				}
				else if (arrmonth[j] == arrmonth[min]) {
					if (arrday[j] < arrday[min]) {
						min = j;
					}
				}
			}
		}
		auxY = arryear[i];
		auxM = arrmonth[i];
		auxD = arrday[i];
		auxiliarT = arrtitulo[i];
		auxID = arrIDUser[i];

		arryear[i] = arryear[min];
		arrmonth[i] = arrmonth[min];
		arrday[i] = arrday[min];
		arrtitulo[i] = arrtitulo[min];
		arrIDUser[i] = arrIDUser[min];

		arryear[min] = auxY;
		arrmonth[min] = auxM;
		arrday[min] = auxD;
		arrtitulo[min] = auxiliarT;
		arrIDUser[min] = auxID;
	};

	datoarreglo = 0;
	listPila.resetselect();
	for (int i = 0; i < aux_cont; i++)
	{
		listPila.select->data.SetDay(arrday[datoarreglo]);
		listPila.select->data.SetMonth(arrmonth[datoarreglo]);
		listPila.select->data.SetYear(arryear[datoarreglo]);
		listPila.select->data.SetIdUser(arrIDUser[datoarreglo]);
		listPila.select->data.SetTitle(arrtitulo[datoarreglo]);
		listPila.sgt();
		datoarreglo++;
	}
}
bool validarfecha(int dia, int mes, int year) {
	if (mes < 1 || mes > 12) return true;
	if (dia < 1 || dia > 31) return true;
	if (year < 2020 || dia > 3000) return true;

	bool esbisiesto = false;
	if ((year % 4 == 0 || year % 400 == 0) && year % 100 != 0) {
		esbisiesto = true;
	}
	if (esbisiesto) {
		switch (mes) {
		case 2:
			if (dia > 29) return true;
			else return false;
			break;
		case 4: case 6: case 9: case 11:
			if (dia > 30) return true;
			else return false;
			break;
		default:
			return false;
		}
	}
	else {
		switch (mes) {
		case 2:
			if (dia > 28) return true;
			else return false;
			break;
		case 4: case 6: case 9: case 11:
			if (dia > 30) return true;
			else return false;
			break;
		default:
			return false;
		}
	}
}
void ShowMyPlanes() {
	system("CLS");
	listPila.resetselect();
	int aux_cont = listPila.cantPila();
	cout << "Los planes estan ubicados del mas prioritario al menos prioritario" << endl << endl;
	for (int i = 0; i < aux_cont; i++)
	{
		if (listPila.select->data.GetIdUser() == userActive->GetId()) {
			listPila.select->data.Show();
			cout << "------------------------------------------------------------" << endl;
		}
		listPila.sgt();
	}
	cout << endl << endl << "Presione cualquier tecla para regresar al menu...";
	_getch();
}
void CreateNewPlanes() {
	system("CLS");

	string titulo, wordkey;
	int dia, mes, year;
	do {
		system("CLS");
		cout << endl << "Digite su palabra Clave: (Sirve como identificador unico)";
		cin >> wordkey;
		cout << "Digite un dia: ";
		cin >> dia;
		cout << endl << "Digite un mes: ";
		cin >> mes;
		cout << endl << "Digite un year: ";
		cin >> year;
		cout << endl << "Digite un titulo: ";
		cin.ignore();
		getline(cin, titulo);
		if (validarfecha(dia, mes, year)) {
			cout << endl << "Error digite correctamente";
			_getch();
		}
	} while (validarfecha(dia, mes, year));
	Planes* planes = new Planes(userActive->GetId(), listPila.cantPila() + 1, titulo, dia, mes, year, wordkey);
	listPila.Append(*planes);
	SaveListPlanes();
	cout << endl << "Se registro satisfactoriamente";
	_getch();
}
int polinomialHash(string x, int size) {
	int hash = 0, p = 1, a = 89;
	for (int i = x.size() - 1; i >= 0; i--) {
		hash = (hash + x.at(i) - 'a' + 1) * p % size;
		p = (p * a) % size;
	}
	return hash;
}
void CreateNewPlanesBST() {
	system("CLS");
	string titulo, wordkey;
	int dia, mes, year, al, al2;
	do {
		system("CLS");
		cout << "Digite su palabra Clave: (Sirve como identificador unico)" << endl;
		cin >> wordkey;
		cout << endl << "Digite un dia: ";
		cin >> dia;
		cout << endl << "Digite un mes: ";
		cin >> mes;
		cout << endl << "Digite un year: ";
		cin >> year;
		cout << endl << "Digite un titulo: ";
		cin.ignore();
		getline(cin, titulo);
		if (validarfecha(dia, mes, year)) {
			cout << endl << "Error digite correctamente";
			_getch();
		}
	} while (validarfecha(dia, mes, year));
	listPlanes.counts();
	al = ((rand() % 9) + 1) * 1000 + rand() % 10 * 100 + rand() % 10 * 10 + rand() % 10;
	al2 = rand() % 10 * 1000 + rand() % 10 * 100 + rand() % 10 * 10 + rand() % 10;
	aleatoriedad[cant] = al * 10000 + al2;
	listPlanes.insertacion(new Planes(userActive->GetId(), al * 10000 + al2, titulo, dia, mes, year, wordkey));
	ArrMergeSort[cant] = new Planes(userActive->GetId(), al * 10000 + al2, titulo, dia, mes, year, wordkey);
	SaveListPlanes();
	cant++;
	cout << endl << "Se registro satisfactoriamente";
	_getch();
}
void ShowMyPlanesBST() {
	system("CLS");
	//listPlanes.preorderdacion();
	listPlanes.inorderdacion(userActive->GetId());
	_getch();
}
void merge(Planes** L, Planes** R, Planes** A, int n) {
	int left_size = n / 2;
	int right_size = n - left_size;
	int i = 0, j = 0, k = 0;
	while (i < left_size && j < right_size) {
		if (L[i]->GetYear() < R[j]->GetYear()) {
			A[k] = L[i];
			k++; i++;
		}
		//
		else if (L[i]->GetYear() == R[j]->GetYear()) {
			if (L[i]->GetMonth() < R[j]->GetMonth()) {
				A[k] = L[i];
				k++; i++;
			}
			//
			else if (L[i]->GetMonth() == R[j]->GetMonth()) {
				if (L[i]->GetDay() > R[j]->GetDay()) {
					A[k] = L[i];
					k++; i++;
				}
				else {
					A[k] = R[j];
					k++; j++;
				}
			}
			else {
				A[k] = R[j];
				k++; j++;
			}
		}
		else {
			A[k] = R[j];
			k++; j++;
		}
	}
	while (i < left_size) {
		A[k] = L[i];
		k++; i++;
	}
	while (j < right_size) {
		A[k] = R[j];
		k++; j++;
	}
}
void mergeSort(Planes** A, int n) {
	if (n > 1) {
		int mid = n / 2;
		Planes** L = new Planes * [mid];
		Planes** R = new Planes * [n - mid];
		for (int i = 0; i < mid; ++i) {
			L[i] = A[i];
		}
		for (int i = mid; i < n; ++i) {
			R[i - mid] = A[i];
		}
		mergeSort(L, mid);
		mergeSort(R, n - mid);
		merge(L, R, A, n);
		delete[]L;
		delete[]R;
	}
}
void BuscarporID() {
	system("CLS");
	long IdPlan;
	cout << "Ingrese el ID del plan a buscar: ";
	cin >> IdPlan;
	Planes* aux = listPlanes.BuscarIndice(IdPlan);
	if (userActive->GetId() == aux->GetIdUser()) {
		cout << endl << endl;
		aux->Show();
		cout << endl;
	}
	else {
		cout << "El ID del plan ingresado no existe por favor ingrese nuevamente" << endl;
	}
	_getch();
}
void BorrarporID() {
	system("CLS");
	long IdPlan;
	cout << "Ingrese el ID del plan a eliminar: ";
	cin >> IdPlan;
	Planes* aux = listPlanes.BuscarIndice(IdPlan);
	if (userActive->GetId() == aux->GetIdUser()) {
		for (int i = 0; i < cant; i++) {
			if (aleatoriedad[i] == IdPlan) {
				aleatoriedad[i] = NULL;
			}
		}
		listPlanes.deleteNode(IdPlan);
		SaveListPlanes();
		cant = 0;
		LoadListPlanes();
		cout << endl << "El plan se ha eliminado correctamente" << endl;
	}
	else {
		cout << "El ID del plan ingresado no existe por favor ingrese nuevamente" << endl;
	}
	_getch();
}

void MenuPlanes() {
	int opt;
	do
	{
		Nav();
		cout << "\t******* MENU *******" << endl << endl;
		cout << "[ 1 ] Crear nuevos planes." << endl;
		cout << "[ 2 ] Mostrar mis planes." << endl;
		cout << "[ 3 ] Ordenar planes por mas prioritarios" << endl;
		cout << "[ 4 ] Buscar por ID de plan." << endl;
		cout << "[ 5 ] Eliminar por ID de plan." << endl;
		cout << "[ 6 ] Atras." << endl << endl;

		cout << "Ingrese su opcion: ";
		cin >> opt;

		if (opt == 1) CreateNewPlanesBST();
		if (opt == 2) {
			//OrdenarPilas();
			//ShowMyPlanes();
			ShowMyPlanesBST();
		}
		if (opt == 3) {
			system("CLS");
			mergeSort(ArrMergeSort, cant);
			for (int i = 0; i < cant; i++) {
				if (ArrMergeSort[i]->GetIdUser() == userActive->GetId())
				{
					ArrMergeSort[i]->Show();
					cout << endl << "------------------------------------------------------------" << endl;
				}
			}
			_getch();
		}
		if (opt == 4) {
			BuscarporID();
		}
		if (opt == 5) {
			BorrarporID();
		}

	} while (opt != 6);
	MenuPrincipal();
}
#pragma endregion


/*---------------------------------------*/
#pragma region USERS
bool Login(string login, string password) {

	auto f = [login, password](User u)->bool { return (u.GetLogin() == login && u.GetPassword() == password); };

	User* user = new User();
	*user = lstUsers.GetData(f);
	userActive = user;
	if (user->GetId() == 0) return false;

	return true;
}
void ShowAllUsers() {
	lstUsers.resetSelected();
	for (int i = 0; i < lstUsers.GetCount(); i++) {
		lstUsers.selected->data.Show();
		cout << "------------------------------------------------------------" << endl;
		lstUsers.Sgt();
	}
}
void MenuIniciarSesion() {
	system("CLS");
	cout << "******  MIS NOTAS UPC  *******" << endl << endl;
	string login, pass;
	cout << "Ingrese su correo: ";
	cin >> login;
	cout << "Ingrese su contrasena: ";
	cin >> pass;

	if (Login(login, pass))
	{
		system("CLS");
		cout << endl << endl << endl << endl << "\tHola de nuevo '" << userActive->GetName() << "',\n\tListo para tomar notas de tus ideas....?";
		_getch();
		MenuPrincipal();
	}
	else
	{
		system("CLS");
		cout << endl << endl << endl << endl << endl << "\t! EL USUARIO O CONTRASEÑA ES INCORRECTO !" << endl << endl << endl;
		Redireccionar();
	}
}


/*---------------------------------------*/
#pragma endregion
void MenuPrincipal() {
	int opt;
	do
	{
		Nav();
		cout << "\t** MENU PRINCIPAL**" << endl << endl;
		cout << "[ 1 ] NOTAS." << endl;
		cout << "[ 2 ] PLANES." << endl;
		cout << "[ 3 ] Cerrar sesion." << endl << endl;

		cout << "Ingrese su opcion: ";
		cin >> opt;

		if (opt == 1) MenuNotes();
		if (opt == 2) MenuPlanes();

	} while (opt != 3);
}