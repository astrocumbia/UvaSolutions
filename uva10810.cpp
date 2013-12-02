#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define T 500000+100

long int A[T];
long long unsigned cont;

void merge( int p, int q ,int r ){
     int i,j;
     int n1 = q-p+1;
     int n2 = r-q;
     long int L[n1+1], R[n2+1];
     memcpy(L,A+p, n1*sizeof(long int) );
     memcpy(R,A+q+1, n2*sizeof(long int) );
     L[n1] = 0xFFFFFFF;
     R[n2] = 0xFFFFFFF;
     i=0;
     j=0;
     for(int k=p; k<=r; k++){
          if( L[i]<=R[j] )
               A[k]=L[i++];
           else{
               cont+=n1-i;
               A[k]=R[j++];
           }
     }
}

void mergeSort( int p, int r ){
     int q;
     if( p < r ){
          q = (p+r)/2;
          
          mergeSort(  p ,  q);
          mergeSort( q+1,  r);
          merge( p, q, r );  
     }
}

int main ( ){
     int size;
     while( scanf("%d",&size)!=EOF, size!=0 ){
          cont = (long long unsigned)0;
          for(int i=0; i<size; i++)
               scanf("%ld",&A[i]);
          mergeSort(0,size-1);
          printf("%llu\n",cont);         
     }
     return 0;
}
