#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Función que ejecutará cada hilo
void *print_message(void *arg)
{
    char *msg = (char *)arg;
    for (int i = 0; i < 5; i++)
    {
        printf("%s (iteración %d)\n", msg, i);
        usleep(100000); // 0.1 segundos para que se mezclen las salidas
    }
    return NULL;
}

int main(void)
{
    pthread_t t1, t2;

    // Crear dos hilos
    pthread_create(&t1, NULL, print_message, "Hola desde el hilo 1");
    pthread_create(&t2, NULL, print_message, "Hola desde el hilo 2");

    // Esperar a que terminen
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Todos los hilos han terminado.\n");
    return 0;
}
