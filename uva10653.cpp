#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#define T 1009
using namespace std;

int R,C,m[T][T];
int mov[][2]={{-1,0},{1,0},{0,-1},{0,1}};

int bfs( int rs, int cs, int rend, int cend ){
     queue< int >q;
     m[rs][cs]=1;
     q.push(rs);
     q.push(cs);
     
     while( !q.empty() ){
          int r = q.front(); q.pop();
          int c = q.front(); q.pop();
          int w = m[r][c];
          
          /*we can get to end*/
          if( r==rend && c==cend) 
               return w;
          
          for(int i=0; i<4; i++){
                /* se calculas las nuevas posiciones usando los cuatro movimientos*/
               int nr = r + mov[i][0];
               int nc = c + mov[i][1];
               /* validar que los numeros sean entre 0 y maximo de columas y reglones*/
               if( nr>=0 && nr<R && nc>=0 && nc<C && m[nr][nc]==0){
                    q.push(nr);
                    q.push(nc);
                    m[nr][nc] = w+1;
               }
          }               
          
     }
     
     return -1;
}

int main ( ){
     while ( scanf("%d%d",&R,&C)!=EOF ) {
          if ( R==0 && C==0 ) break;
          
          memset(m, 0, sizeof m );
          
          int N, arista, u,v;
          scanf("%d",&N);
          for(int i=0; i<N; i++){
               scanf("%d",&u);
               scanf("%d",&arista);
               for(int i=0; i<arista; i++){
                    scanf("%d",&v);
                    m[u][v] = -1;
               }
          }
          
          int rsource,csource,rend,cend;
          scanf("%d %d",&rsource, &csource);
          scanf("%d %d",&rend,&cend);
          
          int ans = bfs(rsource, csource, rend, cend);
          printf("%d\n",ans-1);
     }
     return 0;
}
