# PUSH\_SWAP
[Español](README.md) | [English](README.en.md)
| 42 Project| Descripción |
| ----------- | ----------- |
| <a href=""> <img src="https://github.com/0bvim/42-project-badges/blob/main/badges/push_swape.png?raw=true" /></a> | Push_swap es un proyecto de algoritmia desarrollado en C que tiene como objetivo ordenar un conjunto de números enteros en un stack a utilizando un conjunto limitado de instrucciones y optimizando el número de movimientos. Para lograrlo, se debe implementar un algoritmo eficiente que genere la secuencia más corta posible de operaciones de ordenación.|

## 🎯 Objetivo 
El objetivo principal de este proyecto es desarrollar un programa llamado `push_swap` que reciba una lista de números enteros como argumentos y genere la secuencia más corta de instrucciones para ordenar esos números en orden ascendente. Este ejercicio no solo refuerza conceptos fundamentales sobre algoritmos de ordenamiento, sino que también introduce al desarrollador a la complejidad algorítmica.

## ⚙️ Funcionamiento del Programa
El programa recibe como argumento una lista de números enteros que se cargará en el **stack a**. Un paso previo a la carga de números consite en procesar la entrada de datos numéricos y asegurarse de que sean válidos para su ordenación. A partir de aquí, el objetivo es ordenarlos de menor a mayor utilizando las siguientes operaciones:

| Instrucción | Descripción                                              |
| ----------- | -------------------------------------------------------- |
| **sa**      | Intercambia los dos primeros elementos de la stack a     |
| **sb**      | Intercambia los dos primeros elementos de la stack b     |
| **ss**      | Intercambia los dos primeros elementos de a y b a la vez |
| **pa**      | Toma el primer elemento de b y lo coloca en a            |
| **pb**      | Toma el primer elemento de a y lo coloca en b            |
| **ra**      | Rota todos los elementos de a hacia arriba               |
| **rb**      | Rota todos los elementos de b hacia arriba               |
| **rr**      | Rota a y b hacia arriba simultáneamente                  |
| **rra**     | Rota todos los elementos de a hacia abajo                |
| **rrb**     | Rota todos los elementos de b hacia abajo                |
| **rrr**     | Rota a y b hacia abajo simultáneamente                   |

El programa imprime en salida estándar la secuencia de operaciones necesaria para ordenar la lista.

## Implementación
Para la implementación del proyecto, se utilizó la estructura original de listas enlazadas desarrollada en el proyecto **libft**. Se creó un nuevo struct llamado `t_content`, que almacena un valor entero a ordenar y otro entero que indica la posición en la que debería estar dicho número una vez que la lista esté ordenada:
```c
typedef struct s_content
{
    int value;        // Valor numérico
    int sorted_pos;   // Posición ordenada del valor
} t_content;
```
Este tipo de dato será el que maneje la lista enlazada, de tal forma que planteado con este enfoque se simplifica el manejo de datos y permite reducir complejidad y el número de funciones implementadas y una gestión eviciente de los valores y facilita la indexación sin recorrer los stacks repetidamente (K.I.S.S).

### 🧮 Algoritmos Utilizados: 
Se han planteado varios algoritmos de forma escalonada en función de la cantidad de numeros a ordenar:

#### **Three-sort**
Ordena una stack compuesta de 3 números aplicando soluciones triviales sin tener que usar la stack b

#### **Mini-sort**
Ordena una stack compuesta de numeros comprendidos entre 4 y 7 haciendo hasta tres bucles de ordenación iterativa pasando los números más grandes a la stack b y cuando solo queden 3 números en la stack a se reutiliza el algoritmo anterior y se introducen los números que se pasaron a la stack b ya ordenados

#### **k-sort**
Ordena una stack de números mayores a 7. Para lograr la ordenación en el menor número de movimientos, el algoritmo **k-sort** optimiza el proceso agrupando elementos en subconjuntos y realizando una ordenación incremental. Este enfoque permite reducir significativamente el número de operaciones en comparación con algoritmos más simples.

