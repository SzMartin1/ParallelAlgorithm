#include<stdio.h>  
#include<math.h>  
#include<stdlib.h>
#include<time.h>
#include<pthread.h>




int RandomNumberGenerator(int min, int max);
int isPrime(int num);
void * count_PrimeNumber(void * arg);

pthread_mutex_t value_mutex = PTHREAD_MUTEX_INITIALIZER;
  
int main()  
{  

    time_t start, stop;
    double runtime;
	const int N = 20;
	pthread_t thread[N];	
	

    printf(":::::::::::::CALCULATING WITH N THREADS::::::::::::::::\n");
	
	///Mérés kezdete!
	start = clock();
    for (int i=0; i<N; i++)
    {
        pthread_create(&thread[i], NULL, count_PrimeNumber, (void *)i);
    }

    for (int i=0; i<N; i++)
        pthread_join(thread[i], NULL);
    ///Mérés vége!
    stop = clock();
	runtime=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("\nParallel runtime with N Threads is: %f\n",runtime);
	
    printf("::::::::::::CALCULATING WITH 2 THREADS:::::::::::::::::\n");
	
	
	/// Mérés kezdete!
    start = clock();
    for (int i=0; i<N-(N/2); i++)
    {
        pthread_create(&thread[0], NULL, count_PrimeNumber, (void *)i);
        if ((N-1)-i != i)
            pthread_create(&thread[1], NULL, count_PrimeNumber, (void *)(N-1)-i);
        pthread_join(thread[0], NULL);
        pthread_join(thread[1], NULL);
    }
            
    ///Mérés vége!
    stop = clock();
    runtime=(double)(stop-start)/CLOCKS_PER_SEC;
	printf("\n Parallel runtime with 2 Threads is: %f\n",runtime);
    return 0;  
}

int isPrime(int num)  
{  
    int inum = sqrt(num), prime = 1, count;  
  
    for(count = 2; count <= inum; count++)  
    {  
         if(num % count == 0)  
         {  
            prime = 0;  
            break;  
         }  
    }  
  
    return(prime);  
}

int RandomNumberGenerator(int min, int max)
{
    int num = (rand() % (max - min + 1)) + min;
    return num;
}


void * count_PrimeNumber(void * arg)
{
    int count = 0;
    int * iptr = (int*)&arg;
    int limit = pow(2,*iptr);
	srand(time(NULL));
	int j;
    for (j=0; j<limit; j++)
    {    
        int rng = RandomNumberGenerator(3,1000);
        if (isPrime(rng)){
            count++;
		}
    }
	pthread_mutex_lock(&value_mutex);
    printf("I found %d numbers which is a prime number\n",count);
    pthread_mutex_unlock(&value_mutex);
    
}
