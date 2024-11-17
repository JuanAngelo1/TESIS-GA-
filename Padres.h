/* 
 * File:   Padres.h
 * Autor  : Juan Angelo Flores Rubio
 * Codigo : 20196493
 * Created on 17 de noviembre de 2024, 01:14 PM
 */

#ifndef PADRES_H
#define PADRES_H

#include <fstream>
#include "Individuo.h"
using namespace std;


class Padres{
private:
    
    Individuo padre1;
    Individuo padre2;
    
public:
        // Constructor
    Padres(const Individuo& p1, const Individuo& p2) : padre1(p1), padre2(p2) {}
    Padres() : padre1(), padre2() {}
    // Getters
    Individuo getPadre1() const { return padre1; }
    Individuo getPadre2() const { return padre2; }

    // Setters (opcional)
    void setPadre1(const Individuo& p1) { padre1 = p1; }
    void setPadre2(const Individuo& p2) { padre2 = p2; }
    
    void imprimirPadres() const {
        cout << "Padre 1 - Fitness: " << padre1.getFitness() << endl;
        cout << "Padre 2 - Fitness: " << padre2.getFitness() << endl;
    }
};

#endif /* PADRES_H */
