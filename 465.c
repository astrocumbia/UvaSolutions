#include <stdio.h>
#include <stdlib.h>

char A[10000], B[10000],op;

int main( ){
     
     long double a,b,c;
     
     while( scanf("%s %c %s",A,&op,B) != EOF ){
          
          a = atof( A );
          b = atof( B );
          c = 0;
          
          printf("%s %c %s\n",A,op,B);
          
          if( a > 2147483647 ) printf("first number too big\n");
          if( b > 2147483647 ) printf("second number too big\n");
          
          if( op == '+' ) c = a + b;
          else            c = a * b;
          
          if( c > 2147483647 )
               printf("result too big\n"); 
     }
     return 0;
}
