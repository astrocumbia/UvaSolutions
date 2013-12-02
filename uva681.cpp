#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define T 262150
using namespace std;

typedef struct{ int x,y; }Point;

Point p[T];
int tope,N;

bool mysort(Point a, Point b){
     if( a.y < b.y ) return true;
     if( a.y > b.y ) return false;
     
     if( a.x < b.x ) return true;
     if( a.x > b.x ) return false;
}

int area( Point a, Point b, Point c ){
     Point A,B;
     A.x = c.x-a.x;
     A.y = c.y-a.y;
     B.x = b.x-a.x;
     B.y = b.y-a.y;
     return (A.x*B.y) - (A.y*B.x);
}

vector< Point> convex( ){
     vector< Point >H;
     
     int k=0;
     for(int i=0; i<N;  i++){
          while( H.size()>=2 && area(H[H.size()-2], H[H.size()-1],p[i])<=0 )
               H.pop_back();
          H.push_back(p[i]);
     } 
     int l = H.size()+1;
     for(int i=N-1; i>=0; i--){
          while( H.size()>=l && area(H[H.size()-2], H[H.size()-1],p[i])<=0 )
               H.pop_back();
          H.push_back(p[i]);
     } 
     return H;
}

int main ( ){
     int tc,tmp;
     scanf("%d\n",&tc);
     printf("%d\n",tc);
     for(int k=0; k<tc; k++){
          scanf("%d",&N);
          for(int i=0; i<N; i++)
               scanf("%d%d",&p[i].x,&p[i].y);
          if( k<tc-1 ) scanf("%d",&tmp);
          sort(p,p+N,mysort);  
          
          vector< Point > ans = convex( );
          printf("%d\n",(int)ans.size());
          
          int size = (int)ans.size();
          for(int i=size-1; i>=0; i--)
               printf("%d %d\n",ans[i].x,ans[i].y);  
          if( k<tc-1 ) printf("-1\n");
     }
     return 0;
}
