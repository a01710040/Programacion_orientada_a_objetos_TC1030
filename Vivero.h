/*
 * Proyecto Vivero - Clase Gestora Vivero
 * Autor: Raúl Enrique Torres Ledesma
 * Matrícula: A01710040
 * Fecha: 4 de Junio 2026
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

// Tamaño máximo delimitador para las colecciones en memoria estática
const int MAX_INVENTARIO = 50;

class Vivero {
private:
    // --- POLIMORFISMO EN ACCIÓN ---
    // Un único arreglo de punteros a la clase abstracta Padre para guardar Plantas y Macetas juntos.
    Producto* Inventario[MAX_INVENTARIO];
    Cliente* ListaClientes[MAX_INVENTARIO];

    // Variables contadoras para controlar los índices ocupados
    int contadorProductos;
    int contadorClientes;

public:
    Vivero();
    
    void crearPlanta(string nombre, double precio, int stock);
    void crearMaceta(string nombre, string material, string color, double precio, bool esColgante);
    void registrarCliente(Cliente* c);

    void mostrarInventario();
    void realizarVenta(int indiceCliente, int indiceProducto);
};

/**
 * Constructor por defecto.
 * Inicializa un vivero nuevo controlando que sus registros comiencen en cero.
 */
Vivero::Vivero() {
    cout << ">> Vivero creado (Vacio)." << endl;
    contadorProductos = 0;
    contadorClientes = 0;
}

/**
 * Genera de forma dinámica una nueva Planta en el inventario polimórfico.
 * * @param string nombre: Nombre de la planta.
 * @param double precio: Costo unitario.
 * @param int stock: Cantidad de piezas.
 * @return void
 */
void Vivero::crearPlanta(string nombre, double precio, int stock) {
    if (contadorProductos < MAX_INVENTARIO) {
        // Enlaza un nuevo objeto derivado mediante memoria dinámica
        Inventario[contadorProductos] = new Planta(nombre, precio, stock);
        contadorProductos++;
        cout << ">> Planta agregada exitosamente al inventario general." << endl;
    } else {
        cout << "Error: Inventario lleno." << endl;
    }
}

/**
 * Genera de forma dinámica una nueva Maceta en el inventario polimórfico.
 * * @param string nombre: Identificador del modelo.
 * @param string material: Tipo de material.
 * @param string color: Color físico.
 * @param double precio: Costo unitario.
 * @param bool esColgante: Si se cuelga o no.
 * @return void
 */
void Vivero::crearMaceta(string nombre, string material, string color, double precio, bool esColgante) {
    if (contadorProductos < MAX_INVENTARIO) {
        // Enlaza un nuevo objeto derivado mediante memoria dinámica
        Inventario[contadorProductos] = new Maceta(nombre, material, color, precio, esColgante);
        contadorProductos++;
        cout << ">> Maceta agregada exitosamente al inventario general." << endl;
    } else {
        cout << "Error: Inventario lleno." << endl;
    }
}

/**
 * Registra un cliente apuntando a su dirección de memoria dentro del arreglo.
 * * @param Cliente* c: Puntero al objeto Cliente creado en el main.
 * @return void
 */
void Vivero::registrarCliente(Cliente* c) {
    if (contadorClientes < MAX_INVENTARIO) {
        ListaClientes[contadorClientes] = c;
        contadorClientes++;
        cout << ">> Cliente registrado exitosamente." << endl;
    } else {
        cout << "Error: Lista de clientes llena." << endl;
    }
}

/**
 * Recorre las colecciones imprimiendo de manera polimórfica los datos.
 * * El bucle manda a llamar al método virtual 'mostrar()'. C++ decide en tiempo
 * de ejecución si ejecutará el código propio de Planta o el de Maceta.
 * * @param Ninguno
 * @return void
 */
void Vivero::mostrarInventario() {
    cout << "\n===== REPORTE VIVERO =====" << endl;
    
    cout << "--- Inventario de Productos (" << contadorProductos << ") ---" << endl;
    for (int i = 0; i < contadorProductos; i++) {
        cout << i << ". "; 
        // Llamada Polimórfica Dinámica
        Inventario[i]->mostrar(); 
    }

    cout << "--- Clientes (" << contadorClientes << ") ---" << endl;
    for (int i = 0; i < contadorClientes; i++) {
        cout << i << ". ";
        ListaClientes[i]->mostrar(); 
    }
    cout << "==========================" << endl;
}

/**
 * Ejecuta el proceso unificado de venta usando Castings Dinámicos.
 * * El método identifica el tipo real del objeto apuntado mediante 'dynamic_cast'.
 * Si es una planta, altera su stock; si es una maceta, remueve el puntero del arreglo.
 * * @param int indiceCliente: Ubicación del comprador en la lista.
 * @param int indiceProducto: Ubicación del producto en el inventario.
 * @return void
 */
void Vivero::realizarVenta(int indiceCliente, int indiceProducto) {
    // Verificación previa de límites para la seguridad del software
    if (indiceCliente >= 0 && indiceCliente < contadorClientes && 
        indiceProducto >= 0 && indiceProducto < contadorProductos) {
        
        Cliente* elCliente = ListaClientes[indiceCliente];
        Producto* elProducto = Inventario[indiceProducto];

        cout << "\nIntento de venta: " << elCliente->getNombre() << " quiere " << elProducto->getNombre() << endl;

        // DOWNCASTING: Intentamos convertir el puntero genérico a sus subtipos reales
        Planta* esPlanta = dynamic_cast<Planta*>(elProducto);
        Maceta* esMaceta = dynamic_cast<Maceta*>(elProducto);

        // Caso 1: El producto seleccionado resultó ser de tipo Planta
        if (esPlanta != nullptr) {
            if (esPlanta->getStock() > 0) {
                if (elCliente->comprar(esPlanta->getPrecio())) {
                    esPlanta->actualizarStock(-1); 
                    cout << ">> Venta Exitosa! (Stock actualizado)" << endl;
                } else {
                    cout << ">> Saldo insuficiente." << endl;
                }
            } else {
                cout << ">> No hay stock disponible." << endl;
            }
        } 
        // Caso 2: El producto seleccionado resultó ser de tipo Maceta
        else if (esMaceta != nullptr) {
            if (elCliente->comprar(esMaceta->getPrecio())) {
                cout << ">> Venta Exitosa! (Maceta retirada del inventario)" << endl;
                
                // Eliminación física del puntero recorriendo las celdas posteriores
                for (int i = indiceProducto; i < contadorProductos - 1; i++) {
                    Inventario[i] = Inventario[i + 1];
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
