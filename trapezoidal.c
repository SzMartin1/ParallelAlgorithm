#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define A -15 /*kezdeti korlát*/
#define B 15 /* végső korlát*/
#define EPS 0.00000005 /*pontosság*/


 double f(double x);
 double trapezoidal(double f(double x), double a, double b, int n);


/*Elkezdődik a program*/
int main(){
  int i=2;
  double integral,integral_new;
  time_t start, stop;
  double runtime;

  omp_set_dynamic(0);     // Explicitly disable dynamic teams
  omp_set_num_threads(2); // Use 4 threads for all consecutive parallel regions

  integral_new=trapezoidal(f,A,B,i);

  /* Perform integration by trapezoidal rule for different number of sub-intervals until they converge to the given accuracy:*/
  start=clock();
#pragma omp parallel
  #pragma omp do
    do{
      integral=integral_new;
      i++;
      integral_new=trapezoidal(f,A,B,i);
     }while(fabs(integral_new-integral)>=EPS);
  stop=clock();

  runtime = (double)(stop-start)/CLOCKS_PER_SEC;
  /*Print the answer */
  printf("The integral is: %lf\n with %d intervals",integral_new,i);
  printf("\n Sequential runtime is %f sec.",runtime);

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
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f(x);
  }
  integral=(h/2)*(f(a)+f(b)+2*sum);
  return integral;
}
