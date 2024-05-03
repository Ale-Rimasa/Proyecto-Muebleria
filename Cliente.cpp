#include<iostream>
using namespace std;
#include "CargarCadena.h"
#include "Cliente.h"


/// SETTERS
void Cliente::setNroCliente(int nroCliente){_nroCliente = nroCliente;}
void Cliente::setNombre(const char * nombre){strcpy(_nombre,nombre);}
void Cliente::setApellido(const char * apellido){strcpy(_apellido, apellido);}
void Cliente::setTelefono( const char * telefono){strcpy(_telefono,telefono);}
void Cliente::setMail(const char * mail){strcpy(_mail,mail);}
void Cliente::setDni( const char * dni){strcpy(_dni,dni);}
void Cliente::setLocalidad(const char* localidad){strcpy( _localidad , localidad);}
void Cliente::setDireccion(const char* calle){strcpy(_direccion , calle);}
//void Cliente::setDireccion(Direccion direccion){_direccion = direccion; }///cambiar luego al objeto Direccion
void Cliente::setEliminado(bool eliminado){_eliminado= eliminado;}
void Cliente::setEstado(bool estado){_estado= estado;}

    ///GETTERS
int Cliente::getNroCliente() {return _nroCliente;}
const char * Cliente::getNombre() {return _nombre;}
const char * Cliente::getApellido() {return _apellido;}
const char * Cliente::getTelefono() {return _telefono;}
const char * Cliente::getMail() {return _mail;}
const char * Cliente::getDni() {return _dni;}
const char* Cliente::getLocalidad(){return _localidad;}
const char* Cliente::getDireccion(){return _direccion;}
//Direccion& Cliente::getDireccion(){return _direccion;}///cambiar luego al objeto Direccion
bool Cliente::getEstado(){return _estado;}
bool Cliente::getEliminado(){return _eliminado;}

Cliente::Cliente(){
  setNroCliente(0);
  setNombre(""),
  setApellido("");
  setTelefono("");
  setMail("");
  setDni("");
  setLocalidad("");
  setDireccion("");
  _eliminado= false;
  _estado= false;

}