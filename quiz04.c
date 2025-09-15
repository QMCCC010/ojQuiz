#include <stdio.h>
#include <string.h>

#define MAX_NUM 1000000

int countsPlan(int n, int m, int t){
    int counts = 1;
    int chickenCost = 0;
    int duckCost = 0;

    // 单独买鸡
    while(1){
        chickenCost += m;
        if (chickenCost <= n){
            counts++;
        }else{
            break;
        }
    }

    // 单独买鸭
    while(1){
        duckCost += t;
        if(duckCost <= n){
            counts++;
        }else{
            break;
        }
    }

    //鸡鸭同买
    for(chickenCost = m; chickenCost < n; chickenCost += m){
        for(duckCost = t; ; duckCost += t){
            if(chickenCost + duckCost <= n){
                counts++;
            }else{
                break;
            }
        }
    }
    return counts;
}

int main(){
    int n, m, t = 0;
    scanf("%d %d %d", &n, &m, &t);
    printf("%d", countsPlan(n, m, t));
    return 0;
}