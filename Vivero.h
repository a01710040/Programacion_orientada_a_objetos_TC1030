/*
 * Proyecto Vivero - Clase Gestora Vivero
 * Autor: Raúl Enrique Torres Ledesma | Matrícula: A01710040
 * * Esta clase funciona como la controladora principal del sistema (Manager Class).
 * Almacena colecciones de punteros a la clase base abstracta logrando
 * la aplicación directa de Polimorfismo Dinámico para la gestión de ventas e inventarios.
 */

#ifndef VIVERO_H_
#define VIVERO_H_

#include <iostream>
#include "Productos.h"
#include "Cliente.h"

using namespace std;

const int MAX_INVENTARIO = 50;

class Vivero {
private:
    Producto* inventario[MAX_INVENTARIO];
    Cliente* listaClientes[MAX_INVENTARIO];
    int contadorProductos;
    int contadorClientes;

public:
    Vivero();
    
    void crearPlanta(string nombre, double precio, int stock);
    void crearMaceta(string nombre, string material, string color, 
                     double precio, bool esColgante);
    void registrarCliente(Cliente* c);

    void mostrarInventario();
    void realizarVenta(int indiceCliente, int indiceProducto);
};

/**
 * Constructor por defecto.
 */
Vivero::Vivero() {
    cout << ">> Vivero creado (Vacio)." << endl;
    contadorProductos = 0;
    contadorClientes = 0;
}

/**
 * Genera dinámicamente una nueva Planta en el inventario polimórfico.
 * @param string nombre: Nombre de la planta.
 * @param double precio: Costo unitario.
 * @param int stock: Cantidad de piezas.
 * @return void
 */
void Vivero::crearPlanta(string nombre, double precio, int stock) {
    if (contadorProductos < MAX_INVENTARIO) {
        inventario[contadorProductos] = new Planta(nombre, precio, stock);
        contadorProductos++;
        cout << ">> Planta agregada exitosamente al inventario." << endl;
    } else {
        cout << "Error: Inventario lleno." << endl;
    }
}

/**
 * Genera dinámicamente una nueva Maceta en el inventario polimórfico.
 * @param string nombre: Nombre del modelo.
 * @param string material: Componente físico.
 * @param string color: Color visual.
 * @param double precio: Costo unitario.
 * @param bool esColgante: Condición de altura.
 * @return void
 */
void Vivero::crearMaceta(string nombre, string material, string color, 
                         double precio, bool esColgante) {
    if (contadorProductos < MAX_INVENTARIO) {
        inventario[contadorProductos] = 
            new Maceta(nombre, material, color, precio, esColgante);
        contadorProductos++;
        cout << ">> Maceta agregada exitosamente al inventario." << endl;
    } else {
        cout << "Error: Inventario lleno." << endl;
    }
}

/**
 * Registra un cliente guardando su puntero del Heap.
 * @param Cliente* c: Puntero al objeto Cliente.
 * @return void
 */
void Vivero::registrarCliente(Cliente* c) {
    if (contadorClientes < MAX_INVENTARIO) {
        listaClientes[contadorClientes] = c;
        contadorClientes++;
        cout << ">> Cliente registrado exitosamente." << endl;
    } else {
        cout << "Error: Lista de clientes llena." << endl;
    }
}

/**
 * Recorre las colecciones imprimiendo de manera polimórfica los datos.
 * @return void
 */
void Vivero::mostrarInventario() {
    cout << "\n===== REPORTE VIVERO =====" << endl;
    
    cout << "--- Inventario de Productos (" 
         << contadorProductos << ") ---" << endl;
    for (int i = 0; i < contadorProductos; i++) {
        cout << i << ". "; 
        inventario[i]->mostrar();
    }

    cout << "--- Clientes (" << contadorClientes << ") ---" << endl;
    for (int i = 0; i < contadorClientes; i++) {
        cout << i << ". ";
        listaClientes[i]->mostrar(); 
    }
    cout << "==========================" << endl;
}

/**
 * Realiza el proceso de venta polimórfica discriminando tipos por casting.
 * @param int indiceCliente: Ubicación del cliente.
 * @param int indiceProducto: Ubicación del artículo.
 * @return void
 */
void Vivero::realizarVenta(int indiceCliente, int indiceProducto) {
    if (indiceCliente >= 0 && indiceCliente < contadorClientes && 
        indiceProducto >= 0 && indiceProducto < contadorProductos) {
        
        Cliente* elCliente = listaClientes[indiceCliente];
        Producto* elProducto = inventario[indiceProducto];

        cout << "\nIntento de venta: " << elCliente->getNombre() 
             << " quiere " << elProducto->getNombre() << endl;

        Planta* esPlanta = dynamic_cast<Planta*>(elProducto);
        Maceta* esMaceta = dynamic_cast<Maceta*>(elProducto);

        if (esPlanta != nullptr) {
            if (esPlanta->getStock() > 0) {
                if (elCliente->comprar(esPlanta->getPrecio())) {
                    esPlanta->actualizarStock(-1); 
                    cout << ">> Venta Exitosa! (Stock modificado)" << endl;
                } else {
                    cout << ">> Saldo insuficiente." << endl;
                }
            } else {
                cout << ">> No hay stock disponible." << endl;
            }
        } 
        else if (esMaceta != nullptr) {
            if (elCliente->comprar(esMaceta->getPrecio())) {
                cout << ">> Venta Exitosa! (Maceta removida)" << endl;
                
                for (int i = indiceProducto; i < contadorProductos - 1; i++) {
                    inventario[i] = inventario[i + 1];
                }
                contadorProductos--;
            } else {
                cout << ">> Saldo insuficiente." << endl;
            }
        }
    } else {
        cout << ">> Error: Indices no validos." << endl;
    }
}

#endif // VIVERO_H_
