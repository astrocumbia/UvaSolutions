#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

int A[109],B[109], dp[109][109];

int lcs(int n,int m){

     for(int i=0; i<=n; i++) dp[i][0]=0;
	for(int i=0; i<=m; i++) dp[0][i]=0;
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if( A[i-1]==B[j-1] )
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max( dp[i][j-1], max( dp[i-1][j-1], dp[i-1][j] ) );
				
	return dp[n][m];
	
}

int main( ){
     
     int n,m,tc=0;
     
     while( scanf("%d%d",&n,&m)!=EOF  ){
          
          if( n==0 && m==0 ) break;
          
          for( int i = 0; i<n; i++ ) scanf("%d",&A[i]);
          for( int i = 0; i<m; i++) scanf("%d",&B[i]);
          
          tc++;
          
          printf("Twin Towers #%d\n", tc);
          printf("Number of Tiles : %d\n\n", lcs(n,m) );
          
     }
     return 0;

}
