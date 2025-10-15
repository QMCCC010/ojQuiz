#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 使用set储存交点数量，自动筛除相同数量的组合
set<int> possible_intersections;

void intersectPointCount(int n, int start, vector<int>& current_partition) {
    // 计算每个分组的交点数量
    if (n == 0) {
        int intersections = 0;
        for (int i = 0; i < current_partition.size(); i++) {
            for (int j = i + 1; j < current_partition.size(); j++)
                intersections += current_partition[i] * current_partition[j];
        }
        possible_intersections.insert(intersections);
    }
    
    // 递归寻找所有可能的分组组合
    for (int i = start; i <= n; i++) {
        current_partition.push_back(i);
        intersectPointCount(n - i, i, current_partition);
        current_partition.pop_back();
    }
}

int main() {
    int N = 0;
    cin >> N;
    vector<int> empty_partition;
    intersectPointCount(N, 1, empty_partition);

    cout << possible_intersections.size() << endl;
}