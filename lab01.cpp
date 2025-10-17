#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

#define MAX_NUM 1000

double possibleWin(int num, vector<double> p) {
    if (num == 0) {
        return 1.0;
    }

    // 滚动数组依次覆盖记录打1-num场比赛时，恰好赢j场的概率
    vector<double> dp(num + 1, 0.0);
    dp[0] = 1.0; // 初始条件，在0场比赛中赢0场的概率是1.0

    for (int i = 1; i <= num; i++) {
        for (int j = i; j >= 0; j--) {
            // 第i场赢了，则要求前i - 1场赢j - 1场
            double prob_win_current = (j > 0) ? dp[j - 1] * p[i - 1] : 0.0;
            // 第i场输了，则要求前i - 1场赢j场
            double prob_loss_current = dp[j] * (1.0 - p[i - 1]);
            
            dp[j] = prob_win_current + prob_loss_current;
        }
    }

    //计算总晋级概率
    const int min_wins = ceil(0.7 * num);
    double total_wins = 0.0;
    for (int j = min_wins; j <= num; j++)
        total_wins += dp[j];
    
    return total_wins;
}

int main() {
    int num = 0;
    cin >> num;
    if (num < 0 || num > MAX_NUM) {
        cout << "错误的比赛场数" << endl;
        return 1;
    }
    vector<double> p(num);
    for (int i = 0; i < num; i++) {
        int percentage;
        cin >> percentage;
        p[i] = percentage / 100.0;
    }

    // 计算dp[i][j]矩阵
    double result = possibleWin(num, p);
    
    // 输出总概率
    cout << fixed << setprecision(5) << result << endl;
}