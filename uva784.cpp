#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define T 200
using namespace std;

char maze[T][T],buff[T];
int mov[][2]={{-1,0},{1,0},{0,1},{0,-1}};

void dfs( int r, int c ){
     maze[r][c] = '#';
     for(int i=0; i<4; i++){
          int nr = r + mov[i][0];
          int nc = c + mov[i][1];
          if( maze[nr][nc]!='#' && maze[nr][nc]!='X' )
               dfs( nr, nc ); 
     }
     
}

int main( ){
     int tc;
     
     gets(buff);
     sscanf(buff,"%d",&tc);
     while( tc ){
           
          int flag = 0,R=0,r=0,c=0;
                   
          for(int i=0;  ; i++,R++){
               gets( maze[i] );
               if( maze[i][0]=='_' ) break;
               
               /* find '*' */
               for(int j=0; maze[i][j]!='\0' && flag!=1 ; j++)
                    if( maze[i][j]=='*' ){
                         r = i;
                         c = j;
                         flag = 1;
                    }
          }
          tc--;
          dfs( r, c);
          for(int i=0; i<=R; i++)
               puts(maze[i]);
          
     }
     return 0;
}

