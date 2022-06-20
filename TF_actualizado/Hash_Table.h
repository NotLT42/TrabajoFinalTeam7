#pragma once
#include "Header.h"
#include <list>
#include "FastNotes.h"
using namespace std;

template<typename T>

class HashTable
{
private:
	T key;
	T value;
	int valueHash;
	static const int hashGroups = 10;
	list<pair<string, T>> table[hashGroups];
public:
	HashTable() { }

	~HashTable() { }

	void setValue(T _value) { value = _value; }

	T getValue() { return value; }

	int getHashGroups() { return hashGroups; }

	bool isEmpty() const {
		int sum{};

		for (int i{}; i < hashGroups; i++) {
			sum += table[i].size();
		}

		if (!sum) {
			return true;
		}
	}

	int hashFunction(string key) { //leer materia
		int suma{};

		for (int i = 0; i < key.length(); i++) {
			suma += key[i];
		}

		return suma % hashGroups;
	}


	void insertItem(string key, T value) {
		int hashValue = hashFunction(key);

		auto& cell = table[hashValue];
		auto iterador = begin(cell);
		bool keyExists = false;

		for (; iterador != end(cell); iterador++) {
			if (iterador->first == key) {
				keyExists = true;
				iterador->second = value;

				cout << "La clave existe" << endl;
				break;
			}
		}

		if (!keyExists) {
			cell.emplace_back(key, value);
		}

		return;

	}

	void removeItem(string key) {

		int hashValue = hashFunction(key);
		auto& cell = table[hashGroups];
		auto iterador = begin(cell);
		bool keyExists = false;

		for (; iterador != end(cell); iterador++) {
			if (iterador->first == key) {
				keyExists = true;

				iterador = cell.erase(iterador);
				cout << "Par eliminado " << endl;
				break;
			}
		}

		if (!keyExists) {
			cout << "Clave no encontrada" << endl;
		}

		return;

	}

	void printTable() {

		for (int i{}; i < hashGroups; i++) {
			if (table[i].size() == 0) continue;

			auto iterador = table[i].begin();

			for (; iterador != table[i].end(); iterador++) {
				cout << "Key:  " << iterador->first << "  Value:  " << iterador->second << endl;

			}
		}

		return;
	}

	string seachTable(string key) {

		int hashValue = hashFunction(key);
		auto& cell = table[hashGroups];
		auto iterador = begin(cell);
		bool keyExists = false;

		for (; iterador != end(cell); iterador++) {
			if (iterador->first == key) {
				keyExists = true;

				return true;
				break;
			}
		}

		if (!keyExists) {
			return false;
		}

		return;
	}
};
