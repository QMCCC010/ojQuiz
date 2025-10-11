#include <iostream>
using namespace std;

struct unitData {
    int m, n;
};

int dividApples(int m, int n) {
    if(m == 0 || n == 1)
        return 1;
    if(m < n)
        return dividApples(m, m);
    if(m == n)
        return 1 + dividApples(m, n - 1);
    return dividApples(m, n - 1) + dividApples(m - n, n);
}

int main() {
    int t;
    cin >> t;
    unitData* arr = new unitData[t];
    for(int i = 0; i < t; i++){
        cin >> arr[i].m >> arr[i].n;
    }
    for(int i = 0; i < t; i++){
        cout << dividApples(arr[i].m, arr[i].n) << endl;
    }
    delete[] arr;
}