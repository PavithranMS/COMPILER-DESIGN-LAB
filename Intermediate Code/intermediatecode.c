#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

typedef struct 
{
    char data[MAX][MAX];
    int top;
} Stack;

void push(Stack* s, char* val) 
{
    if (s->top == MAX - 1) 
	{
        printf("Stack Overflow\n");
        exit(1);
    }
    strcpy(s->data[++(s->top)], val);
}

char* pop(Stack* s) 
{
    if (s->top == -1) 
	{
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

char* peek(Stack* s) 
{
    if (s->top == -1) return NULL;
    return s->data[s->top];
}

int precedence(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char ch) 
{
    return strchr("+-*/^", ch) != NULL;
}

void infixToPostfix(char* infix, char* postfix) 
{
    Stack s;
    s.top = -1;
    int j = 0;
    int i;
    for (i = 0; infix[i] != '\0'; i++) 
	{
        char token = infix[i];

        if (isalnum(token)) 
		{
            postfix[j++] = token;
        } 
		else if (token == '(') 
		{
            push(&s, &token);
        } 
		else if (token == ')') 
		{
            while (peek(&s)[0] != '(') 
			{
                postfix[j++] = pop(&s)[0];
            }
            pop(&s); // Pop '('
        } 
		else if (isOperator(token)) 
		{
            while (s.top != -1 && precedence(peek(&s)[0]) >= precedence(token)) 
			{
                postfix[j++] = pop(&s)[0];
            }
            push(&s, &token);
        }
    }

    while (s.top != -1) 
	{
        postfix[j++] = pop(&s)[0];
    }

    postfix[j] = '\0';
}

void generateIntermediateCode(char* postfix) 
{
    Stack s;
    s.top = -1;
    int tempVarCount = 1;
    char tempVar[MAX];
    int i;
    printf("Postfix: %s\n", postfix);

    for (i = 0; postfix[i] != '\0'; i++) 
	{
        char token = postfix[i];

        if (isalnum(token)) 
		{
            char temp[2] = {token, '\0'};
            push(&s, temp);
        } 
		else if (isOperator(token)) 
		{
            char* operand2 = pop(&s);
            char* operand1 = pop(&s);
            sprintf(tempVar, "t%d", tempVarCount++);
            printf("%s = %s %c %s\n", tempVar, operand1, token, operand2);
            push(&s, tempVar);  // Push the temporary variable back for further operations
        }
    }
}

int main() 
{
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    generateIntermediateCode(postfix);

    return 0;
}

