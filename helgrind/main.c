#include <pthread.h>

int var = 0;

void*
f(void* arg)
{
    var++;
    return NULL;
}

int
main(void)
{
    pthread_t th;
    pthread_create(&th, NULL, f, NULL);
    var++;
    pthread_join(th, NULL);
    return 0;
}
