# 🐟 SoLong - ¡Gracias por todos los peces!

## Descripción
**SoLong** es un juego 2D sencillo donde controlas a un personaje (puede ser un delfín si te apetece o lo que prefieras). El objetivo es escapar del mapa después de recoger todos los coleccionables. Es un proyecto que te hará trabajar con gráficos, texturas y sprites usando la librería MiniLibX.

## ¿Cómo funciona?
1. Usa las teclas `W`, `A`, `S`, `D` para moverte en las 4 direcciones clásicas (arriba, abajo, izquierda, derecha). También puedes usar las flechas si eso te resulta más cómodo.
2. El objetivo es recolectar todos los objetos (marcados como `C` en el mapa) y luego dirigirte a la salida (marcada como `E`).
3. No puedes atravesar paredes (marcadas como `1`) y cada paso que des se mostrará en el terminal.
4. El mapa es en 2D y la vista puede ser de "pájaro" o lateral, ¡tú decides!

## Reglas básicas del juego
- El mapa que se usa debe estar en formato `.ber` y puede contener:
  - `1` para muros.
  - `0` para espacios vacíos.
  - `C` para coleccionables.
  - `E` para la salida.
  - `P` es el punto de inicio del personaje.
  
  Aquí tienes un ejemplo básico de cómo sería un mapa válido:
```
  11111
  1P0C1
  10001
  1C0E1
  11111
```
- El mapa debe estar rodeado de muros, tener al menos un coleccionable y una salida. Si no, el juego te dirá **"Error"**.

## Instrucciones técnicas
- Todo el código está escrito en C y se gestiona con un **Makefile**.
- Para compilar el juego, simplemente ejecuta `make`.
- Para correr el juego, usa el siguiente comando:

```bash
./so_long mapa.ber
````

Donde `mapa.ber` es el archivo del mapa que quieres usar.

- El proyecto sigue las normas de 42, por lo que la gestión de memoria y errores está bien cuidada (evitando leaks y crashes inesperados).

## Controles
- `W`, `A`, `S`, `D` o las flechas para mover al personaje.
- `ESC` para cerrar la ventana y salir del juego.
- También puedes hacer clic en la cruz roja de la ventana para salir limpiamente.

---

¡Y eso es todo! Un juego sencillo pero que te hará pensar en la mejor forma de completar el mapa. ¡Disfruta jugando y programando!

