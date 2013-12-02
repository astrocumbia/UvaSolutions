#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

typedef struct{ double x,y; }Point;
typedef struct{ 
	Point a,b,c;
	char type;
	double r;
}Figure;

Figure f[20];
char buff[1000];

void norm( int i ){
	Figure tmp = f[i];
	
	f[i].a.x = min( tmp.a.x, tmp.b.x );
	f[i].a.y = min( tmp.a.y, tmp.b.y );
	f[i].b.x = max( tmp.a.x, tmp.b.x );
	f[i].b.y = max( tmp.a.y, tmp.b.y );
}

bool insideRectangle( int i, Point p ){
	if( p.x > f[i].a.x && p.x < f[i].b.x && p.y > f[i].a.y && p.y < f[i].b.y )
		return true;
	return false;
}

bool insideCircle( int i, Point p ){
	double dist = (f[i].a.x-p.x)*(f[i].a.x-p.x) + (f[i].a.y-p.y)*(f[i].a.y-p.y);
	if( dist < f[i].r*f[i].r )
		return true;
	return false;
}

double Dabs(double n){ return n>0? n:-n;}

double  Atriangle( Point a, Point b, Point c ){
	Point A = { b.x-a.x, b.y-a.y },
	      B = { c.x-a.x, c.y-a.y };
	
	double area = -( A.x*B.y - B.x*A.y );
	return Dabs(area);               
}

bool insideTriangle( int i, Point p ){
	double t  = Atriangle( f[i].a,f[i].b,f[i].c ),
	    t1 = Atriangle( f[i].a,f[i].b,p),
	    t2 = Atriangle( f[i].b,f[i].c,p),
	    t3 = Atriangle( f[i].a,f[i].c,p);

	if( Dabs(t-(t1+t2+t3)) < 1e-5 && t1 != 0 && t2 != 0 && t3 != 0 )
		             return true;
	return false;
}
int main(){
	
	int index = 0, indexp = 0, flag;
	Point p;

	while( gets(buff), buff[0]!='*' ){
		if( buff[0] == 'r' ){
			sscanf( &buff[2], "%lf%lf%lf%lf", &f[index].a.x,
							  &f[index].a.y,
							  &f[index].b.x,
							  &f[index].b.y);
			f[index].type = 'r';
			norm( index );
		}
		else if( buff[0] == 'c' ){
			sscanf( &buff[2],"%lf%lf%lf", &f[index].a.x,
						      &f[index].a.y,
						      &f[index].r);
			f[index].type = 'c';
		}
		else{
			sscanf( &buff[2],"%lf%lf%lf%lf%lf%lf", &f[index].a.x,
							       &f[index].a.y,
							       &f[index].b.x,
							       &f[index].b.y,
							       &f[index].c.x,
							       &f[index].c.y );
			f[index].type = 't';
		}
		index++;
	} 
	while( scanf("%lf%lf",&p.x,&p.y), p.x!=9999.9 && p.y!=9999.9 ){
		indexp++;
		flag = 0;
		
		for(int i = 0; i < index; i++)
			if( f[i].type == 'r' ){
				if( insideRectangle( i, p ) == true ){
					printf("Point %d is contained in figure %d\n",indexp,i+1);	
					flag++;
				}		
			}
			else if( f[i].type == 'c' ){
				if( insideCircle( i, p ) == true ){
					printf("Point %d is contained in figure %d\n",indexp,i+1);	
					flag++;
				}
			}
			else{ 	
				if( insideTriangle( i, p ) == true ){
					printf("Point %d is contained in figure %d\n",indexp,i+1);	
					flag++;
				}
			}
		if( flag == 0 )
			printf("Point %d is not contained in any figure\n",indexp);
	}
	return 0;
}
