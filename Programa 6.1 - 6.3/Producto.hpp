#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include <iostream>

class Producto {
    private:
        int clave;
        char nomProd[64];
        double precio;

    public:
        Producto();
        Producto(int, const char[], double);

        double regresaPrecio();
        
        bool operator == (const Producto &comparado);
        bool operator != (const Producto &comparado);
        bool operator < (const Producto &comparado);
        bool operator > (const Producto &comparado);

        friend std::istream &operator >> (std::istream&, Producto&);
        friend std::ostream &operator << (std::ostream&, Producto&);
};

#endif // PRODUCTO_HPP