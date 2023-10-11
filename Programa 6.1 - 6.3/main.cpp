#include "ListaSimLig.hpp"
#include "Producto.hpp"
#include "ListaSimLig.cpp"

#include <iostream>

using namespace std;

int menu () {
    int opc;
    cout << "\n\nBienevnidos al sistema de registro de productos.\n\n";
    cout << "\n(1) Registrar un nuevo producto.\n";
    cout << "\n(2) Dar de baja un producto.\n";
    cout << "\n(3) Verificar si un producto ya fue registrado.\n";
    cout << "\n(4) Imprimir la lista de productos registrados.\n";
    cout << "\n(5) Salir.\n";
    cout << "\n\nIngrese opcion de trabajo:\n";
    cin >> opc;
    return opc;
}

int main () {
    Lista<Producto> listaProds;
    Producto objProd;
    NodoLista<Producto> *apunt;
    int opc, res, clave;

    opc = menu();
    while (opc >= 1 and opc <= 4) {
        switch (opc) {
        case 1:
            cout << "\n\nIngrese datos del producto a registrar:\n";
            cin >> objProd;
            listaProds.insertaOrdenCrec(objProd);
            break;

        case 2: {
            cout << "\n\nIngrese la clave del producto a eliminar:\n";
            cin >> clave;
            Producto Product(clave, "", 0);

            res = listaProds.EliminaUnNodo(Product);
            switch (res) {
            case 1:
                cout << "\n\nEl producto ya fue eliminado.\n";
                break;
            case 0:
                cout << "\n\nEse producto no se encuentra registrado.\n";
                break;
            case -1:
                cout << "\n\nHo hay prodcutos registrados.\n";
                break;
            }
        }break;

        case 3: {
            cout << "\n\nIngrese la clave del producto a buscar:\n";
            cin >> clave;

            Producto Produc(clave, "", 0);
            apunt = listaProds.BuscaOrdenada(Produc);
            if (!apunt) {
                cout << "\n\nEse producto no esta registrado.\n";
            } else {
                cout << "\n\nEse producto ya esta registrado.\n";
                listaProds.imprimeUnNodo(apunt);
            }
        }break;

        case 4: {
            listaProds.imprimeRecursivo(listaProds.RegresaPrimero());
        }break;

        case 5:
            break;
        }

        opc = menu();
    }
}