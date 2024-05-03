#include "Manager.h"
#include "CargarCadena.h"
#include <iostream>
using namespace std;


void Manager::CargarClientes(){
    int nroCliente;
    char nombre[30], apellido[30], telefono[30], dni[30], mail[30];
    char direccion[100];
    char localidad[30]; 

   // Direccion dire;
   // char codPostal[6], localidad[30], calle[30];
   // int numeroCalle;
   // char piso[5], entrecalle1[30], entrecalle2[30], provincia[30],comentario[80];

cout << "NUMERO DE CLIENTE: ";
cin >> nroCliente;

while(BuscarNroCliente(nroCliente) != -1){
cout << "EL NRO DEL CLIENTE YA SE ENCUENTRA EN NUESTRO SISTEMA." << endl;
cout << "VUELVA A INGRESAR OTRO NUEVAMENTE: " << endl;
        system("pause");
        system("cls");
        cout << "NUMERO DE CLIENTE: ";
        cin >> nroCliente;
}
cout << "NOMBRE: ";
cargarCadena(nombre,29);
cout << "APELLIDO: ";
cargarCadena(apellido,29);
cout << "TELEFONO: ";
cargarCadena(telefono,29);
cout << "DNI: ";
cargarCadena(dni,29);
cout << "MAIL: ";
cargarCadena(mail,29);
cout << "*****DATOS PARA EL ENVIO***** " << endl;
cout << "LOCALIDAD: " ;
cargarCadena(localidad,29);
cout << "DIRECCION: " ;
cargarCadena(direccion,99);

Cliente objCliente;
Direccion objDire;
objCliente.setNroCliente(nroCliente);
objCliente.setNombre(nombre);
objCliente.setApellido(apellido);
objCliente.setTelefono(telefono);
objCliente.setDni(dni);
objCliente.setMail(mail);
objCliente.setLocalidad(localidad);
objCliente.setDireccion(direccion);
//objDire.setCalle(calle);

bool ok = archiCliente.GrabarCliente(objCliente);

    if(ok){
        cout << "Cliente guardado." << endl;
    }
    else{
        cout << "Reingrese cliente, no hubo registro." << endl;
    }
}

void Manager::MostrarCliente(Cliente objCliente){
//Direccion objdire;
cout <<"Numero de cliente: "<< objCliente.getNroCliente() << endl;
cout <<"Nombre: " << objCliente.getNombre() << endl;
cout <<"Apellido: " <<objCliente.getApellido() << endl;
cout <<"Dni: " << objCliente.getDni() << endl;
cout <<"Telefono: " <<objCliente.getTelefono() << endl;
cout <<"Mail: " <<objCliente.getMail() << endl;
cout <<"Localidad: " << objCliente.getLocalidad() << endl;
cout <<"Direccion: " << objCliente.getDireccion() << endl;
//objdire.Mostrar();
}

void Manager::MostrarCantidadRegistros(){
     int cantidadRegistros= archiCliente.ContarRegistros();
    cout << endl << "CANTIDAD DE REGISTROS EN NUESTRO SISTEMAS SON:  " << cantidadRegistros << endl;
}
//Recibe como parametro el NROCLIENTE, si machea, devuelve la posicion del mismo y sino devuelve -1.
int Manager::BuscarNroCliente(int NroCliente){
    int cantReg= archiCliente.ContarRegistros();
        if(cantReg == 0){
            cout << "SIN REGISTROS." << endl;
        }
    for (int i=0; i<cantReg; i++){
            Cliente objCliente= archiCliente.Leer(i);
            if(objCliente.getNroCliente() == NroCliente){
                return i;   //NOS DEVUELVE LA POSICION
            }

    }
        return -1;  //SINO, DEVUELVE -1.

}

void Manager::ListarPorNroCliente(){    ///método que permite elegir un Nro Cliente a consultar.
    int nroCliente, pos;
    cout << "INGRESE EL NUMERO DE CLIENTE A CONSULTAR: " << endl;  
    cin >> nroCliente;

    pos=archiCliente.BuscarNroCliente(nroCliente);                   ///Hay que buscarlo con el numero de posicion
  
  if(pos >= 0){                                                ///Si pos es >0 va a leer el numero de factura y obetenemos la factura.
    Cliente objCliente= archiCliente.Leer(pos);
    if(objCliente.getEliminado()== 0){    ///Validacion

        MostrarCliente(objCliente);
    }
    else{

      cout << "NRO DE CLIENTE " << nroCliente << " YA ESTA ELIMINADO." << endl;
      system("Pause");
      system("cls");
   
    }
  
  }
  else{
    cout << "NRO DE CLIENTE " << nroCliente << " NO EXISTE." << endl;
  }

}

