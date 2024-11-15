/* 
 * File:   Producto.h
 *  Autor  : Juan Angelo Flores Rubio
 *  Codigo : 20196493
 * Created on 14 de noviembre de 2024, 05:36 PM
 */


#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

class Producto {
public:
    enum Orientacion {
        ARRIBA_DERECHA,     
        ARRIBA_IZQUIERDA,   
        ABAJO_DERECHA,      
        ABAJO_IZQUIERDA     
    };
private:
    int id_producto;
    string nombre;           
    double peso;             
    double largo,ancho,alto;             
    double limitePeso;   
    double volumen;
    double latitudDestino;
    double longitudDestino;
    int ordenColocacion; 
    
    Orientacion orientacion;
    
public:
    
    // Constructor
    Producto(int id, string n, double p, double lar, double anch, double alt, double lp,double lat,double lon){
        id_producto=id;
        nombre=n;
        peso=p;
        largo=lar;
        ancho=anch;
        alto=alt;
        limitePeso=lp;
        volumen=lar*anch*alt;
        latitudDestino=lat;
        longitudDestino=lon;
        ordenColocacion=1;
        orientacion= ARRIBA_DERECHA;
    }
    
    // Getters
    int getIdProducto() const { return id_producto; }
    string getNombre() const { return nombre; }
    double getPeso() const { return peso; }
    double getLargo() const { return largo; }
    double getAncho() const { return ancho; }
    double getAltura() const { return alto; }
    double getLimitePeso() const { return limitePeso; }
    double getVolumen()const {return volumen;}
    double getLatitud()const {return latitudDestino;}
    double getLongitud()const{return longitudDestino;}
    int getOrden()const{return ordenColocacion;}
    Orientacion getOrientacion() const { return orientacion;}

    // Setters
    void setIdProducto(int id) { id_producto = id; }
    void setNombre(string n) { nombre = n; }
    void setPeso(double p) { peso = p; }
    void setLargo(double l) { largo = l; }
    void setAncho(double a) { ancho = a; }
    void setAlto(double al) { alto = al; }
    void setLimitePeso(double lp) { limitePeso = lp; }
    void setOrdenColocacion(int i){ordenColocacion=i;}
    void setOrientacion(Orientacion nuevaOrientacion) { orientacion = nuevaOrientacion;}
    
    void cambiarOrientacion() {
        orientacion = static_cast<Orientacion>((orientacion + 1) % 4);
    }
    
    bool esApilableSobre(Producto* nuevoProducto) const {
        return nuevoProducto->getPeso() <= limitePeso;
    }
    
    void mostrarInformacion() const {
        cout << "ID: " << id_producto 
             << " | Nombre: " << nombre 
             << " | Peso: " << peso << " kg"
             << " | Volumen: "<<volumen<<"m3"
             << " | Dimensiones: " << largo << " x " << ancho << " x " << alto << " m"
             << " | Límite de Peso: " << limitePeso << " kg";
        cout << endl;
    }
   
};

#endif /* PRODUCTO_H */

