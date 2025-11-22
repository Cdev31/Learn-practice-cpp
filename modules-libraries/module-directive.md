# 🚀 Directivas, Módulos, Arrays y Vectores en C++

## 1. Directivas del Preprocesador

### 🔹 1.1 `#include` - Inclusión de Archivos
```cpp
#include <iostream>    // Librerías estándar del sistema
#include <vector>
#include <string>

#include "mi_clase.h"  // Archivos de tu proyecto
#include "utils.hpp"
```

**Diferencia clave:**
- `< >` → Busca en las rutas del sistema del compilador
- `" "` → Busca primero en el directorio actual, luego en rutas del sistema

### 🔹 1.2 `#define` - Macros y Constantes
```cpp
// Macros simples (evitar cuando sea posible)
#define PI 3.14159
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Uso
double area = PI * radio * radio;
int mayor = MAX(x, y);
```

**Problemas con `#define`:**
```cpp
// ❌ Problema de precedencia
#define CUADRADO(x) x * x
int resultado = CUADRADO(2 + 3);  // 2 + 3 * 2 + 3 = 11 (no 25)

// ✅ Solución: usar paréntesis
#define CUADRADO(x) ((x) * (x))
```

**Alternativas modernas:**
```cpp
// ✅ Mejor usar constexpr
constexpr double PI = 3.14159;

// ✅ Plantillas para funciones
template<typename T>
constexpr T max(T a, T b) {
    return (a > b) ? a : b;
}
```

### 🔹 1.3 Include Guards vs `#pragma once`
```cpp
// Método tradicional (portable)
#ifndef MI_HEADER_H
#define MI_HEADER_H

// Contenido del header...
class MiClase {
    // ...
};

#endif // MI_HEADER_H
```

```cpp
// Método moderno (más simple, menos portable)
#pragma once

// Contenido del header...
class MiClase {
    // ...
};
```

### 🔹 1.4 Compilación Condicional
```cpp
#include <iostream>

// Flags de compilación comunes
#ifdef DEBUG
    #define LOG(x) std::cout << "DEBUG: " << x << std::endl
#else
    #define LOG(x) // No hace nada en release
#endif

#ifdef _WIN32
    #define PLATAFORMA "Windows"
#elif defined(__linux__)
    #define PLATAFORMA "Linux"
#elif defined(__APPLE__)
    #define PLATAFORMA "macOS"
#endif

int main() {
    LOG("Iniciando aplicación");
    std::cout << "Plataforma: " << PLATAFORMA << std::endl;
    
    #if __cplusplus >= 202002L
        std::cout << "Usando C++20 o superior" << std::endl;
    #else
        std::cout << "Usando C++ anterior a 20" << std::endl;
    #endif
    
    return 0;
}
```

## 2. Módulos y Organización de Archivos

### 🔹 2.1 Estructura de Headers (`.h`/`.hpp`)
```cpp
// persona.h
#pragma once
#include <string>
#include <iostream>

class Persona {
public:
    // Constructor
    Persona(const std::string& nombre, int edad);
    
    // Métodos públicos
    void mostrar() const;
    void cumplir_anios();
    
    // Getters
    std::string get_nombre() const { return nombre_; }
    int get_edad() const { return edad_; }
    
    // Setters
    void set_nombre(const std::string& nombre);
    void set_edad(int edad);

private:
    std::string nombre_;
    int edad_;
};

// Funciones relacionadas (no miembros)
void saludar(const Persona& p);
```

### 🔹 2.2 Implementación en `.cpp`
```cpp
// persona.cpp
#include "persona.h"

// Constructor
Persona::Persona(const std::string& nombre, int edad) 
    : nombre_(nombre), edad_(edad) {
}

// Implementación de métodos
void Persona::mostrar() const {
    std::cout << nombre_ << " (" << edad_ << " años)" << std::endl;
}

void Persona::cumplir_anios() {
    ++edad_;
    std::cout << "¡Feliz cumpleaños " << nombre_ << "!" << std::endl;
}

void Persona::set_nombre(const std::string& nombre) {
    if (!nombre.empty()) {
        nombre_ = nombre;
    }
}

void Persona::set_edad(int edad) {
    if (edad >= 0 && edad <= 150) {
        edad_ = edad;
    }
}

// Función no miembro
void saludar(const Persona& p) {
    std::cout << "Hola " << p.get_nombre() << "!" << std::endl;
}
```

