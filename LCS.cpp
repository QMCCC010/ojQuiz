#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void LCS(int m, int n, const char *X, const char *Y, int **LCS_arr, int **b) {
    for (int i = 1; i <= n; i++)
        LCS_arr[0][i] = 0;
    for (int i = 1; i <= m; i++)
        LCS_arr[i][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                LCS_arr[i][j] = LCS_arr[i - 1][j - 1] + 1;
                b[i][j] = 1;
            } else {
                if (LCS_arr[i - 1][j] >= LCS_arr[i][j - 1]) {
                    LCS_arr[i][j] = LCS_arr[i - 1][j];
                    b[i][j] = 2;
                } else {
                    LCS_arr[i][j] = LCS_arr[i][j - 1];
                    b[i][j] = 3;
                }
            }
        }
    }
}

// 用于根据 b 矩阵回溯并打印 LCS 的函数
void Traceback(int i, int j, const char* X, int** b) {
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 1) {
        Traceback(i - 1, j - 1, X, b);
        cout << X[i - 1];
    } else if (b[i][j] == 2) {
        Traceback(i - 1, j, X, b);
    } else if (b[i][j] == 3) {
        Traceback(i, j - 1, X, b);
    }
}

int main() {
    // 1. 定义测试字符串
    const char* X = "ABCBDAB";
    const char* Y = "BDCABA";

    // 2. 获取字符串长度
    int m = strlen(X);
    int n = strlen(Y);

    int** LCS_arr = new int*[m + 1];
    int** b = new int*[m + 1];
    for (int i = 0; i <= m; ++i) {
        LCS_arr[i] = new int[n + 1];
        b[i] = new int[n + 1];
    }

    LCS(m, n, X, Y, LCS_arr, b);

    // 5. 打印结果
    cout << "String X: " << X << endl;
    cout << "String Y: " << Y << endl;
    cout << "Length of LCS: " << LCS_arr[m][n] << endl; // 预期是 4

    cout << "LCS is: ";
    Traceback(m, n, X, b); // 预期是 "BCBA"
    cout << endl;

    // 释放内存
    for (int i = 0; i <= m; ++i) {
        delete[] LCS_arr[i];
        delete[] b[i];
    }
    delete[] LCS_arr;
    delete[] b;
}