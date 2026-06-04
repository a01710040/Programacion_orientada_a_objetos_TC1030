/*
 * Proyecto Vivero - Jerarquía de Productos
 * Autor: Raúl Enrique Torres Ledesma
 * Matrícula: A01710040
 * Fecha: 4 de Junio 2026
 * * Este archivo define la estructura jerárquica de los artículos del vivero.
 * Cuenta con la clase base abstracta 'Producto' y sus clases derivadas
 * 'Planta' y 'Maceta', las cuales implementan el comportamiento polimórfico.
 */

#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_

#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// CLASE BASE ABSTRACTA
// ============================================================================
class Producto {
protected:
    // Atributos protegidos para que las clases hijas puedan acceder a ellos
    string nombreProducto;
    double precioProducto;

public:
    Producto();
    Producto(string nombreIn, double precioIn);

    // Destructor virtual: Vital para liberar memoria correctamente en Polimorfismo
    virtual ~Producto() {}

    string getNombre() const;
    double getPrecio() const;
    void setPrecio(double nuevoPrecio);

    // MÉTODO VIRTUAL PURO (= 0): Convierte a Producto en una clase abstracta
    virtual void mostrar() = 0;
};

// ============================================================================
// CLASE DERIVADA: PLANTA (Hereda de Producto)
// ============================================================================
class Planta : public Producto {
private:
    int stockDisponible;

public:
    Planta();
    Planta(string nombreIn, double precioIn, int stockIn);

    int getStock() const;
    void actualizarStock(int cantidad);
    
    // Declaración con 'override' para asegurar la sobrescritura válida
    void mostrar() override;
};

// ============================================================================
// CLASE DERIVADA: MACETA (Hereda de Producto)
// ============================================================================
class Maceta : public Producto {
private:
    string materialMaceta;
    string colorMaceta;
    bool esColgante;

public:
    Maceta();
    Maceta(string nombreIn, string materialIn, string colorIn, double precioIn, bool colganteIn);

    // Declaración con 'override' para asegurar la sobrescritura válida
    void mostrar() override;
};


// ============================================================================
// IMPLEMENTACIONES DE MÉTODOS DE LA CLASE PRODUCTO
// ============================================================================

/**
 * Constructor por defecto de Producto.
 */
Producto::Producto() {
    nombreProducto = "Sin Nombre";
    precioProducto = 0.0;
}

/**
 * Constructor parametrizado de Producto.
 */
Producto::Producto(string nombreIn, double precioIn) {
    nombreProducto = nombreIn;
    precioProducto = precioIn;
}

/**
 * Getter para el nombre del producto.
 * @return string: Nombre del artículo.
 */
string Producto::getNombre() const { return nombreProducto; }

/**
 * Getter para el precio del producto.
 * @return double: Precio del artículo.
 */
double Producto::getPrecio() const { return precioProducto; }

/**
 * Setter para actualizar el precio de venta.
 * Validará que el precio introducido sea un valor positivo.
 */
void Producto::setPrecio(double nuevoPrecio) {
    if (nuevoPrecio >= 0) precioProducto = nuevoPrecio;
}


// ============================================================================
// IMPLEMENTACIONES DE MÉTODOS DE LA CLASE PLANTA
// ============================================================================

/**
 * Constructor por defecto de Planta. 
 * Invoca implícitamente al constructor de la clase base.
 */
Planta::Planta() : Producto() { stockDisponible = 0; }

/**
 * Constructor parametrizado de Planta.
 * Pasa los atributos comunes a la clase padre mediante inicializadores.
 * * @param string nombreIn: Nombre de la planta.
 * @param double precioIn: Costo de venta.
 * @param int stockIn: Cantidad inicial en almacén.
 */
Planta::Planta(string nombreIn, double precioIn, int stockIn) : Producto(nombreIn, precioIn) {
    stockDisponible = stockIn;
}

/**
 * Obtiene las unidades en existencia de la planta.
 * @return int: Inventario disponible.
 */
int Planta::getStock() const { return stockDisponible; }

/**
 * Incrementa o reduce las existencias de la planta.
 * * @param int cantidad: El número de unidades a alterar (valores negativos restan).
 * @return void
 */
void Planta::actualizarStock(int cantidad) {
    if (stockDisponible + cantidad >= 0) {
        stockDisponible = stockDisponible + cantidad;
    } else {
        cout << "ERROR: No hay suficiente stock." << endl;
    }
}

/**
 * Sobrescribe el método mostrar de la clase abstracta.
 * Muestra detalladamente los datos de la planta incluyendo sus existencias.
 */
void Planta::mostrar() {
    cout << "Planta: " << nombreProducto << " | Precio: $" << precioProducto << " | Stock: " << stockDisponible << endl;
}


// ============================================================================
// IMPLEMENTACIONES DE MÉTODOS DE LA CLASE MACETA
// ============================================================================

/**
 * Constructor por defecto de Maceta.
 */
Maceta::Maceta() : Producto() {
    materialMaceta = "N/A"; colorMaceta = "N/A"; esColgante = false;
}

/**
 * Constructor parametrizado de Maceta.
 * * @param string nombreIn: Identificador o modelo.
 * @param string materialIn: Componente de fabricación (ej. Barro, Plástico).
 * @param string colorIn: Color visual.
 * @param double precioIn: Costo de adquisición.
 * @param bool colganteIn: Determina el modo de colocación.
 */
Maceta::Maceta(string nombreIn, string materialIn, string colorIn, double precioIn, bool colganteIn) 
    : Producto(nombreIn, precioIn) {
    materialMaceta = materialIn; colorMaceta = colorIn; esColgante = colganteIn;
}

/**
 * Sobrescribe el método mostrar de la clase abstracta.
 * Muestra las especificaciones físicas particulares de la maceta y su precio.
 */
void Maceta::mostrar() {
    string tipo = esColgante ? "Si" : "No";
    cout << "Maceta: " << nombreProducto << " | Mat: " << materialMaceta << " | Colgante: " << tipo << " | Precio: $" << precioProducto << endl;
}

#endif // PRODUCTOS_H_