### 🔹 2.3 Archivo Principal
```cpp
// main.cpp
#include "persona.h"
#include <vector>

int main() {
    Persona juan("Juan", 25);
    Persona maria("María", 30);
    
    juan.mostrar();
    maria.cumplir_anios();
    saludar(maria);
    
    return 0;
}
```

### 🔹 2.4 Convenciones de Nombrado
- **`.h`** → Headers estilo C o compatibilidad mixta
- **`.hpp`** → Headers puros de C++ (templates, clases)
- **`.cpp`** → Implementación de C++
- **`.cc`** / **`.cxx`** → Alternativas a `.cpp`

## 3. Arrays y Vectores - Profundización

### 🔹 3.1 Arrays Nativos (C-style)
```cpp
#include <iostream>

int main() {
    // Declaraciones de arrays
    int arr1[5];                    // No inicializado
    int arr2[5] = {1, 2, 3, 4, 5};  // Inicializado completo
    int arr3[5] = {1, 2};           // Inicializado parcial (resto a 0)
    int arr4[] = {1, 2, 3, 4, 5};   // Tamaño automático
    
    // Acceso y modificación
    arr1[0] = 10;
    std::cout << "Primer elemento: " << arr2[0] << std::endl;
    
    // Tamaño del array
    int tamaño = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Tamaño del array: " << tamaño << std::endl;
    
    // Recorrido
    for (int i = 0; i < tamaño; ++i) {
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
    }
    
    // Array multidimensional
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    return 0;
}
```

### 🔹 3.2 Pasar Arrays a Funciones
```cpp
#include <iostream>

// Tres formas equivalentes
void imprimir_array(int arr[], int tamaño) {
    for (int i = 0; i < tamaño; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void imprimir_array_ptr(int* arr, int tamaño) {
    for (int i = 0; i < tamaño; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Para arrays de tamaño fijo conocido en compilación
template<size_t N>
void imprimir_array_fijo(int (&arr)[N]) {
    for (size_t i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    
    imprimir_array(numeros, 5);
    imprimir_array_ptr(numeros, 5);
    imprimir_array_fijo(numeros);
    
    return 0;
}
```

### 🔹 3.3 `std::array` - Array Moderno de Tamaño Fijo
```cpp
#include <array>
#include <iostream>
#include <algorithm>

int main() {
    // Declaración e inicialización
    std::array<int, 5> arr1 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2{};  // Todos a 0
    
    // Acceso
    std::cout << "Primer elemento: " << arr1[0] << std::endl;
    std::cout << "Último elemento: " << arr1.back() << std::endl;
    
    // Acceso seguro con verificación de límites
    try {
        std::cout << "Elemento 10: " << arr1.at(10) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Propiedades
    std::cout << "Tamaño: " << arr1.size() << std::endl;
    std::cout << "¿Está vacío? " << arr1.empty() << std::endl;
    
    // Recorrido
    for (size_t i = 0; i < arr1.size(); ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    
    for (int valor : arr1) {
        std::cout << valor << " ";
    }
    std::cout << std::endl;
    
    // Algoritmos STL
    std::sort(arr1.begin(), arr1.end());
    auto it = std::find(arr1.begin(), arr1.end(), 3);
    
    if (it != arr1.end()) {
        std::cout << "Encontrado 3 en posición: " 
                  << std::distance(arr1.begin(), it) << std::endl;
    }
    
    // Array multidimensional
    std::array<std::array<int, 3>, 2> matriz = {{
        {1, 2, 3},
        {4, 5, 6}
    }};
    
    return 0;
}
```

