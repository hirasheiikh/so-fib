#include <pthread.h>
#include <stdio.h>
void *rutina(void *arg)
{
    printf("Hola del thread %ld (id: %p)\n", (long) arg, pthread_self());
    return arg;
}
int main()
{
    pthread_t threads[2];
    long ret;
    // Creem el primer thread
    pthread_create(&threads[0], NULL, rutina, (void *) 1);
    printf("Espero...\n");
    pthread_join(threads[0], (void **) &ret);
    printf("Thread finalizado, retorna %ld\n", ret);
    // Creem el segon thread
    pthread_create(&threads[1], NULL, rutina, (void *) 2);
    printf("Espero...\n");
    pthread_join(threads[1], (void **) &ret);
    printf("Thread finalizado, retorna %ld\n", ret);
}