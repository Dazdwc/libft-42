# 🧭 Libft – Plan de trabajo por familias (Checklist)

---

## 1️⃣ Funciones de clasificación (sin punteros)

- [x] ft_isalpha
- [x] ft_isdigit
- [x] ft_isalnum
- [x] ft_isascii
- [x] ft_isprint

---

## 2️⃣ Strings básicas y conversión

- [x] ft_strlen
- [x] ft_toupper
- [x] ft_tolower
- [x] ft_atoi

---

## 3️⃣ Funciones de memoria (punteros crudos)

- [X] ft_memset
- [x] ft_bzero
- [x] ft_memcpy
- [X] ft_memmove
- [x] ft_memchr
- [x] ft_memcmp

---

## 4️⃣ Funciones de strings complejas
👉 Strings + `\0` + punteros + límites.

- [x] ft_strlcpy
- [x] ft_strlcat
- [x] ft_strchr
- [x] ft_strrchr
- [x] ft_strncmp
- [x] ft_strnstr

---

## 5️⃣ Funciones con asignación dinámica (malloc)
👉 **No avanzar sin entender bien heap, leaks y NULL.**

- [ ] ft_calloc
- [ ] ft_strdup
- [ ] ft_substr
- [ ] ft_strjoin
- [ ] ft_strtrim
- [ ] ft_split
- [ ] ft_itoa
- [ ] ft_strmapi
- [ ] ft_striteri

---

## 6️⃣ Funciones de salida por file descriptor (fd)
👉 Escritura en fd, sin malloc, pero con cuidado de errores.

- [x] ft_putchar_fd
- [x] ft_putstr_fd
- [x] ft_putendl_fd
- [x] ft_putnbr_fd

📌 **Notas importantes de esta familia:**
- Usan `write`
- No gestionan errores de fd (según subject)
- No devuelven valor
- No reservan memoria
- Son ideales para afianzar recursividad (`ft_putnbr_fd`)
---

## 7️⃣  Listas enlazadas


- [x] ft_lstnew
- [x] ft_lstadd_front
- [x] ft_lstsize
- [x] ft_lstlast
- [x] ft_lstadd_back
- [x] ft_lstdelone
- [x] ft_lstclear
- [x] ft_lstiter
- [x] ft_lstmap
