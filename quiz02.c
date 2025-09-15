#include <stdio.h>

#define MAX_LEN 10001

int main(){
    char str[MAX_LEN];
    char str1[MAX_LEN / 2], str2[MAX_LEN / 2];
    int i, j = 0;

    if(fgets(str, sizeof(str), stdin) != NULL){
        for(i = 0; str[i] != ' ' && str[i] != '\0'; i++);

        for(j = 0; j < i; j++){
            str1[j] = str[j];
        }
        str1[j+1] = '\0';

        for(j = i+1; str[j] != '\0'; j++){
            str2[j] = str[j];
        }
        str2[j+1] = '\0';

        printf(str1);
        printf(str2);
    }
    return 0;
}