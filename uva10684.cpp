#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long int lli;

lli max( lli a, lli b ){
     return a>b? a:b;
}

int main ( ){
     int n;
     
     while( scanf("%d",&n)!=EOF, n!=0 ){
          lli tmp=0,sum=0,ans=0;
          for(int i=0; i<n; i++){
               scanf("%lld",&tmp);
               sum = max(sum+tmp,0);
               ans = max(ans,sum);
          }
          if( ans > 0 )
               printf("The maximum winning streak is %lld.\n",ans);
          else
               printf("Losing streak.\n");
     }
     return 0;
}
