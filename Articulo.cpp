#include "Articulo.h"
#include "CargarCadena.h"
#include <cstring>
#include <iostream>
using namespace std;

///setters

void Articulo::setNroArticulo(int nroArticulo){_nroArticulo= nroArticulo;}
void Articulo::setStock(int stock){_stock= stock;}
void Articulo::setDescripcion(const char* descripcion){strcpy(_descripcion, descripcion);}
void Articulo::setEstado(bool estado){_estado= estado;}
///Getters

int Articulo::getNroArticulo() {return _nroArticulo;}
int Articulo::getStock() {return _stock; }
const char* Articulo::getDescripcion() {return _descripcion;}
bool Articulo::getEstado(){return _estado;}

Articulo::Articulo(){
    setNroArticulo(0);
    setStock(0);
    setDescripcion("");
    _estado= false;
}

