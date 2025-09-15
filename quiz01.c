#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 10001 // 长度最大为 10000，加上末尾的 '\0'

int main() {
    char str[MAX_LEN];

    if (fgets(str, sizeof(str), stdin) != NULL) {
        int len = strlen(str);
        int last_word_len = 0;

        // 1. 从后向前，跳过末尾的空白字符（空格、换行符等）
        // i 指向最后一个有效字符
        int i = len - 1;
        while (i >= 0 && (str[i] == ' ' || str[i] == '\n' || str[i] == '\r')) {
            i--;
        }

        // 2. 从后向前，计算最后一个单词的长度
        while (i >= 0 && str[i] != ' ') {
            last_word_len++;
            i--;
        }

        printf("%d\n", last_word_len);
    }

    return 0;
}