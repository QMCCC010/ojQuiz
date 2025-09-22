#include <stdio.h>

long long whittle(int x){
    if(x == 1) return 6;
    else return 2 * whittle(x - 1) + 2;
}

int main(){
    int x = 0;
    scanf("%d", &x);
    printf("%lld", whittle(x));
    return 0;
}