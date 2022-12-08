#define MAX 30

typedef struct stack
{
    char s[MAX];
    int top;
} STACK;

void initStack(STACK *ps);
int isEmpty(STACK *ps);
void push(STACK *ps, char ele);
char pop(STACK *ps);
int checkBalanceParentheses(char str[]);