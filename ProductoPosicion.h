/* 
 * File:   ProductoPosicion.h
 * Autor  : Juan Angelo Flores Rubio
 * Codigo : 20196493
 * Created on 14 de noviembre de 2024, 10:17 PM
 */

#ifndef PRODUCTOPOSICION_H
#define PRODUCTOPOSICION_H

#include <fstream>
#include "Producto.h"
using namespace std;

class ProductoPosicion {
public:
    Producto producto;  // Producto a cargar
    double x,y,z;

public:
    ProductoPosicion(Producto prod, double posX, double posY,double posZ) 
        : producto(prod), x(posX), y(posY),z(posZ) {}
    

};

#endif /* PRODUCTOPOSICION_H */
