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

#include "Producto.h"
#include "Funciones.h"
#include "Coordenada.h"
#include "Rutas.h"
#include "Pedido.h"
#include "Poblacion.h"

using namespace std;

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned>(time(0))); // Inicializa el generador de números aleatorios

    vector<Vehiculo> listaVehiculos = obtenerVehiculos();
    vector<Producto> productosBase = obtenerProductosBase();
    vector<int> cantidad = {1, 0, 0, 1,   // Refrigeradoras (cuatro)
                            1, 0, 1,      // Lavadoras (tres modelos)
                            1, 0, 0,      // Microondas (tres modelos)
                            1, 0, 0, 1,   // Televisores (cuatro modelos)
                            1, 0, 0, 1,   // Aspiradoras (cuatro modelos)
                            1, 0, 0, 1,   // Hornos eléctricos (cuatro modelos)
                            1, 0, 0, 1,   // Cocinas (cinco modelos)
                            1, 0, 1};     // Licuadoras (tres modelos)
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
    int tamPoblacion=10;
    int numGeneraciones=20;
    double pmut=0.2;
    
    string metodoSeleccion="Roulette";
    string tipoCruce="Onepoint";

    Poblacion poblacion;
    
    poblacion.iniciarPoblacion(tamPoblacion,productosCargar,vehiculo,maxX,maxY);
    poblacion.calcularFitness(vehiculo,coefEsta,coefApilamiento,coefProximidad,coefAccesibilidad);

    for(int i = 0 ; i < numGeneraciones ; i++){
        
        
        
    }
    
    
    return 0;
}

