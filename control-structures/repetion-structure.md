# 🔄 BUCLES AVANZADOS EN C++

---

## 3.1 Bucle con Centinela (Sentinel)

### **¿Qué es?**
> Un bucle que procesa datos hasta encontrar un valor especial (centinela) que indica el fin.

### **¿Cómo se usa?**
```cpp
// Ejemplo 1: Procesar números hasta -1
int numero, suma = 0;
cout << "Ingrese números (-1 para terminar): ";
while (cin >> numero && numero != -1) {
    suma += numero;
}
cout << "Suma total: " << suma << endl;

// Ejemplo 2: Procesar texto hasta "FIN"
string linea;
cout << "Escribe líneas (FIN para terminar):\n";
while (getline(cin, linea) && linea != "FIN") {
    cout << "Línea: " << linea << endl;
}

// Ejemplo 3: Procesar hasta EOF
int valor;
while (cin >> valor) {  // Se detiene en EOF o error
    procesar(valor);
}
```

### **¿Cuándo usarlo?**
- Lectura interactiva de usuario
- Procesamiento de archivos hasta marcador
- Consolas de comandos
- Carga de datos con terminador conocido

---

## 3.2 Bucle con Flag de Estado

### **¿Qué es?**
> Uso de una variable booleana para controlar la ejecución del bucle basado en condiciones complejas.

### **¿Cómo se usa?**
```cpp
// Ejemplo 1: Búsqueda con salida temprana
bool encontrado = false;
for (int i = 0; i < n && !encontrado; i++) {
    if (arreglo[i] == objetivo) {
        encontrado = true;
        posicion = i;
    }
}

// Ejemplo 2: Validación múltiple
bool datosValidos = true;
int intentos = 0;
while (!datosValidos && intentos < 3) {
    datosValidos = validarEntrada();
    intentos++;
}

// Ejemplo 3: Procesamiento condicional complejo
bool continuar = true;
for (auto& elemento : contenedor) {
    if (!procesarElemento(elemento)) {
        continuar = false;
        break;
    }
    if (elemento.condicionEspecial()) {
        continuar = false;
        break;
    }
}
```

### **¿Cuándo usarlo?**
- Búsquedas que pueden terminar anticipadamente
- Validaciones con múltiples criterios de parada
- Procesamiento que depende de estado externo
- Sistemas con límites de intentos

---

## 3.3 `for` con Múltiples Variables

### **¿Qué es?**
> Un bucle `for` que maneja y actualiza varias variables simultáneamente en su declaración.

### **¿Cómo se usa?**
```cpp
// Ejemplo 1: Dos punteros - invertir array
void invertirArray(int arr[], int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        swap(arr[i], arr[j]);
    }
}

// Ejemplo 2: Múltiples contadores
for (int fila = 0, col = 0; fila < filas && col < columnas; fila++, col++) {
    matriz[fila][col] = 1;  // Diagonal principal
}

// Ejemplo 3: Variables de diferente tipo
for (int i = 0, contador = 10; i < 5; i++, contador -= 2) {
    cout << "i: " << i << ", contador: " << contador << endl;
}

// Ejemplo 4: Recorrido bidireccional en lista
auto itInicio = lista.begin();
auto itFin = lista.end();
for (; itInicio != itFin && itInicio != --itFin; ++itInicio) {
    swap(*itInicio, *itFin);
}
```

### **¿Cuándo usarlo?**
- Algoritmos de dos punteros
- Recorridos desde ambos extremos
- Sincronización de múltiples índices
- Operaciones en diagonales de matrices

---

## 3.4 Bucle Generador (Secuencias Controladas)

### **¿Qué es?**
> Un bucle que genera secuencias matemáticas o patrones específicos con control preciso del incremento.

### **¿Cómo se usa?**
```cpp
// Ejemplo 1: Secuencia aritmética
cout << "Pares del 0 al 20: ";
for (int i = 0; i <= 20; i += 2) {
    cout << i << " ";
}

// Ejemplo 2: Secuencia geométrica
for (double x = 1.0; x <= 1000.0; x *= 2) {
    cout << x << " ";
}

// Ejemplo 3: Secuencia con decimales
for (double t = 0.0; t <= 1.0; t += 0.1) {
    double valor = sin(t * 2 * M_PI);
    cout << "t=" << t << ", sin=" << valor << endl;
}

// Ejemplo 4: Secuencia personalizada
vector<int> fibonacci = {0, 1};
for (int i = 2; i < 15; i++) {
    fibonacci.push_back(fibonacci[i-1] + fibonacci[i-2]);
}
```

