#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
using namespace std;

stack < char >P;
char buff[100];

int bigger( char c ){
     switch( c ){
          case '*':return 2;
          case '/':return 2;
          case '+':return 1;
          case '-':return 1;
          default: return 0;
     }
}

bool isNumber( char c ){
     if( c>='0' && c<='9' )
          return true;
     return false;
}

void procesar(char x){
     if( isNumber(x) ) printf("%c",x);
     else if( x == '(' ) P.push(x);
     else if( x == ')' ){
          while( !P.empty() && P.top()!='(' )
               printf("%c",P.top()),P.pop();
          if( !P.empty() ) P.pop();
     }
     else{
          while( !P.empty() && P.top()!='(' && bigger(x) <= bigger(P.top()))
               printf("%c",P.top()),P.pop();
          P.push(x);
     }
}

int main( ){
     int casos;
     char x;
     scanf("%d\n",&casos);
     
     for(int i=0; i<casos; i++){
     
          if( i ) printf("\n");
          
          while(1){
               gets(buff);
               x=buff[0];
               if(x=='\0' || feof(stdin) )break;
               procesar(x);    
          }
          while( !P.empty() )
               printf("%c",P.top()),P.pop();
          
          
          
          printf("\n");
     }
     return 0;
}

