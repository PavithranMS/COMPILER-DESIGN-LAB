#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter input string (a or b): ");
    scanf("%s", input);

    const char* currentstate = "q0";
    const char* nextstate;
    int i;

    printf("Step\tCurrent State\tInput Symbol\tNext State\n");
    printf("----\t-------------\t------------\t----------\n");

    for (i = 0; i < strlen(input); i++) 
	{
        printf("%d\t%s\t\t%c\t\t", i + 1, currentstate, input[i]);

        if (strcmp(currentstate, "q0") == 0 && input[i] == 'a')
            nextstate = "q1";
        else if (strcmp(currentstate, "q0") == 0 && input[i] == 'b')
            nextstate = "q2";
        else if (strcmp(currentstate, "q1") == 0 && input[i] == 'a')
            nextstate = "q1";
        else if (strcmp(currentstate, "q1") == 0 && input[i] == 'b')
            nextstate = "q2";
        else if (strcmp(currentstate, "q2") == 0 && (input[i] == 'a' || input[i] == 'b'))
            nextstate = "q2";
        else
            nextstate = "error";

        printf("%s\n", nextstate);
        currentstate = nextstate;

        if (strcmp(currentstate, "error") == 0) 
		{
            break;
        }
    }

    if (strcmp(currentstate, "q2") == 0) 
	{
        printf("%s is accepted by the DFA\n", input);
    } 
	else 
	{
        printf("%s is not accepted by the DFA\n", input);
    }
    return 0;
}

