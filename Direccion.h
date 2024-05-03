#ifndef DIRECCION_H
#define DIRECCION_H
#pragma once
#include<cstring>

class Direccion{

private:

char _codPostal[6];
char _localidad[30];
char _calle[30];
int _numeroCalle;
char _piso[5];
char _entrecalle1[30];
char _entrecalle2[30];
char _provincia[30];
char _comentario[80];

public:

void setCodPostal (const char* codPostal);
void setLocalidad (const char* localidad);
void setCalle (const char* calle);
void setNumeroCalle (int numeroCalle);
void setPiso (const char* piso);
void setEntrecalle1 (const char* entrecalle1);
void setEntrecalle2 (const char* entrecalle2);
void setProvincia (const char* provincia);
void setComentario (const char* comentario);

const char* getCodPostal();
const char* getLocalidad();
const char* getCalle();
int getNumeroCalle();
const char* getPiso();
const char* getEntrecalle1();
const char* getEntrecalle2();
const char* getProvincia();
const char* getComentario();

void Cargar();
void Mostrar();

Direccion();


};


#endif // DIRECCION_H