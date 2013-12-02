#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#define T 1009
using namespace std;

char A[T],B[T],buff[500];
int dp[T][T];

void strrev( char v[], int size ){
    char c;
    
    for(int i=0, j=size-1; i<size/2 ; i++,j--){
          c    = v[i];
          v[i] = v[j];
          v[j] = c;       
    }
    v[size]='\0';     
}

int LCS( int n , int m ){
     for(int i=0; i<=n; i++){ 
          dp[ i ][ 0 ] = 0;
          dp[ 0 ][ i ] = 0;
     }
     
     for(int i=1; i<=n; i++)
          for(int j=1; j<=m; j++)
               if( A[i-1]==B[j-1] )
                    dp[ i ][ j ] = dp[i-1][j-1]+1;
               else 
                    dp[i][j] = max( dp[i][j-1], max( dp[i-1][j-1], dp[i-1][j] ) );
     return dp[n][m];
}

int main ( ) {
     
     int n;
     gets( buff );
     sscanf( buff, "%d", &n );
     while( n-- ){
     
          gets( A );
          strcpy( B, A );
          
          int length = strlen(A);
          strrev( B, length );
          
          int ans = LCS( length, length );
          
          printf("%d\n",ans);
     }
     
     return 0;
}
