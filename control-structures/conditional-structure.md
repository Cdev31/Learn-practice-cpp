# 📝 Control de Flujo Avanzado en C++ — Apuntes Completos

## 1. ESTRUCTURAS CONDICIONALES

### 1.1 if / else if / else

#### *¿Qué es?*
> Estructura fundamental que permite ejecutar bloques de código basándose en la evaluación de condiciones booleanas.

#### *¿Cómo se usa?*
```cpp
if (edad >= 18) {
    cout << "Mayor de edad";
} else if (edad >= 13) {
    cout << "Adolescente";
} else {
    cout << "Niño";
}
```

#### *Ventajas:*
- Flexibilidad para condiciones complejas
- Fácil de leer y mantener
- Permite anidamiento múltiple

#### *¿Cuándo usarlo?*
- Al evaluar rangos numéricos (`x > 10 && x < 20`)
- Cuando se necesitan múltiples condiciones relacionadas
- Para lógica de negocio compleja
- Validaciones de entrada de usuario

---

### 1.2 switch (incluyendo enum class)

#### *¿Qué es?*
> Estructura optimizada para selección basada en valores constantes discretos. Ideal con `enum class` para código type-safe.

#### *¿Cómo se usa?*
```cpp
enum class Estado { Menu, Jugar, Pausa, Salir };
Estado estadoActual = Estado::Jugar;

switch (estadoActual) {
    case Estado::Menu:
        cout << "Navegando por el menú\n";
        break;
    case Estado::Jugar:
        cout << "Jugando...\n";
        break;
    case Estado::Pausa:
        cout << "Juego en pausa\n";
        break;
    case Estado::Salir:
        cout << "Saliendo del juego\n";
        break;
    default:
        cout << "Estado desconocido\n";
}

// Switch con integers
int opcion = 2;
switch (opcion) {
    case 1: cout << "Opción 1\n"; break;
    case 2: cout << "Opción 2\n"; break;
    case 3: cout << "Opción 3\n"; break;
}
```

#### *¿Cuándo usarlo?*
- Sistemas de estados finitos (juegos, UI)
- Menús de opciones
- Procesamiento de comandos
- Cuando se evitan cadenas largas de `if-else if`
- Con valores enumerados o constantes

---

### 1.3 Operador ternario (`? :`)

#### *¿Qué es?*
> Operador condicional compacto que devuelve uno de dos valores basado en una condición.

#### *¿Cómo se usa?*
```cpp
// Asignación condicional
string categoria = (edad >= 18) ? "Adulto" : "Menor";

// Uso en expresiones
int precio = (esVIP) ? 50 : 100;
double descuento = (cantidad > 10) ? 0.15 : 0.05;

// Anidamiento (usar con cuidado)
string resultado = (nota >= 90) ? "Excelente" : 
                  (nota >= 70) ? "Aprobado" : "Reprobado";
```

#### *¿Cuándo usarlo?*
- Asignaciones condicionales directas
- Retorno de valores en funciones inline
- Expresiones cortas y legibles
- Evitar bloques `if-else` simples

#### *Precauciones:*
- Evitar anidamiento excesivo
- No usar para lógica compleja

---

## 2. CONDICIONES SIN `if` - TÉCNICAS AVANZADAS

### 2.1 Ejecución condicional con `&&` (AND lógico)

#### *¿Qué es?*
> Aprovecha la evaluación de cortocircuito: la segunda expresión solo se ejecuta si la primera es `true`.

#### *¿Cómo se usa?*
```cpp
// Validación y ejecución en una línea
(edad >= 18) && cout << "Puedes entrar al bar\n";

// Múltiples condiciones
(usuarioValido && tienePermisos) && (
    cout << "Acceso concedido\n",
    cargarDatosUsuario(),
    actualizarLogAcceso()
);

// En asignaciones
bool puedeVotar = (edad >= 18) && (esCiudadano) && !(yaVoto);
```

#### *¿Cuándo usarlo?*
- Validaciones simples con acciones inmediatas
- Debugging condicional
- Precondiciones para ejecución
- Código conciso para checks de seguridad

---

### 2.2 Ejecución condicional con `||` (OR lógico)

#### *¿Qué es?*
> La segunda expresión solo se ejecuta si la primera es `false`.

#### *¿Cómo se usa?*
```cpp
// Mensajes de error
(edad >= 18) || cout << "Error: Menor de edad no permitido\n";

// Valores por defecto
string nombre = nombreUsuario || "Invitado";

// Validación de entrada
(inputEsValido) || (
    cerr << "Error: Entrada inválida\n",
    limpiarBuffer(),
    solicitarReintento()
);
```

#### *¿Cuándo usarlo?*
- Manejo de errores conciso
- Valores por defecto
- Inicialización condicional
- Validaciones negativas

---

### 2.3 Condiciones como índices de arreglos

#### *¿Qué es?*
> Conversión implícita de booleanos a índices (`true → 1`, `false → 0`) para acceso a arrays.

#### *¿Cómo se usa?*
```cpp
// Texto condicional
string mensajes[2] = {"Acceso denegado", "Acceso permitido"};
cout << mensajes[edad >= 18];

// Múltiples categorías
string categorias[3] = {"Niño", "Adolescente", "Adulto"};
int index = (edad >= 18) ? 2 : (edad >= 13) ? 1 : 0;
cout << categorias[index];

// Configuraciones basadas en estado
int velocidades[2] = {100, 200};
int velocidadActual = velocidades[modoTurbo];

// Precios según tipo de usuario
double precios[3] = {25.0, 50.0, 75.0}; // Normal, VIP, Premium
double precioFinal = precios[tipoUsuario];
```

