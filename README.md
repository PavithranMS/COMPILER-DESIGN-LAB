# COMPILER-DESIGN-LAB

TOKENIZATION
1. For a given statement, identify the list of tokens.

Statement: int a = b + 12 ;

2. For a given code snippet, identify the list of tokens.

Code snippet:
int main() 
{
    if ( x == 10 ) 
    {
        x = x + 1 ;
    }
}

DFA
1. For a given regular expression, construct DFA manually. For the given input string, implement a code to determine its acceptance using the constructed DFA. Display each step in your output.

Regular Expression : (a|b)+ b (a|b)*
Input String : aaabbaaa

RECURSIVE DESCENT PARSER
1. Develop a code to implement recursive descent parser for the given grammar and check the acceptance of user-defined input string.

Grammar:
Before Removing Left Recursion :
E -> E+T | T
T -> T*F | F
F -> (E) | i

After Removing Left Recursion :
E -> TE'
E' -> +TE' | $
T -> FT'
T' -> *FT' | $
F -> (E) | i

Input String: i+i*i

INTERMEDIATE CODE
1. Convert a given infix expression to postfix and generate its intermediate code in three-address format.

Expression : a*b+c^d-e*f

QUADRUPLES
1. Convert a given infix expression to postfix and generate its intermediate code in three-address format and then output the quadruple.

Expression : a+b*c/d-e

MACHINE CODE
1. Develop a code to output the machine code for the given intermediate code.

Intermediate Code:
t1 = c * d
t2 = b + t1
a = t2








