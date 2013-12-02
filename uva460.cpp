#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct point{ 
     int x,y; 
} Point;

typedef struct rect{
     Point a,b;
}Rectangle;

Rectangle r[3];

void norm( int i ){
     Rectangle tmp = r[i];
     r[ i ].a.x = min( tmp.a.x, tmp.b.x );
     r[ i ].a.y = min( tmp.a.y, tmp.b.y );
     r[ i ].b.x = max( tmp.a.x, tmp.b.x );
     r[ i ].b.y = max( tmp.a.y, tmp.b.y );
}

bool OverLap(  ){
     r[ 2 ].b.x = min( r[0].b.x, r[1].b.x );
     r[ 2 ].b.y = min( r[0].b.y, r[1].b.y );
     
     r[ 2 ].a.x = max( r[0].a.x, r[1].a.x );
     r[ 2 ].a.y = max( r[0].a.y, r[1].a.y );
     
     if( r[2].a.x < r[2].b.x && r[2].a.y < r[2].b.y )
          return true;
     return false; 
}

int main ( ){
     int tc;
     scanf("%d",&tc);
     
     while( tc-- ){
          scanf("%d %d %d %d\n",   &r[0].a.x,
                                   &r[0].a.y,
                                   &r[0].b.x,
                                   &r[0].b.y);
     
          scanf("%d %d %d %d\n",   &r[1].a.x,
                                   &r[1].a.y,
                                   &r[1].b.x,
                                   &r[1].b.y);
          
           norm( 0 );
           norm( 1 );
         if( OverLap() == true )
               printf("%d %d %d %d\n", r[2].a.x, r[2].a.y, r[2].b.x,r[2].b.y);
            else
               printf("No Overlap\n");
          if( tc ) printf("\n");
     }
     
     return 0;
}
