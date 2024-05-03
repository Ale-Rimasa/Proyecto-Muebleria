#include "MenuListado.h"

#include <iostream>

using namespace std;

void MenuListados::MostrarMenuListado(){
    while(true){
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "--------- MUEBLERIA ---------"<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<< endl;
    cout << "1 - POR CLIENTE" << endl;
    cout << "2 - POR NUMERO FACTURA" << endl;
    cout << "3 - POR FECHA" << endl;
    cout << "4 - POR ARTICULO" << endl; 

    cout << "0 - VOLVER" << endl;
 int opcion;
    cin >> opcion;
    switch(opcion){
      case 1:
      
         objManagerCliente.ListarPorNroCliente();
         system("pause");
         system("cls");
      
      break;
      case 2:
       
         objManagerVentaPedido.ListarPorNroFactura();
       system("pause");
         system("cls");
      break;
      case 3:
         //objManagerVentaPedido.ListarPorFecha();
      break;
      case 4:
         objManagerArticulo.ListarLosArticulos();
        system("pause");
        system("cls");
      break;
     case 0:
        return;
      break;
    }

 }
}