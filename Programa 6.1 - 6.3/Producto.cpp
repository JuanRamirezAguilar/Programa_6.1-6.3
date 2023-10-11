#include "Producto.hpp"

#include <string.h>

Producto::Producto() {}
Producto::Producto(int cla, const char nomP[], double pre) {
    clave = cla;
    strcpy(nomProd, nomP);
    precio = pre;
}

double Producto::regresaPrecio () {
    return precio;
}

bool Producto::operator==(const Producto & comparado) {
    return clave == comparado.clave;
}

bool Producto::operator!=(const Producto & comparado) {
    return !(*this == comparado);
}

bool Producto::operator < (const Producto & comparado) {
    return clave < comparado.clave;
}

bool Producto::operator > (const Producto & comparado) {
    return !(*this < comparado);
}

std::istream &operator >> (std::istream& lee, Producto& objProducto) {
    std::cout << std::endl << std::endl << "Ingresa clave del producto: ";
    lee >> objProducto.clave;
    std::cout << std::endl << std::endl << "Ingresa nombre del producto: ";
    lee >> objProducto.nomProd;
    std::cout << std::endl << std::endl << "Ingrese precio: ";
    lee >> objProducto.precio;

    return lee;
}

std::ostream &operator << (std::ostream &escribe, Producto &objProducto) {
    escribe << std::endl << std::endl << "Datos del producto:" <<std::endl;
    escribe << std::endl << "Clave: " << objProducto.clave;
    escribe << std::endl << "Nombre: " << objProducto.nomProd;
    escribe << std::endl << "Precio: " << objProducto.precio;

    return escribe;
}