#pragma once
#include <iostream>
#include <functional>

using namespace std;

template <typename T>
class Nodo {
public:
	T data;
	Nodo* next;
	Nodo* prev;
	Nodo(T data, Nodo* next = nullptr, Nodo* prev = nullptr) :data(data), next(next), prev(prev) {}
};

template <typename T>
class ListaDoble
{
public:
	Nodo<T>* head = nullptr;
	Nodo<T>* selected = nullptr;

	void append(T data) { // AGREGAR ELEMENTO 
		Nodo<T>* nodo = new Nodo<T>(data);

		if (this->head == nullptr) { //solo para el primer nodo
			this->head = nodo;
			this->selected = head;
			return;
		}
		Nodo<T>* last = this->head;
		while (last->next != nullptr) {
			last = last->next;
		}
		last->next = nodo;
		nodo->prev = last;
	}

	void delete_n() { // ELIMINAR ELEMENTO SELECCIONADO
		Nodo<T>* temp = this->selected;
		// Verificar si está vacío
		if (selected == nullptr) return;

		// Verificar si es el unico nodo
		if (temp->prev == nullptr && temp->next == nullptr) {
			this->head = nullptr;
			selected = head;
			free(temp);
			return;
		}

		// SI anterior tiene un elemento, se reemplaza su next por el que se elimina
		if (temp->prev != nullptr) {
			temp->prev->next = temp->next;
			this->selected = temp->prev;
		}

		// SI siguiente tiene un elemento, se reemplaza su next por el que se elimina
		if (temp->next != nullptr) {
			temp->next->prev = temp->prev;
			this->selected = temp->next;
			free(temp);
		}
	}

	int getCount() {
		if (selected == nullptr) {
			resetSelected();
			return 0;
		}
		selected = selected->next;
		return getCount() + 1;
	}

	void sgt() {
		if (this->selected->next != nullptr)
			selected = selected->next;
	}

	void prev() {
		if (this->selected->prev != nullptr)
			selected = selected->prev;
	}

	bool isEmpty() {
		return this->head == nullptr;
	}

	void resetSelected() {
		selected = head;
	}

	T GetData(function<bool(T)> f) {
		Nodo<T>* aux = head;
		while (aux != nullptr)
		{
			if (f(aux->data))
			{
				return aux->data;
			}
			aux = aux->next;
		}
		T* t = new T();
		return *t;
	}
};
