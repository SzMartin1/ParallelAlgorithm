#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

/// Készítette: Szabó Martin, Neptun kód: WJFAOO, 3. gyakorlat: első rész
void wait_four(void * args);
void wait_eight(void * args);
void kiir(char* s);
pthread_mutex_t value_mutex = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    pthread_t t;
    pthread_create(&t,NULL,wait_four,NULL);
    kiir("[main] A 8 masodperc szamitasa kovetkezik!\n");
    Sleep(8000);
    kiir("[main] Kesz van!\n");
    pthread_join(t,NULL);

    pthread_create(&t,NULL,wait_eight,NULL);
    kiir("[main] A 4 masodperc szamitasa kovetkezik!\n");
    Sleep(4000);
    kiir("[main] Kesz van!\n");
    pthread_join(t,NULL);
    return 0;
}

void  wait_four(void * args)
{
    kiir("[thread]A 4 masodperc szamitasa kovetkezik!\n");
    Sleep(4000);
    printf("[thread] Kesz is!\n");
}

void wait_eight(void * args)
{
    kiir("[thread]A 8 masodperc szamitasa kovetkezik!\n");
    Sleep(8000);
    printf("[thread] Kesz is!\n");
}

void kiir(char* s)
{
    pthread_mutex_lock(&value_mutex);
    printf("%s", s);
    pthread_mutex_unlock(&value_mutex);
}
