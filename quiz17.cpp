#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

string decode(const string& s, int& pos) {
    string current_result = "";

    while (pos < s.size() && s[pos] != ']') {
        if (isalpha(s[pos])) {
            // 如果当前是字母，直接追加
            current_result += s[pos];
            pos++;
        } else if (s[pos] == '[') {
            // 如果是左括号，开始处理一个压缩块
            pos++; // 跳过'['

            // 解析重复次数
            int repeat_count = 0;
            while (isdigit(s[pos])) {
                repeat_count = repeat_count * 10 + (s[pos] - '0');
                pos++;
            }

            // 递归解析字符串里的内容
            string sub_current_result = decode(s, pos);

            // 递归解析完成后，pos位于']'
            pos++; // 跳过']'

            // 将解码后的字串重复指定次数
            for(int i = 0; i < repeat_count; i++) {
                current_result += sub_current_result;
            }
        }
    }
    return current_result;
}

int main() {
    string s;
    cin >> s;
    int pos = 0;
    cout << decode(s, pos) << endl;
}