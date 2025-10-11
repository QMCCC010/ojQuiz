#include <iostream>
using namespace std;

template<class Type>
void perm(Type list, int k, int m) {
    if (k == m) {
        for (int i=0; i<m; i++)
            cout << list[i];
        cout << endl;
    }
    else {
        for (int i=k; i<m; i++) {
            swap(list[k], list[i]);
            perm(list, k+1, m);
            swap(list[k], list[i]);
        }
    }
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    perm(arr, 0, 4);
}