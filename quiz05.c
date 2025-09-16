#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 200
typedef struct {
    int x;
    int y;
    int r;
} Satellite;

int main(){
    return 0;
    int n, x, y, r = 0;
    int max_x, max_y = 0;
    int counts = 0;
    scanf("%d", &n);
    Satellite *satellite = (Satellite*)malloc(n * sizeof(Satellite));

    // 输入各个卫星的数据
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &x, &y, &r);
        satellite[i].x = x;
        satellite[i].y = y;
        satellite[i].r = r;
    }

    // 寻找坐标边界
    for(int i = 0; i < n; i++){
        if(satellite[i].x + satellite[i].r > max_x) max_x = satellite[i].x + satellite[i].r;
        if(satellite[i].y + satellite[i].r > max_y) max_y = satellite[i].y + satellite[i].r;
    }

    // 判断矩阵
    int *pointLocation = (int*)calloc(max_x * max_y, sizeof(int));

    // 计算可扫描坐标点
    for(int i = 0; i < n; i++){
        for(y = satellite[i].y - satellite[i].r; y <= satellite[i].y + satellite[i].r; y++){
            
        }
    }

    free(satellite);
    free(pointLocation);
    return 0;
}