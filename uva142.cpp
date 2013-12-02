#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct{
     int x,y;
     int notVisible;
}Point;

typedef struct{Point a,b;}Rectangle;


char buff[1000];

Point P[200],Click;
Rectangle R[200];
double distancia[200],minimo;
int indexp, indexr;

void normRect( int index ){
     Rectangle tmp = R[ index ];
     R[ index ].a.x = min( tmp.a.x, tmp.b.x );
     R[ index ].a.y = min( tmp.a.y, tmp.b.y );
     R[ index ].b.x = max( tmp.a.x, tmp.b.x );
     R[ index ].b.y = max( tmp.a.y, tmp.b.y ); 
}

bool pointInside( Point p , Rectangle r ){
     
     if( p.x >= r.a.x && p.x <= r.b.x && p.y >= r.a.y && p.y <= r.b.y )
               return true;
     return false;
}

void iconoInRectangle( ){
     for(int i = 0;  i < indexp; i++)
          for(int j = 0; j < indexr; j++){
               if( pointInside( P[i], R[j] ) == true ){
                    P[ i ].notVisible = 1;
                    break;
               }
          } 
}

int clickWindow( Point p ){
     
     for( int i = indexr-1; i >= 0 ; i-- ){
          if( pointInside( p, R[i] ) == true )
               return i;      
     }
     return -1;
}

void initdistancia( ){
     double value = 1<<30;
     for(int i=0; i< indexp; i++)
          distancia[ i ] = value;
}

void calcDistanciaIconos( Point click ){
     for(int i=0; i<indexp; i++ )
          if( P[i].notVisible == 0 ){
               distancia[ i ] = sqrt( (click.x-P[i].x)*(click.x-P[i].x) + (click.y-P[i].y)*(click.y-P[i].y) ); 
               minimo = min( minimo, distancia[i] );
          } 
} 

int main( ){
     indexp = 0;
     indexr = 0;
     
     while( 1 ){
          gets(buff);
         if( buff[0]=='M' || buff[0]=='#' ) break;
          
          if( buff[0] == 'I' ){ //isICONO
               
               sscanf( buff+1, "%d%d", &P[ indexp ].x, &P[ indexp ].y);
               
               indexp++;
          }
          else if( buff[0] == 'R' ){ //isRectangle
               
               sscanf( buff+1, "%d%d%d%d", &R[ indexr ].a.x ,
                                           &R[ indexr ].a.y ,
                                           &R[ indexr ].b.x ,
                                           &R[ indexr ].b.y );
               normRect( indexr );
               indexr++;
               
          }
     }
     
     iconoInRectangle( );
         
     
     while( buff[0]!='#' ){
          
          sscanf(buff+1, "%d%d", &Click.x , &Click.y );
          
          int ans = clickWindow( Click );
          
         if( ans >= 0 ){
               printf("%c\n",ans+'A');
          }
          else{
               initdistancia( );
               minimo = 1<<30;
               
               calcDistanciaIconos( Click ); 
               
               for(int i = 0; i < indexp; i++)
                    if( P[i].notVisible == 0 && minimo == distancia[i] )
                         printf("%3d",i+1);
               printf("\n");             
          }
          gets(buff);
     }
     
          
     return 0;
}