### **¿Cuándo usarlo?**
- Generación de muestras para gráficos
- Simulaciones con paso de tiempo fijo
- Series matemáticas
- Espaciado regular en intervalos

---

## 3.5 Bucle para Validar Input

### **¿Qué es?**
> Un bucle diseñado específicamente para asegurar que la entrada del usuario sea válida y robusta.

### **¿Cómo se usa?**
```cpp
// Ejemplo 1: Validación de número entero
int leerEntero(const string& mensaje, int min, int max) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor && valor >= min && valor <= max) {
            return valor;
        }
        // Limpiar estado de error y buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Ingrese un número entre " << min << " y " << max << endl;
    }
}

// Ejemplo 2: Validación de opción de menú
char leerOpcionMenu() {
    char opcion;
    while (true) {
        cout << "Seleccione opción (A/B/C/S): ";
        cin >> opcion;
        opcion = toupper(opcion);
        if (string("ABCS").find(opcion) != string::npos) {
            return opcion;
        }
        cout << "Opción inválida. Intente nuevamente.\n";
    }
}

// Ejemplo 3: Validación con límite de intentos
string leerPassword() {
    string password;
    int intentos = 3;
    
    while (intentos > 0) {
        cout << "Ingrese contraseña (" << intentos << " intentos restantes): ";
        cin >> password;
        
        if (validarPassword(password)) {
            return password;
        }
        
        intentos--;
        if (intentos > 0) {
            cout << "Contraseña incorrecta.\n";
        }
    }
    
    cout << "Demasiados intentos fallidos.\n";
    exit(1);
}
```

### **¿Cuándo usarlo?**
- Formularios interactivos
- Menús de consola
- Sistemas de login
- Entrada de datos crítica
- Programas que deben ser robustos a errores de usuario

---

## 4. DECISIONES DE DISEÑO (Design Decisions)

### 4.1 ¿Cuándo usar `switch`?

**Úsalo cuando:**
```cpp
// ✅ IDEAL para estados discretos
enum class EstadoJuego { MENU, JUGANDO, PAUSA, GAME_OVER };

void actualizarEstado(EstadoJuego estado) {
    switch (estado) {
        case EstadoJuego::MENU:
            mostrarMenu();
            break;
        case EstadoJuego::JUGANDO:
            actualizarJuego();
            break;
        case EstadoJuego::PAUSA:
            mostrarPausa();
            break;
        case EstadoJuego::GAME_OVER:
            mostrarGameOver();
            break;
    }
}

// ✅ IDEAL para procesamiento de comandos
void procesarComando(char comando) {
    switch (comando) {
        case 'A': case 'a': moverIzquierda(); break;
        case 'D': case 'd': moverDerecha(); break;
        case 'W': case 'w': saltar(); break;
        case 'S': case 's': agacharse(); break;
        default: comandoInvalido();
    }
}
```

### 4.2 ¿Cuándo usar tablas de decisión?

**Úsalo cuando:**
```cpp
// ✅ IDEAL para mapeos directos
string obtenerNombreMes(int mes) {
    static const string meses[] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };
    return (mes >= 1 && mes <= 12) ? meses[mes - 1] : "Mes inválido";
}

// ✅ IDEAL para configuraciones
double calcularTarifa(int tipoVehiculo) {
    static const double tarifas[] = {5.0, 7.5, 12.0, 20.0}; // Moto, Auto, Camion, Bus
    return tarifas[tipoVehiculo];
}
```

### 4.3 ¿Cuándo usar `if`?

**Úsalo cuando:**
```cpp
// ✅ IDEAL para rangos y condiciones complejas
string clasificarEdad(int edad) {
    if (edad < 0) return "Edad inválida";
    else if (edad < 13) return "Niño";
    else if (edad < 18) return "Adolescente";
    else if (edad < 65) return "Adulto";
    else return "Adulto mayor";
}

// ✅ IDEAL para múltiples condiciones
bool puedeConducir(int edad, bool tieneLicencia, bool estaSobrio) {
    return edad >= 18 && tieneLicencia && estaSobrio;
}
```

### 4.4 ¿Cuándo romper un bucle?

