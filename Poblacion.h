/* 
 * File:   Poblacion.h
 *  Autor  : Juan Angelo Flores Rubio
 *  Codigo : 20196493
 * Created on 14 de noviembre de 2024, 09:05 PM
 */


#ifndef POBLACION_H
#define POBLACION_H

#include <fstream>
#include "Individuo.h"
using namespace std;

class Poblacion {
private:
    vector<Individuo> individuos;      // Vector de individuos (soluciones)
    int tamanoPoblacion;               // Tamaño de la población
    double mejorFitness;               // Fitness del mejor individuo actual
    
public:
    
    
    
    //Setters
    void setMejorFitness(double mejorFitness){ mejorFitness = mejorFitness; }
    void setIndividuos(vector<Individuo> individuos) { individuos = individuos; }
    void setTamanoPoblacion(int tamanoPoblacion) { tamanoPoblacion = tamanoPoblacion; }
    
    //Getters
    double getMejorFitness() const { return mejorFitness; }
    int getTamanoPoblacion() const { return tamanoPoblacion; }
    vector<Individuo> getIndividuos() const { return individuos; }
    
    
    void iniciarPoblacion(int numIndividuos,int cantProductos){
        //Se debería inicializar cada uno de los individuos
        //Llamar a su propio metodo de Individuo para crearle su cromosoma
        //Y asignar su solucion de manera random
        
        
    }



};

#endif /* POBLACION_H */

