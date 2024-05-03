#include "MenuArticulo.h"
#include "rlutil.h"
#include <iostream>

using namespace std;

void MenuStock::MostrarMenuSt(){
  system("cls");
    while(true){
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "--------- MUEBLERIA ---------"<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<< endl;
    cout << "1 - IMPLEMENTAR ARTICULO NUEVO" << endl;
    cout << "2 - MOSTRAR LOS ARTICULOS" << endl;
    cout << "3 - MODIFICAR STOCK" << endl;
    cout << "4 - ELIMINAR ARTICULO" << endl;
    cout << "0 - VOLVER" << endl;
    
 int opcion;
    cin >> opcion;
    switch(opcion){
      case 1:
        system("cls");
        objManagerArticulo.CargarArticulo();
        system("pause");
        system("cls"); 
        rlutil::setColor(rlutil::COLOR::YELLOW);
      break;
      case 2:
        system("cls");
        objManagerArticulo.ListarLosArticulos();
        system("pause");
        system("cls");
        rlutil::setColor(rlutil::COLOR::YELLOW); 
      break;
      case 3:
       system("cls");
       objArticulo.ModificarStock();
       system("pause");
       system("cls");
       rlutil::setColor(rlutil::COLOR::YELLOW);
      break;
      case 4:
        objArticulo.EliminarArticulo();
        system("pause");
        system("cls");
        rlutil::setColor(rlutil::COLOR::YELLOW);
        return;
     case 0:
        return;
      break;
    }
 }
}