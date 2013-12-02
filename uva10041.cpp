#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#define T 1000
using namespace std;

int vector[T], size;

int main( ){
     int tc;
     scanf("%d",&tc);
     while( tc-- ){
          
          scanf("%d", &size);
          for(int i=0; i<size; i++)
               scanf("%d", &vector[i]);
           
           sort( vector, vector+size );
           
           int med = vector[ size/2 ], ans =0;
           for(int i=0; i<size; i++)
               ans+= abs( med - vector[i] ); 
          printf("%d\n",ans);
     }
     return 0;
}
