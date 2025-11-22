# 🚀 Bibliotecas Estándar de C++ - Guía Completa

## 🟦 1. **Entrada/Salida (I/O)**

### 📌 `<iostream>` - Flujos Estándar
```cpp
#include <iostream>
#include <string>

int main() {
    // Salida estándar
    std::cout << "Hola Mundo!" << std::endl;
    
    // Salida de error
    std::cerr << "Error crítico" << std::endl;
    
    // Log (bufferizado)
    std::clog << "Mensaje de log" << std::endl;
    
    // Entrada
    int edad;
    std::string nombre;
    
    std::cout << "Nombre: ";
    std::cin >> nombre;
    
    std::cout << "Edad: ";
    std::cin >> edad;
    
    std::cout << "Hola " << nombre << ", tienes " << edad << " años" << std::endl;
    
    return 0;
}
```

### 📌 `<fstream>` - Manipulación de Archivos
```cpp
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // Escritura
    std::ofstream archivo_salida("datos.txt");
    if (archivo_salida.is_open()) {
        archivo_salida << "Línea 1\n";
        archivo_salida << "Línea 2\n";
        archivo_salida << 42 << " " << 3.14 << std::endl;
        archivo_salida.close();
    }
    
    // Lectura
    std::ifstream archivo_entrada("datos.txt");
    std::string linea;
    
    if (archivo_entrada.is_open()) {
        while (std::getline(archivo_entrada, linea)) {
            std::cout << "Leído: " << linea << std::endl;
        }
        archivo_entrada.close();
    }
    
    // Modo append
    std::ofstream archivo_append("datos.txt", std::ios::app);
    archivo_append << "Línea agregada\n";
    archivo_append.close();
    
    return 0;
}
```

### 📌 `<sstream>` - String Streams
```cpp
#include <sstream>
#include <iostream>
#include <string>

int main() {
    // String a valores
    std::string datos = "Juan 25 8.5";
    std::stringstream ss(datos);
    
    std::string nombre;
    int edad;
    double promedio;
    
    ss >> nombre >> edad >> promedio;
    std::cout << nombre << " - " << edad << " - " << promedio << std::endl;
    
    // Valores a string
    std::stringstream ss2;
    ss2 << "Resultado: " << 42 << " - " << 3.1416;
    std::string resultado = ss2.str();
    std::cout << resultado << std::endl;
    
    // Parsing CSV
    std::string csv = "manzana,10,2.50\nnaranja,20,1.75";
    std::stringstream ss3(csv);
    std::string linea;
    
    while (std::getline(ss3, linea)) {
        std::stringstream linea_ss(linea);
        std::string producto, cantidad, precio;
        
        std::getline(linea_ss, producto, ',');
        std::getline(linea_ss, cantidad, ',');
        std::getline(linea_ss, precio, ',');
        
        std::cout << "Producto: " << producto 
                  << ", Cantidad: " << cantidad
                  << ", Precio: " << precio << std::endl;
    }
    
    return 0;
}
```

## 🟦 2. **Estructuras de Datos de la STL**

### 📌 `<vector>` - Array Dinámico
```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numeros = {1, 2, 3, 4, 5};
    
    // Operaciones básicas
    numeros.push_back(6);           // Agregar al final
    numeros.pop_back();             // Eliminar último
    numeros.insert(numeros.begin() + 2, 99); // Insertar
    numeros.erase(numeros.begin() + 1);      // Eliminar
    
    // Capacidad
    std::cout << "Tamaño: " << numeros.size() << std::endl;
    std::cout << "Capacidad: " << numeros.capacity() << std::endl;
    
    // Acceso
    std::cout << "Primero: " << numeros.front() << std::endl;
    std::cout << "Último: " << numeros.back() << std::endl;
    std::cout << "Elemento 2: " << numeros[1] << std::endl;
    
    // Recorrido
    for (int num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Vector de otros tipos
    std::vector<std::string> palabras = {"hola", "mundo"};
    std::vector<std::vector<int>> matriz = {{1, 2}, {3, 4}};
    
    return 0;
}
```

