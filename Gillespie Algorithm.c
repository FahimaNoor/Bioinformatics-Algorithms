#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double* t;                   //time
size_t t_size=500;

double* X;                  //event
size_t X_size=450;

double ran_expo(double lambda){
    double u;
    u = rand() / (RAND_MAX + 1.0);
    return log(1/u)*(1/lambda);
}

int main(int argc,char *argv[]){
    srand(time(0));
     int i=0;
     X= calloc(X_size, sizeof(double));  //taking the array dynamic was not useful here as the array size here will never exceed 500
     t= calloc(t_size, sizeof(double));

     t[0]=0,X[0]=0;  ///dynamic arrays

     int tend=100;   ///final time
     double r1,r2;      ///generates random number.

     double tau;

     double rates[2];
     double rate_sum;
     double k=2.0;
     double gamma=0.1;

     while(t[i]<tend){
      rates[0]= k;
      rates[1]= gamma*X[i];
      rate_sum=rates[0]+rates[1];  //sum of rates

      r2=rand() / (RAND_MAX + 1.0);

       ///here we are randomly determining the time of the next event
      tau=ran_expo(rate_sum);
      t[i+1]=t[i]+tau;
     /// printf("Tau=%lf  -> Time[%d]=%lf  X[%d]=%lf \n",tau,i,t[i],i,X[i]);  ///uncomment this line to check how the iterations proceed. 

      ///here we take the probability of the which of the event will be happening
       if(r2*rate_sum < rates[0]){
       X[i+1]=X[i]+1;
       }
       else if((r2*rate_sum>rates[0]) && (r2*rate_sum <= (rates[0]+rates[1])) ){
        X[i+1] =X[i]-1;
       }
       i++;
    }
free(X);
free(t);
}
