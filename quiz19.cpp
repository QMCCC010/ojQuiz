#include <iostream>
using namespace std;

struct unitDigital {
    int M, N;
};

void digital_showdown(int m, int n, bool& winLabel) {
    if (m > 2 * n || n > 2 * m || m % n == 0 || n % m == 0) 
        return;
    
    winLabel = !winLabel;
    if (m > n) 
        return digital_showdown(m - n, n, winLabel);
    if (m < n)
        return digital_showdown(m, n - m, winLabel);
}

int main() {
    int c;
    cin >> c;
    unitDigital* m_data = new unitDigital[c];
    for (int i = 0; i < c; i++)
        cin >> m_data[i].M >> m_data[i].N;
    for (int i = 0; i < c; i++) {
        bool winLabel = 1;
        digital_showdown(m_data[i].M, m_data[i].N, winLabel);
        if (winLabel)
            cout << "Stan wins" << endl;
        else
            cout << "Ollie wins" << endl;
    }
    delete[] m_data;
}