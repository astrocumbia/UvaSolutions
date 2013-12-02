#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#define T 350
using namespace std;


typedef struct{
     int v[T+T];
     int tope; 
}PILA;

int m[T][T],padre[T],N;
bool visitado[T];
PILA p;

void clear( ){
     p.tope = 0;
}

bool empty( ){
     if( p.tope== 0) return true;
     return false;
}

void push( int n ){
     p.v[p.tope++] = n;
}

int pop(  ){
     if( empty()== false )   
          return p.v[--p.tope];
}

bool isNumber( char c ){
     if( c>='0' && c<='9' )
          return true;
     return false;     
}



void clearString( string &s ){
     int size = s.size( );
     for(int i=0; i<size; i++)
          if( isNumber( s[i] ) == false )
               s[i] = ' ';
}

bool bfs( int source, int end ){
     queue< int >q;
     q.push( source );
     visitado[ source ] = true;
     padre[ source ] = source;
     
     while( !q.empty() ){
          int nodo = q.front(); q.pop();
          if( nodo == end ) return true;
          
          for(int i=1; i<=N; i++)
               if( m[nodo][i] == 1 && visitado[ i ] == false ){
                    visitado[i] = true;
                    padre[ i ] = nodo;
                    q.push( i );
               }
     }
     return false;
}

void pathPadres( int vertex ){
     push( vertex );
     while( padre[vertex]!=vertex ){
          
          vertex = padre[ vertex ];
          push( vertex );
     }
}


int main( ){
     string buff;
     int u,v,consultas;
     while( scanf("%d\n",&N)!=EOF ){
          
          
          memset( m, 0, sizeof m);

          /*leer tablas de ruteo*/
          for(int i=1; i<=N; i++){
               getline(cin, buff);
               clearString( buff );
               
               istringstream flujo1( buff );
               
               
               flujo1 >> u;
               while( flujo1 >> v ){
                    m[u][v] = 1;
               }
           }
           
           printf("-----\n");
           
           /*leer consultas */
           scanf("%d\n",&consultas);
           
           for(int i=0; i<consultas; i++){
               
               memset( padre, 0, sizeof padre);
               memset( visitado, false, sizeof visitado);
               clear( );
               
               scanf("%d %d\n",&u,&v);
               if( bfs(u,v) == true ){
               
                   /* cargar padres*/
                   pathPadres( v );
                   
                   /*print Padres*/
                   int flag = 0;
                   while( !empty() ){
                         /*print space*/
                         if( flag++ ) printf(" ");
                         printf("%d",pop() );
                   }  
                   printf("\n");
                   
               }
               else 
                    printf("connection impossible\n");       
          }                  
     } 
     return 0;
}
