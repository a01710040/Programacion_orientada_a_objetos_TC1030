/*
 * Proyecto Vivero - Sistema de Control y Menú Principal
 * Autor: Raúl Enrique Torres Ledesma | Matrícula: A01710040
 * * Este programa interactivo simula la gestión de un Vivero.
 * Controla un menú por consola, captura entradas de texto y numéricas,
 * e incluye indicaciones explícitas en los mensajes en pantalla para guiar
 * al usuario sobre el formato de datos requerido (evitando el uso de espacios
 * y acentos que desincronizan el búfer de entrada de 'cin').
 */

#include <iostream>
#include "Vivero.h"

using namespace std;

int main() {
    Vivero miVivero;
    int opcion = -1;

    string nombreTemp, materialTemp, colorTemp;
    double precioTemp, presupuestoTemp;
    int stockTemp;
    bool esColganteTemp;
    int indiceCliente, indiceProducto;

    // Datos iniciales precargados seguros
    Cliente* clienteInicial = new Cliente("Ana_Martinez", 500.0);
    miVivero.registrarCliente(clienteInicial);
    
    miVivero.crearPlanta("Rosa_Roja", 150.0, 3);
    miVivero.crearMaceta("Barro", "Arcilla", "Cafe", 40.0, false);
    
    while (opcion != 0) {
        cout << "\n=========================================" << endl;
        cout << "         MENU PRINCIPAL VIVERO           " << endl;
        cout << "=========================================" << endl;
        cout << "1. Crear nueva Planta" << endl;
        cout << "2. Crear nueva Maceta" << endl;
        cout << "3. Registrar Cliente" << endl;
        cout << "4. Mostrar Inventario Completo" << endl;
        cout << "5. Realizar Venta" << endl;
        cout << "0. Salir" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una opcion [Ingrese el numero]: ";
        
        if (!(cin >> opcion)) {
            cout << "\n>> ERROR: Entrada invalida. Reintentando." << endl;
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            continue; 
        }

        if (opcion == 1) {
            cout << "\n--- ALTA DE NUEVA PLANTA ---" << endl;
            cout << "-> Nombre [SIN ESPACIOS, use '_'. Ej: Palma_Areca]: "; 
            cin >> nombreTemp;
            cout << "-> Precio [SOLO NUMEROS. Ej: 185.50]: "; 
            cin >> precioTemp;
            cout << "-> Stock inicial [ENTEROS POSITIVOS. Ej: 5]: "; 
            cin >> stockTemp;
            miVivero.crearPlanta(nombreTemp, precioTemp, stockTemp);
        }
        else if (opcion == 2) {
            cout << "\n--- ALTA DE NUEVA MACETA ---" << endl;
            cout << "-> Nombre [SIN ESPACIOS, use '_'. Ej: Maceta_Gde]: "; 
            cin >> nombreTemp;
            cout << "-> Material [SIN ESPACIOS. Ej: Plastico]: "; 
            cin >> materialTemp;
            cout << "-> Color [SIN ESPACIOS. Ej: Negro]: "; 
            cin >> colorTemp;
            cout << "-> Precio [SOLO NUMEROS. Ej: 65.00]: "; 
            cin >> precioTemp;
            cout << "-> Es colgante? [INGRESE 1 para SI o 0 para NO]: "; 
            cin >> esColganteTemp;
            miVivero.crearMaceta(nombreTemp, materialTemp, colorTemp, 
                                 precioTemp, esColganteTemp);
        }
        else if (opcion == 3) {
            cout << "\n--- REGISTRO DE NUEVO CLIENTE ---" << endl;
            cout << "-> Nombre [SIN ESPACIOS, use '_'. Ej: Juan_Perez]: "; 
            cin >> nombreTemp;
            cout << "-> Presupuesto disponible [NUMEROS. Ej: 1200.00]: "; 
            cin >> presupuestoTemp;
            
            Cliente* nuevoCliente = new Cliente(nombreTemp, presupuestoTemp);
            miVivero.registrarCliente(nuevoCliente);
        }
        else if (opcion == 4) {
            miVivero.mostrarInventario();
        }
        else if (opcion == 5) {
            miVivero.mostrarInventario();
            cout << "\n--- PROCESAR ORDEN DE VENTA ---" << endl;
            cout << "-> Indice Cliente [NUMERO ENTERO]: "; 
            cin >> indiceCliente;
            cout << "-> Indice Producto [NUMERO ENTERO]: "; 
            cin >> indiceProducto;
            miVivero.realizarVenta(indiceCliente, indiceProducto);
        }
        else if (opcion == 0) {
            cout << "\n>> Cerrando el sistema..." << endl;
        }
        else {
            cout << "\n>> ERROR: Opcion invalida." << endl;
        }
    } 

    return 0;
}
