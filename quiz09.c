#include <stdio.h>
#include <math.h>

int reverseNum(int num) {
    int newNum = 0;
    while (num > 0) {
        newNum = newNum * 10 + num % 10;
        num /= 10;
    }
    return newNum;
}


int main(){
    long long L = 0, R = 0;
    int counts = 0;
    scanf("%lld %lld", &L, &R);

    for(int i = (int)ceil(sqrt(L)); i <= (int)floor(sqrt(R)); i++){
        if(i == reverseNum(i) && i * i == reverseNum(i * i)) {
            counts++;
        }
    }
    printf("%d", counts);

    return 0;
}