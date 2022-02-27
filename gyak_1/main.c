#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>
/// Szabó Martin, Párhuzamos Algoritmusok 1. Gyakorlat feladatai, Neptun kód: WJFAOO
void Szovegkitoltes();//2. feladat
void sleepTeszt();//3. feladat
int Random_Egesz(int min, int max, bool disp); //4. és 5. feladat egyben
double Random_Lebegopontos(double min, double max); //4. és 5. feladat egyben
void OsszeadasJatek();//6. feladat
int main() {
    Szovegkitoltes();
    sleepTeszt();
    Random_Egesz(700,1900,true);
    Random_Lebegopontos(700,1900);
    OsszeadasJatek();
    return 0;
}
void Szovegkitoltes(){
    printf("%*s\n", 8, "A");
    printf("%*s\n", 8, "szoveg");
    printf("%*s\n", 8, "jobbra");
    printf("%*s\n", 8, "van");
    printf("%*s\n", 8, "igazitva.");
}
void sleepTeszt(){
    printf("Varni fogunk tiz masodpercet.\n}");
    Sleep(10000);
    printf("Keszen is vagyunk, eltelt 10 masodperc.");
}

int Random_Egesz(int min, int max, bool disp){
    if (min >= max)
    {
        printf("Nem jol adtunk intervallumot.(min >= max)!\n");
        return -1;
    }
    else
    {
        int num = (rand() % (max - min + 1)) + min;
        if (disp == true)
        {
            printf("A random egesz szam %d es %d kozott:\n", min, max);
            printf("%d\n", num);
        }
        return num;
    }
}

double Random_Lebegopontos(double min, double max){
    if (min >= max)
    {
        printf("Nem jol adtunk intervallumot (min >= max)!\n");
        return -1;
    }
    else
    {
        printf("A random lebegopontos szam %f es %f kozott:\n", min, max);
        double part = ((double)rand()) / ((double)RAND_MAX);
        double num = part * (max - min) + min;
        printf("%f\n", num);
        return num;
    }
}

void OsszeadasJatek(){
    int x = Random_Egesz(0,10, false);
    int y = Random_Egesz(0,10, false);
    int guess = -1;
    printf("Jatszunk! Ket szamot fog latni, es ossze kell adnia. Ha jol valaszol, akkor nyer egy pacsit.\n");
    printf("Mennyi %d + %d?\n", x, y);
    clock_t time = clock();
    do
    {
        scanf("%d", &guess);
        if (guess != x+y)
            printf("A valasz helytelen, probalja ujra!\n");
    }while(guess != x+y);
    time = clock()-time;
    double time_taken = ((double)time)/CLOCKS_PER_SEC;
    printf("Helyes valasz, nyert!\n");
    printf("A valasz adas ideje: %f mp\n", time_taken);
}
