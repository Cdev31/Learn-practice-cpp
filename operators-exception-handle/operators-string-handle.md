# 🚀 Operadores y Manejo Avanzado de Cadenas en C++

## 🟥 1. TODOS LOS TIPOS DE OPERADORES EN C++

### 🔹 1.1 Operadores Aritméticos

| Operador | Uso | Ejemplo | Resultado |
|----------|-----|---------|-----------|
| `+` | Suma | `5 + 3` | `8` |
| `-` | Resta | `10 - 4` | `6` |
| `*` | Multiplicación | `3 * 7` | `21` |
| `/` | División | `15 / 4` | `3` (int) |
| `%` | Módulo (resto) | `15 % 4` | `3` |

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 15, b = 4;
    
    cout << "Suma: " << (a + b) << endl;           // 19
    cout << "Resta: " << (a - b) << endl;          // 11
    cout << "Multiplicación: " << (a * b) << endl; // 60
    cout << "División entera: " << (a / b) << endl; // 3
    cout << "Módulo: " << (a % b) << endl;         // 3
    
    // División con decimales
    double x = 15.0, y = 4.0;
    cout << "División decimal: " << (x / y) << endl; // 3.75
    
    return 0;
}
```

### 🔹 1.2 Operadores Relacionales (Comparación)

| Operador | Significado | Ejemplo | Resultado |
|----------|-------------|---------|-----------|
| `==` | Igual | `5 == 5` | `true` |
| `!=` | Diferente | `5 != 3` | `true` |
| `>` | Mayor | `5 > 3` | `true` |
| `<` | Menor | `5 < 3` | `false` |
| `>=` | Mayor o igual | `5 >= 5` | `true` |
| `<=` | Menor o igual | `5 <= 3` | `false` |

```cpp
int edad = 25;
double promedio = 8.5;
bool esMayor = (edad >= 18);           // true
bool esAprobado = (promedio >= 6.0);   // true
bool esPerfecto = (promedio == 10.0);  // false

// Uso en condiciones
if (edad > 0 && edad < 120) {
    cout << "Edad válida" << endl;
}
```

### 🔹 1.3 Operadores Lógicos

| Operador | Descripción | Ejemplo | Resultado |
|----------|-------------|---------|-----------|
| `&&` | AND lógico | `true && false` | `false` |
| `\|\|` | OR lógico | `true \|\| false` | `true` |
| `!` | NOT lógico | `!true` | `false` |

**Evaluación de cortocircuito:**
```cpp
#include <iostream>
using namespace std;

bool funcionA() {
    cout << "Ejecutando A" << endl;
    return true;
}

bool funcionB() {
    cout << "Ejecutando B" << endl;
    return false;
}

int main() {
    // Cortocircuito con AND: si el primero es false, no evalúa el segundo
    if (funcionB() && funcionA()) {
        // No se ejecuta - funcionB() retorna false
    }
    
    // Cortocircuito con OR: si el primero es true, no evalúa el segundo
    if (funcionA() || funcionB()) {
        // Solo se ejecuta funcionA()
    }
    
    return 0;
}
```

### 🔹 1.4 Operadores Bitwise (Manipulación de Bits)

| Operador | Significado | Ejemplo | Binario | Resultado |
|----------|-------------|---------|---------|-----------|
| `&` | AND bitwise | `6 & 3` | `110 & 011` | `2` (010) |
| `\|` | OR bitwise | `6 \| 3` | `110 \| 011` | `7` (111) |
| `^` | XOR | `6 ^ 3` | `110 ^ 011` | `5` (101) |
| `~` | NOT bitwise | `~6` | `~00000110` | `249` (11111001) |
| `<<` | Shift izquierda | `6 << 1` | `110 << 1` | `12` (1100) |
| `>>` | Shift derecha | `6 >> 1` | `110 >> 1` | `3` (11) |

```cpp
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    unsigned char a = 0b0110;  // 6
    unsigned char b = 0b0011;  // 3
    
    cout << "a = " << bitset<4>(a) << " (" << (int)a << ")" << endl;
    cout << "b = " << bitset<4>(b) << " (" << (int)b << ")" << endl;
    
    cout << "a & b = " << bitset<4>(a & b) << " (" << (int)(a & b) << ")" << endl;
    cout << "a | b = " << bitset<4>(a | b) << " (" << (int)(a | b) << ")" << endl;
    cout << "a ^ b = " << bitset<4>(a ^ b) << " (" << (int)(a ^ b) << ")" << endl;
    cout << "~a = " << bitset<8>(~a) << " (" << (int)(~a) << ")" << endl;
    cout << "a << 1 = " << bitset<8>(a << 1) << " (" << (int)(a << 1) << ")" << endl;
    cout << "a >> 1 = " << bitset<8>(a >> 1) << " (" << (int)(a >> 1) << ")" << endl;

    return 0;
}
```

**Casos de uso profesionales:**
```cpp
// Sistema de flags/permissions
enum Permisos {
    LECTURA = 1 << 0,    // 0001
    ESCRITURA = 1 << 1,  // 0010
    EJECUCION = 1 << 2,  // 0100
    ADMIN = 1 << 3       // 1000
};

