#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#define T 10000
using namespace std;

typedef struct{
     char title[100];
     char firstName[100];
     char lastName[100];
     char homeAddress[100];
     char department[100];
     char homePhone[100];
     char workPhone[100];
     char campusBox[100];
}Member;

Member p[T];
int N;

char buff[1000],depa[1000];

void getInformation( int i ){
     char *ptr = strtok(buff,",");
     
     strcpy( p[i].department, depa);
     
     strcpy( p[i].title     , ptr );
     ptr = strtok(NULL,",");
     strcpy( p[i].firstName , ptr );
     ptr = strtok(NULL,",");
     strcpy( p[i].lastName  , ptr );
     ptr = strtok(NULL,",");
     strcpy( p[i].homeAddress, ptr );
     ptr = strtok(NULL,",");
     strcpy( p[i].homePhone ,    ptr);
     ptr = strtok(NULL,",");
     strcpy( p[i].workPhone, ptr );
     ptr = strtok(NULL,",");
     strcpy( p[i].campusBox, ptr ); 
}

bool mysort( Member a, Member b ){
     if( strcmp( a.lastName, b.lastName ) < 0 )
          return true;
     return false;
}
int main( ){
     int n;
     N=0;
     scanf("%d\n",&n);
     
     for(int i=0; i<n; i++){

          gets(depa);     
          while(1){          
               gets(buff);
               if( feof(stdin) || buff[0]=='\0' )
                    break;
               getInformation( N );
               N++;
           }
     }
     sort(p,p+N,mysort);
     
     for(int i=0; i<N; i++){
          printf("----------------------------------------\n");
          printf("%s ",p[i].title);
          printf("%s ",p[i].firstName);
          printf("%s\n",p[i].lastName);
          printf("%s\n",p[i].homeAddress);
          printf("Department: %s\n",p[i].department);
          printf("Home Phone: %s\n",p[i].homePhone);
          printf("Work Phone: %s\n",p[i].workPhone);
          printf("Campus Box: %s\n",p[i].campusBox);
     }
     return 0;     
}
