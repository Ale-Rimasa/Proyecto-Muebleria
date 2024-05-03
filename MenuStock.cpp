#include "MenuStock.h"

#include <iostream>

using namespace std;

void MenuStock::MostrarMenuSt(){
    while(true){
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "--------- MUEBLERIA ---------"<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<< endl;
    cout << "1 - STOCK TOTAL" << endl;
    cout << "2 - STOCK A FECHA" << endl;
    cout << "3 - MODIFICAR STOCK" << endl;
    cout << "0 - VOLVER " << endl;
 int opcion;
    cin >> opcion;
    switch(opcion){
      case 1:
      
        
      
      break;
      case 2:
      
        
      
      break;
      case 3:
      
        objArticulo.ModificarStock();
      
      break;
      case 4:

      break;
     case 0:
        return;
      break;
    }

 }
}