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
#include <vector>

#include "Funciones.h"
#include "Coordenada.h"
#include "Pedido.h"
#include "Producto.h"
#include "Rutas.h"
#include "Vehiculo.h"
#include "ProductoPosicion.h"

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


bool crearPrimerEspacio(map<Coordenada, Espacio>& espacios, vector<Producto>& productos, Vehiculo& vehiculo, ProductoPosicion &gen) {
        
    ProductoPosicion prodPosi=gen;

    Producto& producto = productos[prodPosi.getIdProducto() - 1];

    double posX = prodPosi.getX();
    double posY = prodPosi.getY();


    // Intentar colocar el producto dentro de los límites del vehículo en cada orientación posible
    bool encontrado = false;
    for (int i = 0; i < 4; ++i) { // Máximo 4 orientaciones posibles
        if (cabeEnLimitesVehiculo(posX, posY, producto, vehiculo)) {
            encontrado = true;
            break;
        }
        producto.cambiarOrientacion();

        // Actualizar coordenadas en función de la nueva orientación
        switch (producto.getOrientacion()) {
            case Producto::ARRIBA_DERECHA:
                break;
            case Producto::ARRIBA_IZQUIERDA:
                posX -= producto.getLargo();
                break;
            case Producto::ABAJO_DERECHA:
                posY -= producto.getAncho();
                break;
            case Producto::ABAJO_IZQUIERDA:
                posX -= producto.getLargo();
                posY -= producto.getAncho();
                break;
        }
    }

    if (!encontrado) {
        return encontrado;
    }

    // Crear un nuevo espacio con la altura y posición final del producto
    Espacio nuevoEspacio(vehiculo.getAlto(), posX, posY, 0, 0);
    nuevoEspacio.agregarProducto(&producto);

    Coordenada coordenada(posX, posY);
    espacios.emplace(coordenada, nuevoEspacio);
}
    
bool cabeEnLimitesVehiculo(double posX, double posY, Producto& producto, Vehiculo& vehiculo) {
    switch (producto.getOrientacion()) {
        case Producto::ARRIBA_DERECHA:
            return posX + producto.getLargo() <= vehiculo.getLargo() && posY + producto.getAncho() <= vehiculo.getAncho();
        case Producto::ARRIBA_IZQUIERDA:
            return posX - producto.getLargo() >= 0 && posY + producto.getAncho() <= vehiculo.getAncho();
        case Producto::ABAJO_DERECHA:
            return posX + producto.getLargo() <= vehiculo.getLargo() && posY - producto.getAncho() >= 0;
        case Producto::ABAJO_IZQUIERDA:
            return posX - producto.getLargo() >= 0 && posY - producto.getAncho() >= 0;
        default:
            return false;
    }
}

ResultadoEspacio buscarEspacioDisponible(map<Coordenada, Espacio>& espacios, Producto& producto, double posX, double posY,Vehiculo& vehiculo) {
    
    if (!cabeEnLimitesVehiculo(posX, posY, producto, vehiculo)) {
        bool encontrado = false;
        for (int i = 0; i < 4; ++i) {
            producto.cambiarOrientacion();
            if (cabeEnLimitesVehiculo(posX, posY, producto, vehiculo)) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            return ESPACIO_INVALIDO;
        }
    }

    switch (producto.getOrientacion()) {
        case Producto::ARRIBA_IZQUIERDA:
            posX -= producto.getLargo(); // Mover hacia la izquierda
            break;
        case Producto::ABAJO_DERECHA:
            posY -= producto.getAncho(); // Mover hacia abajo
            break;
        case Producto::ABAJO_IZQUIERDA:
            posX -= producto.getLargo(); // Mover hacia la izquierda
            posY -= producto.getAncho(); // Mover hacia abajo
            break;
        case Producto::ARRIBA_DERECHA:
            // No se realiza ajuste
            break;
    }

    for (pair<const Coordenada, Espacio>& entry : espacios) {
        Coordenada coordExistente = entry.first;
        Espacio& espacioExistente = entry.second;

        if (hayColision(coordExistente.x, espacioExistente.getLargo(), coordExistente.y, espacioExistente.getAncho(), 
                posX, producto.getLargo(), posY, producto.getAncho())) {

            if (espacioExistente.esApilable(&producto)) {
                espacioExistente.agregarProducto(&producto);
                return PUDO_APILAR; 
            } else {
                return NO_SE_PUDO_APILAR;  // No se pudo apilar el producto por restricciones
            }
        }
    }

    return NO_HAY_COLISION; 
}

bool hayColision(double xExistente, double largoExistente, double yExistente, double anchoExistente, 
             double xNuevo, double largoNuevo, double yNuevo, double anchoNuevo) {
    // Verificar si las coordenadas del nuevo espacio caen dentro de las dimensiones del espacio existente
    bool colisionX = (xNuevo < (xExistente + largoExistente)) && ((xNuevo + largoNuevo) > xExistente);
    bool colisionY = (yNuevo < (yExistente + anchoExistente)) && ((yNuevo + anchoNuevo) > yExistente);

    // Si hay colisión en ambos ejes, retornamos true
    return colisionX && colisionY;
}

void crearNuevoEspacio(map<Coordenada, Espacio>& espacios, Producto& producto,
                       double posX, double posY, double posZ, double alturaVehiculo) {

    switch (producto.getOrientacion()) {
        case Producto::ARRIBA_DERECHA:
            break;
        case Producto::ARRIBA_IZQUIERDA:
            posX -= producto.getLargo(); 
            break;
        case Producto::ABAJO_DERECHA:
            posY -= producto.getAncho();
            break;
        case Producto::ABAJO_IZQUIERDA:
            posX -= producto.getLargo();
            posY -= producto.getAncho(); 
            break;
    }

    Espacio nuevoEspacio(alturaVehiculo, posX, posY, posZ,0);
    nuevoEspacio.agregarProducto(&producto);

//    nuevoEspacio.setLargo(producto.getLargo());
//    nuevoEspacio.setAncho(producto.getAncho());

    Coordenada coordAjustada(posX, posY);
    espacios.emplace(coordAjustada, nuevoEspacio);
}