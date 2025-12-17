# Libft — Apuntes por función (mapa mental + flujo + funciones autorizadas)

> Documento para mis dibagaciones y previa investigación antes de empezar a resolver las funciones.  
> Esto es simplemente una primera aproximación  para clarificar mis ideas, una breve descripción y pleanteamientos iniciales.

---
### ft_isalpha
- **Qué hace:** comprueba si `c` es una letra ASCII (`A-Z` o `a-z`).
- **Recibe:** `int c`
- **Devuelve:** `1` si es letra, `0` si no.
- **Funciones autorizadas:** _Ninguna_
- **Flujo mental:**
  1. Idea: usar de manera estática is_upper e is_lower para verificar que es una letra.
  2. Compruebo rango `'A' <= c <= 'Z'` **o** `'a' <= c <= 'z'`.
  3. Si cumple → `return (1)`; si no → `return (0)`.

---

### ft_isdigit
- **Qué hace:** comprueba si `c` es un dígito ASCII (`0-9`).
- **Devuelve:** `1` si sí, `0` si no.
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. `if (c >= '0' && c <= '9') return (1);`
  2. `return (0);`

---

### ft_isalnum
- **Qué hace:** letra o dígito.
- **Devuelve:** `1` si es alfanumérico, `0` si no.
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. Reutilizo `ft_isalpha(c) || ft_isdigit(c)` (recomendado).
  2. Return 1/0.

---

### ft_isascii
- **Qué hace:** comprueba si `c` está en ASCII estándar (0..127).
- **Devuelve:** `1` si sí, `0` si no.
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. `if (c >= 0 && c <= 127) return (1);`
  2. `return (0);`

---

### ft_isprint
- **Qué hace:** ASCII imprimible (incluye espacio).
- **Devuelve:** `1` si `32..126`, `0` si no.
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. `if (c >= 32 && c <= 126) return (1);`
  2. `return (0);`

---

### ft_strlen
- **Qué hace:** cuenta caracteres hasta `'\0'`.
- **Recibe:** `const char *s`
- **Devuelve:** `size_t` (longitud sin contar el `\0`).
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. `i = 0`
  2. while `s[i] != '\0'` → `i++`
  3. return `i`
- **Ojo:** `s == NULL` → comportamiento indefinido (igual que libc).

---

### ft_memset
- **Qué hace:** rellena `len` bytes con el byte `(unsigned char)c`.
- **Recibe:** `void *b, int c, size_t len`
- **Devuelve:** `b`
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. cast `unsigned char *p = b`
  2. bucle `i < len`: `p[i] = (unsigned char)c`
  3. return `b`

---

### ft_bzero
- **Qué hace:** pone a 0 `n` bytes.
- **Recibe:** `void *s, size_t n`
- **Devuelve:** nada
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. bucle poniendo 0 **o** reutilizo tu `ft_memset(s, 0, n)`
  2. fin

---

### ft_memcpy
- **Qué hace:** copia `n` bytes de `src` a `dst` (sin solapamiento).
- **Recibe:** `void *dst, const void *src, size_t n`
- **Devuelve:** `dst`
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. cast a `unsigned char *d` y `const unsigned char *s`
  2. bucle `i < n`: `d[i] = s[i]`
  3. return `dst`
- **Ojo:** solapamiento → indefinido (para eso está `memmove`).

---

### ft_memmove
- **Qué hace:** copia `n` bytes permitiendo solapamiento.
- **Devuelve:** `dst`
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. si `dst == src` o `n == 0` → return `dst`
  2. si `dst < src` → copio hacia delante
  3. si `dst > src` → copio hacia atrás
  4. return `dst`

---

### ft_strlcpy
- **Qué hace:** copia `src` en `dst` garantizando `\0` si `dstsize > 0`.
- **Devuelve:** longitud de `src` (siempre).
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. `src_len = ft_strlen(src)`
  2. si `dstsize == 0` → return `src_len`
  3. copio hasta `dstsize - 1` o `\0`
  4. `dst[i] = '\0'`
  5. return `src_len`

---

### ft_strlcat
- **Qué hace:** concatena `src` al final de `dst` respetando `dstsize`.
- **Devuelve:** `initial_dst_len + src_len` (lo que “intentó” crear).
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. calculo `dst_len` sin leer más allá de `dstsize`
  2. si `dstsize <= dst_len` → return `dstsize + ft_strlen(src)`
  3. copio `src` hasta `dstsize - 1`
  4. `\0` final
  5. return `dst_len + src_len`

---

### ft_toupper
- **Qué hace:** si `a-z` → `A-Z`.
- **Devuelve:** `c` convertido o igual.
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. si `'a' <= c <= 'z'` → return `c - 32`
  2. else return `c`

---

