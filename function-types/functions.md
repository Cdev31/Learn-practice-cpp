# 🚀 Funciones en C++ - Guía Completa

## 🟥 1. ¿QUÉ ES UNA FUNCIÓN?

Una función es un **bloque de código autocontenido** que realiza una tarea específica, promoviendo la reutilización, modularidad y mantenibilidad del código.

### Características principales:
- **Reutilizable**: Se puede llamar múltiples veces
- **Parametrizable**: Acepta datos de entrada (parámetros)
- **Retorna valores**: Opcionalmente devuelve un resultado
- **Scope local**: Variables internas son independientes

```cpp
// Función básica
int sumar(int a, int b) {
    return a + b;
}

// Uso
int resultado = sumar(5, 3);  // resultado = 8
```

---

## 🟥 2. TIPOS DE FUNCIONES

### 🔹 2.1 Según el valor que devuelven

**Funciones con retorno:**
```cpp
double calcularAreaCirculo(double radio) {
    const double PI = 3.14159;
    return PI * radio * radio;
}

// Uso
double area = calcularAreaCirculo(5.0);  // 78.5397
```

**Funciones void (sin retorno):**
```cpp
void mostrarMenu() {
    cout << "1. Jugar\n";
    cout << "2. Configuración\n";
    cout << "3. Salir\n";
}

void saludar(string nombre) {
    cout << "Hola, " << nombre << "!\n";
}
```

### 🔹 2.2 Según parámetros

**Sin parámetros:**
```cpp
void iniciarJuego() {
    // Inicializar recursos del juego
    cargarTexturas();
    configurarAudio();
    reiniciarPuntaje();
}
```

**Con parámetros:**
```cpp
void configurarPersonaje(string nombre, int nivel, bool esHeroe) {
    cout << "Personaje: " << nombre 
         << ", Nivel: " << nivel 
         << ", Tipo: " << (esHeroe ? "Héroe" : "Villano") << endl;
}
```

**Parámetros con valor por defecto:**
```cpp
void conectarServidor(string ip = "127.0.0.1", 
                     int puerto = 8080, 
                     int timeout = 30) {
    cout << "Conectando a " << ip << ":" << puerto 
         << " (timeout: " << timeout << "s)\n";
}

// Uso flexible
conectarServidor();                    // Usa todos los valores por defecto
conectarServidor("192.168.1.100");     // Solo cambia IP
conectarServidor("10.0.0.1", 9000);    // Cambia IP y puerto
```

### 🔹 2.3 Sobrecarga de Funciones (Function Overloading)

Mismo nombre, diferentes parámetros → **polimorfismo en tiempo de compilación**.

```cpp
// Versiones sobrecargadas
int multiplicar(int a, int b) {
    return a * b;
}

double multiplicar(double a, double b) {
    return a * b;
}

int multiplicar(int a, int b, int c) {
    return a * b * c;
}

string multiplicar(string texto, int veces) {
    string resultado;
    for (int i = 0; i < veces; i++) {
        resultado += texto;
    }
    return resultado;
}

// Uso - el compilador elige la versión correcta
cout << multiplicar(3, 4) << endl;        // 12 (int version)
cout << multiplicar(2.5, 3.0) << endl;    // 7.5 (double version)
cout << multiplicar(2, 3, 4) << endl;     // 24 (triple version)
cout << multiplicar("Hola", 3) << endl;   // "HolaHolaHola"
```

---

## 🟥 3. PASO DE PARÁMETROS

### 🔹 3.1 Paso por Valor (Copia)
```cpp
void incrementar(int x) {
    x = x + 1;  // Solo modifica la copia local
    cout << "Dentro: " << x << endl;  // 11
}

int main() {
    int numero = 10;
    incrementar(numero);
    cout << "Fuera: " << numero << endl;  // 10 (sin cambios)
    return 0;
}
```
**Usar cuando:** No necesitas modificar el original o el objeto es pequeño.

### 🔹 3.2 Paso por Referencia (`&`)
```cpp
void incrementar(int& x) {
    x = x + 1;  // Modifica el original
    cout << "Dentro: " << x << endl;  // 11
}

int main() {
    int numero = 10;
    incrementar(numero);
    cout << "Fuera: " << numero << endl;  // 11 (modificado)
    return 0;
}
```

