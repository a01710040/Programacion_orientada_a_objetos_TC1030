/*
 * Proyecto Vivero - Clase Cliente
 * Autor: Raúl Enrique Torres Ledesma | Matrícula: A01710040
 * * Esta clase define al objeto de tipo Cliente que interactúa con el vivero.
 * Contiene los atributos de identificación y control financiero necesarios
 * para realizar operaciones de compra.
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
    string nombreCliente;
    double presupuestoCliente;

public:
    Cliente();
    Cliente(string nombreIn, double presupuestoIn);
    
    string getNombre() const;
    bool comprar(double costoCompra);
    void mostrar();
};

/**
 * Constructor por defecto.
 * @param Ninguno
 * @return Objeto Cliente inicializado por defecto.
 */
Cliente::Cliente() {
    nombreCliente = "Sin Nombre";
    presupuestoCliente = 0.0;
}

/**
 * Constructor parametrizado.
 * @param string nombreIn: Nombre completo del cliente.
 * @param double presupuestoIn: Dinero disponible.
 * @return Objeto Cliente parametrizado.
 */
Cliente::Cliente(string nombreIn, double presupuestoIn) {
    nombreCliente = nombreIn;
    presupuestoCliente = presupuestoIn;
}

/**
 * Getter para el atributo nombreCliente.
 * @param Ninguno
 * @return string: El nombre almacenado del cliente.
 */
string Cliente::getNombre() const {
    return nombreCliente;
}

/**
 * Procesa la compra restando saldo si es suficiente.
 * @param double costoCompra: El monto total a pagar.
 * @return bool: true si cuenta con saldo suficiente, false si no.
 */
bool Cliente::comprar(double costoCompra) {
    if (presupuestoCliente >= costoCompra) {
        presupuestoCliente = presupuestoCliente - costoCompra;
        return true;
    }
    return false;
}

/**
 * Imprime los atributos de Cliente de forma formateada.
 * @param Ninguno
 * @return void
 */
void Cliente::mostrar() {
    cout << "Cliente: " << nombreCliente 
         << " | Saldo: $" << presupuestoCliente << endl;
}

#endif // CLIENTE_H_
