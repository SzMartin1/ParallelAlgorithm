#include<stdio.h>  
#include<math.h>  
#include<stdlib.h>
#include<time.h>

#define N 20

int RandomNumberGenerator(int min, int max);

int isPrime(int num);
  
int main()  
{  

    time_t start, stop;
    double runtime;
	int limit;
    int num, count = 0;	
	srand(time(NULL));

	start=clock();
    for (int i=0; i<N; i++)
    {
        limit = pow(2,i);
        for (int j=0; j<limit; j++)
        {    
            int rng = RandomNumberGenerator(3,1000);
            if (isPrime(rng)){
                count++;
			}
        }
        printf("2^%d iteration: I found %d numbers which is a prime number.\n",i, count);
        count = 0;
    }  
    stop=clock();
	runtime=(double)(stop-start)/CLOCKS_PER_SEC;
	printf("\n Sequential runtime is: %f",runtime);
  
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
