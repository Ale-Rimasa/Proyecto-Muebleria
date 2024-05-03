#pragma once
#include "Cliente.h"
#include "Direccion.h"
#include "VentaPedido.h"
#include "Articulo.h"
#include "VentaPedidoDetalle.h"
#include "Archivo.h"
#include <cstring>

class Manager{
    public:
    //Clientes
    void CargarClientes();
    void MostrarCliente(Cliente objCliente);
    void MostrarCantidadRegistros();  ///Nos muestra la CANTIDAD Total de clientes 
    int BuscarNroCliente(int nroCliente); //BuscaNroCliente
    void ListarPorNroCliente();
    void ListarTodosNroCliente(); 
    void EditarCliente();
    int MenuModificarCliente();  
    bool ModificarNombre();
    bool ModificarApellido();
    bool ModificarTelefono();
    bool ModificarMail();
    bool ModificarDni();
    void EliminarCliente();
   // bool EliminarCliente();
    /*Falta hacer
    void ModificarDireccion();
    
    /*************************************************************************************/
    //VentaPedido
    void CargarVentaPedido(); 
    void MostrarVentaPedido(VentaPedido objVentaPedido);
    void MostrarVentasTotales();
    int BuscarNroFactura(int nroFactura);
    void ListarTodos();
    void ListarPorNroFactura();
    int MenuModificarVentaPedido();
    bool ModificarFormaDePago();
    bool ModificarMontoTotal();
    bool ModificarSenia();
    bool ModificarComentario();
    void EliminarVenta();
    //int BuscarPorFecha(int fecha);
    //void ListarPorFecha();
    /*************************************************************************************/
    //VentaPedidoDetalle
    void CargarVentaPedidoDetalle();
    void MostrarVentaPedidoDetalle(VentaPedidoDetalle objVentaPedidoDetalle);
    void ListarLosDetalles();
    /*************************************************************************************/
    //Articulo
    void CargarArticulo();
    void MostrarArticulo(Articulo objArticulo);
    void ListarLosArticulos();
    void ListarPorArticulo();
    int BuscarNroArticulo(int nroArticulo);
    bool ModificarStock();
    void EliminarArticulo();
    /*************************************************************************************/
    //REPORTES

    void VentasPorDia();
    void VentasPorMeses();

    private:
        ClienteArchivo archiCliente = ClienteArchivo("Cliente.dat");
        VentaPedidoArchivo archiVentaPedido =  VentaPedidoArchivo("VentaPedido.dat");
        ArticuloArchivo archiArticulo = ArticuloArchivo("Articulo.dat");
        VentaPedidoDetalleArchivo archiVentaPedidoDetalle = VentaPedidoDetalleArchivo("VentaPedidoDetalle.dat");
};