*Este proyecto ha sido creado como parte del currículo de 42 por dzafra.*

![Language](https://img.shields.io/badge/Language-C-blue)
![School](https://img.shields.io/badge/School-42-black)
![Norminette](https://img.shields.io/badge/Norminette-Passing-success)
# Libft

## Descripción

Libft es mi primera librería en C. El objetivo del proyecto es rehacer funciones básicas de la libc y algunas adicionales para **entender qué pasa realmente por debajo**, sobre todo con memoria, punteros y strings.

La idea es tener una librería “mágica” que nos provea de todas las herramientas desde el inicio, si no, busco una librería **clara, consistente y ampliable**. Cada función hace una sola cosa y está escrita siguiendo la Norma de 42.

---

## Instrucciones

Compilación:

```bash
  make
```

Esto genera `libft.a` en la raíz del repo.

Reglas:

* `make` / `make all`: compila
* `make clean`: borra `.o`
* `make fclean`: borra `.o` y `libft.a`
* `make re`: recompila desde cero

---

## Recursos 📚

* Páginas del manual (`man`) de cada función de la libc, utilizadas como referencia principal para respetar prototipos, comportamiento y casos límite tal y como exige el subject.
* Documentación oficial de 42 relacionada con la Norma y el proyecto Libft, especialmente en lo referente a restricciones, estilo y requisitos de entrega.
* Notas personales tomadas durante el desarrollo del proyecto, donde se han ido registrando dudas, decisiones y conclusiones.
* Aprendizaje entre pares: intercambio de ideas y razonamientos con otros estudiantes para contrastar enfoques y detectar errores conceptuales.
* Repositorio personal en GitHub con apuntes, esquemas y reflexiones tomadas durante el desarrollo del proyecto: [Libft - dzafra](https://github.com/Dazdwc/libft-42)

---
## Contenido de la librería

### 1️⃣ Funciones de clasificación

* **ft_isalpha**: comprueba si es letra ASCII (`A-Z` o `a-z`).

  * 💡 rangos ASCII, sin helpers raros.

* **ft_isdigit**: comprueba si es dígito (`0-9`).

* **ft_isalnum**: letra o dígito.

  * 💡 aquí reutilizo `ft_isalpha` y `ft_isdigit` para no duplicar lógica.

* **ft_isascii**: comprueba si está en ASCII estándar (0–127).

* **ft_isprint**: comprueba si es imprimible (incluye espacio).

  * 💡 rango `32–126`.

---

### 2️⃣ Strings básicas y conversión

* **ft_strlen**: cuenta caracteres hasta `\0`.

  * 💡 igual que libc: si te pasan `NULL` es UB, no lo maquillo.

* **ft_toupper**: si es `a-z`, lo sube a `A-Z`.

* **ft_tolower**: si es `A-Z`, lo baja a `a-z`.

* **ft_atoi**: convierte string a `int`.

  * 💡 primero salto espacios, luego signo, luego acumulo dígitos.
  * 💡 overflow: comportamiento como libc (no lo “arreglo” si no se pide).

---

### 3️⃣ Funciones de memoria

* **ft_memset**: rellena `len` bytes con el byte `c`.

* **ft_bzero**: pone a 0 `n` bytes.

  * 💡 la idea es simple: es un `memset` a cero.

* **ft_memcpy**: copia `n` bytes de `src` a `dst`.

  * 💡 si hay solapamiento, es UB (por eso existe `memmove`).

* **ft_memmove**: copia `n` bytes permitiendo solapamiento.

  * 💡 si `dst < src` copio hacia delante; si no, copio hacia atrás.

* **ft_memchr**: busca un byte dentro de `n` bytes.

* **ft_memcmp**: compara dos bloques `n` bytes.

  * 💡 siempre comparo como `unsigned char`.

---

### 4️⃣ Strings con límite y búsqueda

* **ft_strlcpy**: copia `src` en `dst` garantizando `\0` si `dstsize > 0`.

  * 💡 devuelve SIEMPRE la longitud de `src`, no lo copiado.

* **ft_strlcat**: concatena `src` al final de `dst` sin pasarse de `dstsize`.

  * 💡 lo que devuelve es lo que “intentó” construir: `dst_len_inicial + src_len`.
  * 💡 ojo con calcular `dst_len` sin leer más allá de `dstsize`.

* **ft_strchr**: primera aparición de `c`.

  * 💡 si `c == '\0'` devuelvo el puntero al final.

* **ft_strrchr**: última aparición de `c`.

  * 💡 mismo caso especial con `\0`.

* **ft_strncmp**: compara hasta `n`.

* **ft_strnstr**: busca `needle` dentro de `len`.

  * 💡 si `needle` es vacío, devuelvo `haystack`.
  * 💡 la trampa aquí es respetar `i + j < len`.

---

### 5️⃣ Funciones con memoria dinámica

* **ft_calloc**: reserva `nmemb * size` y lo deja a cero.

  * 💡 overflow check: `nmemb > SIZE_MAX / size` → `NULL`.
  * 💡 si `nmemb == 0` o `size == 0`, devuelvo un puntero válido para `free()`.

* **ft_strdup**: duplica una string en heap.

  * 💡 `len + 1` por el `\0`.

* **ft_substr**: crea una subcadena desde `start` con máximo `len`.

  * 💡 si `start` se pasa de la longitud, devuelvo `""` reservado.

* **ft_strjoin**: une `s1 + s2` en una nueva string.

* **ft_strtrim**: recorta caracteres del `set` al inicio y al final.

  * 💡 lo “difícil” es mover bien `start/end` antes de reservar.

* **ft_split**: divide por delimitador y devuelve un array terminado en `NULL`.

  * 💡 contar palabras sin comerse delimitadores seguidos.
  * 💡 si falla un `malloc` a mitad, libero TODO lo creado y retorno `NULL`.

* **ft_itoa**: convierte `int` a string.

  * 💡 uso `long` para poder manejar `INT_MIN`.
  * 💡 relleno normalmente de atrás hacia delante.

* **ft_strmapi**: crea nueva string aplicando `f(i, s[i])`.

* **ft_striteri**: aplica `f(i, &s[i])` modificando la string original.

---

### 6️⃣ Escritura por file descriptor

* **ft_putchar_fd**: escribe un carácter.
* **ft_putstr_fd**: escribe una string.
* **ft_putendl_fd**: escribe string + `\n`.
* **ft_putnbr_fd**: escribe un entero.

  * 💡 recursividad y cuidado con negativos.

---

### 7️⃣ Listas enlazadas

Todas las listas usan `t_list` en `libft.h`.

* **ft_lstnew**: crea nodo (`content`, `next = NULL`).

* **ft_lstadd_front**: añade al principio.

* **ft_lstsize**: cuenta nodos.

* **ft_lstlast**: devuelve el último.

* **ft_lstadd_back**: añade al final.

  * 💡 si la lista está vacía, `*lst = new`.

* **ft_lstdelone**: libera un nodo (contenido con `del`, luego el nodo).

* **ft_lstclear**: libera toda la lista y deja `*lst = NULL`.

  * 💡 aquí si te olvidas de poner `NULL`, en evaluación te lo cazan rápido.

* **ft_lstiter**: aplica `f` al content de cada nodo.

* **ft_lstmap**: crea una nueva lista aplicando `f`.

  * 💡 si falla un `malloc`, libero lo ya creado (`ft_lstclear`) y retorno `NULL`.
  * 💡 si ya generé `new_content` y luego falla crear el nodo, llamo también a `del(new_content)`.

---

## Conceptos 🧩

* `static` para helpers internos (encapsulación y evitar colisiones).
* Diferencia real entre stack y heap.
* Leaks y liberación parcial (sobre todo en `split` y `lstmap`).
* Casos límite: `\0`, `n == 0`, buffers pequeños, solapamiento.
* Overflow en multiplicaciones de tamaño (`calloc`).
* Listas enlazadas: punteros, recorridos, y limpieza segura.

---

# 🤖 Uso de IA
* Este proyecto ha contado con la asistencia de Inteligencia Artificial para:
  * Explicación de conceptos: Entendimiento profundo de punteros y estructuras.
  * Debugging: Análisis de trazas de Valgrind (leaks y segfaults).
  * Documentación: Ayuda en la estructura y redacción de este README.

---

## Reflexión personal

Este proyecto me ha resultado muy útil para asentar conceptos clave como la **responsabilidad única**, la **abstracción** y la **organización del código**. Obliga a bajar al detalle, a entender realmente cómo funcionan cosas que normalmente damos por hechas, y eso es un muy buen punto de partida para trabajar con C con más criterio.

Dicho esto, también me ha parecido un proyecto **duro y denso** en algunos momentos. Al no formar parte de un conjunto más grande ni verse aplicado directamente en casos de uso reales dentro del curso, cuesta entender la **big picture** mientras lo estás desarrollando. Son herramientas muy generales, pensadas para reutilizarse en cualquier proyecto, pero al principio se sienten un poco aisladas y eso puede hacer que el avance sea más pesado.

Aun así, creo que es un **muy buen inicio**: la librería funciona, cumple su objetivo y deja una base sólida. Aunque al principio no se vea claramente para qué sirve cada función en un contexto real, el valor del proyecto está en que, cuando empiezas a usarlas más adelante, todo encaja y se agradece haber pasado por este proceso.

En resumen: es un proyecto exigente, a veces frustrante, pero necesario para construir fundamentos reales. No enseña tanto por el resultado final, sino por todo lo que obliga a entender por el camino.
