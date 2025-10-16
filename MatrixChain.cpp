#include <iostream>
using namespace std;

void MatrixChain(int *p, int n, int **m, int **s) {
    for (int i = 1; i <= n; i++) 
        m[i][i] = 0;
    // 从长度为r = 2开始，计算该长度子链的最小数乘次数
    for (int r = 2; r <= n; r++) {
        for (int i = 1; i <= n - r + 1; i++) {
            int j = i + r - 1;
            // 初始情况为按顺序求，即断点在i处
            m[i][j] = m[i+1][j] + p[i - 1] * p[i] * p[j]; // m[i+1][j]的矩阵形状为p[i] * p[j]
            s[i][j] = i;
            // 移动断点，寻找最优的断点位置
            for (int k = i + 1; k < j; k++) {
                int t = m[i][k] + m[k+1][j] + p[i - 1] * p[k] * p[j];
                if (t < m[i][j]) {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main() {
    const int n = 6;
    int p[n + 1] = {30, 35, 15, 5, 10, 20, 25};

    int **m = new int*[n + 1];
    int **s = new int*[n + 1];

    for (int i = 0; i <= n; i++) {
        m[i] = new int[n + 1];
        s[i] = new int[n + 1];
    }

    MatrixChain(p, n, m, s);

    cout << m[1][n] << endl;

    // 释放内存
    for (int i = 0; i <= n; ++i) {
        delete[] m[i];
        delete[] s[i];
    }
    delete[] m;
    delete[] s;
}