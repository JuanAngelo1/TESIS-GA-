/* 
 * File:   Poblacion.h
 *  Autor  : Juan Angelo Flores Rubio
 *  Codigo : 20196493
 * Created on 14 de noviembre de 2024, 09:05 PM
 */


#ifndef POBLACION_H
#define POBLACION_H

#include <fstream>
#include <algorithm> 
#include <random>   
#include <vector>
#include <chrono>
#include "Individuo.h"
#include "Producto.h"
#include "Padres.h"
using namespace std;


class Poblacion {
private:
    vector<Individuo> individuos;      // Vector de individuos (soluciones)
    int tamanoPoblacion;               // Tamaño de la población
    double mejorFitness;               // Fitness del mejor individuo actual
    Individuo mejorIndividuo;
    
public:
    //Setters
    void setMejorFitness(double fitness){ mejorFitness = fitness; }
    void setIndividuos(vector<Individuo> indis) { individuos = indis; }
    void setTamanoPoblacion(int tam) { tamanoPoblacion = tam; }
    void setMejorIndividuo(Individuo in){mejorIndividuo=in;}
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
                individuos.push_back(individuo);
                i++;
                intentos=0;
            }else
                intentos++;
            
        }
        cout<<"Indivudos Inicializados"<<endl;
    }
    
    void calcularFitness(Vehiculo vehiculo,double coefEsta,double coefApilamiento,double coefProximidad, double coefAccesibilidad){
        
        double mejorFit=-1000;
        double fitnessActual,indice;
        for(int i=0;i<tamanoPoblacion;i++){
            fitnessActual= individuos[i].calcularFitness(vehiculo,coefEsta,coefApilamiento,coefProximidad,coefAccesibilidad);
            if(fitnessActual>mejorFit){
                mejorFit=fitnessActual;
                indice=i;
            }
                
        }
        setMejorIndividuo(individuos[indice]);
        setMejorFitness(mejorFit);  
    }
    
    void imprimirSoluFinal(){
        
        mejorIndividuo.imprimirSolu();
    }
    
    Padres seleccionarPadresRuleta() {
        double sumFitness = 0.0;
        for (const auto& individuo : individuos) {
            sumFitness += individuo.getFitness();
        }

        // Seleccionar el primer padre
        double pickFitness1 = (static_cast<double>(rand()) / RAND_MAX) * sumFitness;
        double cumFitness = 0.0;
        Individuo padre1;

        for (const auto& individuo : individuos) {
            cumFitness += individuo.getFitness();
            if (cumFitness >= pickFitness1) {
                padre1 = individuo;
                break;
            }
        }

        // Ajustar el fitness acumulado para excluir al primer padre
        sumFitness -= padre1.getFitness();

        // Seleccionar el segundo padre
        double pickFitness2 = (static_cast<double>(rand()) / RAND_MAX) * sumFitness;
        cumFitness = 0.0;
        Individuo padre2;

        for (const auto& individuo : individuos) {
            if (individuo.getFitness() == padre1.getFitness()) {
                continue; // Evitar elegir el mismo padre
            }
            cumFitness += individuo.getFitness();
            if (cumFitness >= pickFitness2) {
                padre2 = individuo;
                break;
            }
        }

        return Padres(padre1, padre2);
    }
    
    Padres seleccionarPadresTorneo(int tamTorneo) {
        
        vector<int> indices(individuos.size());
        iota(indices.begin(), indices.end(), 0); 
        
        shuffle(indices.begin(), indices.end(), rng);
        

        // Seleccionar el primer padre
        Individuo padre1;
        double mejorFitness = -1000;
        int indexPadre1 = -1;
    
        for (int i = 0; i < tamTorneo; ++i) {
            int idx = indices[i];
            if (individuos[idx].getFitness() > mejorFitness) {
                mejorFitness = individuos[idx].getFitness();
                padre1 = individuos[idx];
                indexPadre1 = idx; 
            }
        }

        indices.erase(remove(indices.begin(), indices.end(), indexPadre1), indices.end());


        shuffle(indices.begin(), indices.end(), rng); // Rebarajar los índices

        // Seleccionar el segundo padre
        Individuo padre2;
        mejorFitness = -1000;

        for (int i = 0; i < tamTorneo; ++i) {
            int idx = indices[i];
            if (individuos[idx].getFitness() > mejorFitness) {
                mejorFitness = individuos[idx].getFitness();
                padre2 = individuos[idx];
            }
        }

        return Padres(padre1, padre2);
    }
    
    vector<Individuo> seleccionarNuevaGeneracion(const vector<Individuo>& nuevaPoblacion,int tamPoblacion) {
        
        // Combinar la población actual con la nueva población generada
        vector<Individuo> poblacionCombinada = individuos;
        poblacionCombinada.insert(poblacionCombinada.end(), nuevaPoblacion.begin(), nuevaPoblacion.end());

        // Ordenar la población combinada por fitness (de mayor a menor)
        sort(poblacionCombinada.begin(), poblacionCombinada.end(), [](const Individuo& a, const Individuo& b) {
            return a.getFitness() > b.getFitness();
        });

        // Seleccionar los mejores individuos para la nueva población
        vector<Individuo> nuevaGeneracion(poblacionCombinada.begin(), 
                                          poblacionCombinada.begin() + tamPoblacion);

        return nuevaGeneracion;
    }

};

#endif /* POBLACION_H */

