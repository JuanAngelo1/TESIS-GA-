/* 
 * File:   Funciones.cpp
 * Autor  : Juan Angelo Flores Rubio
 * Codigo : 20196493
 * Created on 14 de noviembre de 2024, 05:34 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "Funciones.h"
#include "Coordenada.h"
#include "Pedido.h"
#include "Producto.h"
#include "Rutas.h"
#include "Vehiculo.h"

using namespace std;

vector<Producto> obtenerProductosBase() {
    vector<Producto> productosBase;

    // Productos con coordenadas de destino ya asignadas
    productosBase.push_back(Producto(101, "Refrigeradora LG Top Freezer GT57BPSX", 85.5, 0.96, 0.80, 1.76, 40.0, -12.079270, -77.063227)); // Pueblo Libre
    productosBase.push_back(Producto(102, "Refrigeradora Samsung Side By Side RS52B3000M9", 93.0, 0.72, 0.97, 1.89, 50.0, -12.122452, -77.031293)); // Miraflores
    productosBase.push_back(Producto(103, "Refrigeradora MABE Side by Side No Frost Inverter", 94.0, 0.77, 0.92, 1.92, 50.0, -12.097622, -77.036002)); // San Isidro
    productosBase.push_back(Producto(104, "Refrigeradora LG Top Freezer VT37BPM", 70, 0.72, 0.73, 1.79, 40.0, -12.085846, -76.971214)); // La Molina

    productosBase.push_back(Producto(201, "Lavadora Samsung Bubble Smart WA19CG6886BVPE", 51, 0.74, 0.70, 1.17, 34.0, -12.053728, -76.948494)); // Ate
    productosBase.push_back(Producto(202, "Lavadora Mabe LMA8120WDGBB0", 47, 0.67, 0.66, 1.05, 35.0, -12.107380, -76.996883)); // San Borja
    productosBase.push_back(Producto(203, "Lavaseca LG WD9PVC4S6 AI DD", 66, 0.58, 0.66, 0.89, 40.0, -12.134781, -77.014236)); // Surquillo

    productosBase.push_back(Producto(301, "Horno Microonda Panasonic NN-GT34JBRPK", 15.4, 0.55, 0.34, 0.42, 10, -12.140356, -76.985933)); // Surco
    productosBase.push_back(Producto(302, "Horno Microondas Indurama MWI-20TCRP", 11.23, 0.48, 0.38, 0.29, 10, -12.158560, -76.989342)); // San Juan de Miraflores
    productosBase.push_back(Producto(303, "Horno Microondas LG MS2536GIS", 11.0, 0.54, 0.417, 0.294, 10, -12.054500, -77.117600)); // Callao

    productosBase.push_back(Producto(401, "Televisor TCL SMART TV 65 QLED 4K UHD", 17.3, 0.30, 1.09, 0.83 , 0.0, -12.079270, -77.063227)); // Pueblo Libre
    productosBase.push_back(Producto(402, "Televisor Samsung Smart TV 50 LED 4K UHD", 9.5, 0.25, 0.95, 0.69, 0.0, -12.122452, -77.031293)); // Miraflores
    productosBase.push_back(Producto(403, "Televisor LG Smart TV 55 Nanocell 4K UHD", 14.1, 0.23, 1.03, 0.78, 0.0, -12.097622, -77.036002)); // San Isidro
    productosBase.push_back(Producto(404, "Televisor Philips 50 4K Ultra HD Google TV", 9.31, 0.25, 0.94, 0.71, 0.0, -12.085846, -76.971214)); // La Molina

    productosBase.push_back(Producto(501, "Aspiradora Bosch Serie 4", 8.3, 0.58, 0.36, 0.31, 0, -12.053728, -76.948494)); // Ate
    productosBase.push_back(Producto(502, "Aspiradora Electrolux ERG36", 4.21, 0.15, 0.30, 0.69, 0, -12.107380, -76.996883)); // San Borja
    productosBase.push_back(Producto(503, "Aspiradora Thomas TH-1870", 5.2 , 0.33, 0.28, 0.28, 0, -12.134781, -77.014236)); // Surquillo
    productosBase.push_back(Producto(504, "Aspiradora Electrolux PTE10", 2.3, 0.27, 0.31, 1.28, 0, -12.140356, -76.985933)); // Surco

    productosBase.push_back(Producto(601, "Horno Eléctrico Modelo 1", 9.1, 0.78, 0.54, 0.54, 8, -12.158560, -76.989342)); // San Juan de Miraflores
    productosBase.push_back(Producto(602, "Horno Eléctrico Modelo 2", 7.10, 0.43, 0.51, 0.41, 6, -12.054500, -77.117600)); // Callao
    productosBase.push_back(Producto(603, "Horno Eléctrico Modelo 3", 7.25, 0.43, 0.52, 0.38, 6, -12.079270, -77.063227)); // Pueblo Libre
    productosBase.push_back(Producto(604, "Horno Eléctrico Modelo 4", 7.50, 0.42, 0.42, 0.36, 6, -12.122452, -77.031293)); // Miraflores

    productosBase.push_back(Producto(701, "Cocina Klimatic Munchen", 26.6, 0.552, 0.495, 0.85, 15, -12.097622, -77.036002)); // San Isidro
    productosBase.push_back(Producto(702, "Cocina MABE EMP5120GP1", 24.5, 0.540, 0.52, 0.915, 15, -12.085846, -76.971214)); // La Molina
    productosBase.push_back(Producto(703, "Cocina Indurama Parma Zafiro", 45.82, 0.636, 0.76, 0.95, 20, -12.053728, -76.948494)); // Ate
    productosBase.push_back(Producto(704, "Cocina MABE CMP5140FX0", 28.3, 0.540, 0.52, 0.925, 15, -12.107380, -76.996883)); // San Borja

    productosBase.push_back(Producto(801, "Licuadora Miray LIM-9", 1.3, 0.133, 0.22, 0.35, 0, -12.134781, -77.014236)); // Surquillo
    productosBase.push_back(Producto(802, "Licuadora Oster 250-22", 3.74, 0.23, 0.19, 0.335, 0, -12.140356, -76.985933)); // Surco
    productosBase.push_back(Producto(803, "Licuadora Thomas TH-780VR", 4.7, 0.22, 0.29, 0.38, 0, -12.158560, -76.989342)); // San Juan de Miraflores

    return productosBase;
}

vector <Vehiculo> obtenerVehiculos(){
    
    vector<Vehiculo> listaVehiculos;
    
    Vehiculo vehiculo1(1,"Hyundai Mighty EX8", 3000, 4.9, 2.2, 2.2, 10);    
    Vehiculo vehiculo2(2,"Mercedes-Benz Atego 1725" ,3000, 5.5, 2.0, 2.4, 12);
    Vehiculo vehiculo3(3,"Isuzu NPR 4 TON" ,3500, 6, 2.0, 2.2, 9);
    Vehiculo vehiculo4(4,"Hyundai HD78", 4000, 6.5, 2.0, 2.2, 8);
    
    listaVehiculos.push_back(vehiculo1);
    listaVehiculos.push_back(vehiculo2);
    listaVehiculos.push_back(vehiculo3);
    listaVehiculos.push_back(vehiculo4);
    
    return listaVehiculos;
}

vector<Producto> generarProductos(vector<Producto>& productosBase,vector<int>& cantidades) {
    vector<Producto> productosGenerados;
    int id = 1;  

    for (int i = 0; i < productosBase.size(); i++) {
        Producto productoBase = productosBase[i];
        int cantidad = cantidades[i];

        for (int j = 0; j < cantidad; j++) {
            Producto nuevoProducto = productoBase; 
            nuevoProducto.setIdProducto(id++);
            productosGenerados.push_back(nuevoProducto);
        }
    }

    return productosGenerados;
}

Vehiculo SeleccionarVehiculo(Pedido ped, vector<Vehiculo> lista){
    
    Vehiculo vehiculoSeleccionado = lista[0];
    bool encontrado = false;

    for (Vehiculo v : lista) {
        // Primero, verificamos si la hora de salida del vehículo coincide con la prioridad
        if ((ped.getPrioridad() == "alta" && v.getHora() <= 8) ||  // Alta prioridad, vehículos que salen antes de las 8 am
            (ped.getPrioridad() == "media" && v.getHora() <= 12) ||  // Media prioridad, vehículos que salen antes del mediodía
            (ped.getPrioridad() == "baja" && v.getHora() <= 18)) {  // Baja prioridad, vehículos que salen antes de las 6 pm
            
            // Verificar si el vehículo tiene suficiente espacio para el pedido (volumen y peso)
            if (v.getVolMaximo() >= ped.getVolumenTotalProductos() && 
                v.getPesoMaximo() >= ped.getPesoTotalProductos()) {
                vehiculoSeleccionado = v;
                encontrado = true;
                break;
            }
        }
    }

    if (!encontrado) {
        // Si no encontramos un vehículo con suficiente espacio y que cumpla con la prioridad, usar otro criterio.
        // Por ejemplo, escoger el vehículo con la mayor capacidad disponible
        for (Vehiculo v : lista) {
            if (v.getVolMaximo() >= ped.getVolumenTotalProductos() && 
                v.getPesoMaximo() >= ped.getPesoTotalProductos()) {
                vehiculoSeleccionado = v;
                break;
            }
        }
    }

    return vehiculoSeleccionado;
}
