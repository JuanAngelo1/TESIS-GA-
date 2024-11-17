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
    void setMejorFitness(double fitness){ mejorFitness = fitness; }
    void setIndividuos(vector<Individuo> indis) { individuos = indis; }
    void setTamanoPoblacion(int tam) { tamanoPoblacion = tam; }
    
    //Getters
    double getMejorFitness() const { return mejorFitness; }
    int getTamanoPoblacion() const { return tamanoPoblacion; }
    vector<Individuo> getIndividuos() const { return individuos; }
    
    
    void iniciarPoblacion(int numIndividuos,vector<Producto>& productos,Vehiculo& vehiculo,double maxX,double maxY){
        individuos.clear();
        int i=0,intentos=0,maxIntentos=10;
        bool valida;
        setTamanoPoblacion(numIndividuos);
        
        while(i<numIndividuos && intentos<maxIntentos){
            Individuo individuo;
            
            individuo.iniciarCromosoma(productos,maxX,maxY);
            
            //Se debe validar que el cromosoma sea una solución valida
            valida=individuo.validarSolucion(productos,vehiculo);
            
            if(valida){
//                cout<<"Valida"<<endl;
                individuos.push_back(individuo);
                i++;
                intentos=0;
            }else
                intentos++;
            
        }
        cout<<"Indivudos Inicializados"<<endl;
    }
    
    void calcularFitness(Vehiculo vehiculo,double coefEsta,double coefApilamiento,double coefProximidad, double coefAccesibilidad){
        for(int i=0;i<tamanoPoblacion;i++){
            individuos[i].calcularFitness(vehiculo,coefEsta,coefApilamiento,coefProximidad,coefAccesibilidad);           
        } 
        

    }



};

#endif /* POBLACION_H */

