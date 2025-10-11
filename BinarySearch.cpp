#include <iostream>
using namespace std;

template<class Type>
int binarySearch(Type arr[], Type& x, int len) {
    int left = 0;
    int right = len - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(int);
    int target = 0;
    cin >> target;
    cout << binarySearch(arr, target, len) << endl;
}