### 🔹 3.4 `std::vector` - Array Dinámico
```cpp
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    // Diferentes formas de crear vectores
    std::vector<int> v1;                    // Vacío
    std::vector<int> v2(5);                 // 5 elementos (0)
    std::vector<int> v3(5, 10);             // 5 elementos con valor 10
    std::vector<int> v4 = {1, 2, 3, 4, 5}; // Lista inicialización
    std::vector<int> v5(v4.begin(), v4.end()); // Copia de rango
    
    // Operaciones básicas
    v1.push_back(10);           // Agregar al final
    v1.pop_back();              // Eliminar último
    v1.insert(v1.begin() + 1, 20); // Insertar en posición
    v1.erase(v1.begin() + 1);   // Eliminar en posición
    
    // Capacidad y tamaño
    std::cout << "Tamaño: " << v4.size() << std::endl;
    std::cout << "Capacidad: " << v4.capacity() << std::endl;
    std::cout << "¿Vacío? " << v4.empty() << std::endl;
    
    // Redimensionar
    v4.resize(10);              // Aumenta tamaño, nuevos elementos a 0
    v4.resize(3);               // Reduce tamaño
    v4.reserve(100);            // Reservar capacidad
    
    // Acceso
    std::cout << "Primer elemento: " << v4.front() << std::endl;
    std::cout << "Último elemento: " << v4.back() << std::endl;
    std::cout << "Elemento 2: " << v4[1] << std::endl;
    std::cout << "Elemento 2 (seguro): " << v4.at(1) << std::endl;
    
    // Recorridos
    std::cout << "For clásico: ";
    for (size_t i = 0; i < v4.size(); ++i) {
        std::cout << v4[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Range-based for: ";
    for (int valor : v4) {
        std::cout << valor << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Iteradores: ";
    for (auto it = v4.begin(); it != v4.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Algoritmos
    std::sort(v4.begin(), v4.end());
    auto max_it = std::max_element(v4.begin(), v4.end());
    int suma = std::accumulate(v4.begin(), v4.end(), 0);
    
    std::cout << "Máximo: " << *max_it << std::endl;
    std::cout << "Suma: " << suma << std::endl;
    
    return 0;
}
```

### 🔹 3.5 Operaciones Avanzadas con Vectores
```cpp
#include <vector>
#include <iostream>

// Pasar vectores a funciones
void procesar_vector(const std::vector<int>& vec) {
    std::cout << "Procesando vector (solo lectura): ";
    for (int valor : vec) {
        std::cout << valor << " ";
    }
    std::cout << std::endl;
}

void modificar_vector(std::vector<int>& vec) {
    for (auto& valor : vec) {
        valor *= 2;  // Duplicar cada valor
    }
}

std::vector<int> crear_vector() {
    return {1, 2, 3, 4, 5};  // NRVO (Named Return Value Optimization)
}

int main() {
    // Vector de otros tipos
    std::vector<std::string> palabras = {"hola", "mundo", "c++"};
    std::vector<double> precios = {19.99, 29.99, 9.99};
    
    // Intercambiar vectores eficientemente
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {4, 5, 6};
    
    a.swap(b);  // Intercambio O(1)
    
    // Eliminar elementos específicos
    std::vector<int> numeros = {1, 2, 3, 2, 4, 2, 5};
    numeros.erase(std::remove(numeros.begin(), numeros.end(), 2), 
                  numeros.end());
    
    // Eliminar duplicados (primero ordenar)
    std::vector<int> con_duplicados = {1, 2, 2, 3, 3, 3, 4};
    std::sort(con_duplicados.begin(), con_duplicados.end());
    auto last = std::unique(con_duplicados.begin(), con_duplicados.end());
    con_duplicados.erase(last, con_duplicados.end());
    
    // Vector de vectores (matriz)
    std::vector<std::vector<int>> matriz = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Recorrer matriz
    for (const auto& fila : matriz) {
        for (int valor : fila) {
            std::cout << valor << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
```

### 🔹 3.6 Comparación y Elección

| Característica | Array C | `std::array` | `std::vector` |
|----------------|---------|--------------|---------------|
| Tamaño | Fijo (compilación) | Fijo (compilación) | Dinámico (ejecución) |
| Conoce su tamaño | ❌ | ✅ | ✅ |
| Acceso seguro | ❌ | ✅ | ✅ |
| STL compatible | ❌ | ✅ | ✅ |
| Redimensionar | ❌ | ❌ | ✅ |
| Rendimiento | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐⭐⭐ |
| Facilidad de uso | ⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ |

