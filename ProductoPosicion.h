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
private:
    int idProducto;
    Producto producto;  // Producto a cargar
    double x,y,z;

public:
    
    ProductoPosicion(int id,Producto prod, double posX, double posY,double posZ) 
        : idProducto(id), producto(prod), x(posX), y(posY),z(posZ) {}
    
    int getIdProducto() const {
        return idProducto;
    }
    
    string getNombre() const{
        return producto.getNombre();
    }

    Producto getProducto() const {
        return producto;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getZ() const {
        return z;
    }

    // Setters
    void setIdProducto(int id) {
        idProducto = id;
    }

    void setProducto(const Producto& prod) {
        producto = prod;
    }

    void setX(double posX) {
        x = posX;
    }

    void setY(double posY) {
        y = posY;
    }

    void setZ(double posZ) {
        z = posZ;
    }
        
};

#endif /* PRODUCTOPOSICION_H */
