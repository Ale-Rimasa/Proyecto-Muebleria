
#include "VentaPedidoDetalle.h"

    //SETTERS
    void VentaPedidoDetalle::setNroFactura (int nroFactura){_nroFactura = nroFactura;}
    void VentaPedidoDetalle::setNroArticulo (int nroArticulo){_nroArticulo = nroArticulo;}
    void VentaPedidoDetalle::setCantidad (int cantidad){_cantidad = cantidad; }
    void VentaPedidoDetalle::setPrecio (float precio){_precio = precio;}
    void VentaPedidoDetalle::setEstado(bool estado){_estado = estado;}
    //GETTER
    int VentaPedidoDetalle::getNroFactura(){ return _nroFactura; }
    int VentaPedidoDetalle::getNroArticulo (){ return _nroArticulo;}
    int VentaPedidoDetalle::getCantidad (){return _cantidad;}
    float VentaPedidoDetalle::getPrecio (){return _precio;}
    bool VentaPedidoDetalle::getEstado(){return _estado;}
    
    VentaPedidoDetalle::VentaPedidoDetalle(){
        setNroArticulo(0);
        setNroFactura(0);
        setCantidad(0);
        setPrecio(0);
        _estado= false;
    }