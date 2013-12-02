#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define T 10000
using namespace std;

int dp[T][T],n,m;
char buff[T+100],a[T],b[T];

int ans( ){
     for(int i=0; i<=n; i++) dp[i][0]=i;
     for(int i=0; i<=m; i++) dp[0][i]=i;
     for(int i=1; i<=n; i++)
          for(int j=1; j<=m; j++){
               if( a[i-1]==b[j-1] )
                    dp[i][j]=dp[i-1][j-1];
               else
                    dp[i][j] = min( dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
          }
      return dp[n][m];
}

int main( ){
     while(1){
          
          
          gets(buff);
          sscanf(buff,"%d %s",&n,&a);
          if(feof(stdin))break;
          gets(buff);
          sscanf(buff,"%d %s",&m,&b);
          printf("%d\n",ans());
          
     }
     return 0;
}
