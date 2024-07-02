#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char arr[MAX];
int top = -1;

void push(char x) {
    top = top + 1;
    arr[top] = x;
}

void pop() {
    top = top - 1;
}

int ass(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 3;
        default:
            return 0; 
    }
}

int main() {
    char str[] = "a/b+c*(d-e)+f*g%h";
    int len = strlen(str);
    char out[len];
    int i = 0;
    while (i < len) {
        if (str[i] == '(') {
            push(str[i]);
        } else if (isalnum(str[i])) {
            strncat(out, (const char *)&str[i], 1);
        } else if (str[i] == ')') {
            while (top != -1 && arr[top] != '(') {
                strncat(out,(const char *) &arr[top], 1);
                pop();
            }
            if (top != -1 && arr[top] == '(') {
                pop(); 
            }
        } else {
            while (top != -1 && ass(str[i]) <= ass(arr[top])) {
                strncat(out,(const char *) &arr[top], 1);
                pop();
            }
            push(str[i]);
        }
        i++;
    }
    while (top != -1) {
        strncat(out,(const char *) &arr[top], 1);
        pop();
    }
   // out[strlen(str)] = '\0'; 
    printf("%s", out);
   

    return 0;
}
