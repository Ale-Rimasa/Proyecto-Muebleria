#include "MenuReportes.h"

#include <iostream>

using namespace std;

void MenuReportes::MostrarMenuRepo(){
    while(true){
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "--------- MUEBLERIA ---------"<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<< endl;
    cout << "1 - VENTAS TOTALES" << endl;
    cout << "2 - VENTAS CERRADAS" << endl;
    cout << "3 - VENTAS CON ENTREGAS PENDIENTES" << endl;
    cout << "4 - CLIENTES TOTALES" << endl;
    cout << "5 - VENTAS POR DIA" << endl;
    cout << "6 - VENTAS POR MES" << endl;
    cout << "7 - VENTAS POR ANIO" << endl;
    cout << "8 - POSVENTA" << endl;
    cout << "9 - HISTORIAL DE CLIENTE" << endl;       ///Listado de todos los clientes
    cout << "0 - VOLVER " << endl;
 int opcion;
    cin >> opcion;
    switch(opcion){
      case 1:
      objManagerVentaPedido.MostrarVentasTotales();
      break;
      
      case 2:
      
        
      
      break;
      case 3:
      
        
      
      break;
      case 4:
               objManagerCliente.MostrarCantidadRegistros();
      break;
      case 5:
               objManagerVentaPedido.VentasPorDia();
      break;
      case 6:
               objManagerVentaPedido.VentasPorMeses();
      break;
      case 7:

      break;
      case 8:

      break;
      case 9:
             objManagerCliente.ListarTodosNroCliente();
      break;

     case 0:
        return;
      break;
    }

 }
}