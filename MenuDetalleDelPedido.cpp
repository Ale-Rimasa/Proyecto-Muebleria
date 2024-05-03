#include "MenuDetalleDelPedido.h"

#include <iostream>

using namespace std;

void MenuDetalle::MostrarDetalleDelPedido(){
    while(true){
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "--------- MUEBLERIA ---------"<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<< endl;
    cout << "1 - CARGAR ARTICULO " << endl;
    cout << "2 - MOSTRAR ARTICULOS" << endl;
    cout << "3 - CARGAR DETALLE DEL PEDIDO" << endl;
    cout << "4 - MOSTRAR DETALLES DEL PEDIDO" << endl;
    cout << "0 - VOLVER " << endl;
 int opcion;
    cin >> opcion;
    switch(opcion){
      case 1:
    
      objManagerArticulo.CargarArticulo();
    
      break;
      case 2:
      objManagerArticulo.ListarLosArticulos();
      break;

    case 3:
      
       objManagerArticulo.CargarVentaPedidoDetalle(); 
      
      break;

    case 4:
      
       objDetalle.ListarLosDetalles(); 
      
      break;
case 0:
        return;
      break;
    }

 }
}