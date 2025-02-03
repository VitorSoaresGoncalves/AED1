#include <stdio.h>

 
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

 
void verificarTripla(int x, int y, int z) {
    
    if (x > y) { int temp = x; x = y; y = temp; }
    if (y > z) { int temp = y; y = z; z = temp; }
    if (x > y) { int temp = x; x = y; y = temp; }

     
    if (x * x + y * y == z * z) {
        
        if (mdc(mdc(x, y), z) == 1) {
            printf("tripla pitagorica primitiva\n");
        } else {
            printf("tripla pitagorica\n");
        }
    } else {
        printf("tripla\n");
    }
}

int main() {
    int x, y, z;

    
    while (scanf("%d %d %d", &x, &y, &z) != EOF) {
        verificarTripla(x, y, z);
    }

    return 0;
}