### ft_tolower
- **Qué hace:** si `A-Z` → `a-z`.
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. si `'A' <= c <= 'Z'` → return `c + 32`
  2. else return `c`

---

### ft_strchr
- **Qué hace:** puntero a **primera** aparición de `c` en `s` (o `\0` final).
- **Devuelve:** `char *` o `NULL`
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. recorro `s[i]`
  2. si coincide → return `&s[i]`
  3. si `c == '\0'` → return puntero al final
  4. return `NULL`

---

### ft_strrchr
- **Qué hace:** puntero a **última** aparición de `c` en `s` (o `\0` final).
- **Devuelve:** `char *` o `NULL`
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. `last = NULL`
  2. recorro y actualizo `last` cuando coincide
  3. si `c == '\0'` → return puntero al `\0`
  4. return `last`

---

### ft_strncmp
- **Qué hace:** compara `s1` y `s2` hasta `n`.
- **Devuelve:** `<0`, `0`, `>0`
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. si `n == 0` → return 0
  2. comparo byte a byte como `(unsigned char)`
  3. primer distinto → return diferencia
  4. si termino → return 0

---

### ft_memchr
- **Qué hace:** busca byte `c` en `n` bytes de `s`.
- **Devuelve:** puntero al match o `NULL`
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. cast a `const unsigned char *p`
  2. bucle `i < n` y comparo con `(unsigned char)c`
  3. match → return `p + i`
  4. return `NULL`

---

### ft_memcmp
- **Qué hace:** compara dos bloques de memoria `n` bytes.
- **Devuelve:** `<0`, `0`, `>0`
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. cast a `const unsigned char *`
  2. bucle: primer byte distinto → return `a[i] - b[i]`
  3. return 0

---

### ft_strnstr
- **Qué hace:** busca `needle` dentro de `haystack` sin pasar de `len`.
- **Devuelve:** puntero al inicio del match o `NULL`. `needle` vacío → `haystack`.
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. si `needle[0] == '\0'` → return `haystack`
  2. doble bucle controlando `i + j < len`
  3. si completo `needle` → return `haystack + i`
  4. return `NULL`

---

### ft_atoi
- **Qué hace:** convierte string a `int`.
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. salto whitespace
  2. signo opcional
  3. acumulo dígitos
  4. return `sign * res`
- **Ojo:** overflow → como libc (no “protejas” salvo que se pida).

---

### ft_calloc
- **Qué hace:** reserva `nmemb * size` bytes y los inicializa a 0.
- **Devuelve:** puntero o `NULL`
- **Funciones autorizadas:** `malloc`
- **Flujo:**
  1. si `nmemb == 0 || size == 0` → devolver un puntero liberable (p.ej. `malloc(0)`)
  2. check overflow: `nmemb > SIZE_MAX / size` → `NULL`
  3. `p = malloc(nmemb * size)`; si falla → `NULL`
  4. `ft_bzero(p, nmemb * size)`
  5. return `p`

---

### ft_strdup
- **Qué hace:** duplica una string en heap.
- **Devuelve:** nuevo `char *` o `NULL`
- **Funciones autorizadas:** `malloc`
- **Flujo:**
  1. `len = ft_strlen(s)`
  2. `p = malloc(len + 1)`; si falla → `NULL`
  3. copio y pongo `'\0'`
  4. return `p`

---

## Parte 2 — funciones adicionales

> Nota: aquí ya se especifica por función qué está autorizado.

### ft_substr
- **Qué hace:** crea una subcadena desde `start` con máximo `len`.
- **Devuelve:** string nueva o `NULL`
- **Funciones autorizadas:** `malloc`
- **Flujo:**
  1. si `start >= ft_strlen(s)` → devolver `""` (reservada)
  2. `real_len = min(len, s_len - start)`
  3. `malloc(real_len + 1)`, copio, `\0`, return

---

### ft_strjoin
- **Qué hace:** concatena `s1 + s2` en una nueva string.
- **Funciones autorizadas:** `malloc`
- **Flujo:**
  1. calculo longitudes
  2. `malloc(len1 + len2 + 1)`
  3. copio `s1`, copio `s2`, `\0`

---

### ft_strtrim
- **Qué hace:** recorta caracteres del `set` al inicio y final.
- **Funciones autorizadas:** `malloc`
- **Flujo:**
  1. avanzo `start` mientras char ∈ set
  2. retrocedo `end` mientras char ∈ set
  3. `malloc(end - start + 1)` y copio

---

### ft_split
- **Qué hace:** divide `s` por delimitador `c` → array de strings terminado en `NULL`.
- **Funciones autorizadas:** `malloc`, `free`
- **Flujo mental:**
  1. cuento palabras (segmentos no vacíos)
  2. `malloc((words + 1) * sizeof(char *))`
  3. creo cada palabra con `malloc`
  4. si algo falla: libero todo lo creado (`free`) y return `NULL`
  5. cierro con `arr[words] = NULL`