int usuarioPermisos = LECTURA | ESCRITURA;  // 0011

// Verificar permisos
bool puedeLeer = (usuarioPermisos & LECTURA) != 0;
bool puedeEjecutar = (usuarioPermisos & EJECUCION) != 0;

// Agregar permiso
usuarioPermisos |= EJECUCION;

// Quitar permiso
usuarioPermisos &= ~ESCRITURA;
```

### 🔹 1.5 Operadores de Asignación

| Operador | Equivalente | Ejemplo |
|----------|-------------|---------|
| `=` | `a = b` | `x = 5` |
| `+=` | `a = a + b` | `x += 3` |
| `-=` | `a = a - b` | `x -= 2` |
| `*=` | `a = a * b` | `x *= 4` |
| `/=` | `a = a / b` | `x /= 2` |
| `%=` | `a = a % b` | `x %= 3` |
| `&=` | `a = a & b` | `x &= mask` |
| `\|=` | `a = a \| b` | `x \|= flags` |

```cpp
int contador = 10;
contador += 5;   // contador = 15
contador -= 3;   // contador = 12
contador *= 2;   // contador = 24
contador /= 4;   // contador = 6
contador %= 4;   // contador = 2

// Con bits
int flags = 0;
flags |= 0x01;   // Activar bit 0
flags |= 0x04;   // Activar bit 2
flags &= ~0x01;  // Desactivar bit 0
```

### 🔹 1.6 Operadores de Incremento y Decremento

```cpp
int a = 5, b = 5;

// Pre-incremento: incrementa primero, luego usa el valor
int x = ++a;  // a = 6, x = 6

// Post-incremento: usa el valor primero, luego incrementa
int y = b++;  // b = 6, y = 5

cout << "Pre-incremento: a=" << a << ", x=" << x << endl;
cout << "Post-incremento: b=" << b << ", y=" << y << endl;

// En loops
for (int i = 0; i < 5; ++i) {  // Preferir ++i para eficiencia
    cout << i << " ";
}
```

**Regla de eficiencia:** Siempre usa `++i` en loops cuando no necesites el valor anterior.

### 🔹 1.7 Operador Ternario (`? :`)

```cpp
int edad = 20;
string categoria = (edad >= 18) ? "Adulto" : "Menor";
cout << categoria << endl;  // "Adulto"

// Anidado (usar con cuidado)
int nota = 85;
string resultado = (nota >= 90) ? "Excelente" : 
                  (nota >= 70) ? "Aprobado" : "Reprobado";

// En asignaciones
int max = (a > b) ? a : b;
```

### 🔹 1.8 Operador `sizeof`

```cpp
#include <iostream>
using namespace std;

struct Persona {
    char nombre[50];
    int edad;
    double altura;
};

