# 🚀 Manejo de Errores y Excepciones en C++ - Guía Completa

## 🟥 1. ¿QUÉ ES EL MANEJO DE ERRORES?

En C++ existen dos enfoques principales para manejar errores:

### 1. **Errores Controlados sin Excepciones**
- Códigos de retorno
- `errno` (estilo C)
- Validaciones manuales
- `std::optional` (C++17+)

### 2. **Errores con Excepciones**
- `try / throw / catch`
- Jerarquía de clases de excepción
- Propagación y manejo avanzado

**Filosofía clave:** Las excepciones son para **errores excepcionales**, no para flujo normal del programa.

---

## 🟦 2. MANEJO DE ERRORES SIN EXCEPCIONES

### 🔹 2.1 Códigos de Retorno
```cpp
enum class Resultado { EXITO, ERROR_DIVISION_CERO, ERROR_NUMERO_NEGATIVO };

Resultado calcularRaiz(double valor, double& resultado) {
    if (valor < 0) return Resultado::ERROR_NUMERO_NEGATIVO;
    resultado = sqrt(valor);
    return Resultado::EXITO;
}

// Uso
double resultado;
auto estado = calcularRaiz(-5, resultado);
if (estado == Resultado::EXITO) {
    cout << "Resultado: " << resultado << endl;
} else {
    cout << "Error en cálculo" << endl;
}
```

**Ventajas:**
- Simple y predecible
- Bajo overhead de rendimiento
- Ideal para código de alto rendimiento

**Desventajas:**
- Fácil de ignorar los errores
- Código más verboso
- No escala bien con múltiples errores

### 🔹 2.2 Validaciones Manuales (Defensive Programming)
```cpp
#include <fstream>
#include <iostream>

bool cargarConfiguracion(const std::string& archivo) {
    std::ifstream file(archivo);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir " << archivo << std::endl;
        return false;
    }
    
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: Archivo vacío" << std::endl;
        return false;
    }
    
    // Procesar archivo...
    return true;
}
```

### 🔹 2.3 `errno` (Estilo C - Legacy)
```cpp
#include <cerrno>
#include <cstring>
#include <cmath>

double calcularLogaritmo(double valor) {
    errno = 0; // Reset error state
    double resultado = log(valor);
    
    if (errno != 0) {
        std::cout << "Error matemático: " << strerror(errno) << std::endl;
        return NAN;
    }
    return resultado;
}
```

**No recomendado en C++ moderno** - Usar alternativas más type-safe.

### 🔹 2.4 `std::optional` (C++17+) - **MODERNO Y RECOMENDADO**
```cpp
#include <optional>
#include <cmath>

std::optional<double> calcularRaizCuadrada(double valor) {
    if (valor < 0) return std::nullopt;  // No hay resultado válido
    return std::sqrt(valor);
}

std::optional<int> buscarEnArray(const std::vector<int>& arr, int objetivo) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == objetivo) return i;
    }
    return std::nullopt;  // No encontrado
}

// Uso elegante
int main() {
    auto resultado = calcularRaizCuadrada(-4);
    
    if (resultado.has_value()) {
        std::cout << "Raíz: " << resultado.value() << std::endl;
    } else {
        std::cout << "No se puede calcular raíz de número negativo" << std::endl;
    }
    
    // Con pattern matching moderno
    if (auto indice = buscarEnArray({1, 2, 3, 4}, 3)) {
        std::cout << "Encontrado en índice: " << *indice << std::endl;
    }
    
    return 0;
}
```

**¿Cuándo usar `std::optional`?**
- Cuando el "fallo" es parte del flujo normal
- Operaciones que pueden no tener resultado (búsquedas, parsing)
- Alternativa limpia a valores especiales o punteros nulos

---

## 🟥 3. MANEJO DE ERRORES CON EXCEPCIONES

### 🔹 3.1 Mecánica Básica: `throw` / `try` / `catch`
```cpp
#include <stdexcept>
#include <string>

double dividir(double numerador, double denominador) {
    if (denominador == 0.0) {
        throw std::invalid_argument("División por cero no permitida");
    }
    return numerador / denominador;
}

void procesarCalculo() {
    try {
        double a = 10.0, b = 0.0;
        double resultado = dividir(a, b);
        std::cout << "Resultado: " << resultado << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error de argumento: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error general: " << e.what() << std::endl;
    }
}
```

