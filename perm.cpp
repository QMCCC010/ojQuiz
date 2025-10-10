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
    int arr[3] = {1, 2, 3};
    perm(arr, 0, 3);
}