**Romperlo si:**
```cpp
// ✅ Búsqueda exitosa
for (const auto& producto : inventario) {
    if (producto.nombre == nombreBuscado) {
        resultado = producto;
        break;  // ¡Encontrado! No necesitamos seguir buscando
    }
}

// ✅ Condición de error
while (procesarDatos()) {
    if (haOcurridoError()) {
        registrarError();
        break;  // Error crítico, detener procesamiento
    }
}

// ✅ Estado inválido para continuar
while (juegoActivo) {
    if (jugadorSinVidas()) {
        mostrarGameOver();
        break;  // Fin del juego
    }
    // ... lógica del juego
}
```

---

## 5. EJEMPLOS COMBINADOS AVANZADOS

### Sistema de Menú con Validación Robusta
```cpp
enum class Opcion { SALIR, JUGAR, CONFIGURAR, PUNTUACION };

Opcion mostrarMenu() {
    while (true) {
        cout << "\n=== MENÚ PRINCIPAL ===\n";
        cout << "1. Jugar\n";
        cout << "2. Configurar\n";
        cout << "3. Puntuaciones\n";
        cout << "0. Salir\n";
        cout << "Seleccione: ";
        
        int opcion;
        if (cin >> opcion) {
            switch (opcion) {
                case 0: return Opcion::SALIR;
                case 1: return Opcion::JUGAR;
                case 2: return Opcion::CONFIGURAR;
                case 3: return Opcion::PUNTUACION;
            }
        }
        
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Opción inválida. Intente nuevamente.\n";
    }
}
```

### Procesamiento de Datos con Múltiples Estrategias
```cpp
void procesarArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error abriendo archivo\n";
        return;
    }
    
    string linea;
    bool formatoValido = true;
    int numeroLinea = 0;
    
    // Bucle con centinela (EOF) y flag de estado
    while (getline(archivo, linea) && formatoValido) {
        numeroLinea++;
        
        // Técnica sin if para clasificación
        string tipos[3] = {"COMENTARIO", "DATOS", "COMANDO"};
        int tipo = linea.empty() ? 0 : (linea[0] == '#') ? 0 : 
                  (isdigit(linea[0])) ? 1 : 2;
        
        cout << "Línea " << numeroLinea << ": " << tipos[tipo] << endl;
        
        // Condición para romper bucle
        if (linea == "FIN") break;
        
        // Validación de formato
        formatoValido = validarFormato(linea);
    }
    
    if (!formatoValido) {
        cerr << "Archivo con formato inválido en línea " << numeroLinea << endl;
    }
}
```

### Sistema de Estados con Lookup Table
```cpp
enum class Estado { MENU, JUGANDO, PAUSA, FIN };
enum Evento { INICIAR, PAUSAR, REANUDAR, TERMINAR };

Estado maquinaEstados(Estado actual, Evento evento) {
    // Lookup table para transiciones de estado
    static const Estado transiciones[4][4] = {
        /*            INICIAR,    PAUSAR,    REANUDAR,   TERMINAR */
        /* MENU */    {Estado::JUGANDO, Estado::MENU,   Estado::MENU,     Estado::FIN},
        /* JUGANDO */ {Estado::JUGANDO, Estado::PAUSA,  Estado::JUGANDO,  Estado::FIN},
        /* PAUSA */   {Estado::JUGANDO, Estado::PAUSA,  Estado::JUGANDO,  Estado::FIN},
        /* FIN */     {Estado::FIN,     Estado::FIN,    Estado::FIN,      Estado::FIN}
    };
    
    return transiciones[static_cast<int>(actual)][evento];
}
```

---

## 🎯 RESUMEN DE MEJORES PRÁCTICAS

### ✅ **Para Legibilidad:**
- Usar `for` cuando se conoce el número de iteraciones
- Usar `while` para condiciones complejas
- Preferir rangos específicos en bucles generadores

### ✅ **Para Robustez:**
- Siempre validar entrada de usuario
- Usar flags para control de errores
- Implementar límites de intentos

### ✅ **Para Rendimiento:**
- Romper bucles anticipadamente cuando sea posible
- Usar técnicas sin branch en código crítico
- Considerar lookup tables para mapeos frecuentes

### ✅ **Para Mantenibilidad:**
- Documentar condiciones complejas
- Usar enums para estados discretos
- Separar lógica de validación de lógica de negocio

