/* 
 * File:   Vehiculo.h
 * Autor  : Juan Angelo Flores Rubio
 * Codigo : 20196493
 * Created on 14 de noviembre de 2024, 05:56 PM
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <fstream>
using namespace std;

class Vehiculo{
    
private:
    int id_vehiculo;
    string nombre;
    double pesoMaximo;
    double volMaximo;
    double largo;
    double ancho;
    double alto;
    int hora;

    double pesoActual;     
    double volumenActual;  
    
public:
    
    Vehiculo(int idVehiculo,string n,double pMax, double l, double a, double h, int hr){
        id_vehiculo=idVehiculo;
        nombre=n;
        pesoMaximo=pMax;
        volMaximo=l*a*h;
        largo=l;
        ancho=a;
        alto=h;
        hora=hr;
        pesoActual=0;
        volumenActual=0;
    }

    // Métodos getters
    int getIdVehiculo()const{return id_vehiculo;}
    double getPesoMaximo() const {return pesoMaximo; }
    double getVolMaximo() const { return volMaximo; }
    double getLargo() const { return largo; }
    double getAncho() const { return ancho; }
    double getAlto() const { return alto; }
    double getPesoActual() const { return pesoActual; }
    double getVolumenActual() const { return volumenActual; }
    int getHora() const { return hora; }
    string getNombre()const { return nombre;}
    
    // Métodos setters
    void setIdVehiculo(int id){id_vehiculo=id;}
    void setPesoMaximo(double pMax) { pesoMaximo = pMax; }
    void setVolMaximo(double vMax) { volMaximo = vMax; }
    void setLargo(double l) { largo = l; }
    void setAncho(double a) { ancho = a; }
    void setAlto(double h) { alto = h; }
    void setHora(int hr) { hora = hr; }
    
    
    void mostrarEstado() const {
        cout << "Peso Actual: " << pesoActual << " / " << pesoMaximo << endl;
        cout << "Volumen Actual: " << volumenActual << " / " << volMaximo << endl;

    }
};
#endif /* VEHICULO_H */
