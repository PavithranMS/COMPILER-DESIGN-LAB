#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isDelimiter(char ch) 
{
    return strchr(" +-*/;,><=()[]{}", ch) != NULL;
}

int isOperator(char ch) 
{
    return strchr("+-*/><=", ch) != NULL;
}

int isKeyword(const char *str) 
{
    const char *keywords[] = { "if", "else", "while", "do", "break", "continue", "int",
                               "double", "float", "return", "char", "long", "short", "typedef", "switch",
                               "unsigned", "void", "static", "struct", "goto" };
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    int i;
    for (i = 0; i < numKeywords; ++i)
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    return 0;
}

int isNumber(const char *str, int real) 
{
    int i , hasDecimal = 0;
    int len = strlen(str);
    for (i = 0; i < len; ++i) 
	{
        if (str[i] == '.') 
		{
            if (hasDecimal || !real)
                return 0;
            hasDecimal = 1;
        } 
		else if (!isdigit(str[i]) && !(str[i] == '-' && i == 0))
            return 0;
    }
    return 1;
}

void parse(const char *str) 
{
    int left = 0, right = 0;
    int len = strlen(str);
    
    while (right <= len) 
	{
        if (right < len && !isDelimiter(str[right])) 
		{
            right++;
        } 
		else 
		{
            if (left != right) 
			{
                char subStr[100];
                strncpy(subStr, str + left, right - left);
                subStr[right - left] = '\0';

                if (strlen(subStr) > 0 && !isspace(subStr[0])) 
				{
                    if (isKeyword(subStr))
                        printf("'%s' IS A KEYWORD\n", subStr);
                    else if (isNumber(subStr, 0))
                        printf("'%s' IS AN INTEGER\n", subStr);
                    else if (isNumber(subStr, 1))
                        printf("'%s' IS A REAL NUMBER\n", subStr);
                    else if (isalpha(subStr[0]))
                        printf("'%s' IS A VALID IDENTIFIER\n", subStr);
                    else
                        printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
                }
            }
            if (right < len) 
			{
                if (isOperator(str[right])) 
                    printf("'%c' IS AN OPERATOR\n", str[right]);
                else if (str[right] == ';' || str[right] == ',' || strchr("()[]{}", str[right]))
                    printf("'%c' IS A DELIMITER\n", str[right]);
            }
            left = ++right;
        }
    }
}

int main() 
{
    char str[100];
    printf("Enter a statement: ");
    fgets(str, 100, stdin);
    parse(str);
    return 0;
}

