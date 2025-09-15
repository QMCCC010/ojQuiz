#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 10001

void convertedStr(char str[], char newStr[]){
    int index = 0;
    int len = strlen(str);

    for(int i = 0; i < len; i++){
        if(str[i] != '#'){
            newStr[index++] = str[i];
        }
        else if(index > 0){
            index -= 1;
        }
    }
    newStr[index] = '\0';
}

int main(){
    char str[MAX_LEN];
    char str1[MAX_LEN / 2], str2[MAX_LEN / 2];
    int i, j, k = 0;

    if(fgets(str, sizeof(str), stdin) != NULL){
        /*
        分割输入的两个字符串
        */
        for(i = 0; str[i] != ' ' && str[i] != '\0'; i++);

        for(j = 0; j < i; j++){
            str1[j] = str[j];
        }
        str1[j] = '\0';

        // 跳过空格
        if (str[j] == ' ') {
            j++; 
        }

        // j 用于遍历 str，k 用于写入 str2
        for(k = 0; str[j] != '\0' && str[j] != '\n'; j++, k++){
            str2[k] = str[j];
        }
        str2[k] = '\0';

        /*
        判断两个字符串是否相同
        */
       char newStr1[MAX_LEN / 2];
       char newStr2[MAX_LEN / 2];
       convertedStr(str1, newStr1);
       convertedStr(str2, newStr2);

       if(strcmp(newStr1, newStr2) == 0){
        printf("True");
       }
       else{
        printf("False");
       }
    }
    return 0;
}