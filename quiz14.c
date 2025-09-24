#include <stdio.h>
#include <string.h>

char findLetter(char s[], long long  len, long long N){
    // N小于最小字符串长度，直接返回
    if(N <= strlen(s)){
        return s[N-1];
    }
    else{
        // N小于最大长度的一半，则在前半部分查找
        if(N <= len/2){
            return findLetter(s, len/2, N);
        }
        
        else{
            // 后半部分的第一个字符相当于前半部分的最后一个字符
            if(N == len/2 + 1) return findLetter(s, len/2, len/2);
            // 后半部分的第N个其他字符，相当于前半部分的第N - 1个字符
            else return findLetter(s, len/2, N - len/2 - 1);
        }
    }
}

int main(){
    char s[31];
    long long N = 0;
    scanf("%s %lld", s, &N);
    long long len = strlen(s);

    //寻找大于N的最小子字符串长度
    while(len < N){
        len *= 2;
    }
    char result = findLetter(s, len, N);
    printf("%c\n", result);

    return 0;
}