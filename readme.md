# Tareas
- corregir lo que le pasa a mi codigo que no funciona lo de corregir
- subir todo a github
- crear una backup de la maquina virtual (que se guarde varias versiones unas 3 y que se suba a la nube para que luego se pueda abrir desde otro dispositivo)
- empezar con el parseo

# Reglas Importantes a Tener en Cuenta (Parte Obligatoria)

## Lenguaje y Estilo

- **Lenguaje:** El proyecto debe ser desarrollado en **C**.
- **Norma 42:**
  - (NO SE PUEDE UTILIZAR EXIT)
  - Máximo de 25 líneas por función.
  - Indentación de 4 espacios.
  - No se permiten variables globales (ni `static` fuera de funciones).
  - Prohibido el uso de bucles prohibidos y otras prácticas no recomendadas.

- **Gestión de Memoria:** La gestión de memoria debe ser impecable, evitando cualquier tipo de "leaks" (fugas de memoria).

## Ejecución

- Cada filósofo será representado por un **hilo (pthread)**.
- Para evitar que dos filósofos cojan el mismo tenedor al mismo tiempo, se utilizará un **mutex** por tenedor.

### Ciclo de Vida de un Filósofo

El filósofo debe realizar las siguientes acciones, en orden repetido hasta que muera o haya cumplido con el número requerido de comidas:

1. **Tomar el tenedor izquierdo**.
2. **Tomar el tenedor derecho**.
3. **Comer**.
4. **Soltar los tenedores**.
5. **Dormir**.
6. **Pensar**.

Este ciclo se repetirá hasta que el filósofo muera o cumpla con las comidas requeridas.

## Parámetros del Programa

La ejecución del programa se hará con los siguientes parámetros:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]