int main() {
    cout << "sizeof(int): " << sizeof(int) << " bytes" << endl;
    cout << "sizeof(double): " << sizeof(double) << " bytes" << endl;
    cout << "sizeof(Persona): " << sizeof(Persona) << " bytes" << endl;
    
    int arr[10];
    cout << "sizeof(arr): " << sizeof(arr) << " bytes" << endl;
    cout << "Elementos en arr: " << (sizeof(arr) / sizeof(arr[0])) << endl;
    
    return 0;
}
```

### 🔹 1.9 Operadores de Punteros

| Operador | Significado | Ejemplo |
|----------|-------------|---------|
| `*` | Dereferenciar | `*ptr = 5` |
| `&` | Obtener dirección | `ptr = &variable` |
| `->` | Acceder miembro | `ptr->miembro` |

```cpp
#include <iostream>
using namespace std;

struct Punto {
    int x, y;
};

int main() {
    int valor = 42;
    int* ptr = &valor;
    
    cout << "Valor: " << valor << endl;           // 42
    cout << "Dirección: " << ptr << endl;         // 0x...
    cout << "Dereferenciado: " << *ptr << endl;   // 42
    
    *ptr = 100;  // Modificar a través del puntero
    cout << "Nuevo valor: " << valor << endl;     // 100
    
    Punto p = {10, 20};
    Punto* ptrPunto = &p;
    
    // Dos formas equivalentes
    cout << "x: " << (*ptrPunto).x << endl;  // 10
    cout << "y: " << ptrPunto->y << endl;    // 20
    
    return 0;
}
```

### 🔹 1.10 Operador Coma `,`

```cpp
#include <iostream>
using namespace std;

int main() {
    // Evalúa de izquierda a derecha, retorna el último valor
    int a = (printf("Hola "), printf("Mundo\n"), 42);
    cout << "a = " << a << endl;  // a = 42
    
    // En for loops
    for (int i = 0, j = 10; i < j; i++, j--) {
        cout << "i=" << i << ", j=" << j << endl;
    }
    
    // En inicializaciones
    int x, y, z;
    x = (y = 5, z = 10, y + z);  // x = 15
    
    return 0;
}
```

### 🔹 1.11 Operador Scope `::`

```cpp
#include <iostream>
using namespace std;

int variable = 100;  // Variable global

namespace MiEspacio {
    int variable = 200;
    
    class MiClase {
    public:
        static int variable;
        void mostrar() {
            cout << "Local: " << variable << endl;
            cout << "Clase: " << MiClase::variable << endl;
            cout << "Namespace: " << MiEspacio::variable << endl;
            cout << "Global: " << ::variable << endl;
        }
    };
    
    int MiClase::variable = 300;
}

int main() {
    MiEspacio::MiClase obj;
    obj.mostrar();
    return 0;
}
```

### 🔹 1.12 Operadores de Cast

```cpp
#include <iostream>
using namespace std;