**Referencias constantes (mejor rendimiento):**
```cpp
void mostrarPersonaje(const string& nombre, const int& edad) {
    // nombre y edad no pueden modificarse aquí
    cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
}
```

### 🔹 3.3 Paso por Puntero
```cpp
void configurarValor(int* ptr, int nuevoValor) {
    if (ptr != nullptr) {  // Siempre verificar nullptr
        *ptr = nuevoValor;
    }
}

int main() {
    int puntaje = 100;
    configurarValor(&puntaje, 200);  // Pasa dirección
    cout << puntaje << endl;  // 200
    
    // También puede recibir nullptr
    configurarValor(nullptr, 300);  // Seguro - no hace nada
    return 0;
}
```

### 🔹 3.4 Paso de Arrays
```cpp
// Tres formas equivalentes
void procesarArray(int arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        cout << arr[i] << " ";
    }
}

void procesarArray(int* arr, int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        cout << arr[i] << " ";
    }
}

// Con template para cualquier tamaño
template<size_t N>
void procesarArray(int (&arr)[N]) {  // Referencia a array
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
}
```

### 🔹 3.5 Paso de Objetos
```cpp
class Persona {
    string nombre;
    int edad;
public:
    Persona(string n, int e) : nombre(n), edad(e) {}
    // ... más métodos
};

// ❌ INEFICIENTE - copia completa
void procesarPorValor(Persona p) {
    // Crea una copia completa del objeto
}

// ✅ RECOMENDADO - sin copia, solo lectura
void procesarPorRefConstante(const Persona& p) {
    // Accede al original sin copiar, pero no puede modificarlo
}

// ✅ Para modificar el objeto
void modificarPersona(Persona& p) {
    // Puede modificar el objeto original
}

// ✅ Cuando el objeto puede no existir
void procesarOpcional(Persona* p) {
    if (p != nullptr) {
        // Trabajar con el objeto
    }
}
```

---

## 🟥 4. FUNCIONES LAMBDA (ANÓNIMAS)

### 🔹 Sintaxis Básica
```cpp
auto suma = [](int a, int b) -> int {
    return a + b;
};
cout << suma(5, 3) << endl;  // 8

// Tipo de retorno automático
auto multiplicar = [](auto a, auto b) {
    return a * b;
};
cout << multiplicar(4, 5) << endl;    // 20
cout << multiplicar(2.5, 3.0) << endl; // 7.5
```

### 🔹 Sistemas de Captura
```cpp
int x = 10, y = 20;

// Captura por valor
auto copia = [x, y]() {
    cout << x << ", " << y << endl;  // Usa copias
    // x = 5;  // ERROR - x es de solo lectura
};

// Captura por referencia
auto referencia = [&x, &y]() {
    x = 100;  // Modifica las variables originales
    y = 200;
};

// Captura mixta
auto mixta = [x, &y]() {
    // x es copia, y es referencia
    cout << x << endl;  // 10 (copia)
    y = 300;           // modifica y original
};

// Captura todo por valor
auto todoValor = [=]() {
    // Captura todas las variables visibles por valor
};

// Captura todo por referencia
auto todoReferencia = [&]() {
    // Captura todas las variables visibles por referencia
};
```

### 🔹 Lambdas como Parámetros
```cpp
#include <functional>
#include <vector>

// Usando std::function
void procesarNumeros(const vector<int>& numeros, 
                    function<void(int)> procesador) {
    for (int num : numeros) {
        procesador(num);
    }
}

// Usando templates (más eficiente)
template<typename Func>
void procesarConTemplate(const vector<int>& numeros, Func f) {
    for (int num : numeros) {
        f(num);
    }
}

// Uso
int main() {
    vector<int> datos = {1, 2, 3, 4, 5};
    
    // Lambda inline
    procesarNumeros(datos, [](int n) {
        cout << n * 2 << " ";
    });
    // Output: 2 4 6 8 10
    
    // Lambda con captura
    int suma = 0;
    procesarNumeros(datos, [&suma](int n) {
        suma += n;
    });
    cout << "Suma: " << suma << endl;  // Suma: 15
    return 0;
}
```