/*void Manager::EditarCliente(){
    int nroCliente, pos;
    cout << "NRO CLIENTE: ";
    cin >> nroCliente;

    pos= archiCliente.BuscarNroCliente(nroCliente);
        if(pos < 0){
            cout << endl <<"NO SE ENCONTRO EL CLIENTE CON EL NRO CLIENTE: " << nroCliente << endl;
            system("pause");
            system("cls");
            return;
        }
char opc;
    Cliente objCliente= archiCliente.Leer(pos);
    system("cls");
    cout << "CLIENTE A EDITAR: " << endl;
    MostrarCliente(objCliente);
    cout << endl;
    cout << "DESEA EDITAR EL CLIENTE?? S/N" << endl;
    cin >> opc;
        if(opc == 'n' || 'N'){
                cout << endl << "EL CLIENTE SIGUE EN EL SISTEMA, NO AH SIDO MODIFICADO." << endl;
                system("pause");
                system("cls");
            return;
        }
        system("cls");
    bool proxPaso= MenuModificar(pos);
}

bool Manager::MenuModificar(int pos){
    Cliente objCliente=archiCliente.Leer(pos);
    bool ok = false;
    do{
        MostrarCliente(objCliente);
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "--------- ELIJA OPCION ---------"<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<< endl;
    cout << "1 - NOMBRE" << endl;
    cout << "2 - APELLIDO" << endl;
    cout << "3 - TELEFONO" << endl;
    cout << "4 - MAIL" << endl; 
    cout << "5 - DNI" << endl;
    cout << "6 - DIRECCION" << endl;
    cout << "0 - VOLVER" << endl;
 int opcion;
    cin >> opcion;
            system("cls");
    switch(opcion){
      case 1:
          ok= ModificarNombre();//pos
      break;
      case 2:
          //objManager.ModificarApellido();
      break;
      case 3:
          //  objManager.ModificarTelefono();
      break;
      case 4:
        //  objManager.ModificarMail();
      break;
      case 5:
          //objManager.ModificarDni();
      break;
      case 6:
         // objManager.ModificarDireccio();
      break;
      case 0:
        return false;
      break;
      default:
        cout << "Vuelva a ingresar la opcion u otra a su eleccion." << endl;
        system("pause");
        system("cls");
        break;
    }
  }while (ok != true);
    system("cls");
    cout << "Se a realizado la modificacion." << endl;
    system("pause");
    system("cls");
}
   */

  int Manager::MenuModificarCliente()
{
    int opc;
    bool confirmado= false;
    system("cls");
    while(true){
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "--------- ELIJA OPCION ---------"<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<< endl;
    cout << "1 - NOMBRE" << endl;
    cout << "2 - APELLIDO" << endl;
    cout << "3 - TELEFONO" << endl;
    cout << "4 - MAIL" << endl; 
    cout << "5 - DNI" << endl;
    cout << "6 - DIRECCION" << endl;
    cout << "0 - VOLVER" << endl;
    cout<<"Ingrese la opcion:"<<endl;
    cin>>opc;

    switch(opc)
    {
    case 1:
        confirmado=ModificarNombre();
        system("pause");
        system("cls");
        break;
    case 2:
        confirmado=ModificarApellido();
        system("pause");
        system("cls");
        break;
    case 3:
        confirmado=ModificarTelefono();
        system("pause");
        system("cls");
        break;
    case 4:
        confirmado=ModificarMail();
        system("pause");
        system("cls");
        break;
    case 5:
        confirmado=ModificarDni();
        system("pause");
        system("cls");
        break;
    case 6:

        system("pause");
        system("cls");
        break;
    case 0:
        return 0;

    }

    }
}

bool Manager::ModificarNombre(){
    ClienteArchivo archiCliente("Cliente.dat");
    int nroCliente, pos;
    cout << "INGRESE EL NRO DE CLIENTE A MODIFICAR: ";
    cin >> nroCliente;
    
    pos=archiCliente.BuscarNroCliente(nroCliente);
    if(pos == -1){
        cout << "NO EXISTE ESE NRO CLIENTE." << endl;
    }
    Cliente objCliente;
    objCliente=archiCliente.Leer(pos);
    cout << "REGISTRO A MODIFICAR: " << endl;
    MostrarCliente(objCliente);
    cout << endl;
    char opc;
    cout << "DESEA MODIFICARLO?(S/N) ";
    cin >> opc;
    char nuevoNombre[30];
    if(opc == 's' || opc == 'S'){
        cout << "INGRESAR NUEVO NOMBRE: ";
        cargarCadena(nuevoNombre,29);
        objCliente.setNombre(nuevoNombre);
        bool quepaso=archiCliente.sobreEscribirRegistro(objCliente,pos);
        cout << "NOMBRE MODIFICADO CON EXITO." << endl;
        return quepaso;
    }
        cout << "CANCELASTE LA MODIFICACION O NO SE PUDO REALIZAR, ELIJA OTRA OPCION." << endl;
        return false;
}

bool Manager::ModificarApellido(){
    ClienteArchivo archiCliente("Cliente.dat");
    int nroCliente, pos;
    cout << "INGRESE EL NRO DE CLIENTE A MODIFICAR: ";
    cin >> nroCliente;
    
    pos=archiCliente.BuscarNroCliente(nroCliente);
    if(pos == -1){
        cout << "NO EXISTE ESE NRO CLIENTE." << endl;
    }
    Cliente objCliente;
    objCliente=archiCliente.Leer(pos);
    cout << "REGISTRO A MODIFICAR: " << endl;
    MostrarCliente(objCliente);
    cout << endl;
    char opc;
    cout << "DESEA MODIFICARLO?(S/N) ";
    cin >> opc;
    char nuevoApellido[30];
    if(opc == 's' || opc == 'S'){
        cout << "INGRESAR NUEVO APELLIDO: ";
        cargarCadena(nuevoApellido,29);
        objCliente.setApellido(nuevoApellido);
        bool quepaso=archiCliente.sobreEscribirRegistro(objCliente,pos);
        cout << "APELLIDO MODIFICADO CON EXITO." << endl;
        return quepaso;
    }
        cout << "CANCELASTE LA MODIFICACION O NO SE PUDO REALIZAR, ELIJA OTRA OPCION." << endl;
        return false;
}

