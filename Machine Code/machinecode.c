#include <stdio.h>
#include <string.h>

int main() 
{
    FILE *f1 = fopen("input.txt", "r");
    FILE *f2 = fopen("output.txt", "w");

    char op[2], arg1[100], arg2[100], result[100];

    while (fscanf(f1, "%s %s %s %s", op, arg1, arg2, result) != EOF) 
	{
        fprintf(f2, "MOV R0, %s\n", arg1);
        
		if (strcmp(op, "+") == 0) 
            fprintf(f2, "ADD R0, %s\n", arg2);
         
		else if (strcmp(op, "*") == 0) 
            fprintf(f2, "MUL R0, %s\n", arg2);
            
		else if (strcmp(op, "-") == 0) 
            fprintf(f2, "SUB R0, %s\n", arg2);
        
		else if (strcmp(op, "/") == 0) 
            fprintf(f2, "DIV R0, %s\n", arg2);
        
        fprintf(f2, "MOV %s, R0\n", result);
    }

    fclose(f1);
    fclose(f2);
    return 0;
}