### 🔹 3.2 Jerarquía de Excepciones Estándar
```cpp
#include <exception>
#include <stdexcept>
#include <new>
#include <typeinfo>

/*
std::exception
├── std::logic_error
│   ├── std::invalid_argument
│   ├── std::domain_error
│   ├── std::length_error
│   └── std::out_of_range
├── std::runtime_error
│   ├── std::range_error
│   ├── std::overflow_error
│   ├── std::underflow_error
│   └── std::system_error
├── std::bad_alloc
├── std::bad_cast
└── std::bad_typeid
*/
```

**Ejemplos de uso específico:**
```cpp
// Lógica incorrecta del programador
void accederVector(const std::vector<int>& vec, size_t indice) {
    if (indice >= vec.size()) {
        throw std::out_of_range("Índice " + std::to_string(indice) + 
                               " fuera de rango [0, " + 
                               std::to_string(vec.size()) + ")");
    }
    // Usar vec[indice]...
}

// Error en tiempo de ejecución
double calcularEnergia(double masa) {
    if (masa < 0) {
        throw std::runtime_error("Masa negativa no tiene sentido físico");
    }
    const double c = 299792458.0; // velocidad de la luz
    return masa * c * c;
}

// Error del sistema
void reservarMemoriaMasiva() {
    try {
        int* gran_array = new int[10'000'000'000LL]; // 40 GB
        delete[] gran_array;
    }
    catch (const std::bad_alloc& e) {
        throw std::runtime_error("No hay suficiente memoria disponible");
    }
}
```

---

## 🟥 4. EXCEPCIONES AVANZADAS

### 🔹 4.1 Crear Excepciones Personalizadas
```cpp
#include <exception>
#include <string>

class ErrorRed : public std::runtime_error {
public:
    ErrorRed(const std::string& mensaje, int codigo_error) 
        : std::runtime_error(mensaje), codigo_(codigo_error) {}
    
    int codigo() const { return codigo_; }
    
    // Sobrescribir what() para incluir el código
    const char* what() const noexcept override {
        static std::string mensaje_completo = 
            std::string(std::runtime_error::what()) + 
            " [Código: " + std::to_string(codigo_) + "]";
        return mensaje_completo.c_str();
    }
    
private:
    int codigo_;
};

class TimeoutConexion : public ErrorRed {
public:
    TimeoutConexion() 
        : ErrorRed("Timeout en conexión al servidor", 408) {}
};

// Uso
void conectarServidor() {
    bool timeout_ocurrio = true; // Simulación
    
    if (timeout_ocurrio) {
        throw TimeoutConexion();
    }
}
```

### 🔹 4.2 Re-lanzar y Encadenar Excepciones
```cpp
#include <exception>

void funcionBajaNivel() {
    throw std::runtime_error("Error en operación de bajo nivel");
}

void funcionAltoNivel() {
    try {
        funcionBajaNivel();
    }
    catch (const std::exception& e) {
        // Log del error
        std::cerr << "Error en bajo nivel: " << e.what() << std::endl;
        
        // Re-lanzar la misma excepción
        throw;
        
        // O lanzar una nueva con más contexto
        // throw std::runtime_error(std::string("Error en alto nivel: ") + e.what());
    }
}

void funcionCapaSuperior() {
    try {
        funcionAltoNivel();
    }
    catch (const std::exception& e) {
        std::cerr << "Error capturado: " << e.what() << std::endl;
    }
}
```

### 🔹 4.3 Propagación Automática de Excepciones
```cpp
void funcionProfunda() {
    throw std::logic_error("Error desde las profundidades");
}

void funcionIntermedia() {
    funcionProfunda(); // No captura → propaga hacia arriba
}

void funcionSuperficial() {
    funcionIntermedia(); // Sigue propagando
}

int main() {
    try {
        funcionSuperficial();
    }
    catch (const std::logic_error& e) {
        std::cout << "Error capturado en main: " << e.what() << std::endl;
    }
    return 0;
}
```

