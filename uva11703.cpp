#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define T 1000000
using namespace std;

int v[T+10];

void calcular( ){
     v[0] = 1;
     int i;
         for ( i = 1; i <= T; i++ ) {
        v [i] = v [(int)floor(i - sqrt (i))] + v [(int)floor (log (i))] + v [(int)floor (i * sin (i) * sin (i))];
        v [i] %= T;
    }
}

int main ( ){
     int n;
     calcular( );
     while( scanf("%d",&n)!=EOF ){
           if( n == -1 )break;
          printf("%d\n",v[n]);
     }
     return 0;
}

