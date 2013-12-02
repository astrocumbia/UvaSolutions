#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#define Negro 1
#define Blanco 2
#define novis 0
#define T 250
using namespace std;

int m[T][T], people, black, white;
int visitado[T];

int bfs( int vertex ){
     queue< int >q;
     int flag = 1;
     
     visitado[ vertex ] = Negro;
     black++;
     q.push( vertex );     
     
     while( ! q.empty() ){
          int nodo = q.front( ); q.pop();
          int color = visitado[ nodo ];
          
          for(int i=1; i<=people; i++)
               if( m[nodo][i]==1 ){
                    if( visitado[i] == novis ){
                         q.push( i );
                         visitado[i] = 3-color;
                         
                         if( visitado[i] == Negro ) black++;
                         else white++;
                    }
                    else if( visitado[i]==color )/* El grafo no es bicoloreable*/
                         flag = 0;                    
               }     
     }
    /* retornamos si es bicoloreable  o no, es necesario
        recorrer el grafo aunq no sea bicolorable. Esto para
        marcar como visitados todos sus nodos y no volver a 
        recorrer un grafo no bicoloreable*/
     return flag;
}

int main( ){
     int tc;
     scanf("%d",&tc);
     while( tc-- ){
          memset( m, 0, sizeof m );
          memset( visitado, 0, sizeof visitado);
           
          scanf("%d",&people);
         
          int nenemy, tmp;
          
          for(int i=1; i<=people; i++){
               scanf("%d",&nenemy);
               for(int j=0; j<nenemy; j++){
                    scanf("%d",&tmp);
                    m[ i ][tmp] = 1;
                    m[tmp][ i ] = 1;
               }
          }
          
          
          int ans = 0;
          black = 0;
          white = 0;
          
          for(int i=1; i<=people; i++)
               if( visitado[i] == 0 ){
                    int bicoloring = bfs( i );
                    /*si el grafo es bicoloreable tomo el maximo de blaco y negro*/ 
                    if( bicoloring == 1 )
                         ans+= max( black, white);
                                   
                    black = 0;
                    white = 0;
               }
               
          printf("%d\n",ans);     
     }
     return 0;
}
