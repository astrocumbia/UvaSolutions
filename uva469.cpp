#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
using namespace std;

char buff[109], mat[109][109];
int  tmp[109][109];
int mov[][2]={{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
int R,C,ans;

bool isNumber( char c ){return c>='0' && c<'9'? true: false;}

void dfs(int r,int c){
     tmp[r][c]=1;//visitado
     if( mat[r][c]=='L' ) return;
     for(int i=0; i<8; i++){
          int nr = r + mov[i][0];
          int nc = c + mov[i][1];
          if(nr>=0 && nr<R && nc>=0 && nc<C){
               if( mat[nr][nc]=='W' && tmp[nr][nc]==0 ){
                    ans++;
                    dfs(nr,nc);
               }
          }
     }     
}

int main( ){
     int tc;
     gets(buff);
     sscanf(buff,"%d",&tc);
     gets(buff);
     
     
     while(tc--){
          
          R=0;
          C=0;
          for(int i=0; ; i++,R++){
               gets(mat[i]);
               
               if( i == 0 ) C = strlen(mat[i]);
               if( isNumber( mat[i][0] ) == true )
                    break;   
                         
          }
          
          int i,j;
          strcpy( buff, mat[R] );
          
          while( 1 ){
               sscanf(buff,"%d%d",&i,&j);
               memset(tmp, 0, sizeof tmp);  
               ans=0;
               i--;j--;
               dfs(i,j);
              // printf("%c\n",mat[i][j]);
               if( mat[i][j]=='W' ){ ans++;}
               printf("%d\n",ans);         
               gets( buff );
               
               if( feof(stdin) || buff[0]=='\0' )break;
          }
          if( tc ) printf("\n");
     }
     return 0;
}
