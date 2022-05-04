#include<stdio.h>  
#include<math.h>  
#include<stdlib.h>
#include<time.h>

#define LOWER 0
#define UPPER 1000000


int isPrime(int num);
  
int main()  
{  

    time_t start, stop;
    double runtime;
    int num, count = 0; 

	start=clock();
    for(num = LOWER; num <= UPPER; num++)  
    {  
        if(num == 1)  
        {  
            continue;  
        }  
  
        if( isPrime(num) )  
        {  
            count++;    
        }  
    }  
    stop=clock();
	runtime=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("\nThere are %d prime numbers between %d and %d.\n",count, LOWER, UPPER);
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
