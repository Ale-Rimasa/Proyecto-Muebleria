#include <iostream>
#include <cstdio>
#include "Archivo.h"
#include "rlutil.h"
using namespace std;
//Cliente
ClienteArchivo::ClienteArchivo(const char*  _nombreArchivo){strcpy (nombreArchivo,_nombreArchivo);}

//GUARDA UN REGISTRO, AL FINAL DE TODOS LOS REGISTROS EXISTENTES.
bool ClienteArchivo::GrabarCliente(Cliente objCliente){
  bool pudoEscribir;
  FILE *p = fopen(nombreArchivo, "ab");                   
  if (p == nullptr){
  return false;
  }
  pudoEscribir = fwrite(&objCliente, sizeof(Cliente), 1, p);
  fclose(p);
  return pudoEscribir;
  }

  bool ClienteArchivo::GrabarCliente( Cliente objCliente, int posicion){ ///Metodo para la modificacion
  bool pudoEscribir;
  FILE *p = fopen(nombreArchivo, "rb+");                  
  if (p == nullptr){
  return false;
  }
  fseek(p,posicion * sizeof(Cliente), SEEK_SET);
  pudoEscribir = fwrite(&objCliente, sizeof(Cliente), 1, p);
  fclose(p);
  return pudoEscribir;

 }

 /*bool ClienteArchivo::GrabarCliente( Cliente objCliente, Direccion objdir){ ///Metodo para la modificacion
  bool pudoEscribir;
  FILE *p = fopen(nombreArchivo, "rb+");                  
  if (p == nullptr){
  return false;
  }
  fseek(p,objdir * sizeof(Cliente), SEEK_SET);
  pudoEscribir = fwrite(&objdir, sizeof(Cliente), 1, p);
  fclose(p);
  return pudoEscribir;

 }*/

  int ClienteArchivo::ContarRegistros(){
 FILE *p = fopen(nombreArchivo, "rb");
  if (p == nullptr){
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);
  return bytes / sizeof(Cliente);


 }

 Cliente ClienteArchivo::Leer(int pos){ ///este metodo nos permite leer un registro y nos lo devuelve, recibiendo como parametro la pos en la que se encuentra y un objeto del archivo
  Cliente objCliente;
  FILE *p = fopen(nombreArchivo, "rb");
  if(p == nullptr){
    //objCliente.setEstado(0);  //AGREGADO el estado
    return objCliente;
 }
 fseek(p,pos * sizeof (Cliente), SEEK_SET);
 fread(&objCliente, sizeof(Cliente),1,p);
 fclose(p);
 return objCliente;
}

int ClienteArchivo::BuscarNroCliente(int nroCliente){
     FILE *p = fopen(nombreArchivo, "rb");
  if (p == nullptr){
    return -1;
  }
  int i = 0;
  Cliente objCliente;
  while(fread(&objCliente, sizeof(Cliente), 1, p)){
    if(objCliente.getNroCliente() == nroCliente){
      fclose(p);
      return i;
    }
    i++;
  }
  fclose(p);
  return -1;
}

bool ClienteArchivo::sobreEscribirRegistro(Cliente objCliente, int pos){
FILE *p;
    p=fopen(nombreArchivo,"rb+");
    if(p==nullptr){
        return false;
        }
    fseek(p,sizeof objCliente*pos,0);
    bool escribio=fwrite(&objCliente,sizeof objCliente,1,p);
    fclose(p);
    return escribio;

}
/****************************************************************************************/
//VENTA PEDIDO
VentaPedidoArchivo::VentaPedidoArchivo(const char*  _nombreArchivo){strcpy (nombreArchivo,_nombreArchivo);}
//GUARDA UN REGISTRO, AL FINAL DE TODOS LOS REGISTROS EXISTENTES.
bool VentaPedidoArchivo::GrabarVentaPedido(VentaPedido objVentaPedido){
  bool pudoEscribir;
  FILE *p = fopen(nombreArchivo, "ab");                   
  if (p == nullptr){
  return false;
  }
  pudoEscribir = fwrite(&objVentaPedido, sizeof(VentaPedido), 1, p);
  fclose(p);
  return pudoEscribir;
  }

bool VentaPedidoArchivo::GrabarVentaPedido( VentaPedido objVentaPedido, int posicion){ ///Metodo para la modificacion
  bool pudoEscribir;
  FILE *p = fopen(nombreArchivo, "rb+");                  
  if (p == nullptr){
  return false;
  }
  fseek(p,posicion * sizeof(VentaPedido), SEEK_SET);
  pudoEscribir = fwrite(&objVentaPedido, sizeof(VentaPedido), 1, p);
  fclose(p);
  return pudoEscribir;

 }

int VentaPedidoArchivo::ContarRegistros(){
 FILE *p = fopen(nombreArchivo, "rb");
  if (p == nullptr){
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);
  return bytes / sizeof(VentaPedido);
 }

VentaPedido VentaPedidoArchivo::Leer(int pos){ ///este metodo nos permite leer un registro y nos lo devuelve, recibiendo como parametro la pos en la que se encuentra y un objeto del archivo
  VentaPedido objVentaPedido;
  FILE *p = fopen(nombreArchivo, "rb");
  if(p == nullptr){
    //objCliente.setEstado(0);  //AGREGADO el estado
    return objVentaPedido;
 }
 fseek(p,pos * sizeof (VentaPedido), SEEK_SET);
 fread(&objVentaPedido, sizeof(VentaPedido),1,p);
 fclose(p);
 return objVentaPedido;
}

