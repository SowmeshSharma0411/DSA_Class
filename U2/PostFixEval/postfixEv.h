#define MAX 30

typedef struct stack
{
    int s[MAX];
    int top;
} STACK;

void initStack(STACK *ps);
int isEmpty(STACK *ps);
void push(STACK *ps, int ele);
int pop(STACK *ps);
int postfixEval(char str[]);