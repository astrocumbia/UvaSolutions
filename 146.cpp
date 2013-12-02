#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char buff[5000];


int main( ){
     while(1){
          gets(buff);
          if( buff[0]=='#' || feof(stdin) )break;
          
          if( next_permutation(buff,buff+strlen(buff)) )
               puts(buff);
          else
               puts("No Successor");
     }
     return 0;
}
