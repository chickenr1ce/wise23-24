#include <stdio.h>

int main()
{

    double digit = 0.0;
    double output = 0.0;
    char c;
    char last_operator = '+';
    const int DIGIT_NEXT = 1;
    const int OPERATOR_NEXT = 2;
    int next_input = DIGIT_NEXT;
    
    printf("Simple calculator:\n");
    printf("Valid inputs are + - * / = and digits 0,...,9\n");
    
    while (1)
    {
    c = getchar();
    switch (c)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        if (next_input == DIGIT_NEXT)
        {
            printf("\a");
            break;
        }
        else
        {
            c = last_operator;
            next_input = DIGIT_NEXT;
            break;
        }
    
    case '=':
        if (next_input != OPERATOR_NEXT)
        {
            printf("\a");
            break;
        }
        printf("\n%.2f", output);
        next_input = OPERATOR_NEXT;
        break;

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        if (next_input != DIGIT_NEXT)
        {
            printf ("\a");
        }
        printf("%c",c);
        digit = c-48; //ASCII code needs to be subtracted by 48
        switch (last_operator)
        {
            case '+': output += digit; break;
            case '-': output -= digit; break;
            case '*': output *= digit; break;
            case '/': output /= digit; break;
        }
        next_input = OPERATOR_NEXT;
        break;
    
    }
      
    }
}