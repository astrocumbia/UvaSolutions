#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#define T 400
using namespace std;

char buff[T];
int w,h,maze[T][T], cont, longest;
int mov[][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,-1},{1,1}};
void slash( int r, int c, int tipo ){
     r*=4;
     c*=4;
     if( tipo == 1 ){ /* representa '/' */
         maze[r+0][c+1] = -2;
         maze[r+1][c+0] = -2;
         maze[r+2][c+3] = -2;
         maze[r+3][c+2] = -2;  
     }
     else{ /* Representa '\' */
         maze[r+0][c+2] = -2; 
         maze[r+1][c+3] = -2;
         maze[r+2][c+0] = -2;
         maze[r+3][c+1] = -2;
     }
}

void DFS(int r, int c, int pr, int pc, int peso){
     maze[r][c] = peso;
     for(int i=0; i<8; i++){
          int nr = r + mov[i][0];
          int nc = c + mov[i][1];
          
          if( nr >= 0 && nr < h && nc>=0 && nc<w && maze[nr][nc]!=-1 && (nr!=pr || nc!=pc) ){
               if( maze[nr][nc] == -2 ) DFS(nr,nc,r,c,peso+1);
               else if( maze[nr][nc] < peso+1 ){
                    cont++;
                    longest = max( longest, ( peso+1 - maze[nr][nc] )/2 );
               }
          }
     }
}

int main( ){

     int tc = 0;
     
     while( scanf("%d %d\n",&w,&h)!= EOF ){
          if( w==0 && h==0 ) break;
          memset(maze, -1, sizeof maze );
          
          for(int i=0; i<h; i++){
               gets(buff);
               for(int j=0; j<w; j++)
                    if( buff[j]=='/' )
                         slash(i,j,1);
                    else               
                        slash(i,j,2);
           }
                   
          w*=4;
          h*=4;
          cont=0;
          longest=0;
                       
          for(int i=0; i<h; i++)
              for(int j=0; j<w; j++)
                   if( maze[i][j] == -2 ) DFS(i,j,-1,-1,0);
          
          tc++;
          printf("Maze #%d:\n",tc);
          
          if( cont == 0 )
               printf("There are no cycles.\n");
          else          
               printf("%d Cycles; the longest has length %d.\n",cont,longest);
          printf("\n");
     }     
     return 0;
}
