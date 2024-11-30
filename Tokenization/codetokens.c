#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(const char* token) 
{
    const char* keywords[] = { "if", "else", "while", "do", "break", "continue", "int",
                                "double", "float", "return", "char", "long", "short", "typedef",
                                "switch", "unsigned", "void", "static", "struct", "goto" };
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    int i;
    for (i = 0; i < num_keywords; i++) 
	{
        if (strcmp(token, keywords[i]) == 0) 
		{
            return 1;
        }
    }
    return 0;
}

int isInteger(const char* token) 
{
	int i;
    for (i = 0; token[i] != '\0'; i++) 
	{
        if (!isdigit(token[i])) 
		{
            return 0;
        }
    }
    return strlen(token) > 0;
}

void parseAndClassify(const char* input) 
{
    char* token = strtok(strdup(input), " \n\t");
    while (token != NULL) 
	{
        if (isKeyword(token)) 
		{
            printf("'%s' IS A KEYWORD\n", token);
        } 
		else if (strlen(token) == 1 && strchr("+-*/><=", token[0])) 
		{
            printf("'%s' IS AN OPERATOR\n", token);
        } 
		else if (isInteger(token)) 
		{
            printf("'%s' IS AN INTEGER\n", token);
        } 
		else if (isalpha(token[0])) 
		{
            printf("'%s' IS AN IDENTIFIER\n", token);
        } 
		else 
		{
            printf("'%s' IS A DELIMITER\n", token);
        }
        token = strtok(NULL, " \n\t");
    }
}

int main() 
{
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) 
	{
        perror("Error opening file");
        return 1;
    }

    char line[256];
    char code[1024] = "";

    while (fgets(line, sizeof(line), file)) 
	{
        strcat(code, line);
    }
    fclose(file);
    parseAndClassify(code);
    return 0;
}

