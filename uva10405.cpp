#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

char A[1009],B[1009];
int dp[1009][1009];

int lcs(int n,int m){

     
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if( A[i-1]==B[j-1] )
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max( dp[i][j-1], max( dp[i-1][j-1], dp[i-1][j] ) );
				
	return dp[n][m];
	
}

int main( ){
     while(1){
          gets(A);
          gets(B);
          if( feof(stdin) ) break;
          memset( dp, 0, sizeof dp );                  
          printf("%d\n", lcs( strlen(A), strlen(B) ) );
     }
     return 0;
}
