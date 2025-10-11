#include <iostream>
using namespace std;

int partition(int n, int m){
    if (n < 1 || m < 1) 
        return 0;
    if (n == 1 && m == 1)
        return 1;
    if (n < m)
        return partition(n, n);
    if (n == m)
        return 1 + partition(n, m - 1);
    return partition(n, m - 1) + partition(n - m, m);
}

int main(){
    int n = 0;
    cin >> n;
    cout << partition(n, n) << endl;
}