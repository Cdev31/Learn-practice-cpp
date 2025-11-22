# 📝 Resumen Completo de Tipos de Datos en C++

---

## # 1. TIPOS DE DATOS PRIMITIVOS

### ## 1.1 Enteros

| Tipo | Tamaño típico | Rango aproximado | Uso recomendado |
|------|---------------|------------------|-----------------|
| `short` | 2 bytes | –32,768 a 32,767 | Datos pequeños, sensores |
| `unsigned short` | 2 bytes | 0 a 65,535 | Contadores pequeños |
| `int` | 4 bytes | –2,147,483,648 a 2,147,483,647 | Uso general |
| `unsigned int` | 4 bytes | 0 a 4,294,967,295 | Conteos que jamás serán negativos |
| `long` | 4–8 bytes | Depende del SO | Histórico, evitar si posible |
| `unsigned long` | igual que long | — | Lo mismo que arriba |
| `long long` | 8 bytes | ±9,223,372,036,854,775,807 | Conteos grandes, IDs, sumatorias |
| `unsigned long long` | 8 bytes | 0 a 18,446,744,073,709,551,615 | Conteos enormes sin negativos |

**Ejemplos prácticos:**
```cpp
// ✅ Uso correcto de enteros
int edad = 25;                          // Uso general
unsigned int contadorVisitas = 1000;    // Nunca será negativo
long long poblacionMundial = 7800000000LL;  // Número muy grande
short temperatura = -5;                 // Valor pequeño con signo
```

### ## 1.2 Coma Flotante

| Tipo | Tamaño | Precisión | Uso recomendado |
|------|--------|-----------|-----------------|
| `float` | 4 bytes | 6–7 dígitos decimales | Juegos, GPU, IA (rendimiento) |
| `double` | 8 bytes | 15–16 dígitos decimales | Cálculos generales (estándar) |
| `long double` | 10–16 bytes | 18–20 dígitos decimales | Ciencia, alta precisión |

**Ejemplos prácticos:**
```cpp
// ✅ Uso correcto de punto flotante
float gravedad = 9.8f;                  // Juegos, física simple
double pi = 3.141592653589793;          // Cálculos matemáticos
long double constanteFisica = 1.602176634e-19L; // Alta precisión

// ❌ Evitar comparaciones exactas
double a = 0.1 + 0.2;
double b = 0.3;
// if (a == b) // ¡Peligroso!
if (abs(a - b) < 1e-9) { // ✅ Forma correcta
    cout << "Son iguales dentro de la precisión\n";
}
```

### ## 1.3 Caracteres

| Tipo | Tamaño | Descripción | Uso |
|------|--------|-------------|-----|
| `char` | 1 byte | Carácter ASCII | Texto simple |
| `signed char` | 1 byte | Carácter con signo (-128 a 127) | Casos especiales |
| `unsigned char` | 1 byte | Byte puro (0 a 255) | Buffers, binarios, imágenes |

**Ejemplos prácticos:**
```cpp
// ✅ Uso correcto de caracteres
char letra = 'A';                       // Carácter simple
unsigned char buffer[1024];             // Datos binarios
signed char valorTemperatura = -25;     // Temperatura con signo

// Caracteres especiales
char nuevaLinea = '\n';
char tabulador = '\t';
char comillaSimple = '\'';
```

### ## 1.4 Booleanos

| Tipo | Tamaño | Valores |
|------|--------|---------|
| `bool` | 1 byte | `true`, `false` |

**Ejemplos prácticos:**
```cpp
// ✅ Uso correcto de booleanos
bool esValido = true;
bool encontrado = false;
bool puedeContinuar = (edad >= 18) && (tieneLicencia);

// Conversiones implícitas
int numero = 42;
bool comoBool = numero;  // true (diferente de 0)
```

### ## 1.5 Tipo Especial: `void`

**No tiene tamaño.** Se usa para:

- Funciones sin retorno (`void f()`)
- Punteros genéricos (`void*`)

**Ejemplos prácticos:**
```cpp
// ✅ Uso correcto de void
void saludar() {                        // Función sin retorno
    cout << "Hola mundo!\n";
}

void* memoriaGenerica = malloc(100);    // Puntero genérico

// Conversión segura de void*
int* ptrEntero = static_cast<int*>(memoriaGenerica);
```

---