### 📌 `<array>` - Array de Tamaño Fijo
```cpp
#include <array>
#include <iostream>

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    
    // Operaciones
    std::cout << "Tamaño: " << arr.size() << std::endl;
    std::cout << "Primero: " << arr.front() << std::endl;
    std::cout << "Último: " << arr.back() << std::endl;
    
    // Acceso seguro
    try {
        std::cout << "Elemento 10: " << arr.at(10) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Llenar con mismo valor
    arr.fill(42);
    
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

### 📌 Contenedores Asociativos
```cpp
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iostream>

int main() {
    // Map ordenado
    std::map<std::string, int> edad;
    edad["Juan"] = 25;
    edad["Maria"] = 30;
    edad["Pedro"] = 20;
    
    for (const auto& [nombre, edad_val] : edad) {
        std::cout << nombre << ": " << edad_val << std::endl;
    }
    
    // Map no ordenado (hash map)
    std::unordered_map<std::string, double> precios;
    precios["manzana"] = 2.50;
    precios["naranja"] = 1.75;
    
    // Set ordenado
    std::set<int> numeros = {3, 1, 4, 1, 5, 9}; // {1, 3, 4, 5, 9}
    
    // Set no ordenado
    std::unordered_set<std::string> palabras = {"hola", "mundo", "hola"};
    
    return 0;
}
```

### 📌 Contenedores de Secuencia Especializados
```cpp
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <iostream>

int main() {
    // Lista doblemente enlazada
    std::list<int> lista = {1, 2, 3};
    lista.push_front(0);  // Eficiente
    lista.push_back(4);   // Eficiente
    
    // Deque - vector doblemente terminado
    std::deque<int> dq;
    dq.push_front(1);  // Eficiente
    dq.push_back(2);   // Eficiente
    
    // Queue - FIFO
    std::queue<int> cola;
    cola.push(1);
    cola.push(2);
    cola.push(3);
    
    while (!cola.empty()) {
        std::cout << cola.front() << " ";  // 1 2 3
        cola.pop();
    }
    std::cout << std::endl;
    
    // Stack - LIFO
    std::stack<int> pila;
    pila.push(1);
    pila.push(2);
    pila.push(3);
    
    while (!pila.empty()) {
        std::cout << pila.top() << " ";  // 3 2 1
        pila.pop();
    }
    std::cout << std::endl;
    
    // Priority queue - heap
    std::priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(2);
    
    while (!pq.empty()) {
        std::cout << pq.top() << " ";  // 4 3 2 1
        pq.pop();
    }
    std::cout << std::endl;
    
    return 0;
}
```

## 🟦 3. **Algoritmos y Utilidades**

### 📌 `<algorithm>` - Algoritmos Genéricos
```cpp
#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

int main() {
    std::vector<int> numeros = {5, 2, 8, 1, 9, 3};
    
    // Ordenamiento
    std::sort(numeros.begin(), numeros.end());
    
    // Búsqueda
    auto it = std::find(numeros.begin(), numeros.end(), 8);
    if (it != numeros.end()) {
        std::cout << "Encontrado: " << *it << std::endl;
    }
    
    // Búsqueda binaria (requiere ordenado)
    bool encontrado = std::binary_search(numeros.begin(), numeros.end(), 5);
    
    // Conteo
    int cantidad = std::count(numeros.begin(), numeros.end(), 3);
    
    // Máximo y mínimo
    auto max_it = std::max_element(numeros.begin(), numeros.end());
    auto min_it = std::min_element(numeros.begin(), numeros.end());
    
    // Transformación
    std::vector<int> dobles(numeros.size());
    std::transform(numeros.begin(), numeros.end(), dobles.begin(),
                   [](int x) { return x * 2; });
    
    // Eliminar duplicados
    numeros.erase(std::unique(numeros.begin(), numeros.end()), numeros.end());
    
    // Reverso
    std::reverse(numeros.begin(), numeros.end());
    
    // Suma acumulativa
    int suma = std::accumulate(numeros.begin(), numeros.end(), 0);
    
    // Algoritmos de modificación
    std::fill(numeros.begin(), numeros.end(), 42);
    std::generate(numeros.begin(), numeros.end(), []() { return rand() % 100; });
    
    // Partición
    auto pivot = std::partition(numeros.begin(), numeros.end(),
                               [](int x) { return x % 2 == 0; });
    
    std::cout << "Suma: " << suma << std::endl;
    
    return 0;
}
```

### 📌 `<functional>` - Objetos Función
```cpp
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // std::function - wrapper para cualquier cosa llamable
    std::function<int(int, int)> operacion;
    
    operacion = [](int a, int b) { return a + b; };
    std::cout << "Suma: " << operacion(5, 3) << std::endl;
    
    operacion = std::multiplies<int>();
    std::cout << "Multiplicación: " << operacion(5, 3) << std::endl;
    
    // Bind - crear funciones parcialmente aplicadas
    auto sumar_5 = std::bind(std::plus<int>(), std::placeholders::_1, 5);
    std::cout << "10 + 5 = " << sumar_5(10) << std::endl;
    
    // Functores predefinidos
    std::vector<int> nums = {1, 2, 3, 4, 5};
    
    // Usar functor con algoritmo
    std::transform(nums.begin(), nums.end(), nums.begin(),
                  std::bind(std::multiplies<int>(), std::placeholders::_1, 2));
    
    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

