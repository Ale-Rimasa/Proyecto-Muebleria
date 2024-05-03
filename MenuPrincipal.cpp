#include "MenuPrincipal.h"
#include "ClienteMenu.h"
#include "MenuVentas.h"
#include "MenuListado.h"
#include "MenuReportes.h"
#include "MenuStock.h"
#include "MenuDetalleDelPedido.h"

#include <iostream>

using namespace std;

void MenuPrincipal::Mostrar(){
    while(true){
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "--------- MUEBLERIA ---------"<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<< endl;
    cout << "1 - CLIENTES" << endl;
    cout << "2 - VENTAS" << endl;
    cout << "3 - LISTADOS" << endl;
    cout << "4 - REPORTES " << endl;
    cout << "5 - STOCK" << endl;
    cout << "6 - DETALLES DE LOS ARTICULOS" << endl;
    cout << "0 - VOLVER - " << endl;
 int opcion;
    cin >> opcion;
    switch(opcion){
      case 1:
      {
        MenuClientes objMenuCl;
        objMenuCl.MostrarMenuCl();
        system("pause");
        system("cls");
      }
      break;
      case 2:
      {
      MenuVentas objMenuV;
      objMenuV.MostrarMenuVentas();
        system("pause");
         system("cls");
      }
      break;
      case 3:
      {
        
        MenuListados objMenuListados;
        objMenuListados.MostrarMenuListado();
        system("pause");
        system("cls");
      }
      break;
      case 4:
      {
        MenuReportes objMenuReportes;
        objMenuReportes.MostrarMenuRepo();
        system("pause");
        system("cls");
      }
      break;
      case 5:
      {
        MenuStock objMenuStock;
        objMenuStock.MostrarMenuSt();
        system("pause");
        system("cls");  
      }
      break;
      case 6:
      {
        MenuDetalle objMenuDetalle;
        objMenuDetalle.MostrarDetalleDelPedido();
        system("pause");
        system("cls");  
      }
      break;
      case 0:
        return;
      break;
    }
   }



}
