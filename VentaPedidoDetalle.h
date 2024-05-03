#pragma once    

class VentaPedidoDetalle {

    private:
    int _nroFactura, _nroArticulo, _cantidad;
    float _precio;
    bool _estado;

    public:
    VentaPedidoDetalle();
    //SETTERS
    void setNroFactura (int nroFactura);
    void setNroArticulo (int nroArticulo);
    void setCantidad (int cantidad);
    void setPrecio (float precio);
    void setEstado (bool estado);

    //GETTER
    int getNroFactura ();
    int getNroArticulo ();
    int getCantidad ();
    float getPrecio ();
    bool getEstado();
};