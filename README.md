# TETRIS

Un proyecto en C++ que implementa una versión simplificada del clásico juego Tetris. La lógica del juego está separada por responsabilidades: gestión de piezas, tablero y flujo general de la partida.

## Descripción general

Este repositorio incluye una implementación básica de Tetris con:

- piezas tetromino con distintos tipos y colores
- tablero de juego con validación de movimientos
- rotación de figuras
- descenso de piezas
- eliminación de líneas completas
- carga de configuraciones desde archivos de prueba
- validación automática de resultados para pruebas de evaluación

La estructura del código está pensada para un enfoque académico/educativo, con clases bien diferenciadas y una lógica de juego separada en capas.

## Estructura del repositorio

```text
TETRIS/
├── Figura.h                 # Definición de tipos, colores, casillas y la clase Figura
├── Figura.cpp               # Implementación de formas, giro y movimiento de las piezas
├── Tauler.h                 # Definición del tablero y reglas de validación
├── Tauler.cpp               # Implementación del tablero, colisiones y eliminación de filas
├── Joc.h                    # Definición de la lógica global del juego
├── Joc.cpp                  # Implementación de la inicialización, giro, movimiento y caída
├── main.cpp                 # Programa principal con pruebas automáticas del juego
├── TETRIS.sln               # Solución de Visual Studio
├── TETRIS.vcxproj           # Proyecto de Visual Studio
├── TETRIS.vcxproj.filters   # Filtros del proyecto en Visual Studio
├── .gitignore               # Configuración de Git
├── .gitattributes           # Atributos de Git
└── README.md                # Documentación del proyecto
```

## Componentes principales

### Figura
La clase `Figura` representa cada pieza del juego. Gestiona:

- tipo de figura
- color
- forma interna en matriz
- tamaño de la pieza
- casilla de referencia
- rotación y desplazamiento

Los tipos implementados son:

- O
- I
- T
- L
- J
- Z
- S

### Tauler
La clase `Tauler` representa el tablero del juego y se encarga de:

- inicializar el tablero
- comprobar si un movimiento es válido
- colocar una pieza
- eliminar una figura temporalmente para mover otra
- detectar filas completas y eliminarlas

El tablero es un array bidimensional de 8x8, definido por las constantes `MAX_FILA` y `MAX_COL`.

### Joc
La clase `Joc` orquesta la partida. Incluye:

- inicialización desde un archivo de entrada
- giro de la pieza actual
- movimiento horizontal
- caída vertical
- colocación de la figura en el tablero
- eliminación de filas
- escritura del tablero final en un archivo de salida

### main.cpp
El archivo `main.cpp` es el punto de entrada del programa. Incluye una serie de pruebas automatizadas que:

1. inicializan el tablero con distintos casos
2. muestran la información del archivo de entrada
3. escriben el resultado generado en archivos de salida
4. comparan el resultado con archivos esperados
5. imprimen la nota o validación final

Esto sugiere que el proyecto se usa como práctica de programación con validación automática por comparación de salida.

## Cómo compilar y ejecutar

### Opción recomendada: Visual Studio

1. Abre la solución `TETRIS.sln`.
2. Compila el proyecto con Visual Studio.
3. Ejecuta la aplicación desde el entorno de desarrollo.

### Opción alternativa: línea de comandos con MSBuild

Desde la carpeta del proyecto:

```bat
msbuild TETRIS.sln
```

Luego ejecuta el ejecutable generado por Visual Studio o el proyecto de salida correspondiente.

## Flujo de juego

El programa lee una configuración inicial desde archivos de prueba y genera un estado del tablero que se compara con un resultado esperado. En otras palabras, el proyecto está orientado a validar la lógica de piezas y tablero, más que a una interfaz gráfica completa.

El comportamiento principal incluye:

- lectura de una figura inicial
- lectura del tablero inicial
- giro de la figura según un valor indicado
- validación de movimientos en el tablero
- caída y fijación de la pieza
- eliminación de filas llenas
- salida del tablero resultante

## Requisitos

- Windows
- Visual Studio / MSVC
- C++ con soporte de compilación de proyectos .vcxproj

## Observaciones

Este repositorio no incluye una interfaz gráfica moderna ni una versión de arcade completa, sino una implementación de lógica de Tetris centrada en operaciones de tablero y piezas, ideal para aprendizaje o evaluación de estructura de datos y algoritmos básicos.


## Conclusión

TETRIS es un proyecto sencillo pero bien estructurado para comprender la lógica detrás del juego: representación de figuras, tablero, validación de movimientos y eliminación de líneas. Es una base muy útil para ampliar la funcionalidad con controles, puntuación, niveles, interfaz gráfica o IA.
