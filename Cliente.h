/*
 * Proyecto Vivero - Clase Cliente
 * Autor: Raúl Enrique Torres Ledesma
 * Matrícula: A01710040
 * Fecha: 4 de Junio 2026
 * * Esta clase define al objeto de tipo Cliente que interactúa con el vivero.
 * Contiene los atributos de identificación y control financiero necesarios
 * para realizar operaciones de compra.
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <iostream>
#include <string>

using namespace std;

// Declaración de la clase Cliente
class Cliente {
private:
    // Atributos privados de instancia
    string nombreCliente;
    double presupuestoCliente;

public:
    // --- Declaraciones de los métodos públicos ---
    Cliente();
    Cliente(string nombreIn, double presupuestoIn);
    
    string getNombre() const;
    bool comprar(double costoCompra);
    void mostrar();
};

/**
 * Constructor por defecto.
 * * Inicializa un cliente con valores base o genéricos cuando no se 
 * proporcionan datos iniciales.
 * * @param Ninguno
 * @return Objeto Cliente inicializado por defecto
 */
Cliente::Cliente() {
    nombreCliente = "Sin Nombre";
    presupuestoCliente = 0.0;
}

/**
 * Constructor con parámetros.
 * * Asigna el nombre y el presupuesto inicial especificados al crear el objeto.
 * * @param string nombreIn: Nombre completo del cliente.
 * @param double presupuestoIn: Dinero disponible para realizar compras.
 * @return Objeto Cliente parametrizado
 */
Cliente::Cliente(string nombreIn, double presupuestoIn) {
    nombreCliente = nombreIn;
    presupuestoCliente = presupuestoIn;
}

/**
 * Método getter para el atributo nombreCliente.
 * * Permite a clases externas consultar de forma segura el nombre del cliente.
 * * @param Ninguno
 * @return string: El nombre almacenado del cliente.
 */
string Cliente::getNombre() const {
    return nombreCliente;
}

/**
 * Simula y procesa la transacción de una compra.
 * * Compara el saldo disponible del cliente contra el costo del artículo.
 * Si es suficiente, efectúa la resta y autoriza la transacción.
 * * @param double costoCompra: El monto total a pagar por el producto.
 * @return bool: true si el cliente cuenta con saldo suficiente, false en caso contrario.
 */
bool Cliente::comprar(double costoCompra) {
    if (presupuestoCliente >= costoCompra) {
        presupuestoCliente = presupuestoCliente - costoCompra;
        return true;
    }
    return false;
}

/**
 * Convierte e imprime los atributos del Cliente en consola.
 * * Muestra el nombre del cliente y su saldo actual de manera formateada.
 * * @param Ninguno
 * @return void
 */
void Cliente::mostrar() {
    cout << "Cliente: " << nombreCliente << " | Saldo: $" << presupuestoCliente << endl;
}

#endif // CLIENTE_H_
