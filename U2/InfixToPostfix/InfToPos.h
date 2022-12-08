#define MAX 30
typedef struct stack
{
    int top;
    char a[MAX];
} STACK;

void initStack(STACK *ps);
int isEmpty(STACK *ps);
void push(STACK *ps, char ele);
char pop(STACK *ps);
char stackTop(STACK *ps);

int precedence(char st, char in);
void infixToPostfix(char infix[], char postfix[]);