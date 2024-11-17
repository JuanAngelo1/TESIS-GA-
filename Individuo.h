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
#include "Espacio.h"
#include "Coordenada.h"
#include "Funciones.h"
using namespace std;

class Individuo {
    
private:
    vector<ProductoPosicion> cromosoma;
    Solucion solucion;
    double fitness;
    
public:
    
    double getFitness() const { return fitness; }    
    void setFitness(double f) { fitness = f;}
    
    void iniciarCromosoma(vector<Producto> prods,double maxX,double maxY){
        cromosoma.clear();

        for (int i=0;i<prods.size();i++) {

            double posX = round((static_cast<double>(rand()) / RAND_MAX * maxX) * 100.0) / 100.0;  // Redondear a 2 decimales
            double posY = round((static_cast<double>(rand()) / RAND_MAX * maxY) * 100.0) / 100.0;

            ProductoPosicion productoPosicionado(prods[i].getIdProducto(),prods[i], posX, posY, 0); // z inicializado a 0
            cromosoma.push_back(productoPosicionado);
        } 
    }
    
    bool validarSolucion(vector<Producto> prods,Vehiculo& vehiculo){
        
        map<Coordenada, Espacio> espacios;
        
        bool primeroValido= crearPrimerEspacio(espacios,prods,vehiculo,cromosoma[0]);
        int i=1;
        int tam=cromosoma.size();
        bool valida=true;
        Producto &producto;
        double posX,posY;
        while(i<tam){
            producto=cromosoma[i].getProducto();
            posX=cromosoma[i].getX();
            posY=cromosoma[i].getY();
            ResultadoEspacio resultado = buscarEspacioDisponible(espacios,producto,posX,posY,vehiculo);
            
            if (resultado == PUDO_APILAR || resultado == NO_HAY_COLISION) {

                if (resultado == NO_HAY_COLISION) 
                    crearNuevoEspacio(espacios, producto, posX, posY, 0, vehiculo.getAlto());
                
            } else {
                if(resultado == NO_SE_PUDO_APILAR || resultado == ESPACIO_INVALIDO){           
                    //-> Ver opcion de crear nueva posicion si no se puede apilar
                }
            }
            
            //Finalmente se devuelve que sea valida y se setea los espacios
            //Para cuando se haga cruce se debe validar tmb la solucion
            
            i++;
        }
        
        if(valida){
            solucion.setEspaciosSolucion(espacios);
            return true;
        }else
            return false;

    }
    
    void calcularFitness(Vehiculo vehiculo,double coefEsta,double coefApilamiento,
                            double coefProximidad, double coefAccesibilidad){
        
        solucion.calcularFitness(vehiculo,coefEsta,coefApilamiento,coefProximidad,coefAccesibilidad);
        
        setFitness(solucion.getFitness());
    }
    
    
    
    
};

#endif /* INDIVIDUO_H */

