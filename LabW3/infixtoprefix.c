#include <stdio.h>
#include <string.h>
#include <limits.h>
#define SIZE 100

char str_tmp[100];

typedef struct stack
{
    int top;
    char a[SIZE];
} STACK;

void initStack(STACK *ps)
{
    ps->top = -1;
}
int isFull(STACK *ps)
{
    return ps->top == SIZE - 1;
}
int isEmpty(STACK *ps)
{
    return ps->top == -1;
}
void push(STACK *ps, char ele)
{
    ps->a[++ps->top] = ele;
}
char pop(STACK *ps)
{
    return ps->a[ps->top--];
}
char top(STACK *ps)
{
    return ps->a[ps->top];
}

char *rev(char str[], int n)
{
    int len = strlen(str);
    int j = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == '(')
        {
            str_tmp[j] = ')';
            j++;
        }
        else if (str[i] == ')')
        {
            str_tmp[j] = '(';
            j++;
        }
        else
        {
            str_tmp[j] = str[i];
            j++;
        }
    }
    str_tmp[j++] = '\0';
    return str_tmp;
}

// void rev(char inf[], int n)
//  {
//      // printf("%s\n", inf);
//      char temp = '\0';
//      int start = 0, end = n - 1;
//      while (start != end)
//      {
//          temp = inf[start];
//          // printf("%c\n", temp);
//          if (inf[start] == ')')
//              temp = '(';
//          else if (inf[start] == '(')
//              temp = ')';
//          if (inf[end] == ')')
//              inf[end] = '(';
//          else if (inf[end] == '(')
//              end = ')';
//          inf[start] = inf[end];
//          inf[end] = temp;
//          start++;
//          end--;
//          // printf("%s\n", inf);
//      }
//      // printf("\n");

//}

int precedence(char inf, char s)
{
    switch (inf)
    {
    case '+':
    case '-':
        if (s == '(' || s == '+' || s == '-')
            return 0;
        else
            return 1;
    case '*':
    case '/':
    case '^':
        if (s == ')' || s == '^')
            return 1;
        else
            return 0;
    case '(':
        return 0;
    case ')':
        if (s == '(')
            return 0;
        else
            return 1;
    }
}

void infix_to_prefix(char infix[SIZE], char prefix[SIZE], int n)
{
    STACK obj;
    initStack(&obj);
    int i = 0, j = 0;
    char waste;
    int brack = 0;
    infix = rev(infix, n);
    // printf("rev : %s\n", infix);
    for (i = 0; infix[i] != '\0'; i++)
    {
        if ((int)infix[i] >= 48 && (int)infix[i] <= 57)
        {
            prefix[j++] = infix[i];
            // printf("%c ", prefix[j]);
            // j++;
        }
        else
        {
            while (!isEmpty(&obj) && precedence(infix[i], top(&obj)))
            {
                prefix[j] = pop(&obj);
                // printf("%c ", prefix[j]);
                j++;
            }
            if (infix[i] == ')')
            {
                waste = pop(&obj);
                brack += 2;
            }
            else
            {
                push(&obj, infix[i]);
                // printf("%c ", infix[i]);
            }
        }
    }
    while (!isEmpty(&obj))
    {
        prefix[j] = pop(&obj);
        // printf("%c ", prefix[j]);
        j++;
    }
    prefix[j] = '\0';
    str_tmp[0] = '\0';
    prefix = rev(prefix, n - brack);
}

int evaluate_prefix(char prefix[SIZE], int n)
{
    // TODO
    STACK eval;
    initStack(&eval);

    for (int i = n - 1; i >= 0; i--)
    {
        int exp = 0;
        int a = 0, b = 0;
        if ((int)(prefix[i]) >= 48 && (int)(prefix[i]) <= 57)
            push(&eval, prefix[i] - '0');
        else
        {
            a = pop(&eval);
            b = pop(&eval);
            // printf("%d %d\n", b, a);
            //  printf("%d top :\n", top(&eval));
            switch (prefix[i])
            {
            case '+':
                // printf("+ : %d\n", b + a);
                exp = (a + b);
                break;
            case '-':
                // printf("- : %d\n", b - a);
                exp = (a - b);
                break;
            case '*':
                // printf("* : %d\n", b * a);
                exp = (a * b);
                break;
            case '/':
                // printf("/ : %d\n", b / a);
                if (b == 0)
                    return INT_MAX;
                exp = (a / b);
                break;
            }
            push(&eval, exp);
        }
    }
    return top(&eval);
}

int main()
{
    char infix[SIZE], prefix[SIZE];

    int n;

    scanf("%d", &n);
    scanf("%s", infix);

    infix_to_prefix(infix, prefix, n);

    printf("%s\n", prefix);

    int res = evaluate_prefix(prefix, strlen(prefix));

    // printf("%s %d\n", prefix, res);

    return 0;
}
