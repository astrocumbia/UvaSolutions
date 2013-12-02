#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <string>
#define T 200
using namespace std;

char buff[T];
char m[T][T];
int  ans[T][T],R,C;
int mov[][2]={{-1,0},{1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,-1},{1,1}};
int blanks[T];

void buildGrid( int r ){
     char *ptr = strtok(buff," ");
     int i;
     for(i=0; ptr!=NULL; i++ ){
          m[r][i] = ptr[0];
          ptr = strtok(NULL," ");
     }
     /* length of columns*/
     C=i;
}

bool load( ){
     for(R=0; ; R++){
         
          gets(buff);
          /* we have a row more*/ 
          if( buff[0]=='%' ) return true;
          /* the input is over*/
          if( feof(stdin) ) return false;
               
          buildGrid( R );
     }     
}

void dfs( int r, int c, char letter, int num ){
     ans[r][c]=num;
     for(int i=0; i<8; i++){
          int nr = r + mov[i][0];
          int nc = c + mov[i][1];
          
          if( nr>=0 && nr<R && nc>=0 && nc<C ){
               if( m[nr][nc]==letter && ans[nr][nc]==0 )
                    dfs(nr, nc, letter, num); 
          }
     }
}

void solve( ){
     for(int i=0,number=1; i<R; i++)
          for(int j=0; j<C; j++)
               if( ans[i][j]==0 )
                    dfs(i,j,m[i][j],number++);
              
 
      /* calculate blank spaces*/
      for(int i=0; i<C; i++){
          for(int j=0; j<R; j++){
               sprintf(buff,"%d",ans[j][i]);
               blanks[i]= max(blanks[i],(int)strlen(buff));
          }
      }
      
      
      /*print solution*/
      for(int i=0; i<R; i++){
          for(int j=0; j<C; j++)
               if( j==0 ) printf("%*d",blanks[j],ans[i][j]); 
               else printf("%*d",blanks[j]+1,ans[i][j]);
          printf("\n");
      }         
      
      printf("%c\n",'%');
}

int main( ){
     while( 1 ){
          bool go = load( );
          memset(ans,0,sizeof ans);
          memset(blanks,0,sizeof blanks);
          solve( );
          if( go == false)break;
     }     
     return 0;
}
