#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#define T 100
using namespace std;

typedef struct{
     int n;
     char c;
}PAR;

char m[T][T];
int R,C,mov[][2]={{-1,0},{1,0},{0,1},{0,-1}};
vector<PAR>v;

int dfs( int r, int c, char letra ){
     int ans = 1;
     m[r][c]='.';
     
     for(int i=0; i<4; i++){
          int nr = r + mov[ i ][ 0 ];
          int nc = c + mov[ i ][ 1 ];
          
          if( nr>=0 && nr<R && nc>=0 && nc<C && m[nr][nc]==letra )
               ans+=dfs(nr,nc,letra);
     }
     return ans;
}

bool mysort( PAR a, PAR b){
     if( a.n == b.n ){
          return a.c < b.c;
     }
     else if( a.n > b.n ) return true;
     return false;
}

int main( ){
     int nproblem = 0;
     
     while( scanf("%d %d\n",&R,&C)!=EOF ){
          if( R==0 && C==0 ) break;
          v.clear( );
          
          for(int i=0; i<R; i++)
               gets(m[i]);
               
          for(int i=0; i<R; i++)
               for(int j=0; j<C; j++)
                    if(m[i][j]!='.'){
                         PAR tmp;
                         tmp.c = m[i][j];
                         tmp.n = dfs(i,j,m[i][j]);
                         v.push_back(tmp);
                    }
          
          nproblem++;
          printf("Problem %d:\n",nproblem);
          
          sort( v.begin(), v.end(), mysort );
          
          for(int i=0; i<v.size(); i++)
               printf("%c %d\n",v[i].c,v[i].n);
     
     }
     return 0;
}