bool Manager::ModificarTelefono(){
    ClienteArchivo archiCliente("Cliente.dat");
    int nroCliente, pos;
    cout << "INGRESE EL NRO DE CLIENTE A MODIFICAR: ";
    cin >> nroCliente;
    
    pos=archiCliente.BuscarNroCliente(nroCliente);
    if(pos == -1){
        cout << "NO EXISTE ESE NRO CLIENTE." << endl;
    }
    Cliente objCliente;
    objCliente=archiCliente.Leer(pos);
    cout << "REGISTRO A MODIFICAR: " << endl;
    MostrarCliente(objCliente);
    cout << endl;
    char opc;
    cout << "DESEA MODIFICARLO?(S/N) ";
    cin >> opc;
    char nuevoTelefono[30];
    if(opc == 's' || opc == 'S'){
        cout << "INGRESAR NUEVO TELEFONO: ";
        cargarCadena(nuevoTelefono,29);
        objCliente.setTelefono(nuevoTelefono);
        bool quepaso=archiCliente.sobreEscribirRegistro(objCliente,pos);
        cout << "TELEFONO MODIFICADO CON EXITO." << endl;
        return quepaso;
    }
        cout << "CANCELASTE LA MODIFICACION O NO SE PUDO REALIZAR, ELIJA OTRA OPCION." << endl;
        return false;
}

bool Manager::ModificarMail(){
    ClienteArchivo archiCliente("Cliente.dat");
    int nroCliente, pos;
    cout << "INGRESE EL NRO DE CLIENTE A MODIFICAR: ";
    cin >> nroCliente;
    
    pos=archiCliente.BuscarNroCliente(nroCliente);
    if(pos == -1){
        cout << "NO EXISTE ESE NRO CLIENTE." << endl;
    }
    Cliente objCliente;
    objCliente=archiCliente.Leer(pos);
    cout << "REGISTRO A MODIFICAR: " << endl;
    MostrarCliente(objCliente);
    cout << endl;
    char opc;
    cout << "DESEA MODIFICARLO?(S/N) ";
    cin >> opc;
    char nuevoMail[30];
    if(opc == 's' || opc == 'S'){
        cout << "INGRESAR NUEVO MAIL: ";
        cargarCadena(nuevoMail,29);
        objCliente.setMail(nuevoMail);
        bool quepaso=archiCliente.sobreEscribirRegistro(objCliente,pos);
        cout << "MAIL MODIFICADO CON EXITO." << endl;
        return quepaso;
    }
        cout << "CANCELASTE LA MODIFICACION O NO SE PUDO REALIZAR, ELIJA OTRA OPCION." << endl;
        return false;
}

bool Manager::ModificarDni(){
    ClienteArchivo archiCliente("Cliente.dat");
    int nroCliente, pos;
    cout << "INGRESE EL NRO DE CLIENTE A MODIFICAR: ";
    cin >> nroCliente;
    
    pos=archiCliente.BuscarNroCliente(nroCliente);
    if(pos == -1){
        cout << "NO EXISTE ESE NRO CLIENTE." << endl;
    }
    Cliente objCliente;
    objCliente=archiCliente.Leer(pos);
    cout << "REGISTRO A MODIFICAR: " << endl;
    MostrarCliente(objCliente);
    cout << endl;
    char opc;
    cout << "DESEA MODIFICARLO?(S/N) ";
    cin >> opc;
    char nuevoDNI[30];
    if(opc == 's' || opc == 'S'){
        cout << "INGRESAR NUEVO DNI: ";
        cargarCadena(nuevoDNI,29);
        objCliente.setDni(nuevoDNI);
        bool quepaso=archiCliente.sobreEscribirRegistro(objCliente,pos);
        cout << "DNI MODIFICADO CON EXITO." << endl;
        return quepaso;
    }
        cout << "CANCELASTE LA MODIFICACION O NO SE PUDO REALIZAR, ELIJA OTRA OPCION." << endl;
        return false;
}

void Manager::EliminarCliente(){      
    int nroCliente, pos;
    cout << "INGRESE EL NUMERO DE CLIENTE A ELIMINAR: " << endl;
    cin >> nroCliente;  

    pos=archiCliente.BuscarNroCliente(nroCliente);                                           
  if(pos >= 0){                                                     
    Cliente objCliente= archiCliente.Leer(pos);
        cout << "REGISTRO DE CLIENTE A ELIMINAR" << endl;
    MostrarCliente(objCliente);
    
    char confirmacion;
    cout << "SEGURO DE ELIMINAR REGISTRO ? S/N " << endl;
    cin >> confirmacion;
    
    if(confirmacion == 'S' || confirmacion == 's'){
        objCliente.setEliminado(0);
        archiCliente.GrabarCliente(objCliente,pos);
        cout << "REGISTRO ELIMINADO CORRECTAMENTE." << endl;
    }
  else{
    cout << "REGISTRO NO FUE ELIMINADO." << endl;
  }
}

else{
    cout << endl << "NO SE ENCONTRO EL NUMERO DE FACTURA." << endl;
    }
}

