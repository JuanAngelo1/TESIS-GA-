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
#include "Producto.h"
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
    
    
    void iniciarPoblacion(int numIndividuos,vector<Producto> productos,double maxX,double maxY){
        individuos.clear();
        setTamanoPoblacion(numIndividuos);
        
        for(int i=0;i<numIndividuos;i++){
            Individuo individuo;
            
            individuo.iniciarCromosoma(productos,maxX,maxY);
            
            //Se debe validar que el cromosoma sea una solución valida, sino cambiar orientacion productos
//            individuo.validarSolucion();
            
            individuos.push_back(individuo);
            
        }
        
        //actualizarMejorFitness();
        
    }
    
    void calcularFitness(Vehiculo vehiculo,double coefEsta,double coefApilamiento,double coefProximidad, double coefAccesibilidad){
        
        for(int i=0;i<tamanoPoblacion;i++){
            individuos[i].calcularFitness(vehiculo,coefEsta,coefApilamiento,coefProximidad,coefAccesibilidad);
        }
        
    }



};

#endif /* POBLACION_H */

