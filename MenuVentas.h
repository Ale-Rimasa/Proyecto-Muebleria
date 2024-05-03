#pragma once
#include "Manager.h"    ///Incluimos el h del manager para trabajar con el objeto en el menu

class MenuVentas{

    private:
    Manager objManagerVentaPedido;       ///Hacemos este atributo con el objeto para usarlo en el menu

    public:
    void MostrarMenuVentas();
};