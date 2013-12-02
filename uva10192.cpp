#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

char A[109],B[109];
int dp[109][109];

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
     
     int tc = 0;
     while( gets(A) ){
          if(A[0]=='#') break;
          gets(B);
          tc++;
          printf("Case #%d: you can visit at most %d cities.\n",tc,lcs( strlen(A), strlen(B) ) );
     }     
     return 0;
}