### 🔧 Funciones Implementadas
Según el propósito y utilidad de cada función se han organizado en diferentes archivos: 
- **ps_input_utils.c**: Lectura y validación de argumentos numéricos de tipo int no duplicados y carga de estos en la stack a
  - `load_stack(int argc, char **argv)`: Carga los números desde los argumentos en la stack a si los datos son válidos, si no devuelve null.

- **ps_array_utils.c**: Manejo de arrays
  - Funciones para crear y manejar arrays que serán útiles para elaborar un índice con la posición de cada elemento una vez sea ordenado. Para ello se crea un array que contenga los mismos números de la stack a manteniendo su orden, se creará un duplicado de ese array con los elementos ya ordenados utilizando el algoritmo de la burbuja y finalmente se creará un índice buscando para cada número sin ordenar en el array ordenado para determinar cual es su posición estando ordenado para luego cargar dichos valores en la stack a y liberar la memoria de los arrays.

- **ps_swap.c**: Intercambia los dos primeros elementos de una stack
  - `swap_a(t_list **stack_a)`: Intercambia los dos primeros elementos del stack `a`.
  - `swap_b(t_list **stack_b)`: Intercambia los dos primeros elementos del stack `b`.
  - `swap_a_b(t_list **stack_a, t_list **stack_b)`: Realiza `swap_a` y `swap_b` simultáneamente.

- **ps_push.c**: Movimiento entre stacks
  - `push_a(t_list **stack_b, t_list **stack_a)`: Mueve el primer elemento del stack `b` al stack `a`.
  - `push_b(t_list **stack_a, t_list **stack_b)`: Mueve el primer elemento del stack `a` al stack `b`.

- **ps_rotate.c**: Rotación
  - `rotate_a(t_list **stack_a)`: Rota hacia arriba todos los elementos del stack `a`.
  - `rotate_b(t_list **stack_b)`: Rota hacia arriba todos los elementos del stack `b`.
  - `rotate_a_b(t_list **stack_a, t_list **stack_b)`: Realiza ambas rotaciones simultáneamente.

- **ps_rev_rotate.c**: Rotación inversa
  - `rev_rotate_a(t_list **stack_a)`: Rota hacia abajo todos los elementos del stack `a`.
  - `rev_rotate_b(t_list **stack_b)`: Rota hacia abajo todos los elementos del stack `b`.
  - `rev_rotate_a_b(t_list **stack_a, t_list **stack_b)`: Realiza ambas rotaciones inversas simultáneamente.

- **ps_stack_utils.c**: Utilidades para stacks
  - Funciones para obtener posiciones mínimas y máximas, calcular costos de rotación y verificar si un stack está ordenado.

- **ps_sort.c**: algoritmos de ordenación
  - `three_sort(t_list **stack)`: Ordena una lista de tres elementos
  - `mini_sort(t_list **stack_a, t_list **stack_b, int size)`: Ordena una lista de cuatro a siete elementos
  - `k_sort(t_list **stack_a, t_list **stack_b, int size)`: Ordena una lista mayor de 7 números

##  Evaluación y Rendimiento
Para aprobar el proyecto se deben cumplir los siguientes criterios de eficiencia:
- **Ordenar 100 números en menos de 700 operaciones.** ✅
- **Ordenar 500 números en menos de 5500 operaciones.** ✅

## 🚀 Checker (Bonus)
Una vez completada la parte obligatoria, se implementó un programa adicional llamado *checker*. Este programa replica el funcionamiento del proyecto principal pero en lugar de aplicar un algoritmo de ordenación, ejecuta una a una las instrucciones leídas desde la entrada estándar. Para ello se utiliza la función *get_next_line*, implementada en un proyecto anterior. Al finalizar las instrucciones, se verifica si el stack está correctamente ordenado y devuelve **"OK"**, **"KO"** o **"Error"** según corresponda.

