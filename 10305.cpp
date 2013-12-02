#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define T 200
using namespace std;

int graph[T][T], N;
bool visitado[T];
vector< int >vec;

void dfs( int node ){
     visitado[ node ] = true;
     for(int i=1; i<=N; i++)
          if( graph[node][i]==1 && visitado[i]==false)
               dfs(i);
     vec.push_back(node);
}

int main( ){
     int aristas;
     
     while( scanf("%d %d",&N,&aristas)!=EOF ){
          
          if(N==0 && aristas==0) break;
          
          memset(graph, 0, sizeof graph );
          memset(visitado, false, sizeof visitado);
          vec.clear();
          
          int u,v;
          while( aristas-- ){
               scanf("%d %d",&u,&v);
               graph[u][v] = 1;
          }
          
          for(int i=1; i<=N; i++)
               if( visitado[i] == false )
                    dfs(i);
          int blank = 0;
          reverse( vec.begin(), vec.end() );
          for(int i=0; i<vec.size(); i++){
               
               if( blank++ ) printf(" ");
               
               printf("%d",vec[i]);
               
           }
           printf("\n"); 
     }
     return 0;     
}

