#include <iostream>
using namespace std;

#include "ClienteMenu.h"
//#include "ClienteSubMenu.h"

void MenuClientes::MostrarMenuCl(){
    while(true){
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "--------- MUEBLERIA ---------"<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<< endl;
    cout << "1 - NUEVO CLIENTE" << endl;
    cout << "2 - MODIFICAR CLIENTE" << endl;
    cout << "3 - ELIMINAR CLIENTE" << endl;
    cout << "4 - LISTAR TODOS." << endl; ///A MODO DE PRUEBA PARA NOSOTROS
    cout << "0 - VOLVER " << endl;
 int opcion;
    cin >> opcion;
    switch(opcion){
      case 1:
            
         objManagerCliente.CargarClientes();
         system("pause");
         system("cls");
   
      break;
      case 2:

       objManagerCliente.MenuModificarCliente();
       
      break;
      case 3:
         objManagerCliente.EliminarCliente();
         system("pause");
         system("cls");
         //objManagerCliente.MostrarClientesTotales(); //NOS MUESTRA LA CANTIDAD
      break;
      case 4:
         objManagerCliente.ListarTodosNroCliente();
         system("pause");
         system("cls");
      break;
     case 0:
        return;
      break;
    }

 }
}