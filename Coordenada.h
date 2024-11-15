/* 
 * File:   Coordenada.h
 * Autor  : Juan Angelo Flores Rubio
 * Codigo : 20196493
 * Created on 14 de noviembre de 2024, 05:52 PM
 */

#ifndef COORDENADA_H
#define COORDENADA_H

#include <fstream>
#include <iostream>
using namespace std;

class Coordenada {
public:
    double x, y;

    Coordenada(double posX, double posY) : x(posX), y(posY) {}

    // Sobrecargar el operador < para usar Coordenada como clave en map
    bool operator<(const Coordenada& otra) const {
        if (x == otra.x) return y < otra.y;
        return x < otra.x;
    }

    // Función para mostrar la coordenada (opcional, para debugging)
    void mostrarCoordenada() const {
        cout << "Coordenada: (" << x << ", " << y << ")" <<endl;
    }
};
#endif /* COORDENADA_H */
