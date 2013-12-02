#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct{
    char dna[200];
    int n;
}P;

P v[102];
int N,M;

int burbuja(char p[]){
	int cnt = 0;
	for ( int i = 0; p [i]; i++ ) 
		for ( int j = i + 1; p [j]; j++ )
			if ( p [i] > p [j] ) cnt++;
	return cnt;
}

bool mysort( P a, P b ){
    return a.n < b.n ? true: false;
}

int main( ){
    int casos;
    scanf("%d",&casos);
    
    while( casos-- ){
     
        scanf("%d %d\n",&N,&M);
       
        for(int i=0; i<M; i++){
            scanf("%s\n",v[i].dna);
            v[i].n = burbuja(v[i].dna);
         }
         
        stable_sort( v, v+M, mysort );
       
        for(int i=0; i<M; i++)
            printf("%s\n",v[i].dna);
        
        if( casos ) printf("\n"); 
    }

    return 0;
}

