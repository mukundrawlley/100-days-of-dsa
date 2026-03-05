#include <ctype.h>

int calculate(char* s) {
    int stack[1000];
    int top = -1;
    char op = '+';
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == ' ') {
            i++;
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            op = s[i];
            i++;
        }
        else {
            int num = 0;
            while (s[i] != '\0' && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            if (op == '+') {
                stack[++top] = num;
            }
            else if (op == '-') {
                stack[++top] = -num;
            }
            else if (op == '*') {
                stack[top] = stack[top] * num;
            }
            else if (op == '/') {
                stack[top] = stack[top] / num; // truncates toward zero
            }
        }
    }

    int result = 0;
    while (top >= 0) {
        result += stack[top--];
    }

    return result;
}