int main() {
    double pi = 3.14159;
    
    // C-style cast (evitar en C++)
    int entero = (int)pi;
    
    // static_cast (recomendado para conversiones seguras)
    int entero2 = static_cast<int>(pi);
    
    // const_cast (quitar const)
    const int valorConst = 42;
    int& valorModificable = const_cast<int&>(valorConst);
    
    // reinterpret_cast (reinterpretar bits - peligroso)
    int numero = 0x12345678;
    char* bytes = reinterpret_cast<char*>(&numero);
    
    cout << "double: " << pi << endl;
    cout << "static_cast<int>: " << entero2 << endl;
    
    return 0;
}
```

---

## 🟥 2. MANEJO AVANZADO DE CADENAS EN C++

### 🔹 2.1 Funciones Avanzadas de `std::string`

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string texto = "Hola mundo C++";
    
    // append - agregar al final
    texto.append(" programming");
    cout << "append: " << texto << endl;
    
    // insert - insertar en posición
    texto.insert(5, "mi ");
    cout << "insert: " << texto << endl;
    
    // erase - eliminar porciones
    texto.erase(5, 3);  // Elimina 3 caracteres desde posición 5
    cout << "erase: " << texto << endl;
    
    // replace - reemplazar subcadena
    texto.replace(0, 4, "Hello");  // Reemplaza 4 chars desde 0
    cout << "replace: " << texto << endl;
    
    // find - buscar subcadena
    size_t pos = texto.find("mundo");
    if (pos != string::npos) {
        cout << "'mundo' encontrado en posición: " << pos << endl;
    }
    
    // find_last_of - último ocurrencia de cualquier caracter del conjunto
    string ruta = "/home/usuario/documentos/archivo.txt";
    size_t ultimaBarra = ruta.find_last_of("/\\");
    if (ultimaBarra != string::npos) {
        string archivo = ruta.substr(ultimaBarra + 1);
        cout << "Archivo: " << archivo << endl;
    }
    
    // compare - comparar cadenas
    string clave = "admin";
    if (texto.compare(0, 5, "Hello") == 0) {
        cout << "Comienza con 'Hello'" << endl;
    }
    
    // C++20: starts_with / ends_with
    string url = "https://ejemplo.com";
    // if (url.starts_with("https")) { // C++20
    //     cout << "URL segura" << endl;
    // }
    
    return 0;
}
```

### 🔹 2.2 Parsing Profesional con `stringstream`

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // Parsing básico
    string datos = "Juan 25 Programador 75000";
    stringstream ss(datos);
    
    string nombre, ocupacion;
    int edad;
    double salario;
    
    ss >> nombre >> edad >> ocupacion >> salario;
    
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Ocupación: " << ocupacion << endl;
    cout << "Salario: " << salario << endl;
    
    // Lectura palabra por palabra
    string texto = "C++ es un lenguaje de programación poderoso";
    stringstream ss2(texto);
    string palabra;
    
    cout << "\nPalabras:" << endl;
    while (ss2 >> palabra) {
        cout << "- " << palabra << endl;
    }
    
    // Separar por delimitador específico
    string csv = "manzana,naranja,banana,uva";
    stringstream ss3(csv);
    string fruta;
    
    cout << "\nFrutas CSV:" << endl;
    while (getline(ss3, fruta, ',')) {
        cout << "- " << fruta << endl;
    }
    
    // Conversión string → número con validación
    string entrada = "123.45";
    stringstream ss4(entrada);
    double numero;
    
    if (ss4 >> numero) {
        cout << "\nNúmero convertido: " << numero << endl;
    } else {
        cout << "Error en conversión" << endl;
    }
    
    return 0;
}
```

### 🔹 2.3 Transformaciones de Cadenas

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string texto = "  Hola Mundo C++  ";
    
    // Mayúsculas/minúsculas
    string mayusculas = texto;
    transform(mayusculas.begin(), mayusculas.end(), mayusculas.begin(), ::toupper);
    cout << "Mayúsculas: '" << mayusculas << "'" << endl;
    
    string minusculas = texto;
    transform(minusculas.begin(), minusculas.end(), minusculas.begin(), ::tolower);
    cout << "Minúsculas: '" << minusculas << "'" << endl;
    
    // Invertir cadena
    string invertido = texto;
    reverse(invertido.begin(), invertido.end());
    cout << "Invertido: '" << invertido << "'" << endl;
    
    // Eliminar espacios (remove-erase idiom)
    string sinEspacios = texto;
    sinEspacios.erase(remove(sinEspacios.begin(), sinEspacios.end(), ' '), sinEspacios.end());
    cout << "Sin espacios: '" << sinEspacios << "'" << endl;
    
    // Eliminar espacios al principio y final
    string trimado = texto;
    
    // Trim inicio
    trimado.erase(trimado.begin(), find_if(trimado.begin(), trimado.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
    
    // Trim final
    trimado.erase(find_if(trimado.rbegin(), trimado.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), trimado.end());
    
    cout << "Trimado: '" << trimado << "'" << endl;
    
    return 0;
}
```

