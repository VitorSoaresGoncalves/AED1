//primeira analise

#include <stdio.h> 
#include <stdlib.h> 
int main() 
{ 
   int *px,*py ;
   int x=1,y=3 ;
 


   *px=10 ;
   *py=30 ;
   *px=*px+*py;
 
   printf("x=%d, y=%d\n", x, y) ;
   printf("*px=%d, *py=%d\n", *px, *py) ;
   printf("px=%p, py=%p\n", px, py) ;
   printf("&x=%p, &y=%p\n", &x, &y) 
}
