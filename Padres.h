/* 
 * File:   Padres.h
 * Autor  : Juan Angelo Flores Rubio
 * Codigo : 20196493
 * Created on 17 de noviembre de 2024, 01:14 PM
 */

#ifndef PADRES_H
#define PADRES_H

#include <fstream>
#include <algorithm> 
#include <random>   
#include <vector>
#include <chrono>
#include "Individuo.h"
#include "rng.h"
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
    
    vector<Individuo> crossoverOnePoint() const{
        // Obtener los cromosomas de los padres
        vector<ProductoPosicion> cromosoma1  = padre1.getCromosoma();
        vector<ProductoPosicion> cromosoma2  = padre2.getCromosoma();
        int tamCromosoma = cromosoma1.size();

        // Generar un punto de cruce aleatorio
        uniform_int_distribution<int> dist(1, tamCromosoma - 1); // Punto entre 1 y tamCromosoma - 1
        int puntoCruce = dist(rng);
       
        // Crear los cromosomas de los hijos
        vector<ProductoPosicion> hijo1Cromosoma(cromosoma1.begin(), cromosoma1.begin() + puntoCruce);
        hijo1Cromosoma.insert(hijo1Cromosoma.end(), cromosoma2.begin() + puntoCruce, cromosoma2.end());

        vector<ProductoPosicion> hijo2Cromosoma(cromosoma2.begin(), cromosoma2.begin() + puntoCruce);
        hijo2Cromosoma.insert(hijo2Cromosoma.end(), cromosoma1.begin() + puntoCruce, cromosoma1.end());

        // Crear los objetos Individuo para los hijos
        Individuo hijo1(hijo1Cromosoma);
        Individuo hijo2(hijo2Cromosoma);        

        return {hijo1, hijo2};
    }
    
    vector<Individuo> crossoverUniform() const {
        // Obtener los cromosomas de los padres
        vector<ProductoPosicion> cromosoma1 = padre1.getCromosoma();
        vector<ProductoPosicion> cromosoma2 = padre2.getCromosoma();
        int tamCromosoma = cromosoma1.size();

        // Cromosomas para los hijos
        vector<ProductoPosicion> hijo1Cromosoma;
        vector<ProductoPosicion> hijo2Cromosoma;

        // Generar la máscara aleatoria para el cruce uniforme
        for (int i = 0; i < tamCromosoma; ++i) {
            if (uniform_real_distribution<double>(0.0, 1.0)(rng) < 0.5) {
                // Gen del padre 1 va al hijo 1, gen del padre 2 va al hijo 2
                hijo1Cromosoma.push_back(cromosoma1[i]);
                hijo2Cromosoma.push_back(cromosoma2[i]);
            } else {
                // Gen del padre 2 va al hijo 1, gen del padre 1 va al hijo 2
                hijo1Cromosoma.push_back(cromosoma2[i]);
                hijo2Cromosoma.push_back(cromosoma1[i]);
            }
        }

        // Crear los objetos Individuo para los hijos
        Individuo hijo1(hijo1Cromosoma);
        Individuo hijo2(hijo2Cromosoma);

        // Retornar los dos hijos
        return {hijo1, hijo2};
    }


    
};

#endif /* PADRES_H */
