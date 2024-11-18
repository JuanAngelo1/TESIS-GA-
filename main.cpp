/* 
 * File:   main.cpp
 * Autor  : Juan Angelo Flores Rubio
 * Codigo : 20196493
 * Created on 14 de noviembre de 2024, 12:32 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>
#include <ctime> 
#include <chrono>

#include "Producto.h"
#include "Funciones.h"
#include "Coordenada.h"
#include "Rutas.h"
#include "Pedido.h"
#include "Poblacion.h"
#include "Padres.h"
#include "rng.h"

using namespace std;

mt19937 rng(static_cast<unsigned>(chrono::high_resolution_clock::now().time_since_epoch().count()));

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned>(time(0))); // Inicializa el generador de números aleatorios

    vector<Vehiculo> listaVehiculos = obtenerVehiculos();
    vector<Producto> productosBase = obtenerProductosBase();
    vector<int> cantidad = {1, 0, 0, 1,   // Refrigeradoras (cuatro)
                            1, 0, 1,      // Lavadoras (tres modelos)
                            1, 0, 0,      // Microondas (tres modelos)
                            1, 0, 0, 1,   // Televisores (cuatro modelos)
                            1, 0, 1, 1,   // Aspiradoras (cuatro modelos)
                            1, 0, 1, 1,   // Hornos eléctricos (cuatro modelos)
                            1, 0, 1, 1,   // Cocinas (cinco modelos)
                            1, 1, 1};     // Licuadoras (tres modelos)
    vector<Producto> productosCargar = generarProductos(productosBase,cantidad);
    int cantProd=productosCargar.size();
    Pedido pedido1(1, productosCargar, 8, "alta");
    
    Vehiculo vehiculo=SeleccionarVehiculo(pedido1,listaVehiculos);
    double maxX = vehiculo.getLargo(); // Dimensión máxima X (largo)
    double maxY = vehiculo.getAncho(); // Dimensión máxima Y (ancho)
    double pesoMax= vehiculo.getPesoMaximo();
    double volMax= vehiculo.getVolMaximo();
    
//    Solucion mejorSol;
//    mejorSol.setFitness(-1000);
    
    Coordenada tiendaOrigen = Coordenada(-12.077275894793303, -77.09255117444374);
    optimizarRuta(productosCargar,tiendaOrigen.x,tiendaOrigen.y);
    
    //Parametros fitness
    double coefEsta=0.2,coefApilamiento=0.3 ,coefProximidad= 0.4,coefAccesibilidad=0.2; 
    
    //Parametros AG
    int tamPoblacion=40;
    int numGeneraciones=30;
    double pmut=0.2;
    
    double fit1,fit2;
    
    string metodoSeleccion="Torneo";
    string tipoCruce="Onepoint";
    string tipoMutacion="Position";
    
    int tamTorneo=2;
    Poblacion poblacion;
    
    poblacion.iniciarPoblacion(tamPoblacion,productosCargar,vehiculo,maxX,maxY);
    poblacion.calcularFitness(vehiculo,coefEsta,coefApilamiento,coefProximidad,coefAccesibilidad);

    for(int i = 0 ; i < numGeneraciones ; i++){
        vector<Padres> matingPool;
        
        // Crear el mating pool
        for (int j = 0; j < tamPoblacion / 2; ++j) {
            Padres padres;
            if (metodoSeleccion == "Torneo") {
                padres = poblacion.seleccionarPadresTorneo(tamTorneo);
            } else if (metodoSeleccion == "Ruleta") {
                padres = poblacion.seleccionarPadresRuleta();
            }     
            matingPool.emplace_back(padres); // Añadir al mating pool
        }
        
        vector<Individuo> nuevaPoblacion;
        for (const Padres &padres : matingPool) {
            if (tipoCruce == "Onepoint") {
                vector<Individuo> hijos = padres.crossoverOnePoint();
                
                hijos[0].validarHijos(productosCargar,vehiculo,coefEsta,
                        coefApilamiento,coefProximidad,coefAccesibilidad);
                
                hijos[1].validarHijos(productosCargar,vehiculo,coefEsta,
                        coefApilamiento,coefProximidad,coefAccesibilidad);
                        
                nuevaPoblacion.insert(nuevaPoblacion.end(), hijos.begin(), hijos.end());
            } else if (tipoCruce == "Uniform") {
                vector<Individuo> hijos = padres.crossoverUniform();
                
                hijos[0].validarHijos(productosCargar,vehiculo,coefEsta,
                        coefApilamiento,coefProximidad,coefAccesibilidad);
                
                hijos[1].validarHijos(productosCargar,vehiculo,coefEsta,
                        coefApilamiento,coefProximidad,coefAccesibilidad);
                
                nuevaPoblacion.insert(nuevaPoblacion.end(), hijos.begin(), hijos.end());
            }
        }
        
        poblacion.calcularFitness(vehiculo, coefEsta, coefApilamiento, coefProximidad, coefAccesibilidad);
        
        vector<Individuo> nuevaGeneracion = poblacion.seleccionarNuevaGeneracion(nuevaPoblacion,tamPoblacion);
        
        poblacion.setIndividuos(nuevaGeneracion);
        
        cout << "Generación " << i + 1
             << " - Mejor Fitness: " << poblacion.getMejorFitness() << endl;
    }
    
    poblacion.imprimirSoluFinal();
    
    return 0;
}

