#pragma once

class Articulo{

private:

int _nroArticulo, _stock;
char _descripcion[50];
bool _estado;

public:
Articulo();
///Setters
void setNroArticulo (int nroArticulo);
void setStock (int stock);
void setDescripcion (const char* descripcion);
void setEstado(bool estado);
///Getters
int getNroArticulo();
int getStock() ;
const char* getDescripcion() ;
bool getEstado();
};

