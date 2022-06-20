#pragma once
#include <iostream>
#include <functional>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class ListaSimple {

public:
    Node<T>* head = nullptr;
    Node<T>* selected = nullptr;

    ~ListaSimple() {
        delete head;
    }

    void Append(T data) {
        if (head == nullptr) {
            head = new Node<T>();
            head->data = data;
            selected = head;
            return;
        }

        Node<T>* aux = head;
        Node<T>* newNode = new Node<T>();

        newNode->data = data;

        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = newNode;
    }

    int GetCount() {

        int count = 0;
        Node<T>* aux = head;
        while (aux != nullptr) {
            count++;
            aux = aux->next;
        }
        delete aux;
        return count;
    }

    void Sgt() {
        if (selected->next != nullptr)
            selected = selected->next;
    }

    void resetSelected() {
        if (head != nullptr)
            selected = head;
    }

    T GetData(function<bool(T)> f) {
        Node<T>* aux = head;
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
