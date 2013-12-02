#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char c[10000];

void decoder( ){
     int i;
     for ( i=0; c[i]!='\0' ; i++ )
          printf( "%c",c[i]-7 );
     printf("\n");
}

int main ( ){
     while (1){
          gets(c);
          
          if ( feof(stdin) ) 
               break;
          decoder( );
     }
     return 0;
}
