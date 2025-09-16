/*
对于所有异常值，应满足以下条件：
1、所有元素之和减去异常值为偶数
2、剩下的元素中存在表示正常值之和的数据
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 10000
#define MIN_NUM -1000
#define MAX_NUM 1000

int main(){
    int n = 0;
    int total = 0; // 所有元素之和
    int sum = 0; // 表示正常值之和的数据
    scanf("%d", &n);
    int *nums = (int*)malloc(n * sizeof(int));
    int *outlier = (int*)malloc(n * sizeof(int));
    int outlierCouts = 0;

    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
        // 计算所有元素之和（包括正常值，正常值的和以及异常值）
        total += nums[i];
    }
    for(int i = 0; i < n; i++){
        if((total - nums[i]) % 2 == 0){
            sum = (total - nums[i]) / 2;
            for(int j = 0; j < n && j != i; j++){
                if(nums[j] == sum) outlier[outlierCouts++] = nums[i];
            }
        }
    }
    int maxOutlier = outlier[0];
    for(int i = 1; i <outlierCouts; i++){
        if(outlier[i] > maxOutlier) maxOutlier = outlier[i];
    }

    printf("%d", maxOutlier);

    free(nums);
    free(outlier);
    return 0;
}