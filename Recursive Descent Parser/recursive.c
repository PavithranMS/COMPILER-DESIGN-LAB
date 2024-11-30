#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *input;

void E();
void Edash();
void T();
void Tdash();
void F();
void match(char expected);
void error();

void match(char expected) 
{
    if (*input == expected) 
	{
        input++;
    } 
	else 
	{
        error();
    }
}

void error() 
{
    printf("Syntax error\n");
    exit(1);
}

void E() 
{
    printf("%-16s E -> T E'\n", input);
    T();
    Edash();
}

void Edash() 
{
    if (*input == '+') {
        printf("%-16s E' -> + T E'\n", input);
        match('+');
        T();
        Edash();
    } 
	else 
	{
        printf("%-16s E' -> $\n", input);
    }
}

void T() 
{
    printf("%-16s T -> F T'\n", input);
    F();
    Tdash();
}

void Tdash() 
{
    if (*input == '*') 
	{
        printf("%-16s T' -> * F T'\n", input);
        match('*');
        F();
        Tdash();
    } 
	else 
	{
        printf("%-16s T' -> $\n", input);  
    }
}

void F() 
{
    if (*input == '(') 
	{
        printf("%-16s F -> ( E )\n", input);
        match('(');
        E();
        match(')');
    } 
	else if (*input == 'i') 
	{
        printf("%-16s F -> i\n", input);
        match('i');
    } 
	else 
	{
        error();
    }
}

int main() 
{
    char expression[100];

    printf("Enter a string: ");
    fgets(expression, sizeof(expression), stdin);

    size_t len = strlen(expression);
    if (expression[len - 1] == '\n') 
	{
        expression[len - 1] = '\0';
    }

    input = expression;

    printf("\nInput            Action\n");
    printf("--------------------------------\n");

    E();

    if (*input == '\0') 
	{
        printf("--------------------------------\n");
        printf("The string is valid according to the grammar.\n");
    } 
	else 
	{
        printf("--------------------------------\n");
        printf("Syntax error: unexpected input at the end.\n");
    }

    return 0;
}

