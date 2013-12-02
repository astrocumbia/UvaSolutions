#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct { double x,y; }Point;
typedef struct { Point a,b; }Rectangle;

char buff[1000];

Rectangle R[20];

void norm( int index ){
	Rectangle tmp = R[index];

	R[index].a.x = min( tmp.a.x,tmp.b.x ); 
	R[index].a.y = min( tmp.a.y,tmp.b.y ); 
	R[index].b.x = max( tmp.a.x,tmp.b.x ); 
	R[index].b.y = max( tmp.a.y,tmp.b.y ); 
}

bool insideRectangle( double x,double y,int i ){
	if( x > R[i].a.x && x < R[i].b.x && y > R[i].a.y && y < R[i].b.y ) 
		return true;
	return false;
}

int main(){
	
	int indexr = 0, indexp = 0;
	Point p;

	while( gets(buff), buff[0]!='*' ){
		sscanf(&buff[2],"%lf%lf%lf%lf",&R[indexr].a.x,
					       &R[indexr].a.y,
					       &R[indexr].b.x,
					       &R[indexr].b.y);
		norm( indexr );
		indexr++;
	}
	
	while( scanf("%lf%lf",&p.x,&p.y), p.x!=9999.9 && p.y!= 9999.9 ){
		indexp++;

		int flag = 0;
		for( int i=0; i< indexr; i++) 
			if( insideRectangle( p.x, p.y, i )==true ){
				flag++;
				printf("Point %d is contained in figure %d\n",indexp,i+1);
			}
		
		if( flag == 0 ) printf("Point %d is not contained in any figure\n",indexp);
	}
	return 0;
}
