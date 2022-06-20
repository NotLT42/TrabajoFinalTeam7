#pragma once
#include <string>
using namespace std;

class FastNotes {

private:
	string materia;
	string descripcion; 
	string estado;
	FastNotes* fn;
public:

	FastNotes();
	FastNotes(string pmateria, string pdescripcion, string pestado);
	~FastNotes();

	void setMateria(string value);
	void setDescripcion(string value);
	void setEstado(string value);

	string getMateria();
	string getDescripcion();
	string getEstado();

	FastNotes* getFastnotes() { return fn; }
	void show();
};