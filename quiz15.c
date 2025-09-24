// 字符串一定要以'\0'结尾！！！！！！！#include <stdio.h>

#include <string.h>

#define MAX_LEN 100001
#define True 1
#define False 0

int findMinStr(char str[]){
    int len = strlen(str);
    int allSameLabel = True;
    int label = True;

    // 如果字符串长度为奇数
    if(len % 2 != 0) return len;

    // 如果字符串长度为1
    if(len == 1) return 1;


    for(int i= 0; i < len; i++){
        if(str[i] != str[len - i - 1]) label = False;
    }
    if(label == False) return len;
    else{
        char subStr[len/2 + 1];
        for(int i = 0; i < len/2; i++) subStr[i] = str[i];
        subStr[len/2] = '\0'; 
        return findMinStr(subStr);
    }
}

int main(){
    char kingsStr[MAX_LEN];
    scanf("%s", kingsStr);
    printf("%d\n", findMinStr(kingsStr));

    return 0;
}