/******************************************************************************************/
///VENTA PEDIDO
void Manager::CargarVentaPedido(){
    int nroFactura, nroCliente, formaPago;          
    char comentarios[100];    
    float montoTotal, senia;
    bool estadoEntrega;
    int dia, mes, anio;

    cout << "INGRESE NRO FACTURA: " ;
    cin >> nroFactura;

    while(BuscarNroFactura(nroFactura) != -1){
cout << "EL NRO DE LA FACTURA YA SE ENCUENTRA EN NUESTRO SISTEMA." << endl;
cout << "VUELVA A INGRESAR OTRO NUEVAMENTE: " << endl;
        system("pause");
        system("cls");
        cout << "NUMERO DE FACTURA: ";
        cin >> nroFactura;
}

    cout << "INGRESE NRO CLIENTE: " ;
    cin >> nroCliente;
    cout << "INGRESE FORMA DE PAGO: (1 para debito - 2 para Tarjeta - 3 para Efectivo)" << endl;
    cin >> formaPago;
    cout << "INGRESE COMENTARIO: " ;
    cargarCadena(comentarios,99);
    cout << "INGRESE FECHA: ";
    cin >> dia;
    cin >> mes;
    cin >> anio;
    cout << "INGRESE MONTO TOTAL: $";
    cin >> montoTotal;
    cout << "INGRESE SENIA: $" ;
    cin >> senia; 

    VentaPedido objVentaPedido;
    objVentaPedido.setNroFactura(nroFactura);
    objVentaPedido.setNroCliente(nroCliente);
    objVentaPedido.setFormaPago(formaPago);
    objVentaPedido.setComentario(comentarios);
    objVentaPedido.setFecha(Fecha(dia,mes,anio));
    objVentaPedido.setMontoTotal(montoTotal);
    objVentaPedido.setSenia(senia);

    bool ok = archiVentaPedido.GrabarVentaPedido(objVentaPedido);

    if(ok){
        cout << "VENTA GUARDADA." << endl;
    }
    else{
        cout << "Reingrese venta, no hubo registro." << endl;
    }
}

void Manager::MostrarVentaPedido(VentaPedido objVentaPedido){
cout << "NRO FACTURA: " << objVentaPedido.getNroFactura() << endl;
cout << "NRO CLIENTE: " << objVentaPedido.getNroCliente() << endl;
cout << "FORMA DE PAGO: " << objVentaPedido.getFormaPago() << endl;
cout << "COMENTARIO: " << objVentaPedido.getComentario() << endl;
cout << "FECHA: " <<  objVentaPedido.getFecha().toString() << endl;
cout << "MONTO TOTAL: $" << objVentaPedido.getMontoTotal ()<< endl;
cout << "SENIA: $" << objVentaPedido.getSenia() << endl;
}

void Manager::MostrarVentasTotales(){ ///Nos muestra la cantidad de las ventas  
    int cantidadRegistros= archiVentaPedido.ContarRegistros();
    cout << endl << "VENTAS TOTALES: " << cantidadRegistros << endl;
}

int Manager::BuscarNroFactura(int NroFactura){
    int cantReg= archiVentaPedido.ContarRegistros();
        if(cantReg == 0){
            cout << "SIN REGISTROS." << endl;
        }
    for (int i=0; i<cantReg; i++){
            VentaPedido objVentaPedido= archiVentaPedido.Leer(i);
            if(objVentaPedido.getNroFactura() == NroFactura){
                return i;   //NOS DEVUELVE LA POSICION
            }

    }
        return -1;  //SINO, DEVUELVE -1.

}

void Manager::ListarTodos(){    ///CON ESTE METODO LEO TODOS Y MUESTRO TODOS
int cantidadRegistros = archiVentaPedido.ContarRegistros();
  cout << endl;

    for(int i=0; i<cantidadRegistros; i++){        ///Con el for va recorriendo registro por registro 
    VentaPedido objVentaPedido =archiVentaPedido.Leer(i);
    
    if(objVentaPedido.getEliminado()== 0){

        MostrarVentaPedido(objVentaPedido);
    }
    /*Prueba: Muestra  los numeros dados de baja
    else{

      cout << "NRO DE FACTURA " << objVentaPedido.getNroFactura() << "ESTA DADA DE BAJA." << endl;
      system("Pause");
      system("cls");
   
    }*/
    cout << endl << endl;
    }

}

void Manager::ListarPorNroFactura(){
    int nroFactura, pos;
    cout << "INGRESE EL NUMERO DE FACTURA A CONSULTAR: " << endl;  
    cin >> nroFactura;

    pos=archiVentaPedido.BuscarNroFactura(nroFactura);                   ///Hay que buscarlo con el numero de posicion
  
  if(pos >= 0){                                                ///Si pos es >0 va a leer el numero de factura y obetenemos la factura.
    VentaPedido objVentaPedido= archiVentaPedido.Leer(pos);
    if(objVentaPedido.getEliminado()== 0){    ///Validacion

        MostrarVentaPedido(objVentaPedido);
    }
    else{

      cout << "NRO DE FACTURA " << nroFactura << " YA ESTA ELIMINADO." << endl;
      system("Pause");
      system("cls");
   
    }
  
  }
  else{
    cout << "NRO DE FACTURA " << nroFactura << " NO EXISTE." << endl;
  }

}

