#include <stdio.h>
#include <stdlib.h>
#include 
#include 

bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else {
            if (top == -1) return false;
            
            char last = stack[top--];
            if ((c == ')' && last != '(') ||
                (c == ']' && last != '[') ||
                (c == '}' && last != '{')) {
                return false;
            }
        }
    }
    
    return top == -1;
}
