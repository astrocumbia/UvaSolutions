#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int n, mov[][2]={{1,0},{0,1},{-1,0},{0,-1},{1,-1},{-1,-1},{1,1},{-1,1}};
char mat[50][50];

void BFS( int r, int c ){
	queue <  pair <int,int>  > q;
	q.push( make_pair(r,c) );

	while( !q.empty() ){
		int R = q.front().first;
		int C = q.front().second;
		q.pop();
		mat[R][C] = '0';

		for(int i= 0; i< 8; i++){
			int nr = R + mov[i][0];
			int nc = C + mov[i][1];
			if( nr >= 0 && nr <n && nc >= 0 && nc < n && mat[nr][nc]=='1' )
				q.push( make_pair(nr,nc) );
		}

	}

}
int main(){
	int casos = 0;
	while( scanf("%d\n",&n)!=EOF ){
		int ans = 0;
		casos++;
		for(int i=0; i<n; i++) 
			gets( mat[i] );

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if( mat[i][j]=='1' ){
					ans++;
					BFS(i,j);
				}
		printf("Image number %d contains %d war eagles.\n",casos,ans);
	}
	return 0;
}
