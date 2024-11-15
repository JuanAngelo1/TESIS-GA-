/* 
 * File:   Espacio.h
 *  Autor  : Juan Angelo Flores Rubio
 *  Codigo : 20196493
 * Created on 14 de noviembre de 2024, 11:40 PM
 */


#ifndef ESPACIO_H
#define ESPACIO_H

#include <fstream>
#include <vector>
#include <stack>
#include "Producto.h"
using namespace std;

class Espacio {
private:
    stack<Producto*> pilaDeProductos;  // Pila de productos en este espacio
    double alturaMaxima;               // Altura máxima que puede ser apilada
    double alturaActual;               // Altura actual ocupada

    double posX, posY, posZ;           // Coordenadas del espacio

    double largo;                      // Largo del espacio (basado en el primer producto)
    double ancho;                      // Ancho del espacio (basado en el primer producto)
    
public:
    Espacio(double alturaMaxVehiculo, double x, double y, double z, double alturaProducto)
    : alturaMaxima(alturaMaxVehiculo), alturaActual(alturaProducto), posX(x), posY(y), posZ(z), largo(0), ancho(0) {}
    
    double getLargo() const { return largo; }
    double getAncho() const { return ancho; }
    double getalturaActual() const { return alturaActual; }
    double getalturaMax() const {return alturaMaxima;}
    stack<Producto*> getPilaDeProductos() const {return pilaDeProductos;}
    
    void setLargo(double la){largo=la;}
    void setAncho(double an){ancho=an;}
    
    bool esApilable(Producto* nuevoProducto) const {
        
        if (pilaDeProductos.empty()) {
            return true;
        }
        
        double pesoAcumulado = nuevoProducto->getPeso();
        
        stack<Producto*> copiaPila = pilaDeProductos; 
        while (!copiaPila.empty()) {
            Producto* productoEnPila = copiaPila.top();
            copiaPila.pop();

            if (pesoAcumulado > productoEnPila->getLimitePeso()) {
                return false; // No es apilable, se excede el límite
            }

            pesoAcumulado += productoEnPila->getPeso();
        }
        
        if (alturaActual + nuevoProducto->getAltura() > alturaMaxima || 
            nuevoProducto->getLargo() > largo || nuevoProducto->getAncho() > ancho) {
            return false; 
        }
        return true;
    }

    bool agregarProducto(Producto* nuevoProducto) {
        if (pilaDeProductos.empty()) {
            largo = nuevoProducto->getLargo();  
            ancho = nuevoProducto->getAncho();  
        }

        if (esApilable(nuevoProducto)) {
            pilaDeProductos.push(nuevoProducto);
            alturaActual += nuevoProducto->getAltura();
            return true;
        }
        return false; 
    }

    
    bool estaVacio() const {
        return pilaDeProductos.empty();
    }
};

#endif /* ESPACIO_H */