## 🟦 4. **Cadenas y Texto**

### 📌 `<string>` - Cadena Moderna
```cpp
#include <string>
#include <iostream>
#include <algorithm>

int main() {
    std::string texto = "Hola Mundo C++";
    
    // Operaciones básicas
    std::cout << "Tamaño: " << texto.size() << std::endl;
    std::cout << "Vacío: " << texto.empty() << std::endl;
    
    // Búsqueda
    size_t pos = texto.find("Mundo");
    if (pos != std::string::npos) {
        std::cout << "Encontrado en posición: " << pos << std::endl;
    }
    
    // Subcadena
    std::string sub = texto.substr(5, 5); // "Mundo"
    
    // Reemplazo
    texto.replace(0, 4, "Hello"); // "Hello Mundo C++"
    
    // Conversión
    int numero = std::stoi("42");
    double decimal = std::stod("3.1416");
    std::string str_num = std::to_string(123);
    
    // Transformaciones
    std::transform(texto.begin(), texto.end(), texto.begin(), ::toupper);
    
    std::cout << texto << std::endl;
    
    return 0;
}
```

### 📌 `<regex>` - Expresiones Regulares
```cpp
#include <regex>
#include <iostream>
#include <string>

int main() {
    std::string texto = "Los precios son $15, $20 y $30. Contacto: user@example.com";
    
    // Validación de email
    std::regex patron_email(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)");
    
    if (std::regex_search(texto, patron_email)) {
        std::cout << "Email válido encontrado" << std::endl;
    }
    
    // Extracción de precios
    std::regex patron_precios(R"(\$(\d+))");
    auto inicio = texto.cbegin();
    auto fin = texto.cend();
    std::smatch coincidencia;
    
    std::cout << "Precios encontrados: ";
    while (std::regex_search(inicio, fin, coincidencia, patron_precios)) {
        std::cout << "$" << coincidencia[1] << " ";
        inicio = coincidencia[0].second;
    }
    std::cout << std::endl;
    
    // Reemplazo
    std::string resultado = std::regex_replace(texto, patron_precios, "€$1");
    std::cout << "Reemplazado: " << resultado << std::endl;
    
    return 0;
}
```

## 🟦 5. **Matemáticas y Números**

### 📌 `<cmath>` - Funciones Matemáticas
```cpp
#include <cmath>
#include <iostream>
#include <numbers>  // C++20

int main() {
    // Constantes (C++20)
    // std::cout << "Pi: " << std::numbers::pi << std::endl;
    
    // Funciones básicas
    std::cout << "Raíz cuadrada: " << std::sqrt(25.0) << std::endl;
    std::cout << "Potencia: " << std::pow(2.0, 3.0) << std::endl;
    std::cout << "Valor absoluto: " << std::abs(-5.5) << std::endl;
    
    // Trigonometría
    std::cout << "Seno: " << std::sin(3.14159 / 2) << std::endl;
    std::cout << "Coseno: " << std::cos(0) << std::endl;
    
    // Exponencial y logaritmo
    std::cout << "Exponencial: " << std::exp(1.0) << std::endl;
    std::cout << "Logaritmo natural: " << std::log(2.71828) << std::endl;
    std::cout << "Logaritmo base 10: " << std::log10(100.0) << std::endl;
    
    // Redondeo
    std::cout << "Techo: " << std::ceil(3.2) << std::endl;
    std::cout << "Piso: " << std::floor(3.8) << std::endl;
    std::cout << "Redondeo: " << std::round(3.5) << std::endl;
    
    return 0;
}
```