### 🔹 4.4 Excepciones en Constructores - **CRÍTICO**
```cpp
#include <memory>
#include <fstream>

class ArchivoSeguro {
public:
    explicit ArchivoSeguro(const std::string& nombre_archivo) {
        archivo_.open(nombre_archivo);
        if (!archivo_.is_open()) {
            throw std::runtime_error("No se pudo abrir: " + nombre_archivo);
        }
        
        // Más inicializaciones que pueden fallar...
        if (!leerEncabezado()) {
            throw std::runtime_error("Archivo corrupto o formato inválido");
        }
    }
    
    // El destructor se llama automáticamente si el constructor falla
    ~ArchivoSeguro() {
        if (archivo_.is_open()) {
            archivo_.close();
        }
    }
    
private:
    std::ifstream archivo_;
    
    bool leerEncabezado() {
        // Simulación de fallo
        return false;
    }
};

// Uso seguro
int main() {
    try {
        ArchivoSeguro archivo("datos.txt");
        // Usar archivo...
    }
    catch (const std::exception& e) {
        std::cerr << "Error creando archivo: " << e.what() << std::endl;
    }
    return 0;
}
```

### 🔹 4.5 Especificación `noexcept`
```cpp
class Calculadora {
public:
    // Esta función PROMETE no lanzar excepciones
    int sumarSegura(int a, int b) noexcept {
        return a + b; // Operación que nunca falla
    }
    
    // Esta función PUEDE lanzar excepciones
    double dividir(double a, double b) {
        if (b == 0.0) throw std::invalid_argument("División por cero");
        return a / b;
    }
};

// noexcept permite optimizaciones del compilador
void funcionCriticaRendimiento() noexcept {
    // Código que debe ser ultra-rápido
    // Si lanza excepción → std::terminate() se llama
}
```

### 🔹 4.6 RAII y Gestión Automática de Recursos
```cpp
#include <memory>
#include <vector>

// ❌ PELIGROSO: Gestión manual con excepciones
void procesoPeligroso() {
    int* buffer = new int[1000];
    try {
        // Código que puede lanzar excepciones...
        throw std::runtime_error("Error inesperado");
    }
    catch (...) {
        delete[] buffer; // ¿Se ejecutará siempre?
        throw;
    }
    delete[] buffer; // Código duplicado
}

// ✅ SEGURO: RAII automático
void procesoSeguro() {
    std::vector<int> buffer(1000); // Gestión automática
    std::unique_ptr<int[]> buffer2 = std::make_unique<int[]>(1000);
    
    throw std::runtime_error("Error inesperado");
    // Los recursos se liberan automáticamente
}

class ConexionBD {
public:
    ConexionBD() { conectar(); }
    ~ConexionBD() { desconectar(); } // Siempre se ejecuta
    
private:
    void conectar() { /* ... */ }
    void desconectar() { /* ... */ }
};

void transaccionSegura() {
    ConexionBD conexion; // RAII
    // Si hay excepción, ~ConexionBD() desconecta automáticamente
    realizarOperaciones();
}
```

---

## 🟥 5. BUENAS PRÁCTICAS PROFESIONALES

### ✅ **Reglas de Oro:**

1. **Usa excepciones para errores excepcionales**, no para flujo normal
2. **Prefiere `std::optional`** para operaciones que pueden fallar normalmente
3. **Nunca lances excepciones desde destructores**
4. **Captura por referencia constante**: `catch (const std::exception& e)`
5. **Usa RAII** para gestión automática de recursos
6. **Documenta** qué excepciones lanzan tus funciones
7. **Mantén la seguridad ante excepciones** (exception safety)

### ✅ **Niveles de Seguridad ante Excepciones:**
```cpp
class ContenedorSeguro {
public:
    // 1. No-throw guarantee: Nunca lanza excepciones
    void clear() noexcept {
        datos_.clear(); // Operación que no falla
    }
    
    // 2. Strong guarantee: O se completa o no modifica estado
    void agregarElemento(const Elemento& elem) {
        auto copia = datos_; // Copia temporal
        copia.push_back(elem);
        datos_.swap(copia); // Swap atómico
    }
    
    // 3. Basic guarantee: Estado permanece válido
    void procesar() {
        // Si hay excepción, el objeto sigue siendo usable
        for (auto& elem : datos_) {
            elem.procesar(); // Puede lanzar
        }
    }
    
private:
    std::vector<Elemento> datos_;
};
```

