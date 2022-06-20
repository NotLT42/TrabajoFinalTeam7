#include "controller.h"



void color(int X)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), X);
}

int main() {
	srand(time(0));
	color(228);//249--233
	LoadListUsers();
	LoadListNotes();
	LoadListPlanes();

	//cout << lstNotes.getCount();
	//LoadListFastNotes(); 
	//cout << lstNotes.getCount();
	int opt;
	do
	{
		system("CLS");
		cout << endl << "******  MIS NOTAS UPC  *******" << endl << endl;

		cout << "\t** MENU **" << endl << endl;
		cout << "[ 1 ] Iniciar Sesion." << endl;
		cout << "[ 2 ] Registrarse." << endl;
		cout << "[ 3 ] Salir de la aplicacion." << endl << endl;

		cout << "Ingrese su opcion: ";
		cin >> opt;

		if (opt == 1)  MenuIniciarSesion();
		if (opt == 2) MenuRegistrarse();

	} while (opt != 3);

	_getch();
}