int VentaPedidoArchivo::BuscarNroFactura(int nroFactura){
     FILE *p = fopen(nombreArchivo, "rb");
  if (p == nullptr){
    return -1;
  }
  int i = 0;
  VentaPedido objVentaPedido;
  while(fread(&objVentaPedido, sizeof(VentaPedido), 1, p)){
    if(objVentaPedido.getNroFactura() == nroFactura){
      fclose(p);
      return i;
    }
    i++;
  }
  fclose(p);
  return -1;
}

bool VentaPedidoArchivo::sobreEscribirRegistro(VentaPedido objVentaPedido, int pos){
FILE *p;
    p=fopen(nombreArchivo,"rb+");
    if(p==nullptr){
        return false;
        }
    fseek(p,sizeof objVentaPedido*pos,0);
    bool escribio=fwrite(&objVentaPedido,sizeof objVentaPedido,1,p);
    fclose(p);
    return escribio;

}

/****************************************************************************************/
//VENTA PEDIDO DETALLE
VentaPedidoDetalleArchivo::VentaPedidoDetalleArchivo(const char*  _nombreArchivo){strcpy (nombreArchivo,_nombreArchivo);}

bool VentaPedidoDetalleArchivo::GrabarVentaPedidoDetalle(VentaPedidoDetalle objVentaPedidoDetalle){
    bool pudoEscribir;
  FILE *p = fopen(nombreArchivo, "ab");                   
  if (p == nullptr){
  return false;
  }
  pudoEscribir = fwrite(&objVentaPedidoDetalle, sizeof(VentaPedidoDetalle), 1, p);
  fclose(p);
  return pudoEscribir;
 }

int VentaPedidoDetalleArchivo::ContarRegistros(){
  FILE *p = fopen(nombreArchivo, "rb");
  if (p == nullptr){
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);
  return bytes / sizeof(VentaPedidoDetalle);
}

VentaPedidoDetalle VentaPedidoDetalleArchivo:: Leer(int pos){
    VentaPedidoDetalle objVentaPedidoDetalle;
  FILE *p = fopen(nombreArchivo, "rb");
  if(p == nullptr){
    //objCliente.setEstado(0);  //AGREGADO el estado
    return objVentaPedidoDetalle;
 }
 fseek(p,pos * sizeof (VentaPedidoDetalle), SEEK_SET);
 fread(&objVentaPedidoDetalle, sizeof(VentaPedidoDetalle),1,p);
 fclose(p);
 return objVentaPedidoDetalle;

}

int VentaPedidoDetalleArchivo::BuscarVentaPedidoDetalle(int nroFactura){
     FILE *p = fopen(nombreArchivo, "rb");
  if (p == nullptr){
    return -1;
  }
  int i = 0;
  VentaPedidoDetalle objVentaPedidoDetalle;
  while(fread(&objVentaPedidoDetalle, sizeof(VentaPedidoDetalle), 1, p)){
    if(objVentaPedidoDetalle.getNroFactura() == nroFactura){
      fclose(p);
      return i;
    }
    i++;
  }
  fclose(p);
  return -1;
}
/****************************************************************************************/
//ARTICULO

ArticuloArchivo::ArticuloArchivo(const char* _nombreArchivo){strcpy(nombreArchivo,_nombreArchivo);}

bool ArticuloArchivo::GrabarArticulo(Articulo objArticulo){
  bool pudoEscribir;
  FILE *p = fopen(nombreArchivo, "ab");                   
  if (p == nullptr){
  return false;
  }
  pudoEscribir = fwrite(&objArticulo, sizeof(Articulo), 1, p);
  fclose(p);
  return pudoEscribir;
}

bool ArticuloArchivo::GrabarArticulo(Articulo objArticulo, int posicion){
  bool pudoEscribir;
  FILE *p = fopen(nombreArchivo, "rb+");                  
  if (p == nullptr){
  return false;
  }
  fseek(p,posicion * sizeof(Articulo), SEEK_SET);
  pudoEscribir = fwrite(&objArticulo, sizeof(Articulo), 1, p);
  fclose(p);
  return pudoEscribir;
}

int ArticuloArchivo::ContarRegistros(){
    FILE *p = fopen(nombreArchivo, "rb");
  if (p == nullptr){
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);
  return bytes / sizeof(Articulo);
 }

Articulo ArticuloArchivo::Leer(int pos){
 Articulo objArticulo;
  FILE *p = fopen(nombreArchivo, "rb");
  if(p == nullptr){
    //objCliente.setEstado(0);  //AGREGADO el estado
    return objArticulo;
 }
 fseek(p,pos * sizeof (Articulo), SEEK_SET);
 fread(&objArticulo, sizeof(Articulo),1,p);
 fclose(p);
 return objArticulo;
}

int ArticuloArchivo::BuscarNroArticulo(int nroArticulo){
    FILE *p = fopen(nombreArchivo, "rb");
  if (p == nullptr){
    return -1;
  }
  int i = 0;
  Articulo objArticulo;
  while(fread(&objArticulo, sizeof(Articulo), 1, p)){
    if(objArticulo.getNroArticulo() == nroArticulo){
      fclose(p);
      return i;
    }
    i++;
  }
  fclose(p);
  return -1;
}

bool ArticuloArchivo::sobreEscribirRegistro(Articulo objArticulo, int pos){
FILE *p;
    p=fopen(nombreArchivo,"rb+");
    if(p==nullptr){
        return false;
        }
    fseek(p,sizeof objArticulo*pos,0);
    bool escribio=fwrite(&objArticulo,sizeof objArticulo,1,p);
    fclose(p);
    return escribio;

}