### ✅ **Patrones de Diseño con Errores:**
```cpp
// Pattern: Result Object (alternativa moderna)
template<typename T, typename E = std::string>
class Resultado {
public:
    static Resultado Exito(T valor) { return Resultado(std::move(valor)); }
    static Resultado Error(E error) { return Resultado(std::move(error)); }
    
    bool tieneExito() const { return tiene_exito_; }
    const T& valor() const { return valor_; }
    const E& error() const { return error_; }
    
private:
    Resultado(T valor) : tiene_exito_(true), valor_(std::move(valor)) {}
    Resultado(E error) : tiene_exito_(false), error_(std::move(error)) {}
    
    bool tiene_exito_;
    T valor_;
    E error_;
};

// Uso
Resultado<double, std::string> calcular(double entrada) {
    if (entrada < 0) return Resultado<double>::Error("Entrada negativa");
    return Resultado<double>::Exito(sqrt(entrada));
}
```

---

## 🟥 6. EJEMPLOS APLICADOS EN SISTEMAS REALES

### 🔹 Sistema de Archivos con Manejo Robusto
```cpp
#include <filesystem>
#include <fstream>
#include <system_error>

class ManejadorArchivos {
public:
    static std::optional<std::string> leerArchivoCompleto(const std::string& ruta) {
        namespace fs = std::filesystem;
        
        // Verificar que existe
        std::error_code ec;
        if (!fs::exists(ruta, ec)) {
            std::cerr << "Archivo no existe: " << ruta << std::endl;
            return std::nullopt;
        }
        
        // Verificar que es archivo regular
        if (!fs::is_regular_file(ruta, ec)) {
            std::cerr << "No es archivo regular: " << ruta << std::endl;
            return std::nullopt;
        }
        
        // Leer contenido
        std::ifstream archivo(ruta);
        if (!archivo) {
            std::cerr << "Error abriendo archivo: " << ruta << std::endl;
            return std::nullopt;
        }
        
        return std::string(std::istreambuf_iterator<char>(archivo),
                          std::istreambuf_iterator<char>());
    }
};
```

### 🔹 API Web con Manejo de Errores por Capas
```cpp
class ClienteAPI {
public:
    std::optional<Json> solicitarDatos(const std::string& url) {
        try {
            auto respuesta = realizarHttpRequest(url);
            return parsearJson(respuesta);
        }
        catch (const ErrorRed& e) {
            std::cerr << "Error de red: " << e.what() << std::endl;
            return std::nullopt;
        }
        catch (const ErrorJson& e) {
            std::cerr << "Error parseando JSON: " << e.what() << std::endl;
            return std::nullopt;
        }
        catch (const std::exception& e) {
            std::cerr << "Error inesperado: " << e.what() << std::endl;
            return std::nullopt;
        }
    }
    
private:
    std::string realizarHttpRequest(const std::string& url) {
        // Simulación - podría lanzar ErrorRed
        if (url.empty()) throw ErrorRed("URL vacía", 400);
        return "{\"datos\": \"ejemplo\"}";
    }
    
    Json parsearJson(const std::string& texto) {
        // Simulación - podría lanzar ErrorJson
        if (texto.empty()) throw ErrorJson("Texto JSON vacío");
        return Json::parse(texto);
    }
};
```

---

## 🟥 7. MINI-PREGUNTA DE COMPRENSIÓN

**¿En qué caso preferís usar `std::optional` en vez de lanzar una excepción?**

### 🎯 **Respuesta Esperada:**

**Uso `std::optional` cuando:**
- El "fallo" es **parte del flujo normal** del programa (ej: búsqueda sin resultados)
- El costo de las excepciones es **inaceptable** (código de ultra alto rendimiento)
- Quiero forzar al caller a **manejar explícitamente** el caso de fallo
- Trabajo con operaciones que **frecuentemente** pueden no tener resultado

**Uso excepciones cuando:**
- El error es **excepcional** y realmente inesperado
- Necesito **propagación automática** a través de múltiples capas
- El error requiere **acción de recuperación** compleja
- Trabajo con **errores de sistema** o recursos críticos

### 💡 **Regla Mnemotécnica:**
- **`std::optional`**: "Esta operación a veces no da resultado, y eso está OK"
- **Excepciones**: "¡Algo salió terriblemente mal y no puedo continuar normalmente!"
