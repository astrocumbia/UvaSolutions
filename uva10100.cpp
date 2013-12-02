#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

vector< string > A;
vector< string > B;

int dp[1001][1001];

bool isLetter( char c ){
     if( c>='A' && c<='Z' ) return true;
     if( c>='a' && c<='z' ) return true;
     if( c>='0' && c<='9' ) return true;
     return false;
}

void clearString( string &s ){
     int n = s.size( );
     for( int i=0; i < n; i++ )
          if( isLetter( s[i] ) == false )
               s[i]=' ';
}

int LCS( int n, int m){
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
     string a,b, tmp;
     int tc = 0;
     
     while( getline( cin, a) ){
          getline(cin,b);
          
          
          int atam = a.size( );
          int btam = b.size( );
          
          clearString(a);
          clearString(b);

          A.clear( );
          B.clear( );

          istringstream Ain(a);
          while( Ain >> tmp )
               A.push_back( tmp );
          
          istringstream Bin(b);
          while( Bin >> tmp )
               B.push_back( tmp ); 
          tc++;
          if( atam == 0 || btam == 0 ) printf("%2d. Blank!\n",tc);
          else                         printf("%2d. Length of longest match: %d\n",tc,LCS(A.size(), B.size( )) );
     } 
     return 0;
}
