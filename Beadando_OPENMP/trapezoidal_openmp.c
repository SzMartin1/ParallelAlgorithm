#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define A -15 /*kezdeti korlát*/
#define B 15 /* végső korlát*/
#define EPS 0.000001 /*pontosság*/


 double f(double x);
 double trapezoidal(double f(double x), double a, double b, int n);


/*Elkezdődik a program*/
int main(){
  int i=2;
  double integral,integral_new;
  time_t start, stop;
  double runtime;

  omp_set_dynamic(0);     // Explicitly disable dynamic teams
  omp_set_num_threads(16); // Use n threads for all consecutive parallel regions

  integral_new=trapezoidal(f,A,B,i);

  /* Perform integration by trapezoidal rule for different number of sub-intervals until they converge to the given accuracy:*/
  start=clock();
    do{
	printf("\n %d",i);
      integral=integral_new;
      i++;
      integral_new=trapezoidal(f,A,B,i);
     }while(fabs(integral_new-integral)>=EPS);
  stop=clock();

  runtime = (double)(stop-start)/CLOCKS_PER_SEC;
  /*Print the answer */
  printf("\nThe integral is: %lf\n with %d intervals",integral_new,i);
  printf("\n Parallel runtime is %f sec.",runtime);

  return 0;
}

/*Itt definiáljuk a függvényt, amelyet használni fogunk */
double f(double x){
  return x*x;
}

/* A trapézmódszer függvénydefiníciója */
double trapezoidal(double f(double x), double a, double b, int n)
{
  double x,h,sum=0,integral;
  int i;
  h=fabs(b-a)/n;
 #pragma omp parallel
  #pragma omp for
   for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f(x);
   }
  integral=(h/2)*(f(a)+f(b)+2*sum);
  return integral;
}
