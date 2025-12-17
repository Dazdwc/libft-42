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

- [ ] ft_memset
- [ ] ft_bzero
- [ ] ft_memcpy
- [ ] ft_memmove
- [ ] ft_memchr
- [ ] ft_memcmp

---

## 4️⃣ Funciones de strings complejas
👉 Strings + `\0` + punteros + límites.

- [ ] ft_strlcpy
- [ ] ft_strlcat
- [ ] ft_strchr
- [ ] ft_strrchr
- [ ] ft_strncmp
- [ ] ft_strnstr

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

- [ ] ft_putchar_fd
- [ ] ft_putstr_fd
- [ ] ft_putendl_fd
- [ ] ft_putnbr_fd

📌 **Notas importantes de esta familia:**
- Usan `write`
- No gestionan errores de fd (según subject)
- No devuelven valor
- No reservan memoria
- Son ideales para afianzar recursividad (`ft_putnbr_fd`)
---

## 7️⃣ Bonus – Listas enlazadas


- [ ] ft_lstnew
- [ ] ft_lstadd_front
- [ ] ft_lstsize
- [ ] ft_lstlast
- [ ] ft_lstadd_back
- [ ] ft_lstdelone
- [ ] ft_lstclear
- [ ] ft_lstiter
- [ ] ft_lstmap
