/*
对于所有异常值，应满足以下条件：
1、所有元素之和减去异常值为偶数
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 10000
#define MIN_NUM -1000
#define MAX_NUM 1000
int main(){
    int n = 0;
    int total = 0;
    scanf("%d", &n);
    int *nums = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
        // 计算所有元素之和（包括正常值，正常值的和以及异常值）
        total += nums[i];
    }

    free(nums);
    return 0;
}