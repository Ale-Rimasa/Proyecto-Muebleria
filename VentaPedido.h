#ifndef VENTAPEDIDO_H
#define VENTAPEDIDO_H

#pragma once
#include "Fecha.h"

class VentaPedido
{
private:
    int _nroFactura, _nroCliente, _formaPago;
    Fecha _fecha;
    char _comentarios[100];
    float _montoTotal, _senia;
    bool _estadoEntrega;
    bool _eliminado;

public:
    VentaPedido();

    /// SETTERS
    void setNroFactura(int nroFactura);
    void setNroCliente(int nroCliente);
    void setFormaPago(int formaPago);
    void setFecha(Fecha fecha);
    void setComentario(const char *comentario);
    void setMontoTotal(float montoTotal);
    void setEstadoEntrega(bool estadoEntrega);
    void setSenia(float senia);
    void setEliminado(bool eliminado);

    /// GETTERS
    int getNroFactura();
    int getNroCliente();
    int getFormaPago();
    Fecha getFecha();
    const char *getComentario();
    float getMontoTotal();
    bool getEstadoEntrega();
    float getSenia();
    bool getEliminado();

    bool operator==(const VentaPedido &p1);
};

#endif // VENTAPEDIDO_H