### 🔹 2.4 Conversión Cadena ↔ Números

```cpp
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    // string → números (funciones estándar)
    string strInt = "123";
    string strFloat = "45.67";
    string strDouble = "89.123456";
    
    int n = stoi(strInt);
    float f = stof(strFloat);
    double d = stod(strDouble);
    
    cout << "stoi: " << n << endl;
    cout << "stof: " << f << endl;
    cout << "stod: " << d << endl;
    
    // Con base hexadecimal
    string hexStr = "FF";
    int hexVal = stoi(hexStr, nullptr, 16);
    cout << "Hex 'FF' = " << hexVal << endl;
    
    // números → string
    string fromInt = to_string(12345);
    string fromDouble = to_string(3.14159);
    
    cout << "to_string int: " << fromInt << endl;
    cout << "to_string double: " << fromDouble << endl;
    
    // Formateo avanzado con stringstream
    stringstream ss;
    ss << "Valor: " << 42 << ", Pi: " << 3.1416 << ", Bool: " << boolalpha << true;
    string resultado = ss.str();
    cout << "stringstream: " << resultado << endl;
    
    // Precisión controlada
    stringstream ss2;
    ss2.precision(3);
    ss2 << fixed << 3.1415926535;
    cout << "Precisión 3: " << ss2.str() << endl;
    
    return 0;
}
```

