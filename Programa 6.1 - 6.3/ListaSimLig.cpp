#include "ListaSimLig.hpp"

#include <iostream>

template <class T>
NodoLista<T>::NodoLista(){
    Liga = NULL;
}

template <class T>
T NodoLista<T>::RegresaInfo(){
    return Info;
}

template<class T>
Lista<T>::Lista() {
    primero = NULL;
}

template<class T>
NodoLista<T>* Lista<T>::RegresaPrimero() {
    return primero;
}

template<class T>
void Lista<T>::imprimeRecursivo(NodoLista<T>* p) {
    if (p) {
        std::cout << "\nInformacion: " << p->Info;
        imprimeRecursivo(p->Liga);
    }
    std::cout << "\n";
}

template<class T>
void Lista<T>::imprimeUnNodo(NodoLista<T>* p) {
    if (p) {
        std::cout << p->Info;
    }
}

template<class T>
void Lista<T>::insertarInicio(T dato) {
    NodoLista<T> *p;
    p = new NodoLista<T>();
    p->Info = dato;
    p->Liga = primero;
    primero = p;
}

template<class T>
void Lista<T>::insertaOrdenCrec(T dato) {
    NodoLista<T> *p, *q, *ant;
    if (!primero or primero->Info > dato) {
        insertarInicio(dato);
    } else {
        q = primero;
        while (q and q->Info < dato) {
            ant = q;
            q = q->Liga;
        }
        p = new NodoLista<T>();
        p->Info = dato;
        ant->Liga = p;
        p->Liga = q;
    }
}

template<class T>
int Lista<T>::EliminaUnNodo(T ref) {
    NodoLista<T> *p, *ant;
    int resp = 1;
    if (primero) {
        p = primero;
        while ((p->Liga) and (p->Info != ref)) {
            ant = p;
            p = p->Liga;
        }
        if (p->Info != ref) {
            resp = 0;
        } else {
            if (primero == p) {
                primero = p->Liga;
            } else {
                ant->Liga = p->Liga;
            }
            delete p;
        }
    } else {
        resp = -1;
    }
    return resp;
}

template<class T>
NodoLista<T> * Lista<T>::BuscaOrdenada(T ref) {
    NodoLista<T> *q, *resp = NULL;
    if (primero) {
        q = primero;
        while ((q->Info != ref) and (q->Liga)) {
            q = q->Liga;
        }
        if (q->Info == ref) {
            resp = q;
        }
    }
    return resp;
}