### 📌 `<limits>` - Límites Numéricos
```cpp
#include <limits>
#include <iostream>

int main() {
    std::cout << "Límites para int:" << std::endl;
    std::cout << "Mínimo: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Máximo: " << std::numeric_limits<int>::max() << std::endl;
    
    std::cout << "Límites para double:" << std::endl;
    std::cout << "Mínimo: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "Máximo: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "Épsilon: " << std::numeric_limits<double>::epsilon() << std::endl;
    
    // Verificación de propiedades
    std::cout << "int con signo: " << std::numeric_limits<int>::is_signed << std::endl;
    std::cout << "int es entero: " << std::numeric_limits<int>::is_integer << std::endl;
    
    return 0;
}
```

## 🟦 6. **Tiempo y Fechas**

### 📌 `<chrono>` - Manejo Moderno de Tiempo
```cpp
#include <chrono>
#include <iostream>
#include <thread>

int main() {
    using namespace std::chrono;
    
    // Medición de tiempo
    auto inicio = high_resolution_clock::now();
    
    // Simular trabajo
    std::this_thread::sleep_for(milliseconds(100));
    
    auto fin = high_resolution_clock::now();
    
    // Diferencia en diferentes unidades
    auto ms = duration_cast<milliseconds>(fin - inicio);
    auto micros = duration_cast<microseconds>(fin - inicio);
    auto nanos = duration_cast<nanoseconds>(fin - inicio);
    
    std::cout << "Tiempo transcurrido: " << ms.count() << " ms" << std::endl;
    std::cout << "Tiempo transcurrido: " << micros.count() << " μs" << std::endl;
    std::cout << "Tiempo transcurrido: " << nanos.count() << " ns" << std::endl;
    
    // Trabajar con time_points
    auto ahora = system_clock::now();
    auto tiempo_t = system_clock::to_time_t(ahora);
    
    std::cout << "Timestamp actual: " << std::ctime(&tiempo_t);
    
    // Duración específica
    hours una_hora(1);
    minutes treinta_min(30);
    auto total = una_hora + treinta_min;
    
    std::cout << "90 minutos en segundos: " 
              << duration_cast<seconds>(total).count() << std::endl;
    
    return 0;
}
```

## 🟦 7. **Concurrencia**

### 📌 `<thread>` - Programación Multihilo
```cpp
#include <thread>
#include <iostream>
#include <vector>

void tarea(int id) {
    std::cout << "Hilo " << id << " ejecutándose" << std::endl;
}

int main() {
    // Crear múltiples hilos
    std::vector<std::thread> hilos;
    
    for (int i = 0; i < 5; ++i) {
        hilos.emplace_back(tarea, i);
    }
    
    // Esperar a que todos terminen
    for (auto& hilo : hilos) {
        hilo.join();
    }
    
    std::cout << "Todos los hilos terminaron" << std::endl;
    
    return 0;
}
```

### 📌 `<mutex>` - Sincronización
```cpp
#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

std::mutex mtx;
int contador = 0;

void incrementar() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);  // RAII
        ++contador;
    }
}

int main() {
    std::vector<std::thread> hilos;
    
    for (int i = 0; i < 10; ++i) {
        hilos.emplace_back(incrementar);
    }
    
    for (auto& hilo : hilos) {
        hilo.join();
    }
    
    std::cout << "Contador final: " << contador << std::endl;
    
    return 0;
}
```

## 🟦 8. **Memoria Inteligente**