### 🔹 2.5 Split Manual Profesional

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// Versión con stringstream (para delimitadores simples)
vector<string> split(const string& s, char delim) {
    vector<string> tokens;
    string token;
    stringstream ss(s);
    
    while (getline(ss, token, delim)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}

// Versión con find (más flexible)
vector<string> split_find(const string& s, const string& delim) {
    vector<string> tokens;
    size_t start = 0, end = 0;
    
    while ((end = s.find(delim, start)) != string::npos) {
        if (end != start) {
            tokens.push_back(s.substr(start, end - start));
        }
        start = end + delim.length();
    }
    
    if (start < s.length()) {
        tokens.push_back(s.substr(start));
    }
    
    return tokens;
}

int main() {
    string texto = "manzana,naranja,banana,,uva";
    
    cout << "Split por coma:" << endl;
    vector<string> frutas = split(texto, ',');
    for (const auto& fruta : frutas) {
        cout << "- '" << fruta << "'" << endl;
    }
    
    cout << "\nSplit por múltiples espacios:" << endl;
    string frase = "Hola   mundo    C++   ";
    vector<string> palabras = split_find(frase, "  ");
    for (const auto& palabra : palabras) {
        cout << "- '" << palabra << "'" << endl;
    }
    
    return 0;
}
```

### 🔹 2.6 Expresiones Regulares (Regex)

```cpp
#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    // Validación de formato email
    regex patronEmail(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    string email = "usuario@ejemplo.com";
    
    if (regex_match(email, patronEmail)) {
        cout << "Email válido: " << email << endl;
    } else {
        cout << "Email inválido" << endl;
    }
    
    // Validación de números
    regex patronNumeros(R"(\d+)");
    string soloNumeros = "12345";
    string conLetras = "123abc";
    
    cout << "'" << soloNumeros << "' es solo números: " 
         << regex_match(soloNumeros, patronNumeros) << endl;
    cout << "'" << conLetras << "' es solo números: " 
         << regex_match(conLetras, patronNumeros) << endl;
    
    // Búsqueda y extracción
    string texto = "Los precios son $15, $20 y $30";
    regex patronPrecios(R"(\$(\d+))");
    smatch coincidencias;
    
    cout << "\nPrecios encontrados:" << endl;
    auto inicio = texto.cbegin();
    auto fin = texto.cend();
    
    while (regex_search(inicio, fin, coincidencias, patronPrecios)) {
        cout << "Precio: $" << coincidencias[1] << endl;
        inicio = coincidencias[0].second;
    }
    
    // Reemplazo con regex
    string texto2 = "Hola mundo, hola C++";
    regex patronHola("hola", regex_constants::icase);
    string resultado = regex_replace(texto2, patronHola, "adiós");
    
    cout << "\nReemplazo: " << resultado << endl;
    
    return 0;
}
```

### 🔹 2.7 Optimización y Eficiencia

```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    // 1. Reserve para evitar reallocations
    string cadenaGrande;
    cadenaGrande.reserve(10000);  // Reservar espacio por adelantado
    
    for (int i = 0; i < 1000; i++) {
        cadenaGrande += "texto";  // Más eficiente con reserve
    }
    
    // 2. Evitar concatenación múltiple en loops
    // ❌ INEFICIENTE
    string resultadoMalo;
    for (int i = 0; i < 100; i++) {
        resultadoMalo += "palabra" + to_string(i) + " ";  // Muchas reallocations
    }
    
    // ✅ EFICIENTE
    ostringstream resultadoBueno;
    for (int i = 0; i < 100; i++) {
        resultadoBueno << "palabra" << i << " ";
    }
    string final = resultadoBueno.str();
    
    // 3. Pasar strings por referencia
    auto procesarString = [](const string& str) {  // ✅ Por referencia constante
        return str.length();
    };
    
    auto modificarString = [](string& str) {  // ✅ Por referencia para modificar
        str += " modificado";
    };
    
    // 4. Usar string_view (C++17) para solo lectura
    string textoLargo = "Este es un texto muy largo que no queremos copiar";
    // string_view vista(textoLargo);  // Sin copia - C++17
    
    cout << "Optimizaciones aplicadas" << endl;
    
    return 0;
}
```

### 🔹 2.8 Interoperabilidad con C-Strings

```cpp
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
    // De std::string a C-string
    string cppStr = "Hola Mundo";
    const char* cStr = cppStr.c_str();
    cout << "C-string: " << cStr << endl;
    
    // De C-string a std::string
    const char* cStyleStr = "Texto estilo C";
    string fromCStr(cStyleStr);
    cout << "std::string: " << fromCStr << endl;
    
    // Operaciones con C-strings (solo cuando es necesario)
    char buffer[100];
    strcpy(buffer, "Hola ");      // Copiar
    strcat(buffer, "Mundo");      // Concatenar
    cout << "Buffer: " << buffer << endl;
    
    // Búsqueda en C-strings
    const char* texto = "Programación en C++";
    const char* found = strstr(texto, "C++");
    if (found) {
        cout << "Encontrado 'C++' en posición: " << (found - texto) << endl;
    }
    
    // Comparación segura
    char pass1[] = "password";
    char pass2[] = "password";
    
    if (strcmp(pass1, pass2) == 0) {
        cout << "Contraseñas iguales" << endl;
    }
    
    // Copia segura con límite
    char destino[20];
    strncpy(destino, "Texto muy largo que podría desbordar", sizeof(destino) - 1);
    destino[sizeof(destino) - 1] = '\0';  // Asegurar terminación nula
    cout << "Destino seguro: " << destino << endl;
    
    return 0;
}
```

---

## 🟥 3. MINI-PREGUNTA DE COMPRENSIÓN

**¿Qué diferencia práctica hay entre usar `stringstream` y `regex` cuando querés procesar una cadena?**

### 🎯 **Respuesta Esperada:**

**`stringstream`** es ideal para **parsing estructurado** con delimitadores simples y conversión automática a tipos números. Es más **eficiente y simple** para formatos predecibles como CSV, datos separados por espacios, o conversión directa string→número.

**`regex`** es poderoso para **patrones complejos**, validación de formatos, y búsqueda/reemplazo flexible. Es **más expresivo** pero menos eficiente, ideal para emails, URLs, números de teléfono, o extracción de patrones en texto no estructurado.

### 💡 **Regla de Elección:**
- **`stringstream`**: "Sé exactamente cómo está estructurado el texto"
- **`regex`**: "Necesito buscar/validar patrones complejos en texto libre"