#### *¿Cuándo usarlo?*
- Clasificación en categorías discretas
- Sistemas de tarifas/configuración
- Internacionalización (textos por idioma)
- Máquinas de estado simples

---

### 2.4 Tablas de decisión (Lookup Tables)

#### *¿Qué es?*
> Patrón donde la entrada sirve como índice para buscar resultados precalculados en arrays.

#### *¿Cómo se usa?*
```cpp
// Sistema de precios por categoría
enum Categoria { ECONOMICA, ESTANDAR, PREMIUM };
double precios[] = {100.0, 200.0, 350.0};
double precio = precios[categoria];

// Días de la semana
string dias[] = {"Dom", "Lun", "Mar", "Mie", "Jue", "Vie", "Sab"};
cout << dias[diaSemana];

// Calculadora de operaciones
int operar(int a, int b, char op) {
    // Usando función pointers en la lookup table
    static int (*operaciones[])(int, int) = {
        [](int x, int y) { return x + y; },  // '+'
        [](int x, int y) { return x - y; },  // '-'
        [](int x, int y) { return x * y; },  // '*'
        [](int x, int y) { return x / y; }   // '/'
    };
    
    int index = op - '+'; // Convierte char a índice
    return (index >= 0 && index < 4) ? operaciones[index](a, b) : 0;
}
```

#### *¿Cuándo usarlo?*
- Menús y sistemas de opciones
- Conversión de códigos a texto
- Funciones matemáticas discretas
- Máquinas de estado complejas
- Cuando el rendimiento es crítico

---

### 2.5 Multiplicación booleana (Boolean Masking)

#### *¿Qué es?*
> Uso de la conversión implícita booleana (`true=1`, `false=0`) para activar/desactivar cálculos matemáticos.

#### *¿Cómo se usa?*
```cpp
// Sistema de descuentos y cargos
int precioBase = 100;
int precioFinal = precioBase 
    - (esEstudiante) * 20          // Descuento estudiante
    + (esVIP) * 30                 // Cargo VIP
    - (edad < 12) * 15             // Descuento infantil
    + (horasPico) * 10;            // Recargo horas pico

// Cálculo de puntajes en juegos
int puntaje = puntosBase 
    + (comboPerfecto) * 1000 
    + (nivelCompletadoRapido) * 500 
    - (usoPistas) * 200;

// Fórmulas condicionales en física/simulaciones
double fuerza = masa * aceleracion 
    * (!enVacío)                    // Si no está en vacío
    + (aplicarGravedad) * 9.8 * masa;

// Optimización: evitar branching en loops críticos
for (int i = 0; i < n; i++) {
    resultado[i] = (condicion[i]) * valorVerdadero 
                 + (!condicion[i]) * valorFalso;
}
```

#### *Ventajas:*
- Elimina branches del CPU (mejor predicción)
- Código vectorizable
- Ideal para SIMD y GPGPU

#### *¿Cuándo usarlo?*
- Cálculos en tiempo real (videojuegos)
- Procesamiento de señales
- Simulaciones físicas
- Operaciones sobre arrays grandes
- Donde el rendimiento es crítico

---

## 3. PATRONES AVANZADOS COMBINADOS

### 3.1 Sistema de estados con lookup tables
```cpp
enum class Estado { Inactivo, Activo, Pausado, Error };
enum Evento { Iniciar, Pausar, Reanudar, Detener, Error };

using Transicion = Estado(*)(Estado);
Transicion transiciones[] = {
    [](Estado s) { return Estado::Activo; },   // Iniciar
    [](Estado s) { return Estado::Pausado; },  // Pausar  
    [](Estado s) { return s == Estado::Pausado ? Estado::Activo : s; }, // Reanudar
    [](Estado s) { return Estado::Inactivo; }, // Detener
    [](Estado s) { return Estado::Error; }     // Error
};

Estado nuevoEstado = transiciones[evento](estadoActual);
```

### 3.2 Configuración flexible con boolean masking
```cpp
struct Configuracion {
    int flags; // Cada bit representa una opción
    
    enum Opciones { 
        SONIDO = 1, MUSICA = 2, FULLSCREEN = 4, VSYNC = 8 
    };
    
    void aplicar() {
        int volumen = 100 * ((flags & SONIDO) != 0);
        bool pantallaCompleta = flags & FULLSCREEN;
        // ... configura según flags
    }
};
```

---

## 4. MEJORES PRÁCTICAS

### ✅ **Recomendado:**
- Usar `enum class` para type safety
- Aplicar técnicas sin branch en código crítico
- Utilizar lookup tables para mapeos fijos
- Documentar patrones no convencionales

### ❌ **Evitar:**
- Anidamiento excesivo de ternarios
- Técnicas oscuras sin comentarios
- Optimización prematura
- Comprometer legibilidad por rendimiento mínimo

### 🎯 **Elección de técnica:**
- **Legibilidad:** `if/else`, `switch`
- **Rendimiento:** Lookup tables, boolean masking  
- **Concisión:** Ternarios, `&&/||` cortocircuito
- **Mantenibilidad:** `enum class` + `switch`

Estas técnicas permiten escribir código C++ más expresivo, eficiente y mantenible, adaptándose a diferentes contextos y requisitos de performance.