### 📌 `<memory>` - Punteros Inteligentes
```cpp
#include <memory>
#include <iostream>

class Recurso {
public:
    Recurso() { std::cout << "Recurso creado" << std::endl; }
    ~Recurso() { std::cout << "Recurso destruido" << std::endl; }
    void usar() { std::cout << "Usando recurso" << std::endl; }
};

int main() {
    // unique_ptr - propiedad exclusiva
    std::unique_ptr<Recurso> ptr1 = std::make_unique<Recurso>();
    ptr1->usar();
    
    // Movimiento de unique_ptr
    std::unique_ptr<Recurso> ptr2 = std::move(ptr1);
    if (!ptr1) {
        std::cout << "ptr1 ahora es nulo" << std::endl;
    }
    
    // shared_ptr - propiedad compartida
    std::shared_ptr<Recurso> shared1 = std::make_shared<Recurso>();
    {
        std::shared_ptr<Recurso> shared2 = shared1;
        std::cout << "Conteo de referencias: " << shared1.use_count() << std::endl;
    }
    std::cout << "Conteo de referencias: " << shared1.use_count() << std::endl;
    
    // weak_ptr - referencia no poseedora
    std::weak_ptr<Recurso> weak = shared1;
    
    if (auto temp = weak.lock()) {
        temp->usar();
    } else {
        std::cout << "Recurso ya no existe" << std::endl;
    }
    
    return 0;
}
```

## 🟦 9. **Sistema de Archivos**

### 📌 `<filesystem>` - Manipulación de Archivos
```cpp
#include <filesystem>
#include <iostream>
#include <vector>

namespace fs = std::filesystem;

int main() {
    // Información de archivo
    fs::path archivo("main.cpp");
    
    if (fs::exists(archivo)) {
        std::cout << "Tamaño: " << fs::file_size(archivo) << " bytes" << std::endl;
        std::cout << "Es directorio: " << fs::is_directory(archivo) << std::endl;
    }
    
    // Listar directorio
    std::cout << "Contenido del directorio actual:" << std::endl;
    for (const auto& entry : fs::directory_iterator(".")) {
        std::cout << "  " << entry.path().filename() << std::endl;
    }
    
    // Operaciones
    fs::create_directory("temp");           // Crear directorio
    fs::copy("main.cpp", "temp/copia.cpp"); // Copiar archivo
    // fs::remove_all("temp");              // Eliminar recursivo
    
    return 0;
}
```

## 🟦 10. **Manejo de Errores**

### 📌 `<stdexcept>` - Excepciones Estándar
```cpp
#include <stdexcept>
#include <iostream>
#include <vector>

double dividir(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("División por cero");
    }
    return a / b;
}

int main() {
    try {
        std::vector<int> v(5);
        
        // Acceso fuera de rango
        std::cout << v.at(10) << std::endl;  // lanza std::out_of_range
        
    } catch (const std::out_of_range& e) {
        std::cout << "Error de rango: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error general: " << e.what() << std::endl;
    }
    
    try {
        double resultado = dividir(10, 0);
    } catch (const std::invalid_argument& e) {
        std::cout << "Error matemático: " << e.what() << std::endl;
    }
    
    return 0;
}
```

## 🎯 **MINI-PREGUNTA DE COMPRENSIÓN**

**¿Para qué usarías `<algorithm>` junto con `std::vector` en un problema real?**

### 🎯 **Respuesta Esperada:**

Para **procesar y transformar datos eficientemente** - como ordenar usuarios, filtrar elementos que cumplan cierta condición, buscar valores específicos, o calcular estadísticas sobre colecciones de datos, aprovechando algoritmos optimizados en lugar de escribir loops manuales.

### 💡 **Ejemplo Práctico:**
```cpp
// Ordenar empleados por salario, filtrar los que ganan más de 50k,
// y calcular el salario promedio - todo con <algorithm>
std::sort(empleados.begin(), empleados.end(), comparar_salario);
auto it = std::remove_if(empleados.begin(), empleados.end(), 
                        [](const Empleado& e) { return e.salario <= 50000; });
double promedio = std::accumulate(empleados.begin(), it, 0.0, 
                                 [](double sum, const Empleado& e) { 
                                     return sum + e.salario; 
                                 }) / std::distance(empleados.begin(), it);
```