---

## 🟥 5. FUNCIONES COMO DATOS DE PRIMERA CLASE

### 🔹 5.1 Punteros a Funciones (Estilo C)
```cpp
#include <cmath>

// Definir tipos de funciones
using OperacionBinaria = int(*)(int, int);

int sumar(int a, int b) { return a + b; }
int restar(int a, int b) { return a - b; }
int multiplicar(int a, int b) { return a * b; }

// Función que acepta puntero a función
int calcular(int a, int b, OperacionBinaria op) {
    return op(a, b);
}

int main() {
    cout << calcular(10, 5, sumar) << endl;        // 15
    cout << calcular(10, 5, restar) << endl;       // 5
    cout << calcular(10, 5, multiplicar) << endl;  // 50
    
    // Array de punteros a funciones
    OperacionBinaria operaciones[] = {sumar, restar, multiplicar};
    for (auto op : operaciones) {
        cout << op(8, 2) << " ";  // 10 6 16
    }
    return 0;
}
```

### 🔹 5.2 `std::function` (Moderna y Flexible)
```cpp
#include <functional>
#include <map>

int sumar(int a, int b) { return a + b; }

int main() {
    // Almacenar cualquier cosa llamable
    function<int(int, int)> operacion;
    
    // Puede almacenar función normal
    operacion = sumar;
    cout << operacion(3, 4) << endl;  // 7
    
    // Puede almacenar lambda
    operacion = [](int a, int b) { return a * b; };
    cout << operacion(3, 4) << endl;  // 12
    
    // Puede almacenar functors
    struct Divisor {
        int operator()(int a, int b) { return a / b; }
    };
    operacion = Divisor();
    cout << operacion(12, 4) << endl;  // 3
    
    // Útil para dispatchers/menús
    map<string, function<int(int, int)>> calculadora = {
        {"suma", sumar},
        {"resta", [](int a, int b) { return a - b; }},
        {"multiplica", multiplicar}
    };
    
    cout << calculadora["suma"](10, 2) << endl;      // 12
    cout << calculadora["resta"](10, 2) << endl;     // 8
    return 0;
}
```

---

## 🟥 6. MANEJO AVANZADO DE FUNCIONES

### 🔹 6.1 Devolver Referencias
```cpp
class Contador {
    int valor = 0;
public:
    int& obtenerReferencia() {
        return valor;  // Permite modificar el miembro privado
    }
    
    const int& obtenerValor() const {
        return valor;  // Solo lectura
    }
};

int main() {
    Contador c;
    c.obtenerReferencia() = 42;  // Modifica directamente
    cout << c.obtenerValor() << endl;  // 42
    
    // Cuidado: nunca devolver referencia a variable local
    return 0;
}
```

### 🔹 6.2 Devolver Punteros
```cpp
#include <memory>

// Devolver puntero crudo (responsabilidad del caller)
int* crearArray(int tamaño) {
    return new int[tamaño];  // Caller debe hacer delete[]
}

// Mejor: devolver smart pointer
unique_ptr<int[]> crearArraySeguro(int tamaño) {
    return make_unique<int[]>(tamaño);  // Memoria automática
}

// Para polimorfismo
class Animal {
public:
    virtual ~Animal() = default;
    virtual void hablar() const = 0;
};

unique_ptr<Animal> crearAnimal(string tipo) {
    if (tipo == "perro") return make_unique<Perro>();
    if (tipo == "gato") return make_unique<Gato>();
    return nullptr;
}
```

### 🔹 6.3 Funciones `inline`
```cpp
// Sugerencia al compilador para expandir el código
inline int cuadrado(int x) {
    return x * x;
}

// Template functions son inline por defecto
template<typename T>
T maximo(T a, T b) {
    return (a > b) ? a : b;
}
```

### 🔹 6.4 Recursividad
```cpp
// Factorial recursivo
unsigned long long factorial(int n) {
    if (n < 0) throw invalid_argument("No factorial para negativos");
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Fibonacci con memoization
#include <unordered_map>
long fibonacci(int n) {
    static unordered_map<int, long> cache;
    
    if (n <= 1) return n;
    if (cache.find(n) != cache.end()) return cache[n];
    
    cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return cache[n];
}
```