int Manager::MenuModificarVentaPedido()
{
    int opc;
    bool confirmado= false;
    system("cls");
    while(true){
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "--------- ELIJA OPCION ---------"<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<< endl;
    cout << "1 - FORMA DE PAGO" << endl;
    cout << "2 - MONTO TOTAL" << endl;
    cout << "3 - SENIA" << endl;
    cout << "4 - COMENTARIO" << endl; 
    cout << "0 - VOLVER" << endl;
    cout<<"Ingrese la opcion:"<<endl;
    cin>>opc;

    switch(opc)
    {
    case 1:
        confirmado=ModificarFormaDePago();
        system("pause");
        system("cls");
        break;
    case 2:
        confirmado=ModificarMontoTotal();
        system("pause");
        system("cls");
        break;
    case 3:
        confirmado=ModificarSenia();
        system("pause");
        system("cls");
        break;
    case 4:
        confirmado=ModificarComentario();
        system("pause");
        system("cls");
        break;
    case 0:
        return 0;

    }

    }
}

bool Manager::ModificarFormaDePago(){
    VentaPedidoArchivo archiVentaPedido("VentaPedido.dat");
    int nroFactura, pos;
    cout << "INGRESE EL NRO DE FACTURA A MODIFICAR: ";
    cin >> nroFactura;
    
    pos=archiVentaPedido.BuscarNroFactura(nroFactura);
    if(pos == -1){
        cout << "NO EXISTE ESE NRO FACTURA." << endl;
    }
    VentaPedido objVentaPedido;
    objVentaPedido=archiVentaPedido.Leer(pos);
    cout << "REGISTRO A MODIFICAR: " << endl;
    MostrarVentaPedido(objVentaPedido);
    cout << endl;
    char opc;
    cout << "DESEA MODIFICARLO?(S/N) ";
    cin >> opc;
    int nuevaFormaPago;
    if(opc == 's' || opc == 'S'){
        cout << "INGRESAR NUEVA FORMA DE PAGO: (1 para debito - 2 para Tarjeta - 3 para Efectivo) ";
        cin >> nuevaFormaPago;
        objVentaPedido.setFormaPago(nuevaFormaPago);
        bool quepaso=archiVentaPedido.sobreEscribirRegistro(objVentaPedido,pos);
        cout << "FORMA DE PAGO MODIFICADO CON EXITO." << endl;
        return quepaso;
    }
        cout << "CANCELASTE LA MODIFICACION O NO SE PUDO REALIZAR, ELIJA OTRA OPCION." << endl;
        return false;
}

bool Manager::ModificarMontoTotal(){
    VentaPedidoArchivo archiVentaPedido("VentaPedido.dat");
    int nroFactura, pos;
    cout << "INGRESE EL NRO DE FACTURA A MODIFICAR: ";
    cin >> nroFactura;
    
    pos=archiVentaPedido.BuscarNroFactura(nroFactura);
    if(pos == -1){
        cout << "NO EXISTE ESE NRO FACTURA." << endl;
    }
    VentaPedido objVentaPedido;
    objVentaPedido=archiVentaPedido.Leer(pos);
    cout << "REGISTRO A MODIFICAR: " << endl;
    MostrarVentaPedido(objVentaPedido);
    cout << endl;
    char opc;
    cout << "DESEA MODIFICARLO?(S/N) ";
    cin >> opc;
    float nuevoMonto;
    if(opc == 's' || opc == 'S'){
        cout << "INGRESAR NUEVO MONTO ";
        cin >> nuevoMonto;
        objVentaPedido.setMontoTotal(nuevoMonto);
        bool quepaso=archiVentaPedido.sobreEscribirRegistro(objVentaPedido,pos);
        cout << "NUEVO MONTO MODIFICADO CON EXITO." << endl;
        return quepaso;
    }
        cout << "CANCELASTE LA MODIFICACION O NO SE PUDO REALIZAR, ELIJA OTRA OPCION." << endl;
        return false;
}

bool Manager::ModificarSenia(){
    VentaPedidoArchivo archiVentaPedido("VentaPedido.dat");
    int nroFactura, pos;
    cout << "INGRESE EL NRO DE FACTURA A MODIFICAR: ";
    cin >> nroFactura;
    
    pos=archiVentaPedido.BuscarNroFactura(nroFactura);
    if(pos == -1){
        cout << "NO EXISTE ESE NRO FACTURA." << endl;
    }
    VentaPedido objVentaPedido;
    objVentaPedido=archiVentaPedido.Leer(pos);
    cout << "REGISTRO A MODIFICAR: " << endl;
    MostrarVentaPedido(objVentaPedido);
    cout << endl;
    char opc;
    cout << "DESEA MODIFICARLO?(S/N) ";
    cin >> opc;
    float nuevaSenia;
    if(opc == 's' || opc == 'S'){
        cout << "INGRESAR NUEVO MONTO ";
        cin >> nuevaSenia;
        objVentaPedido.setSenia(nuevaSenia);
        bool quepaso=archiVentaPedido.sobreEscribirRegistro(objVentaPedido,pos);
        cout << "LA NUEVA SENIA SE A MODIFICADO CON EXITO." << endl;
        return quepaso;
    }
        cout << "CANCELASTE LA MODIFICACION O NO SE PUDO REALIZAR, ELIJA OTRA OPCION." << endl;
        return false;
}

