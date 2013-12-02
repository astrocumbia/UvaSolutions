#include <stdio.h>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;

map < int, vector< int > > mapa;
int visitados[50000];

int bfs( int vertex, int ttl ){
     int nVertex = 0;
     queue< int > q;
     
     q.push( vertex );
     q.push(    0   );
     visitados[ vertex ] = 1;
     
     while( !q.empty( ) ){
          int actualVertex = q.front( ); q.pop();
          int w = q.front( ); q.pop( );
          
          if( w == ttl ) return nVertex;
          
          vector< int > v = mapa[ actualVertex ];
          
          for(int i = 0; i < v.size(); i++){
               int nextVertex = v[i];
               if( visitados[ nextVertex ] == 0 ){
                    q.push( nextVertex );
                    q.push( w+1 );
                    nVertex++;
                    visitados[ nextVertex ] = 1;
               } 
          }        
     }
     return nVertex;
}
int main( ){
     int n, casos = 0;
     while( scanf("%d",&n), n!=0 ){
          
          memset(visitados, 0,sizeof(visitados) );
          mapa.clear( );
          
          int u,v,ttl,vertex;
          
          for(int i = 0; i < n; i++){
               scanf("%d%d",&u,&v);
               mapa[u].push_back(v);
               mapa[v].push_back(u);     
          }
          while( scanf("%d%d",&vertex,&ttl)!=EOF ){
               if( vertex==0 && ttl==0 ) break;
               memset(visitados, 0,sizeof(visitados) );
               casos++;
               int ans = mapa.size()-bfs( vertex,ttl)-1;
               //printf("mapa.size(): %d\n",mapa.size());
               //printf("bfs: %d\n",bfs(vertex, ttl));
               printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", casos, ans, vertex, ttl );              
          }

     }
     return 0;
}
