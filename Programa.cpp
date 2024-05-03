#include "Programa.h"
#include <iostream>
using namespace std;

#include "MenuPrincipal.h"

void Programa::Iniciar(){
  while(true){
    cout << "*******************************" << endl;
    cout << "*** GESTION PARA MUEBLERIA ***" << endl;
    cout << "*******************************" << endl;
    cout << "1 - MANOS A LA OBRA" << endl;
    cout << "2 - Creditos" << endl;
    cout << "*******************************" << endl;
    cout << "0 - Salir del programa" << endl;
    
    int opcion;
    cin >> opcion;
    switch(opcion){
      case 1:
        
        MenuPrincipal objMenuPrinc;
        objMenuPrinc.Mostrar();
        system("pause");
        system("cls");
      break;
      case 2:
        cout << endl << "UTN LABORATORIO II" << endl;
        cout << endl << "BY ROMERO FEDERICO, RIMASA ALEJANDRO." << endl;
        system("pause");
         system("cls");
      break;
      case 0:
        return;
      break;
    }
  }
}