bool Manager::ModificarComentario(){
    VentaPedidoArchivo archiVentaPedido("VentaPedido.dat");
    int nroFactura, pos;
    cout << "INGRESE EL NRO DE FACTURA A MODIFICAR: ";
    cin >> nroFactura;
    
    pos=archiVentaPedido.BuscarNroFactura(nroFactura);
    if(pos == -1){
        cout << "NO EXISTE ESE NRO FACTURA." << endl;
    }
    VentaPedido objVentaPedido;
    objVentaPedido=archiVentaPedido.Leer(pos);
    cout << "REGISTRO A MODIFICAR: " << endl;
    MostrarVentaPedido(objVentaPedido);
    cout << endl;
    char opc;
    cout << "DESEA MODIFICARLO?(S/N) ";
    cin >> opc;
    char nuevoComentario[100];
    if(opc == 's' || opc == 'S'){
        cout << "INGRESAR NUEVO COMENTARIO ";
        cargarCadena(nuevoComentario,99);
        objVentaPedido.setComentario(nuevoComentario);
        bool quepaso=archiVentaPedido.sobreEscribirRegistro(objVentaPedido,pos);
        cout << "EL NUEVO COMENTARIO SE A MODIFICADO CON EXITO." << endl;
        return quepaso;
    }
        cout << "CANCELASTE LA MODIFICACION O NO SE PUDO REALIZAR, ELIJA OTRA OPCION." << endl;
        return false;
}
//FUNCIONA, REVISAR PORQUE DEJA BASURA.
/*void Manager::EliminarVenta(){      
    int nroFactura, pos;
    cout << "INGRESE EL NUMERO DE FACTURA: " << endl;
    cin >> nroFactura;  

    pos=archiVentaPedido.BuscarNroFactura(nroFactura);                                                
  if(pos >= 0){                                                     
    VentaPedido objVentaPedido= archiVentaPedido.Leer(pos);
        cout << "REGISTRO DE VENTA A ELIMINAR" << endl;
    MostrarVentaPedido(objVentaPedido);
    
    char confirmacion;
    cout << "SEGURO DE ELIMINAR REGISTRO ? S/N " << endl;
    cin >> confirmacion;
    
    if(toupper(confirmacion) == 'S'){
        objVentaPedido.setEliminado(true);
        archiVentaPedido.GrabarVentaPedido(objVentaPedido,pos);
        cout << "REGISTRO ELIMINADO CORRECTAMENTE." << endl;
    }
  else{
    cout << "REGISTRO NO FUE ELIMINADO." << endl;
  }
}

else{
    cout << endl << "NO SE ENCONTRO EL NUMERO DE FACTURA." << endl;
    }
}*/

void Manager::EliminarVenta(){      
    int nroFactura, pos;
    cout << "INGRESE EL NUMERO DE FACTURA: " << endl;
    cin >> nroFactura;  

    pos=archiVentaPedido.BuscarNroFactura(nroFactura);                                                
  if(pos >= 0){                                                     
    VentaPedido objVentaPedido= archiVentaPedido.Leer(pos);
        cout << "REGISTRO DE VENTA A ELIMINAR" << endl;
    MostrarVentaPedido(objVentaPedido);
    
    char confirmacion;
    cout << "SEGURO DE ELIMINAR REGISTRO ? S/N " << endl;
    cin >> confirmacion;
    
    if(confirmacion == 'S' || confirmacion == 's'){
        objVentaPedido.setEliminado(true);
        archiVentaPedido.GrabarVentaPedido(objVentaPedido,pos);
        cout << "REGISTRO ELIMINADO CORRECTAMENTE." << endl;
    }
  else{
    cout << "REGISTRO NO FUE ELIMINADO." << endl;
  }
}

else{
    cout << endl << "NO SE ENCONTRO EL NUMERO DE FACTURA." << endl;
    }
}

/****************************************************************************************/
//VENTA PEDIDO DETALLE

void Manager::CargarVentaPedidoDetalle(){
    int _nroFactura, _nroArticulo, _cantidad;
    float _precio;

cout << "INGRESE NUMERO DE FACTURA A CONSULTAR: " ;
cin >> _nroFactura;
cout << "INGRESE NUMERO DE ARTICULO: " ;
cin >> _nroArticulo;
cout << "INGRESE LA CANTIDAD: ";
cin >> _cantidad;
cout << "INGRESE EL PRECIO: ";
cin >> _precio;

VentaPedidoDetalle objVentaPedidoDetalle;
objVentaPedidoDetalle.setNroFactura(_nroFactura);
objVentaPedidoDetalle.setNroArticulo(_nroArticulo);
objVentaPedidoDetalle.setCantidad(_cantidad);
objVentaPedidoDetalle.setPrecio(_precio);

bool ok = archiVentaPedidoDetalle.GrabarVentaPedidoDetalle(objVentaPedidoDetalle);

    if(ok){
        cout << "DETALLE DEL PEDIDO GUARDADO." << endl;
    }
    else{
        cout << "Reingrese pedido, no hubo registro." << endl;
    }
}

