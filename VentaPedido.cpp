#include <iostream>
using namespace std;
#include <cstring>

#include "VentaPedido.h"
#include "CargarCadena.h"
#include "Fecha.h"

VentaPedido::VentaPedido()
{
setNroFactura(0);
setNroCliente(0);
setFormaPago(0);
_fecha = Fecha();
setComentario("");
setMontoTotal(0);
setSenia(0);
_estadoEntrega = false;
_eliminado= false;
}


/// Setters
void VentaPedido::setNroFactura(int nroFactura){_nroFactura= nroFactura;}
void VentaPedido::setNroCliente(int nroCliente){_nroCliente = nroCliente;}
void VentaPedido::setFormaPago(int formaPago){_formaPago= formaPago;}
void VentaPedido::setFecha(Fecha fecha){ _fecha= fecha;}
void VentaPedido::setComentario(const char* comentario){strcpy(_comentarios,comentario);}
void VentaPedido::setEstadoEntrega( bool estadoEntrega){_estadoEntrega= estadoEntrega;}
void VentaPedido::setMontoTotal(float montoTotal){_montoTotal= montoTotal;}
void VentaPedido::setSenia(float senia){_senia=senia;}
void VentaPedido::setEliminado(bool eliminado){_eliminado= eliminado;}

//Getters
int VentaPedido::getNroFactura() {return _nroFactura;}
int VentaPedido::getNroCliente() {return _nroCliente;}
int VentaPedido::getFormaPago() {return _formaPago;}
const char* VentaPedido::getComentario() {return _comentarios;}
Fecha VentaPedido::getFecha() {return _fecha;}
float VentaPedido::getMontoTotal() {return _montoTotal;}
float VentaPedido::getSenia() {return _senia;}
bool VentaPedido::getEstadoEntrega() {return _estadoEntrega;}
bool VentaPedido::getEliminado() {return _eliminado;}
