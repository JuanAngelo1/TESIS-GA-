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
    
    //constructor
    Individuo() : fitness(0.0) {}
    Individuo(const vector<ProductoPosicion>& cromosoma)
        : cromosoma(cromosoma), fitness(0.0) {}
    
    double getFitness() const { return fitness; }    
    void setFitness(double f) { fitness = f;}
    
    vector<ProductoPosicion> getCromosoma() const {
        return cromosoma;
    }
    
    void iniciarCromosoma(vector<Producto> prods,double maxX,double maxY){
        cromosoma.clear();

        for (int i=0;i<prods.size();i++) {

            double posX = round((static_cast<double>(rand()) / RAND_MAX * maxX) * 100.0) / 100.0;  // Redondear a 2 decimales
            double posY = round((static_cast<double>(rand()) / RAND_MAX * maxY) * 100.0) / 100.0;

            ProductoPosicion productoPosicionado(prods[i].getIdProducto(),prods[i], posX, posY, 0); // z inicializado a 0
            cromosoma.push_back(productoPosicionado);
//            cout<<"X: "<<posX<<endl;
//            cout<<"Y  "<<posY<<endl<<endl;
        } 
    }
    
    bool validarSolucion(vector<Producto>& prods, Vehiculo& vehiculo) {
        map<Coordenada, Espacio> espacios;
        double maxX = vehiculo.getLargo(); // Dimensión máxima X (largo)
        double maxY = vehiculo.getAncho(); // Dimensión máxima Y (ancho)
        
        solucion.setPesoRestante(vehiculo.getPesoMaximo());
        solucion.setVolumenRestante(vehiculo.getVolMaximo());
        
        // Crear primer espacio
        if (!crearPrimerEspacio(espacios, prods, vehiculo, cromosoma[0])) {
            return false;
        }

        for (int i = 1; i < cromosoma.size(); i++) {
            Producto& producto = prods[cromosoma[i].getIdProducto() - 1];
            double posX = cromosoma[i].getX();
            double posY = cromosoma[i].getY();

            int intentos = 0;
            int maxIntentos = 20;
            ResultadoEspacio resultado;

            while (intentos < maxIntentos) {
                resultado = buscarEspacioDisponible(espacios, producto, posX, posY, vehiculo);

                if (resultado == PUDO_APILAR || resultado == NO_HAY_COLISION) {
                    if (resultado == NO_HAY_COLISION) {
                        crearNuevoEspacio(espacios, producto, posX, posY, 0, vehiculo.getAlto());
                    }
                    break; // Salir del bucle si la posición es válida
                } else if (resultado == NO_SE_PUDO_APILAR || resultado == ESPACIO_INVALIDO) {
//                    cout<<"Apilar"<<endl;
                    asignarNuevasCoordenadas(posX, posY, maxX, maxY);
                    cromosoma[i].setX(posX);
                    cromosoma[i].setY(posY);
                }

                intentos++;
            }
            solucion.agregarProducto(producto);
            

            if (intentos >= maxIntentos) {
//                cout << "Error: No se pudo validar el producto " << i << " después de varios intentos." << endl;
                return false;
            }
        }

        solucion.setEspaciosSolucion(espacios);
        return true;
    }

    void asignarNuevasCoordenadas(double& posX, double& posY, double maxX, double maxY) {
        posX = round((static_cast<double>(rand()) / RAND_MAX) * maxX * 100.0) / 100.0; // Redondear a 2 decimales
        posY = round((static_cast<double>(rand()) / RAND_MAX) * maxY * 100.0) / 100.0;

    }
    
    double calcularFitness(Vehiculo vehiculo,double coefEsta,double coefApilamiento,
                            double coefProximidad, double coefAccesibilidad){
        
        solucion.calcularFitness(vehiculo,coefEsta,coefApilamiento,coefProximidad,coefAccesibilidad);
        
        setFitness(solucion.getFitness());
        
        return solucion.getFitness();
        
//        cout<<"Fitness: "<<solucion.getFitness()<<endl;
    }
    
    void imprimirSolu(){
//        solucion.imprimirProductosCargados();
        solucion.imprimirSolu();
        solucion.imprimirEspaciosSolucion();
    }
    
    void imprimirCromosoma() const {
        cout << "Cromosoma (Productos y Coordenadas):" << endl;
        for (const auto& productoPos : cromosoma) {
            cout << "Producto: " <<productoPos.getIdProducto()<<" "<<productoPos.getNombre() 
                 << ", Coordenadas: (" << productoPos.getX() 
                 << ", " << productoPos.getY() << ")" << endl;
        }
    }
    
    double validarHijos(vector<Producto>& prods,Vehiculo& vehiculo,double coefEsta,
                            double coefApilamiento,double coefProximidad, double coefAccesibilidad){
        this->validarSolucion(prods,vehiculo);

        double fitness= this->calcularFitness(vehiculo,coefEsta,coefApilamiento,coefProximidad,coefAccesibilidad);
        
        return fitness;
}

    
    
};

#endif /* INDIVIDUO_H */

