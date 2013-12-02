#include <stdio.h>
#include <stdlib.h>
#define T 1009
int a[T];

long long int flip( int n ){
     int i,j;
     long long int cnt=0;
     
     for( i = 0; i < n; i++ ) {
       for( j = i + 1; j < n; j++ )
           if( a[i] > a[j] ) cnt++;  
     }
     
     return cnt;
}

int main ( ){
     int n,i;
     while( scanf("%d",&n)!=EOF ){
          for(i=0; i<n; i++)
               scanf("%d",&a[i]);
          printf("Minimum exchange operations : %lld\n", flip(n) );
     }
     return 0;
}
