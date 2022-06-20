#pragma once
#include <string>

using namespace std;

template <typename T>
struct Node_Pila {
    T data;
    Node_Pila* siguiente;
    Node_Pila(T data, Node_Pila* siguiente = NULL) :data(data), siguiente(siguiente) {}
};

template <typename T>
class Pila
{
public:
    Node_Pila<T>* pila = NULL;
    Node_Pila<T>* select = NULL;
    //int cantidad = 0;
    ~Pila() {
        delete pila;
    }

    void Append(T data) {
        Node_Pila<T>* nuevoNodo = new Node_Pila<T>(data);
        nuevoNodo->data = data;
        nuevoNodo->siguiente = pila;
        pila = nuevoNodo;
    }

    void sacarPila(T& data) {
        Node_Pila<T>* aux = pila;
        data = aux->data
            pila = aux->siguiente;
        delete aux;
    }

    void MostrarPila(T& data) {
        Node_Pila<T>* aux = pila;
        data = aux->data
            select = aux->siguiente;
        delete aux;
    }

    int cantPila() {
        Node_Pila<T>* aux = pila;
        int cantidad = 0;
        while (aux != NULL) {
            aux = aux->siguiente;
            cantidad++;
        }
        delete aux;
        return cantidad;
    }

    void sgt() {
        if (select->siguiente != NULL) {
            select = select->siguiente;
        }
    }

    void resetselect() {
        select = pila;
    }
};

namespace Estructura {
    template <typename G>
    class PilaS {
        class NodoS {
        public:
            G valor;
            NodoS* s;
            NodoS(G v = nullptr) : valor(v) {}
        };

        long cantidad;
        NodoS* inicio;
    public:
        void push(G v) {//insertar
            NodoS* nuevo = new NodoS(v);
            if (inicio == nullptr) inicio = nuevo;
            else {
                nuevo->s = inicio;
                inicio = nuevo;
            }
            cantidad++;
        }

        void pop() {//eliminar inicio
            if (inicio != nullptr) {
                NodoS* aux = inicio;
                inicio = inicio->s;
                delete aux;
            }
        }

        string top() {
            if (inicio != nullptr) {
                return inicio->valor;
            }
            else return NULL;
        }

        bool empty() {
            return (inicio == nullptr) ? true : false;
        }
    };
}

