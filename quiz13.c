// 任意两个相邻的斐波那契数，它们的最大公约数一定是 1
#include <stdio.h>

int counter = 0;



int gcd(int a, int b) {

if (b == 0) return a;

counter++;

return gcd(b, a % b);

}


void reverseGcd(int a, int b, int x){
    gcd(a, b);
    if(x == counter) printf("%d %d", a, b);
    else{
        counter = 0;
        reverseGcd(b, a + b, x);
    }
}

int main() {

int a = 1, b = 1;
int x;
scanf("%d", &x);

reverseGcd(a, b, x);

}