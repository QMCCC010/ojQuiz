#include <stdio.h>

int right(int n, int k){
    if(k == 1) return n % 10;
    else return right(n / 10, k - 1);
}

int main(){
    long long n = 0;
    int k = 0;
    scanf("%lld %d", &n, &k);
    printf("%d", right(n, k));
    return 0;
}