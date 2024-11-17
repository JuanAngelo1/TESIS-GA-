/* 
 * File:   Funciones.h
 * Autor  : Juan Angelo Flores Rubio
 * Codigo : 20196493
 * Created on 14 de noviembre de 2024, 05:34 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Vehiculo.h"
#include "Pedido.h"
#include "Producto.h"
#include "Espacio.h"
#include "Coordenada.h"
#include "ProductoPosicion.h"
#include <fstream>
#include <map>

using namespace std;

enum ResultadoEspacio {
    PUDO_APILAR,
    NO_SE_PUDO_APILAR,
    NO_HAY_COLISION,
    ESPACIO_INVALIDO
};

vector<Producto> obtenerProductosBase();
vector <Vehiculo> obtenerVehiculos();
vector<Producto> generarProductos(vector<Producto>& ,vector<int>& ) ;
Vehiculo SeleccionarVehiculo(Pedido ped, vector<Vehiculo> );

bool crearPrimerEspacio(map<Coordenada, Espacio>& , vector<Producto>& , Vehiculo& , ProductoPosicion &);
bool cabeEnLimitesVehiculo(double , double , Producto& , Vehiculo& );
ResultadoEspacio buscarEspacioDisponible(map<Coordenada, Espacio>& , Producto& , double , double ,Vehiculo& );
bool hayColision(double , double , double , double , double , double , double , double );
void crearNuevoEspacio(map<Coordenada, Espacio>& , Producto& , double , double , double , double );
void imprimirEspaciosSolucion(map<Coordenada, Espacio>& );

#endif /* FUNCIONES_H */
