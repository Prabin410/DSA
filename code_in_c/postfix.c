#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

struct STACK {
    int TOS;
    int data[MAX];
};

int isFull(struct STACK *s) {
    return s->TOS == MAX - 1;
}

int isEmpty(struct STACK *s) {
    return s->TOS == -1;
}

void push(struct STACK *s, int element) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->data[++s->TOS] = element;
}

int pop(struct STACK *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->data[s->TOS--];
}

int main() {
    struct STACK s;
    s.TOS = -1;

    char expression[100];
    printf("Enter a postfix expression: ");
    fgets(expression, 100, stdin); 
    int len = strlen(expression);
    if (expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }
    char *token = strtok(expression, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&s, atoi(token));
        } else {
            int b = pop(&s);
            int a = pop(&s);
            int result;

            if (token[0] == '+') result = a + b;
            else if (token[0] == '-') result = a - b;
            else if (token[0] == '*') result = a * b;
            else if (token[0] == '/') result = a / b;
            else if (token[0] == '^') result = (int)pow(a, b);  // cast to int
            else {
                printf("Invalid operator: %s\n", token);
                exit(1);
            }

            push(&s, result);
        }

        token = strtok(NULL, " ");
    }

    printf("Result: %d\n", pop(&s));
    system("pause");  
}
