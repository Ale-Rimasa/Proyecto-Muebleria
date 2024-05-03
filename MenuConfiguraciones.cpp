#include "MenuConfiguraciones.h"
//#include "HacerCopiaDeSeuridad"
#include "rlutil.h"
#include <iostream>

using namespace std;

void MenuConfig::MostrarMenuConfiguraciones(){
    while(true){
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "--------- MUEBLERIA ---------"<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<< endl;
    cout << "1 - COPIA DE SEGURIDAD VENTAS. " << endl;
    cout << "2 - COPIA DE SEGURIDAD CLIENTES" << endl;
    cout << "0 - VOLVER " << endl;
 int opcion;
    cin >> opcion;
    switch(opcion){
      case 1:
    
       // objBKP.HacerCopiaDeSeguridadVentas();
        system("pause");
        system("cls");  
        rlutil::setColor(rlutil::COLOR::YELLOW);
      break;
      case 2:
       //  objBKP.HacerCopiaDeSeguridadCliente();
        system("pause");
        system("cls");
        rlutil::setColor(rlutil::COLOR::YELLOW);  
      break;
case 0:
        return;
      break;
    }

 }
}