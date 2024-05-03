#include "MenuVentas.h"
//#include "SubMenuVentaPedido.h"
#include <iostream>

using namespace std;

void MenuVentas::MostrarMenuVentas(){
    while(true){
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "--------- MUEBLERIA ---------"<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<< endl;
    cout << "1 - NUEVA VENTA" << endl;
    cout << "2 - MODIFICAR VENTA" << endl;
    cout << "3 - ELIMINAR VENTA" << endl;
    cout << "4 - LISTAR TODAS LAS VENTAS" << endl; //a modo de prueba para ver los registros del momento
    cout << "0 - VOLVER " << endl;
 int opcion;
    cin >> opcion;
    switch(opcion){
      case 1:
     
       
         objManagerVentaPedido.CargarVentaPedido();
       
       
      break;
      case 2:
    
        objManagerVentaPedido.MenuModificarVentaPedido();
      break;
      case 3:
        
        objManagerVentaPedido.EliminarVenta();
      
      break;
     case 4:
        objManagerVentaPedido.ListarTodos(); 
      break;
     case 0:
        return;
      break;
    }

 }
}