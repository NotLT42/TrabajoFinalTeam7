#include "FastNotes.h"
#include <iostream>

using namespace std;

FastNotes::FastNotes() { }

FastNotes::FastNotes(string pmateria, string pdescripcion, string pestado) {
	materia = pmateria;
	descripcion = pdescripcion;
	estado = pestado;
}

FastNotes::~FastNotes() { }

void FastNotes::setMateria(string value) { materia = value; }
void FastNotes::setDescripcion(string value) { descripcion = value; }
void FastNotes::setEstado(string value) { estado = value; }

string FastNotes::getMateria() { return materia; }
string FastNotes::getDescripcion() { return descripcion; }
string FastNotes::getEstado() { return estado; }

void FastNotes::show() {
	cout << "Materia: " << materia << "\n" << "Descripcion: " << descripcion << "\n" << "Estado: " << estado << "\n";
}