void Manager::MostrarVentaPedidoDetalle(VentaPedidoDetalle objVentaPedidoDetalle){
    cout << "NUMERO FACTURA: " << objVentaPedidoDetalle.getNroFactura() << endl;
    cout << "NUMERO DE ARTICULO: " << objVentaPedidoDetalle.getNroArticulo() << endl;
    cout << "CANTIDAD: " << objVentaPedidoDetalle.getCantidad() << endl;
    cout << "PRECIO: $" << objVentaPedidoDetalle.getPrecio() << endl;
}

void Manager::ListarLosDetalles(){    ///CON ESTE METODO LEO TODOS Y MUESTRO TODOS
int cantidadRegistros = archiVentaPedidoDetalle.ContarRegistros();
  cout << endl;

    for(int i=0; i<cantidadRegistros; i++){        ///Con el for va recorriendo registro por registro 
    VentaPedidoDetalle objDetalle =archiVentaPedidoDetalle.Leer(i);
    
    if(objDetalle.getEstado() == 0){

        MostrarVentaPedidoDetalle(objDetalle);
    }
    //Prueba: Muestra  los numeros dados de baja
    else{

      cout << "NRO DE FACTURA " << objDetalle.getNroArticulo() << "ESTA DADA DE BAJA." << endl;
      system("pause");
      system("cls");
   
    }
    cout << endl << endl;
    }

}

/****************************************************************************************/
///ARTICULOS
void Manager::CargarArticulo(){
int _nroArticulo, _stock;
char _descripcion[50];

cout << "INGRESE EL NUMERO DE ARTICULO: " ;
cin >> _nroArticulo;
cout << "INGRESE EL STOCK QUE SE ENCUENTRA: ";
cin >> _stock;
cout << "INGRESE DESCRIPCION: ";
cargarCadena(_descripcion,49);

Articulo objArticulo;
objArticulo.setNroArticulo(_nroArticulo);
objArticulo.setStock(_stock);
objArticulo.setDescripcion(_descripcion);

bool ok= archiArticulo.GrabarArticulo(objArticulo);

 if(ok){
        cout << "ARTICULO GUARDADO." << endl;
    }
    else{
        cout << "REINGRESE ARTICULO, NO HUBO REGISTRO." << endl;
    }
}

void Manager::MostrarArticulo(Articulo objArticulo){
    cout << "NUMERO DE ARTICULO: " << objArticulo.getNroArticulo() << endl;
    cout << "STOCK: " << objArticulo.getStock() << endl;
    cout << "DESCRIPCION DEL ARTICULO: " << objArticulo.getDescripcion() << endl;
}   



void Manager::ListarLosArticulos(){    ///CON ESTE METODO LEO TODOS Y MUESTRO TODOS
int cantidadRegistros = archiArticulo.ContarRegistros();
  cout << endl;

    for(int i=0; i<cantidadRegistros; i++){        ///Con el for va recorriendo registro por registro 
    Articulo objArticulo =archiArticulo.Leer(i);
    
    if(objArticulo.getEstado() == 0){

        MostrarArticulo(objArticulo);
    }
    //Prueba: Muestra  los numeros dados de baja
    else{

      cout << "NRO DE ARTICULO " << objArticulo.getNroArticulo() << "ESTA DADA DE BAJA." << endl;
      system("pause");
      system("cls");
   
    }
    cout << endl << endl;
    }

}

void Manager::ListarPorArticulo(){
    int nroArticulo, pos;
    cout << "INGRESE EL ARTICULO A CONSULTAR: " << endl;  
    cin >> nroArticulo;

    pos=archiArticulo.BuscarNroArticulo(nroArticulo);                   ///Hay que buscarlo con el numero de posicion
  
  if(pos >= 0){                                                ///Si pos es >0 va a leer el numero de factura y obetenemos la factura.
    Articulo objArt= archiArticulo.Leer(pos);
    if(objArt.getEstado()== 0){    ///Validacion

        MostrarArticulo(objArt);
    }
    else{

      cout << "NRO DE ARTICULO " << nroArticulo << " YA ESTA ELIMINADO." << endl;
      system("Pause");
      system("cls");
   
    }
  
  }
  else{
    cout << "NRO DE ARTICULO " << nroArticulo << " NO EXISTE." << endl;
  }

}

/*int Manager::BuscarPorFecha(int fecha){
    int cantReg= archiVentaPedido.ContarRegistros();
        if(cantReg == 0){
            cout << "SIN REGISTROS." << endl;
        }
    for (int i=0; i<cantReg; i++){
            VentaPedido objVentaPedido= archiVentaPedido.Leer(i);
            if(objVentaPedido.getFecha().toString() == fecha){
                return i;   //NOS DEVUELVE LA POSICION
            }

    }
        return -1;  //SINO, DEVUELVE -1.

}*/
/*void Manager::ListarPorFecha(){
    int fecha, pos;
    cout << "INGRESE LA FECHA A CONSULTAR: " << endl;  
    cin >> fecha;

    pos=archiVentaPedido.BuscarPorFecha(fecha);                   ///Hay que buscarlo con el numero de posicion
  
  if(pos >= 0){                                                ///Si pos es >0 va a leer el numero de factura y obetenemos la factura.
    Articulo objArt= archiArticulo.Leer(pos);
    if(objArt.getEstado()== 0){    ///Validacion

        MostrarArticulo(objArt);
    }
    else{

      cout << "NRO DE ARTICULO " << nroArticulo << " YA ESTA ELIMINADO." << endl;
      system("Pause");
      system("cls");
   
    }
  
  }
  else{
    cout << "NRO DE ARTICULO " << nroArticulo << " NO EXISTE." << endl;
  }

}*/