---

## 🟥 7. EJEMPLOS APLICADOS EN SISTEMAS REALES

### 🔹 Sistema de Juego
```cpp
class Juego {
    int puntaje = 0;
    int vidas = 3;
public:
    // Paso por referencia para modificar estado
    void agregarPuntos(int& score, int puntos) {
        score += puntos;
        cout << "+" << puntos << " puntos! Total: " << score << endl;
    }
    
    // Lambda para comportamiento dinámico
    void ejecutarPowerUp(function<void()> efecto) {
        cout << "¡PowerUp activado! ";
        efecto();
    }
    
    // Callback para eventos
    void configurarOnGameOver(function<void(int)> callback) {
        onGameOver = callback;
    }
    
private:
    function<void(int)> onGameOver;
};

// Uso
Juego juego;
juego.agregarPuntos(juego.puntaje, 100);

juego.ejecutarPowerUp([]() {
    cout << "Invencibilidad por 5 segundos!\n";
});

juego.configurarOnGameOver([](int puntajeFinal) {
    cout << "Game Over! Puntaje: " << puntajeFinal << endl;
});
```

### 🔹 Sistema de Procesamiento de Datos
```cpp
template<typename T>
vector<T> filtrar(const vector<T>& datos, function<bool(const T&)> criterio) {
    vector<T> resultado;
    for (const auto& item : datos) {
        if (criterio(item)) {
            resultado.push_back(item);
        }
    }
    return resultado;
}

// Uso con diferentes criterios
vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Pares
auto pares = filtrar(numeros, [](int n) { return n % 2 == 0; });

// Mayores que 5
auto mayores = filtrar(numeros, [](int n) { return n > 5; });

// Personalizado
int limite = 7;
auto custom = filtrar(numeros, [limite](int n) { 
    return n > limite && n % 2 != 0; 
});
```

---

## 🟥 8. MEJORES PRÁCTICAS Y RECOMENDACIONES

### ✅ **Elección de Paso de Parámetros:**
```cpp
// ✅ Pequeños tipos nativos → por valor
void procesar(int x, char c, bool flag);

// ✅ Objetos grandes → por referencia constante  
void procesar(const string& texto, const vector<int>& datos);

// ✅ Necesitas modificar → por referencia
void modificar(string& texto, vector<int>& datos);

// ✅ Parámetro opcional → por puntero
void configurar(int* valorOpcional = nullptr);

// ✅ Múltiples valores de salida → por referencia
bool dividir(int a, int b, int& cociente, int& resto);
```

### ✅ **Nombrado Clarificador:**
```cpp
// ❌ Mal nombre
void f(int x, int y);

// ✅ Buen nombre
void dibujarRectangulo(int ancho, int altura);
```

### ✅ **Una Función, Una Responsabilidad:**
```cpp
// ❌ Hace demasiado
void procesarUsuarioCompleto();

// ✅ Separado en responsabilidades
bool validarDatosUsuario(const Usuario& usuario);
void guardarEnBaseDeDatos(const Usuario& usuario);
void enviarEmailConfirmacion(const Usuario& usuario);
```

---

## 🟥 9. MINI-PREGUNTA DE COMPRENSIÓN

**¿Cuándo preferís pasar un parámetro por referencia (`&`) y cuándo preferís pasar un puntero (`*`)?**

### 🎯 **Respuesta Esperada:**

**Uso Referencias (`&`) cuando:**
- El parámetro **siempre debe existir** (no es opcional)
- Quieres **sintaxis más limpia** sin `*` y `&`
- Trabajas con **objetos grandes** que no quieres copiar
- Necesitas **modificar el original** directamente

**Uso Punteros (`*`) cuando:**
- El parámetro es **opcional** (puede ser `nullptr`)
- Trabajas con **arrays C-style** o memoria dinámica
- Necesitas **reasignar** lo que apunta el parámetro
- Interoperas con **código C** o APIs que usan punteros
- Implementas **polimorfismo** con herencia

### 💡 **Regla Mnemotécnica:**
- **Referencia**: "Este objeto existe y trabajaré con él directamente"
- **Puntero**: "Este objeto podría existir o no, o necesito manipular su dirección"

