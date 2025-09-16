#include <stdio.h>

int reverseNum(int num){
    int newNum = 0;
    if(num == 0) return 0;
    else{
        int digit = 0;
        int temp = 0;
        for(int i = 1; i <= num; i *= 10) digit ++;

        for(int i = 10; i <= num*10; i *= 10){
            temp = num % i - num % (i/10);
            temp = temp / (i/10);
            for(int k = digit - 1; k > 0; k--) temp *= 10;
            newNum += temp;
            digit--;
        }
        return newNum;
    }
    
}

int main(){
    int num = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        int j = reverseNum(i);
        if(i + j == num){
            printf("True");
            return 0;
        }
    }
    printf("False");
    return 0;
}