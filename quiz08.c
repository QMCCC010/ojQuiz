// 双指针法,时间复杂度为O(k),不符合本题要求，但也是一种解法
/*
#include <stdio.h>

int main(){
    int target = 0;
    int counts = 1;
    scanf("%d", &target);

    // 双指针法提取符合条件的子数列
    int left = 0;
    int right = 0;
    int sum = 0;
    while(right <= target){
        if(sum == target) {
            counts++;
            sum += right + 1;
            right++;
        }
        else if(sum < target) {
            sum += right + 1;
            right++;
        }
        else{
            sum -= left + 1;
            left++;
        }
    }

    printf("%d", counts);

    return 0;
}
*/

// 数学法,时间复杂度为O(√n)
#include <stdio.h>
#include <math.h>
int main(){
    int target = 0;
    int counts = 1;
    scanf("%d", &target);

    // 数学法提取符合条件的子数列
    for(int k = 2; k <= (int)(sqrt(2 * target)); k++){
        if((2 * target) % k == 0){
            int temp = (2 * target) / k - k + 1;
            if(temp > 0 && temp % 2 == 0){
                counts++;
            }
        }
    }

    printf("%d", counts);

    return 0;
}