---

### ft_itoa
- **Qué hace:** convierte `int` a string.
- **Funciones autorizadas:** `malloc`
- **Flujo:**
  1. uso `long` para manejar `INT_MIN`
  2. cuento dígitos y signo
  3. `malloc(total + 1)`
  4. relleno de atrás hacia delante
  5. `\0`

---

### ft_strmapi
- **Qué hace:** crea string nueva aplicando `f(i, s[i])`.
- **Funciones autorizadas:** `malloc`
- **Flujo:**
  1. `malloc(len + 1)`
  2. `out[i] = f(i, s[i])`
  3. `out[len] = '\0'`

---

### ft_striteri
- **Qué hace:** aplica `f(i, &s[i])` modificando `s` in-place.
- **Funciones autorizadas:** _Ninguna_
- **Flujo:** recorro `s` y llamo a `f`.

---

### ft_putchar_fd
- **Qué hace:** escribe un carácter en `fd`.
- **Funciones autorizadas:** `write`
- **Flujo:** `write(fd, &c, 1)`

---

### ft_putstr_fd
- **Qué hace:** escribe una string en `fd`.
- **Funciones autorizadas:** `write`
- **Flujo:** o bien `write(fd, s, ft_strlen(s))` (si ya tienes `ft_strlen`) o bucle.

---

### ft_putendl_fd
- **Qué hace:** escribe string + `\n`.
- **Funciones autorizadas:** `write`
- **Flujo:** `ft_putstr_fd` + `ft_putchar_fd('\n')` (o dos writes).

---

### ft_putnbr_fd
- **Qué hace:** escribe un entero en `fd`.
- **Funciones autorizadas:** `write`
- **Flujo:**
  1. uso `long` para `INT_MIN`
  2. imprimo signo si toca
  3. imprimo dígitos (recursivo o iterativo)
  4. `ft_putchar_fd` para cada dígito

---

## Parte 3 — Listas enlazadas

Estructura en `libft.h`:
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

### ft_lstnew
- **Qué hace:** crea nodo con `content`, `next = NULL`.
- **Funciones autorizadas:** `malloc`
- **Flujo:**
  1. `node = malloc(sizeof(t_list))`
  2. `node->content = content`
  3. `node->next = NULL`
  4. return node

---

### ft_lstadd_front
- **Qué hace:** añade `new` al principio.
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. `new->next = *lst`
  2. `*lst = new`

---

### ft_lstsize
- **Qué hace:** cuenta nodos.
- **Funciones autorizadas:** _Ninguna_
- **Flujo:** while(lst) {count++; lst = lst->next;}

---

### ft_lstlast
- **Qué hace:** devuelve el último nodo.
- **Funciones autorizadas:** _Ninguna_
- **Flujo:** while(lst && lst->next) lst = lst->next; return lst;

---

### ft_lstadd_back
- **Qué hace:** añade `new` al final.
- **Funciones autorizadas:** _Ninguna_
- **Flujo:**
  1. si `*lst == NULL` → `*lst = new`
  2. else: `last = ft_lstlast(*lst)` → `last->next = new`

---

### ft_lstdelone
- **Qué hace:** libera un nodo (contenido con `del`, luego el nodo).
- **Funciones autorizadas:** `free`
- **Flujo:**
  1. `del(lst->content)` si `del` existe
  2. `free(lst)`

---

### ft_lstclear
- **Qué hace:** libera toda la lista y deja `*lst = NULL`.
- **Funciones autorizadas:** `free`
- **Flujo:**
  1. mientras haya nodos:
     - guardo `next`
     - `ft_lstdelone(current, del)`
     - avanzo
  2. `*lst = NULL`

---

### ft_lstiter
- **Qué hace:** aplica `f` al `content` de cada nodo.
- **Funciones autorizadas:** _Ninguna_
- **Flujo:** while(lst){ f(lst->content); lst = lst->next; }

---

### ft_lstmap
- **Qué hace:** crea una nueva lista aplicando `f` al content de cada nodo.
- **Funciones autorizadas:** `malloc`, `free`
- **Flujo mental (el clásico que preguntan en evaluación):**
  1. `new_list = NULL`
  2. para cada nodo en `lst`:
     - `new_content = f(old->content)`
     - `new_node = ft_lstnew(new_content)` (usa malloc)
     - si falla:
       - si aplica, libero `new_content` con `del`
       - `ft_lstclear(&new_list, del)` (usa free)
       - return `NULL`
     - `ft_lstadd_back(&new_list, new_node)`
  3. return `new_list`

---
