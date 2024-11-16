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
#include "Producto.h"
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
    
    void iniciarCromosoma(vector<Producto> prods,double maxX,double maxY){
        cromosoma.clear();

        for (int i=0;i<prods.size();i++) {

            double posX = round((static_cast<double>(rand()) / RAND_MAX * maxX) * 100.0) / 100.0;  // Redondear a 2 decimales
            double posY = round((static_cast<double>(rand()) / RAND_MAX * maxY) * 100.0) / 100.0;

            ProductoPosicion productoPosicionado(prods[i].getIdProducto(),prods[i], posX, posY, 0); // z inicializado a 0
            cromosoma.push_back(productoPosicionado);

        }
        
    }
    
    void calcularFitness(Vehiculo vehiculo,double coefEsta,double coefApilamiento,
                            double coefProximidad, double coefAccesibilidad){
        
        solucion.calcularFitness(vehiculo,coefEsta,coefApilamiento,coefProximidad,coefAccesibilidad);
        
        setFitness(solucion.getFitness());
    }
    
    
    
    
};

#endif /* INDIVIDUO_H */

