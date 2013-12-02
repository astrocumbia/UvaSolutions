#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
using namespace std;
#define T 500
map<char,int> p;
char buff[10000],tmp;

int main( ){
     int casos,n,i,j,k,x;
     long long int ans;
     double ans_div = 0;
     scanf("%d\n",&casos);
     for(i=0; i<casos; i++){
          ans = 0;
          p.clear();
          scanf("%d\n",&n);
          for(j=0; j<n; j++){
               scanf("%c %d\n",&tmp,&x);
               p[tmp]=x;
           }
           scanf("%d\n",&n);
           for(j=0; j<n; j++){
               gets(buff);
               for(k=0; buff[k]!='\0'; k++){
                    ans+=p[ buff[k] ];
               }
           }
           ans_div = (double) ans/100;
           printf("%.2lf$\n", ans_div);     
     }
     return 0;
}

