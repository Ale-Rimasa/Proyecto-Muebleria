#pragma once
#include <cstdio>
#include "Cliente.h"
#include "VentaPedido.h"
#include "Articulo.h"
#include "VentaPedidoDetalle.h"
class ClienteArchivo{
public:
    ClienteArchivo(const char* _nombreArchivo);
    bool GrabarCliente(Cliente objCliente);
    bool GrabarCliente(Cliente objCliente, int nroCliente); //Revisar contra el sobreescribir
    bool GrabarCliente(Cliente objCliente, Direccion objDir);
    int ContarRegistros();
    Cliente Leer(int nroCliente);
    int BuscarNroCliente(int nroCliente);
    bool sobreEscribirRegistro(Cliente objCliente, int pos);

private:
     char nombreArchivo[30];

};

class VentaPedidoArchivo{
    public:
    VentaPedidoArchivo(const char* _nombreArchivo);
    bool GrabarVentaPedido(VentaPedido objVentaPedido);
    bool GrabarVentaPedido(VentaPedido objVentaPedido, int nroFactura);
    int ContarRegistros();
    VentaPedido Leer(int ventaPedido);
    int BuscarNroFactura(int nroFactura);
    bool sobreEscribirRegistro(VentaPedido objVentaPedido, int pos);


    private:
    char nombreArchivo[30];
};

class VentaPedidoDetalleArchivo{
    public:
    VentaPedidoDetalleArchivo(const char* _nombreArchivo);
    bool GrabarVentaPedidoDetalle(VentaPedidoDetalle objVentaPedidoDetalle);
    //bool GrabarVentaPedido(VentaPedido objVentaPedido, int nroFactura);
    int ContarRegistros();
    VentaPedidoDetalle Leer(int VentaPedidoDetalle);
    int BuscarVentaPedidoDetalle(int nroFactura);
    
    private:
    char nombreArchivo[30];



};

class ArticuloArchivo{
    public:
    ArticuloArchivo(const char* _nombreArchivo);
    bool GrabarArticulo(Articulo objArticulo);
    bool GrabarArticulo(Articulo objArticulo, int nroArticulo);
    int ContarRegistros();
    Articulo Leer(int nroArticulo);
    int BuscarNroArticulo(int nroArticulo);
    bool sobreEscribirRegistro(Articulo objArticulo, int pos);

    private:
    char nombreArchivo[30];
};
