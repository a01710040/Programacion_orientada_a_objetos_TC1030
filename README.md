# TC1030 Proyecto: Sistema de Gestión de Vivero Polimórfico

Este proyecto implementa un sistema básico de gestión de inventario y clientes para un vivero utilizando C++, desarrollado para la materia de **Pensamiento Orientado a Objetos (TC1030)**.

***

## 1. Contexto y Diseño POO Avanzado

El sistema tiene como objetivo principal administrar el inventario del vivero y la lista de compradores, permitiendo simular transacciones de venta bajo reglas de negocio particulares para cada tipo de artículo. 

Para lograr esto, la estructura de clases implementa los siguientes pilares de POO 

* **Clase Abstracta:** La clase **`Producto`** define la interfaz base del sistema. Al contener un método virtual puro (`virtual void mostrar() = 0;`), se vuelve abstracta, impidiendo la creación de productos genéricos y obligando a las clases hijas a definir su propio comportamiento.
* **Herencia:** Las clases **`Planta`** y **`Maceta`** heredan los atributos protegidos (`nombreProducto`, `precioProducto`) y métodos de la clase base **`Producto`**, especializándose con atributos propios (existencias, materiales, etc.).
* **Polimorfismo:** La clase gestora **`Vivero`** no utiliza arreglos separados. En su lugar, implementa un único **Inventario Polimórfico** de apuntadores a la clase base: `Producto* Inventario[MAX_INVENTARIO]`. Esto permite almacenar plantas y macetas juntas.
* **Encapsulamiento:** Se utilizan atributos privados (`private`) o protegidos (`protected`) y métodos públicos (`Getters`/`Setters`) para controlar el acceso y la modificación de datos.

---

## 2. Estructura y Estándares de Código

### A. Archivos del Proyecto

| Archivo | Contenido e Implementación POO |
| :--- | :--- |
| **`Productos.h`** | Contiene la jerarquía completa: Clase base abstracta `Producto` (con destructor virtual) y clases derivadas `Planta` y `Maceta` con sobrescritura (`override`). |
| **`Cliente.h`** | Clase independiente `Cliente`. Administra la identidad y el presupuesto financiero del comprador. |
| **`Vivero.h`** | Clase Controladora (Manager Class). Almacena las colecciones polimórficas mediante arreglos de apuntadores y ejecuta la lógica de ventas automatizada. |
| **`main.cpp`** | Punto de entrada del programa. Contiene el menú interactivo, la precarga de datos en la memoria y las interfaces de captura validadas. |

### B. Convenciones de Estilo y Documentación

* **Nomenclatura:** Uso estricto de **`PascalCase`** para la definición de clases y **`camelCase`** para nombres de funciones, variables y atributos.
* **Legibilidad:** Restricción estricta de **máximo 80 caracteres por línea** en el código fuente para facilitar su lectura y revisión en cualquier editor.
* **Documentación Profesional:** Todo el proyecto se encuentra documentado bajo el estándar **Javadoc/Doxygen** (`/** ... */`), detallando explícitamente el propósito de cada función, sus parámetros (`@param`) y sus valores de retorno (`@return`).

---

## 3. Funcionalidad y Alcance del Sistema

### ¿Para qué sirve?

* **Inventario :** Permite dar de alta y listar en un solo reporte general tanto Plantas como Macetas.
* **Gestión de Clientes:** Registra usuarios y lleva el control en tiempo real de sus fondos disponibles.
* **Simulación de Ventas Inteligente:** Ejecuta transacciones automáticas. Si el artículo es una planta con stock, disminuye sus existencias; si es una maceta, reestructura el inventario eliminando dinámicamente la pieza vendida.

### ¿Para qué no sirve?

* **No Maneja Persistencia:** Al trabajar con memoria dinámica (`new`) y arreglos en tiempo de ejecución, los datos se pierden al cerrar la consola.
* **Sin Interfaz Gráfica (GUI):** Está diseñado exclusivamente para operar a través de la terminal de comandos de forma eficiente.
* **Límite de Memoria Estática:** El tamaño de las listas gestoras está limitado por software a un máximo de **50 elementos**.

---

## 4. Guía de Uso Rápido e Interacción Segura

Una vez compilado, el programa despliega un menú interactivo con 5 opciones principales y una opción de salida:

1. **Crear nueva Planta (Opción 1):** Solicita datos técnicos para instanciar una planta en el heap.
2. **Crear nueva Maceta (Opción 2):** Solicita propiedades físicas para instanciar una maceta en el heap.
3. **Registrar Cliente (Opción 3):** Da de alta un comprador con presupuesto inicial.
4. **Mostrar Inventario Completo (Opción 4):** Muestra el reporte general del vivero. **Aquí se deben consultar los índices numéricos de cada entidad.**
5. **Realizar Venta Polimórfica (Opción 5):** Solicita el índice del cliente y del producto para procesar el pago y aplicar los cambios físicos en el almacén.
6. **Salir (Opción 0):** Termina la ejecución de la simulación.

### Reglas críticas para evitar fallos (Crashes) en Consola:
Para garantizar que el flujo de la terminal (`cin`) no se rompa o desincronice, la interfaz interactiva incluye instrucciones explícitas en pantalla:
* **Sin Espacios:** Al ingresar nombres o cadenas de texto, **no se deben usar espacios**. En su lugar, se debe utilizar el guion bajo `_` (Ej: `Raul_Torres`, `Juan_Perez`).
* **Sin Acentos:** No utilices caracteres especiales ni tildes para prevenir errores de codificación en la salida estándar de la consola.
* **Formatos Numéricos:** Los precios y presupuestos deben ingresarse solo con números y punto decimal (Ej: `150.50`). Los booleanos (como saber si una maceta es colgante) se capturan ingresando estrictamente `1` para **SÍ** o `0` para **NO**.

---

## 5. Diagrama de Clases
[Diagrama de clases](./diagramadeClases.png)

---

## 6. Compilación y Ejecución

Para compilar y ejecutar el programa desde la terminal, siga estos pasos:

1.  **Compilación:** Ejecute el siguiente comando para generar el ejecutable `gestor_vivero`:
    ```bash
    g++ main.cpp -o gestor_vivero
    ```
2.  **Ejecución:** Ejecute el siguiente comando:
    ```bash
    ./gestor_vivero
