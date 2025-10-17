#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void possibleWin(int num, vector<double> p, vector<vector<double>>& dp) {
    dp[0][0] = 1.0;
    for (int i = 1; i <= num; i++) {
        for (int j = 0; j <= i; j++) {
            // // 第i场赢了，则要求前i - 1场赢j - 1场
            // double prob_win_current = (j > 0) ? dp[i - 1][j - 1] * p[i - 1] : 0.0;
            // // 第i场输了，则要求前i - 1场赢j场
            // double prob_loss_current = dp[i - 1][j] * (1.0 - p[i - 1]);

            dp[i][j] = (j > 0) ? dp[i - 1][j - 1] * p[i - 1] : 0.0 + dp[i - 1][j] * (1.0 - p[i - 1]);
        }
    }
}

int main() {
    int num = 0;
    cin >> num;
    const int min_wins = ceil(0.7 * num);
    vector<double> p(num);
    for (int i = 0; i < num; i++) {
        int percentage;
        cin >> percentage;
        p[i] = percentage / 100.0;
    }
    //用于记录恰好前i场比赛恰好赢j场的概率
    // dp[i][j] 表示前 i 场赢 j 场的概率
    vector<vector<double>> dp(num + 1, vector<double>(num + 1, 0.0));

    // 计算dp[i][j]矩阵
    possibleWin(num, p, dp);

    // 计算总晋级概率
    double total_wins = 0.0;
    for (int j = min_wins; j <= num; j++)
        total_wins += dp[num][j];
    
    // 输出总概率
    cout << fixed << setprecision(5) << total_wins << endl;
}