/****************************************************************************************/
//REPORTES
void Manager::VentasPorDia(){
VentaPedidoArchivo archiVentaPedido("VentaPedido.dat");
VentaPedido objVp;
int cantRegistro=archiVentaPedido.ContarRegistros();
int vCantVentasDias[30]={};
for(int i=0; i<cantRegistro; i++){
    objVp=archiVentaPedido.Leer(i);

        vCantVentasDias[objVp.getFecha().getDia() -1]++;
}
    for(int i=0; i<30; i++){

    if(vCantVentasDias [i] > 0){
        cout << "PARA EL DIA " << i+1 << " LA CANTIDAD DE VENTAS FUERON : " << vCantVentasDias[i] << endl;   ;
             
             }
        }

    }

void Manager::VentasPorMeses(){
    VentaPedidoArchivo archiVentaPedido("VentaPedido.dat");
VentaPedido objVp;
int cantRegistro=archiVentaPedido.ContarRegistros();
int vCantVentasXMes[12]={};
for(int i=0; i<cantRegistro; i++){
    objVp=archiVentaPedido.Leer(i);

        vCantVentasXMes[objVp.getFecha().getMes() -1]++;
}
    for(int i=0; i<12; i++){

    if(vCantVentasXMes [i] > 0){
        cout << "PARA EL MES " << i+1 << " LA CANTIDAD DE VENTAS FUERON : " << vCantVentasXMes[i] << endl;   ;
             
             }
        }

    }

void Manager::ListarTodosNroCliente(){    ///CON ESTE METODO LEO TODOS Y MUESTRO TODOS
int cantidadRegistros = archiCliente.ContarRegistros();
  cout << endl;

    for(int i=0; i<cantidadRegistros; i++){        ///Con el for va recorriendo registro por registro 
    Cliente objCliente =archiCliente.Leer(i);
    
    if(objCliente.getEliminado()== 0){

        MostrarCliente(objCliente);
    }
    //Prueba: Muestra  los numeros dados de baja
    else{

      cout << "NRO DE CLIENTE " << objCliente.getNroCliente() << "ESTA DADA DE BAJA." << endl;
      system("pause");
      system("cls");
   
    }
    cout << endl << endl;
    }

}

bool Manager::ModificarStock(){
    ArticuloArchivo archiArticulo("Articulo.dat");
    int nroArticulo, pos;
    cout << "INGRESE EL NRO DE ARTICULO A MODIFICAR: ";
    cin >> nroArticulo;
    
    pos=archiArticulo.BuscarNroArticulo(nroArticulo);
    if(pos == -1){
        cout << "NO EXISTE ESE NRO DE ARTICULO." << endl;
    }
    Articulo objArticulo;
    objArticulo=archiArticulo.Leer(pos);
    cout << "REGISTRO A MODIFICAR: " << endl;
    MostrarArticulo(objArticulo);
    cout << endl;
    char opc;
    cout << "DESEA MODIFICARLO?(S/N) ";
    cin >> opc;
    int nuevoStock;
    if(opc == 's' || opc == 'S'){
        cout << "INGRESAR EL STOCK NUEVO DEL ARTICULO: " << endl;
        cin >> nuevoStock;
        objArticulo.setStock(nuevoStock);
        bool quepaso=archiArticulo.sobreEscribirRegistro(objArticulo,pos);
        cout << "STOCK MODIFICADO CON EXITO." << endl;
        return quepaso;
    }
        cout << "CANCELASTE LA MODIFICACION O NO SE PUDO REALIZAR, ELIJA OTRA OPCION." << endl;
        return false;
}
     
       
          

void Manager::EliminarArticulo(){      
    int nroArticulo, pos;
    Articulo objArticulo;
    cout << "INGRESE EL NUMERO DE ARTICULO A ELIMINAR: " << endl;
    cin >> nroArticulo;  

    pos=archiArticulo.BuscarNroArticulo(nroArticulo);                                           
  /*if(pos >= 0){                                                     
    Articulo objArticulo= objArticulo.L(pos);
        cout << "REGISTRO DE ARTICULO A ELIMINAR" << endl;
    MostrarArticulo(objArticulo);*/
    
    char confirmacion;
    cout << "SEGURO DE ELIMINAR REGISTRO ? S/N " << endl;
    cin >> confirmacion;
    
    if(confirmacion == 'S' || confirmacion == 's'){
        objArticulo.setEstado(0);
        archiArticulo.GrabarArticulo(objArticulo,pos);
        cout << "REGISTRO ELIMINADO CORRECTAMENTE." << endl;
    }
  else{
    cout << "REGISTRO NO FUE ELIMINADO." << endl;
  }
}