## # 2. TIPOS DEL PREPROCESADOR / DIRECTIVAS

### ## 2.1 `size_t`

**¿Qué es?** Entero **sin signo** que representa tamaños y conteos de memoria.
Proviene de `<cstddef>` / `<stddef.h>`.

**Tamaño:**
- 4 bytes en sistemas 32 bits
- 8 bytes en sistemas 64 bits

**Ejemplos prácticos:**
```cpp
#include <cstddef>

// ✅ Uso correcto de size_t
size_t tamanoArray = 100;
size_t longitudCadena = strlen("Hola mundo");

for (size_t i = 0; i < tamanoArray; i++) {  // Índices seguros
    // procesar elemento i
}

size_t tamano = sizeof(long long);      // Resultado de sizeof
```

### ## 2.2 `ptrdiff_t`

**¿Qué es?** Entero **con signo** que mide la diferencia entre dos punteros.
Proviene de `<cstddef>`.

**Ejemplos prácticos:**
```cpp
#include <cstddef>

int arreglo[10] = {0};
ptrdiff_t diferencia = &arreglo[9] - &arreglo[4];  // Vale 5

// Uso con iteradores
std::vector<int> vec = {1, 2, 3, 4, 5};
auto it1 = vec.begin();
auto it2 = vec.end();
ptrdiff_t elementos = it2 - it1;  // Diferencia entre iteradores
```

### ## 2.3 `uintptr_t` / `intptr_t`

Provienen de `<cstdint>`.

**Descripción:** Enteros capaces de almacenar **direcciones de memoria**.

**Ejemplos prácticos:**
```cpp
#include <cstdint>

int variable = 42;
uintptr_t direccion = reinterpret_cast<uintptr_t>(&variable);

// Manipulación de direcciones
uintptr_t nuevaDir = direccion + 0x1000;

// Reconversión a puntero
int* ptr = reinterpret_cast<int*>(nuevaDir);
```

### ## 2.4 Tipos Exactos de `<cstdint>`

| Tipo | Tamaño exacto | Uso |
|------|---------------|-----|
| `int8_t` / `uint8_t` | 1 byte | bytes, protocolos, binarios |
| `int16_t` / `uint16_t` | 2 bytes | hardware, redes |
| `int32_t` / `uint32_t` | 4 bytes | datos portables |
| `int64_t` / `uint64_t` | 8 bytes | archivos, IDs grandes |

**Ejemplos prácticos:**
```cpp
#include <cstdint>

// ✅ Para protocolos de red
struct CabeceraPaquete {
    uint32_t id;
    uint16_t longitud;
    uint8_t tipo;
    uint8_t flags;
};

// ✅ Para archivos binarios
int32_t leerEntero32Bits(std::ifstream& archivo) {
    int32_t valor;
    archivo.read(reinterpret_cast<char*>(&valor), sizeof(valor));
    return valor;
}

// ✅ Para sistemas embebidos
uint16_t leerSensorADC() {
    return 0x3FF;  // Valor de 10 bits
}
```

### ## 2.5 Macros de Límites (`<climits>` y `<cfloat>`)

**Límites de enteros (`<climits>`):**
```cpp
#include <climits>

cout << "INT_MAX: " << INT_MAX << endl;      // 2,147,483,647
cout << "INT_MIN: " << INT_MIN << endl;      // -2,147,483,648
cout << "UINT_MAX: " << UINT_MAX << endl;    // 4,294,967,295
cout << "LLONG_MAX: " << LLONG_MAX << endl;  // 9,223,372,036,854,775,807
```

**Límites de punto flotante (`<cfloat>`):**
```cpp
#include <cfloat>

cout << "FLT_MAX: " << FLT_MAX << endl;      // ~3.4e38
cout << "DBL_MAX: " << DBL_MAX << endl;      // ~1.8e308
cout << "FLT_DIG: " << FLT_DIG << endl;      // 6 (dígitos decimales de precisión)
```

---

## # 3. TIPOS COMPLEJOS (DE ALTO NIVEL)

### `std::string`
```cpp
#include <string>
std::string nombre = "Juan Pérez";
std::string saludo = "Hola " + nombre;
```

### `std::vector<T>`
```cpp
#include <vector>
std::vector<int> numeros = {1, 2, 3, 4, 5};
numeros.push_back(6);
```

