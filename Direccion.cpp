#include<iostream>
using namespace std;
#include<cstring>
#include "Direccion.h"
#include "CargarCadena.h"

///SETTERS

void Direccion::setCodPostal(const char* codPostal){strcpy (_codPostal, codPostal);}
void Direccion::setLocalidad(const char* localidad){strcpy( _localidad , localidad);}
void Direccion::setCalle(const char* calle){strcpy(_calle , calle);}
void Direccion::setNumeroCalle(int numeroCalle){_numeroCalle = numeroCalle;}
void Direccion::setPiso(const char*  piso){strcpy(_piso, piso);}
void Direccion::setEntrecalle1(const char* entrecalle1){strcpy(_entrecalle1, entrecalle1);}
void Direccion::setEntrecalle2(const char* entrecalle2){strcpy(_entrecalle2, entrecalle2);}
void Direccion::setProvincia(const char* provincia){strcpy(_provincia ,provincia);}
void Direccion::setComentario(const char* comentario){strcpy(_comentario, comentario);}

///GETTERS

const char* Direccion::getCodPostal(){return _codPostal;}
const char* Direccion::getLocalidad(){return _localidad;}
const char* Direccion::getCalle(){return _calle;}
int Direccion::getNumeroCalle(){return _numeroCalle;}
const char* Direccion::getPiso(){return _piso;}
const char* Direccion::getEntrecalle1(){return _entrecalle1;}
const char* Direccion::getEntrecalle2(){return _entrecalle2;}
const char* Direccion::getProvincia(){return _provincia;}
const char* Direccion::getComentario(){return _comentario;}

void Direccion::Cargar(){
    cout << "CALLE: ";
    cargarCadena(_calle,29);
    cout << "NUMERO DE CALLE: ";
    cin >> _numeroCalle;
    cout << "LOCALIDAD: ";
    cargarCadena(_localidad,29);
    cout << "ENTRE CALLE 1: ";
    cargarCadena(_entrecalle1,29);
    cout << "ENTRE CALLE 2: ";
    cargarCadena(_entrecalle2,29);
    cout << "CODIGO POSTAL: ";
    cargarCadena(_codPostal,29);
    cout << "PISO: ";
    cargarCadena(_piso,4);
    cout << "PROVINCIA: ";
    cargarCadena(_provincia,29);
    cout << "COMENTARIO: ";
    cargarCadena(_comentario,79);
}

void Direccion::Mostrar(){
    cout << "CALLE: " << _calle << endl;
    cout << "NUMERO DE CALLE: " << _numeroCalle << endl;
    cout << "LOCALIDAD: " << _localidad << endl;
    cout << "ENTRE CALLE 1: " << _entrecalle1 << endl;
    cout << "ENTRE CALLE 2: " << _entrecalle2 << endl;
    cout << "CODIGO POSTAL: " << _codPostal << endl;
    cout << "PISO: " << _piso << endl;
    cout << "PROVINCIA: " << _provincia << endl;
    cout << "COMENTARIO: " << _comentario << endl;
}
Direccion::Direccion(){
    setCalle("");
    setNumeroCalle(0);
    setLocalidad("");
    setEntrecalle1("");
    setEntrecalle2("");
    setCodPostal("");
    setPiso("");
    setProvincia("");
    setComentario("");
}