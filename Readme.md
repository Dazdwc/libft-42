apuntes:
*Este proyecto ha sido creado como parte del currículo de 42 por <login>.*

# Descripción
<!-- TODO: Añadir descripción del proyecto -->

# Instrucciones
<!-- TODO: Información sobre compilación, instalación y ejecución -->

# Recursos
<!-- TODO: Referencias utilizadas -->

## IA
La IA ha sido utilizada únicamente para ayudar a formatear y traducir este README.md.


## 📝 Apuntes

### 🔹 Sobre funciones `static`

> *“Si necesitas crear funciones auxiliares para descomponer una función más compleja, debes definirlas como static para restringir su alcance al archivo correspondiente.”*

- Una función declarada como **`static`** en C **solo es visible dentro del archivo `.c` donde se define**.  
- Aunque se compile todo junto, esa función **no puede usarse desde otros archivos**.
- Esto ayuda a:
  - Encapsular lógica interna  
  - Evitar colisiones de nombres  
  - Mejorar la organización del código  
  - Seguir buenas prácticas de modularidad

**Resumen:**  
👉 `static` = función privada al archivo.

---

### 🔹 Sobre las reglas del Makefile

> *“Tu Makefile debe contener al menos las normas $(NAME), all, clean, fclean y re.”*

- **`$(NAME)`**  
  Variable que guarda el nombre del binario o librería final.

- **`all`**  
  Regla por defecto. Si ejecutas `make` sin argumentos, se ejecuta esta.

- **`clean`**  
  Borra los archivos objeto (`*.o`).  
  No borra el binario/librería final.

- **`fclean`**  
  Full clean.  
  Hace lo mismo que `clean` y además elimina `$(NAME)`.

- **`re`**  
  Ejecuta `fclean` seguido de `all` para recompilar desde cero.

- **`.PHONY`**  
  Indica que estas reglas no representan archivos reales, sino comandos.  
  Previene conflictos cuando existen archivos con esos nombres.

  Ejemplo recomendado:
  ```make
  .PHONY: all clean fclean re
Bruto
apuntes:

Busqueda de información:

> Si necesitas crear funciones auxiliares para descomponer una función más compleja,
debes definirlas como static para restringir su alcance al archivo correspondiente.

leyendo el subject me surge la duda de que quiere decir que una funcion sea estatica,
si marcamos una funcion con 'static' se limita su visiviladad únicamente a el scope de ese archivo,
haciendo así que no pueda usarse desde otro punto del programa aunque se compile junto.

esto tiene que ver con las buenas prácticas, encapsulación, evitar colisiones y mejor organización.

> Tu Makefile debe contener al menos las normas $(NAME), all, clean, fclean y re.

- $(NAME) : es una variable que se usa para guardar el nombre del binario / libreria.
- all es la regla que se ejecutara por defecto, si haces solo make en el directorio se ejecuta esta.
- clean normalmente sirve para borrar los .o, es como limpiar la basura, aunque no deberia borrar el binario final
- fclean es fullclean y este hara lo mismo que el clean ademas borrara el resultado final de $(NAME)
- re es rebuild, se encargara de borrar los objetos y libreria (fclean) y volver a ejecutar all.
- .PHONY: es la manera en la que indicamos que las reglas no son archivos, que son solo un comando y deben ejecutarse siepre. ej: .PHONY: all clean fclean re
dejariamos name fuera porque si genera archivos.

isalpha esta funcion la he planteado como nos pone el man, calculando si es mayuscula o minuscula,por tanto, todas las letras posibles. para poder implantarla como dice el subject  he hecho estas funciones com estaticas. 


isdigit esta funcion simplemente te indica si es o no un numero, para ello debe coincidir su valor en ascii, es decir ser mayor de '0' y menor a '9'.


isalnum, esta funcion es una mezcla entre isalpha y isdigit, si cualquiera de estas diese positivo entonces se cumpliria la condicion.

isascii, en esta funcion nos aseguraremos que lo que nos pasen quepan en siete bits para saber si es ascii, por tanto calcularemos que entre en el rango del  0 al 127.

isprint, en esta funcion tenemos que indicar si se mostrar'ia en consola, esta funcion debera comprobar que el valor de ascii sea mayor a 32 (el valor que representa el espacio) y menor a 127 (Del).  

