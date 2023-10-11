#ifndef LISTASIMLIG_HPP
#define LISTASIMLIG_HPP

template <class T> 
class Lista;

// Nodo
template <class T>
class NodoLista {
    private:
        NodoLista<T> *Liga;
        T Info;

    public:
        NodoLista();
        T RegresaInfo();
        friend class Lista<T>;
};

// Lista
template <class T>
class Lista{
    private:
        NodoLista<T> * primero;
    public:
        Lista ();
        NodoLista<T> * RegresaPrimero();
        //void creaInicio();
        //void creaFinal();
        //void imprimeIterativo();
        void imprimeRecursivo(NodoLista <T> *);
        void imprimeUnNodo(NodoLista <T> *);
        void insertarInicio(T);
        //void insertarFinal(T);
        void insertaOrdenCrec(T);
        //void insertaAntes(T, T);
        //void EliminaPrimero();
        //void EliminaUltimo();
        int EliminaUnNodo(T);
        //void EliminaAnterior(T);
        //void EliminaDespues(T);
        //NodoLista<T> * BuscaDesordenada(T);
        NodoLista<T> * BuscaOrdenada(T);
        //NodoLista<T> * BuscaRecursivo(T, NodoLista<T> *);
};

#endif // LISTASIMLIG_HPP