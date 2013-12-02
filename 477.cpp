#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct{ double x,y; }Point;

typedef struct{ 
	char type; 
	Point a,b;
	double r;
}Figure;

Figure F[20];
char buff[1000];

void norm( int index ){
	Figure tmp = F[index];

	F[index].a.x = min( tmp.a.x, tmp.b.x );
	F[index].a.y = min( tmp.a.y, tmp.b.y );
	F[index].b.x = max( tmp.a.x, tmp.b.x );
	F[index].b.y = max( tmp.a.y, tmp.b.y );
}

bool insideRectangle( int i, Point p ){
	if( p.x < F[i].b.x && p.x > F[i].a.x && p.y < F[i].b.y && p.y > F[i].a.y )
		return true;
	return false;
}

bool insideCircle( int i, Point p ){
	double dist =(p.x-F[i].a.x)*(p.x-F[i].a.x) + (p.y-F[i].a.y)*(p.y-F[i].a.y);
	if( dist < F[i].r*F[i].r )
		return true;
	return false;
}

int main( ){
	int index = 0, indexp = 0, flag;
	Point p;

	while( gets(buff), buff[0]!='*' ){
		if( buff[0]=='r' ){
			sscanf( &buff[2],"%lf%lf%lf%lf",&F[index].a.x,
							&F[index].a.y,
							&F[index].b.x,
							&F[index].b.y);
			F[index].type = 'r';
			norm( index );
		}
		else{
			sscanf( &buff[2],"%lf%lf%lf",&F[index].a.x,&F[index].a.y,&F[index].r );
			F[index].type = 'c';
		}
		index++;
	}
	while( scanf("%lf%lf",&p.x,&p.y), p.x!=9999.9 && p.y!=9999.9 ){
		indexp++;
		flag = 0;

		for(int i = 0; i< index; i++)
			if( F[i].type == 'r' ){
				if( insideRectangle( i, p )==true ){
					printf("Point %d is contained in figure %d\n",indexp,i+1);
					flag++;
				}
			}
			else{
				if( insideCircle( i, p ) ){
					printf("Point %d is contained in figure %d\n",indexp,i+1);
					flag++;
				}
			}

		if( flag == 0 ) 
		printf("Point %d is not contained in any figure\n",indexp);	
		
	}
	return 0;
}