**Recomendaciones:**
- **`std::vector`** → Caso general, tamaño variable
- **`std::array`** → Tamaño fijo conocido en compilación
- **Array C** → Compatibilidad con C, bajo nivel

## 4. Argumentos de Línea de Comandos

### 🔹 4.1 Sintaxis Básica
```cpp
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    // argc = argument count (número de argumentos)
    // argv = argument vector (array de C-strings)
    
    std::cout << "Número de argumentos: " << argc << std::endl;
    
    // Mostrar todos los argumentos
    for (int i = 0; i < argc; ++i) {
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    }
    
    return 0;
}
```

### 🔹 4.2 Parser de Argumentos Simple
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    // Convertir a vector de strings para mayor comodidad
    std::vector<std::string> args(argv, argv + argc);
    
    // Variables para almacenar opciones
    std::string archivo_entrada;
    std::string archivo_salida;
    bool modo_verbose = false;
    bool mostrar_ayuda = false;
    
    // Procesar argumentos
    for (size_t i = 1; i < args.size(); ++i) {
        if (args[i] == "-h" || args[i] == "--help") {
            mostrar_ayuda = true;
        }
        else if (args[i] == "-v" || args[i] == "--verbose") {
            modo_verbose = true;
        }
        else if (args[i] == "-i" || args[i] == "--input") {
            if (i + 1 < args.size()) {
                archivo_entrada = args[++i];
            } else {
                std::cerr << "Error: -i requiere un archivo" << std::endl;
                return 1;
            }
        }
        else if (args[i] == "-o" || args[i] == "--output") {
            if (i + 1 < args.size()) {
                archivo_salida = args[++i];
            } else {
                std::cerr << "Error: -o requiere un archivo" << std::endl;
                return 1;
            }
        }
        else {
            // Argumento posicional (sin flag)
            if (archivo_entrada.empty()) {
                archivo_entrada = args[i];
            } else if (archivo_salida.empty()) {
                archivo_salida = args[i];
            }
        }
    }
    
    // Mostrar ayuda si se solicitó
    if (mostrar_ayuda || argc == 1) {
        std::cout << "Uso: " << args[0] << " [OPCIONES] [ENTRADA] [SALIDA]\n"
                  << "Opciones:\n"
                  << "  -h, --help     Mostrar esta ayuda\n"
                  << "  -v, --verbose  Modo verboso\n"
                  << "  -i, --input    Archivo de entrada\n"
                  << "  -o, --output   Archivo de salida\n";
        return 0;
    }
    
    // Modo verboso
    if (modo_verbose) {
        std::cout << "Modo verboso activado" << std::endl;
        std::cout << "Archivo de entrada: " << archivo_entrada << std::endl;
        std::cout << "Archivo de salida: " << archivo_salida << std::endl;
    }
    
    // Validar argumentos requeridos
    if (archivo_entrada.empty()) {
        std::cerr << "Error: Se requiere archivo de entrada" << std::endl;
        return 1;
    }
    
    std::cout << "Procesando '" << archivo_entrada << "' -> '" 
              << archivo_salida << "'" << std::endl;
    
    return 0;
}
```

### 🔹 4.3 Ejemplo de Uso
```bash
# Compilar
g++ -o mi_programa main.cpp

# Ejecutar con diferentes argumentos
./mi_programa -h
./mi_programa -v -i entrada.txt -o salida.txt
./mi_programa --verbose --input datos.csv --output resultado.txt
./mi_programa entrada.txt salida.txt
```

## 🎯 **Resumen Ejecutivo**

### **Directivas:**
- Usa `#pragma once` para headers
- `constexpr` en lugar de `#define` para constantes
- Compilación condicional para debug/plataforma

### **Organización:**
- Headers (`.hpp`) → Declaraciones
- Implementación (`.cpp`) → Definiciones
- Separación clara de responsabilidades

### **Arrays/Vectores:**
- **`std::vector`** → Caso general (95% del tiempo)
- **`std::array`** → Tamaño fijo conocido
- **Array C** → Solo para bajo nivel/compatibilidad

### **Argumentos CLI:**
- `argc`/`argv` para entrada de comandos
- Parser simple con flags y validación
- Mensajes de ayuda útiles

