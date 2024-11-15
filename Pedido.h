/* 
 * File:   Pedido.h
 *  Autor  : Juan Angelo Flores Rubio
 *  Codigo : 20196493
 * Created on 14 de noviembre de 2024, 07:03 PM
 */


#ifndef PEDIDO_H
#define PEDIDO_H

#include <vector>
#include <fstream>
#include "Producto.h"

using namespace std;

class Pedido {
private:
    int id_pedido;
    vector<Producto> productos;
    int horaEntrega;
    string prioridad;
    
public:
    
Pedido(int id,vector <Producto> prods,int hora, string prio){
    id_pedido=id;
    productos=prods;
    horaEntrega=hora;
    prioridad=prio;
}

    // Métodos setters
    void setIdPedido(int id){id_pedido=id;}
    void setHoraEntrega(int hora) { horaEntrega = hora; }
    void setPrioridad(string prio){ prioridad=prio; }
    void setProductos(vector<Producto> prods) { productos = prods; }

    
    // Métodos getters
    int getIdPedido()const{return id_pedido;}
    int getHoraEntrega() const {return horaEntrega; }
    string getPrioridad() const { return prioridad; }
    vector<Producto> getProductos() const { return productos; }
    
    double getVolumenTotalProductos()const{
        
        double totalVolumen=0;
        
        for(Producto prod: productos)
            totalVolumen+=prod.getVolumen();
        
        return totalVolumen;
    }
    
    double getPesoTotalProductos()const{
        
        double totalPeso=0;
        
        for(Producto prod: productos)
            totalPeso+=prod.getPeso();
        
        return totalPeso;
        
    }
};

#endif /* PEDIDO_H */

