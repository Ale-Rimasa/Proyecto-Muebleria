#ifndef CLIENTE_H
#define CLIENTE_H
#pragma once
#include "Direccion.h"

class Cliente{
    private:
    int _nroCliente;
    char _nombre[30], _apellido[30];
    char _telefono[15], _mail[100], _dni[12];
    char _localidad[30];
    char _direccion[100];
    //Direccion _direccion;
    bool _eliminado;
    bool _estado;

    public:
    Cliente();
    //Cliente(int nroCliente,const std::string& nombre, const std::string& apellido, const std::string& telefono, const std::string& mail, const std::string& dni ); //Direccion direccion

    ///SETTERS
        void setNroCliente(int nroCliente);
        void setNombre(const char * nombre);
        void setApellido(const char * apellido);
        void setTelefono( const char * telefono);
        void setMail(const char * mail);
        void setDni(const char * dni);
        void setLocalidad (const char* localidad);
        void setDireccion (const char* direccion);
        //void setDireccion(Direccion direccion);
        void setEliminado(bool eliminado);
        void setEstado(bool estado);

    ///GETTERS
        int getNroCliente();
        const char * getNombre();
        const char * getApellido();
        const char * getTelefono();
        const char * getMail();
        const char * getDni();
        const char* getLocalidad();
        const char* getDireccion();
        //Direccion& getDireccion();
        bool getEliminado();
        bool getEstado();
};

#endif // CLIENTE_H