### `std::array<T, N>`
```cpp
#include <array>
std::array<int, 5> arregloFijo = {1, 2, 3, 4, 5};
```

### `std::pair<T1, T2>`
```cpp
#include <utility>
std::pair<std::string, int> persona = {"Ana", 25};
```

### `std::tuple<T...>`
```cpp
#include <tuple>
std::tuple<std::string, int, double> datos = {"Carlos", 30, 1.75};
```

### `std::bitset<N>`
```cpp
#include <bitset>
std::bitset<8> bits("11001010");
bits.set(0);  // Poner bit 0 a 1
```

---

## # 4. RECOMENDACIONES DE USO

### ✅ **Reglas Generales:**

1. **Usa `int` para casi todo** - Es el tipo entero por defecto
2. **Usa `double` para cálculos reales** - Precisión balanceada
3. **Usa `long long` para conteos grandes** - IDs, poblaciones, sumas grandes
4. **Usa `size_t` para índices y tamaños** - Compatible con contenedores STL
5. **Usa `uint8_t` para bytes crudos** - Protocolos, datos binarios

### ✅ **Casos Específicos:**

```cpp
// ✅ EJEMPLOS CORRECTOS:

// Uso general
int calcularPromedio(const std::vector<int>& numeros);

// Conteos grandes (nunca negativos)
size_t contarElementos(const std::vector<std::string>& lista);

// IDs únicos grandes
long long idUsuario = 123456789012345LL;

// Datos binarios/red
uint8_t buffer[1024];
uint32_t checksum = calcularChecksum(buffer);

// Alta precisión científica
long double constanteFisica = 6.67430e-11L;
```

### ❌ **Qué Evitar:**

1. **Evita `unsigned` salvo razones fuertes** - Puede causar bugs sutiles
2. **Evita `long double` salvo matemáticas avanzadas** - Overkill para la mayoría de casos
3. **Evita `long` porque cambia según el sistema** - No es portable
4. **Evita `signed char` para texto** - Usa `char` simple

### ✅ **Para Código Portable:**

```cpp
#include <cstdint>

// Para protocolos de red
struct PaqueteRed {
    uint32_t id;
    uint16_t puerto;
    uint8_t tipo;
    uint8_t flags;
};

// Para archivos binarios
struct EncabezadoArchivo {
    int32_t version;
    int64_t tamano;
    uint16_t checksum;
};
```

---

## # 5. EJEMPLOS RÁPIDOS

### Índice Seguro con `size_t`
```cpp
std::string texto = "Hola mundo";
for (size_t i = 0; i < texto.size(); i++) {
    std::cout << texto[i];
}
```

### Bytes Puros con `uint8_t`
```cpp
uint8_t pixelRojo = 0xFF;
uint8_t pixelVerde = 0x80;
uint8_t pixelAzul = 0x00;
```

### Conteo Grande con `long long`
```cpp
long long visitasTotales = 10'000'000'000LL;
long long tamanoArchivo = 2LL * 1024 * 1024 * 1024;  // 2 GB
```

### Diferencia entre Punteros
```cpp
int arreglo[20];
ptrdiff_t distancia = &arreglo[15] - &arreglo[5];  // 10 elementos
```

### Tipos Exactos para Red
```cpp
struct PaqueteNetwork {
    uint32_t id;
    uint16_t longitud;
    uint8_t protocolo;
    uint8_t ttl;
};
```

### Validación de Rangos
```cpp
#include <climits>

int valorUsuario;
std::cin >> valorUsuario;

if (valorUsuario < INT_MIN || valorUsuario > INT_MAX) {
    std::cerr << "Valor fuera de rango\n";
}
```

---

## 🎯 **RESUMEN EJECUTIVO**

| Escenario | Tipo Recomendado | Alternativa |
|-----------|------------------|-------------|
| Contadores generales | `int` | `size_t` |
| Índices de arrays | `size_t` | `int` |
| Números muy grandes | `long long` | `int64_t` |
| Punto flotante general | `double` | `float` |
| Alta precisión | `long double` | - |
| Datos binarios | `uint8_t` | `unsigned char` |
| Protocolos de red | Tipos `<cstdint>` | - |
| Texto | `std::string` | `char[]` |

**Regla de oro:** Cuando dudes, usa `int` para enteros y `double` para decimales. Solo especializa cuando tengas una razón específica.
