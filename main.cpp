/*
 * Proyecto Vivero - Sistema de Control y Menú Principal
 * Autor: Raúl Torres
 * Matrícula: A01710040
 * Fecha: 4 de Junio 2026
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
    // Instancia de la clase gestora
    Vivero miVivero;
    int opcion = -1;

    // Variables temporales utilizadas para recopilar capturas del usuario
    string nombreTemp, materialTemp, colorTemp;
    double precioTemp, presupuestoTemp;
    int stockTemp;
    bool esColganteTemp;
    int indiceCliente, indiceProducto;

    // PRECARGA DE DATOS SEGUROS: Datos iniciales formateados correctamente
    Cliente* clienteInicial = new Cliente("Ana_Martinez", 500.0);
    miVivero.registrarCliente(clienteInicial);
    
    miVivero.crearPlanta("Rosa_Roja", 150.0, 3);
    miVivero.crearMaceta("Barro_Clasico", "Arcilla", "Cafe", 40.0, false);
    
    // Bucle interactivo principal
    while (opcion != 0) {
        cout << "\n=========================================" << endl;
        cout << "         MENU PRINCIPAL VIVERO           " << endl;
        cout << "=========================================" << endl;
        cout << "1. Crear nueva Planta" << endl;
        cout << "2. Crear nueva Maceta" << endl;
        cout << "3. Registrar Cliente" << endl;
        cout << "4. Mostrar Inventario Completo" << endl;
        cout << "5. Realizar Venta Polimorfica" << endl;
        cout << "0. Salir" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una opcion [Ingrese solo el numero]: ";
        
        // Mecanismo de seguridad contra ingresos accidentales de texto en el menú
        if (!(cin >> opcion)) {
            cout << "\n>> ERROR: Entrada invalida. Ingrese unicamente un digito." << endl;
            cin.clear();             // Limpia los flags de error del flujo cin
            cin.ignore(10000, '\n'); // Descarta caracteres residuales dañinos
            continue; 
        }

        // OPCIÓN 1: CREAR PLANTA
        if (opcion == 1) {
            cout << "\n--- ALTA DE NUEVA PLANTA ---" << endl;
            cout << "-> Nombre [SIN ESPACIOS NI ACENTOS, use '_'. Ej: Palma_Areca]: "; 
            cin >> nombreTemp;
            
            cout << "-> Precio [SOLO NUMEROS, use '.' para decimales. Ej: 185.50]: "; 
            cin >> precioTemp;
            
            cout << "-> Stock inicial [SOLO NUMEROS ENTEROS positivos. Ej: 5]: "; 
            cin >> stockTemp;
            
            miVivero.crearPlanta(nombreTemp, precioTemp, stockTemp);
        }
        // ====================================================================
        // OPCIÓN 2: CREAR MACETA
        // ====================================================================
        else if (opcion == 2) {
            cout << "\n--- ALTA DE NUEVA MACETA ---" << endl;
            cout << "-> Nombre [SIN ESPACIOS NI ACENTOS, use '_'. Ej: Maceta_Colgante_Gde]: "; 
            cin >> nombreTemp;
            
            cout << "-> Material [SIN ESPACIOS NI ACENTOS. Ej: Plastico]: "; 
            cin >> materialTemp;
            
            cout << "-> Color [SIN ESPACIOS NI ACENTOS. Ej: Verde_Olivo]: "; 
            cin >> colorTemp;
            
            cout << "-> Precio [SOLO NUMEROS, use '.' para decimales. Ej: 65.00]: "; 
            cin >> precioTemp;
            
            cout << "-> Es colgante? [INGRESE EXCLUSIVAMENTE 1 para SI o 0 para NO]: "; 
            cin >> esColganteTemp;
            
            miVivero.crearMaceta(nombreTemp, materialTemp, colorTemp, precioTemp, esColganteTemp);
        }
        // OPCIÓN 3: REGISTRAR CLIENTE
        else if (opcion == 3) {
            cout << "\n--- REGISTRO DE NUEVO CLIENTE ---" << endl;
            cout << "-> Nombre [SIN ESPACIOS NI ACENTOS, use '_'. Ej: Juan_Perez]: "; 
            cin >> nombreTemp;
            
            cout << "-> Presupuesto disponible [SOLO NUMEROS, ej: 1200.00]: "; 
            cin >> presupuestoTemp;
            
            Cliente* nuevoCliente = new Cliente(nombreTemp, presupuestoTemp);
            miVivero.registrarCliente(nuevoCliente);
        }
        // OPCIÓN 4: MOSTRAR REPORTES
        else if (opcion == 4) {
            miVivero.mostrarInventario();
        }
        // OPCIÓN 5: REALIZAR VENTA (PROCESO POLIMÓRFICO)
        else if (opcion == 5) {
            // Se despliega el inventario para que el usuario observe los índices válidos
            miVivero.mostrarInventario();
            cout << "\n--- PROCESAR ORDEN DE VENTA ---" << endl;
            
            cout << "-> Indice del Cliente [INGRESE EL NUMERO ENTERO QUE APARECE A LA IZQUIERDA DE SU NOMBRE]: "; 
            cin >> indiceCliente;
            
            cout << "-> Indice del Producto [INGRESE EL NUMERO ENTERO QUE APARECE A LA IZQUIERDA DEL PRODUCTO]: "; 
            cin >> indiceProducto;
            
            miVivero.realizarVenta(indiceCliente, indiceProducto);
        }
        // OPCIÓN 0: SALIDA
        else if (opcion == 0) {
            cout << "\n>> Cerrando sesion de Vivero virtual. Saliendo del sistema..." << endl;
        }
        // MANEJO DE VALORES FUERA DEL RANGO DEL MENÚ
        else {
            cout << "\n>> ERROR: Opcion fuera de rango (0 a 5). Intente de nuevo." << endl;
        }
    } 

    return 0;
}
