/* 
 * File:   Individuo.h
 *  Autor  : Juan Angelo Flores Rubio
 *  Codigo : 20196493
 * Created on 14 de noviembre de 2024, 09:12 PM
 */


#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include <fstream>
#include <vector>
#include "ProductoPosicion.h"
#include "Solucion.h"
using namespace std;

class Individuo {
    
private:
    vector<ProductoPosicion> cromosoma;
    Solucion solucion;
    double fitness;
    
public:
    double getFitness() const { return fitness; }    
    void setFitness(double f) {
        fitness = f;
    }
    
};

#endif /* INDIVIDUO_H */

