#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <string>
#define T 100
using namespace std;

char grid[T][T];
int R;
int mov[][2]={{-1,0},{1,0},{0,1},{0,-1}};
bool load( ){
     for(R=0; ; R++){
          gets(grid[R]);
          
          if( grid[R][0]=='_' )
               return true;
     }
}

void dfs( int r, int c, char letter ){
     grid[r][c]=letter;
     for(int i=0; i<4; i++){
          int nr = r + mov[i][0];
          int nc = c + mov[i][1];
          
          if( grid[nr][nc]==' ' ) 
               dfs(nr,nc,letter);
     }
}

int main( ){
     while(load()){
          
          if(feof(stdin))break;
          
          for(int i=0; i<R; i++)
               for(int j=0; grid[i][j]!='\0'; j++)
                    if( grid[i][j]!=' ' && grid[i][j]!='X' )
                         dfs( i, j, grid[i][j] );
           
           for(int i=0; i<=R; i++)
               puts( grid[i] ); 
     }
     return 0;
}
