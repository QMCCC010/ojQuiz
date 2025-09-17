#include <stdio.h>
#include <string.h>

#define MAX_LEN 10000

int main(){
    char biStr[MAX_LEN];
    int numOps = 0;
    if(fgets(biStr, MAX_LEN, stdin) != NULL){
        biStr[strcspn(biStr, "\n")] = '\0';
        scanf("%d", &numOps);
        int len = strlen(biStr);
        int biArr[len];
        for(int i = 0; i < len; i++){
            biArr[i] = biStr[i] - '0';
        }
        int zeroCounts = 0, oneCounts = 0;
        int lenArr[len];
        int index = 0;

        // 统计所有连续子段的长度
        for(int i = 0; i < len; i++){
            if(biArr[i] == 0){
                zeroCounts++;
                if(oneCounts != 0){
                    lenArr[index++] = oneCounts;
                    oneCounts = 0;
                }
            }
            else if(biArr[i] == 1){
                oneCounts++;
                if(zeroCounts != 0){
                    lenArr[index++] = zeroCounts;
                    zeroCounts = 0;
                }
            }
        }
        if (zeroCounts > 0) lenArr[index++] = zeroCounts;
        if (oneCounts > 0) lenArr[index++] = oneCounts;

        int maxLen = lenArr[0]; // 记录最长的子字符串长度
        int maxIndex = 0;
        for(int i = 1; i < index; i++){
            if(lenArr[i] > maxLen){
                maxLen = lenArr[i];
                maxIndex = i;
            }
        }
    }
    return 0;
}