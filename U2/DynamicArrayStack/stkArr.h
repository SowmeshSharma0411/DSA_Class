typedef struct stack
{
    int *s;
    int top;
    int size;
} STACK;

void initStack(STACK *ps, int n);
int isFull(STACK *ps);
int isEmpty(STACK *ps);
void push(STACK *ps, int ele);
int pop(STACK *ps);
int stackTop(STACK *ps); // Peek
void display(STACK *ps);
void stackDouble(STACK *ps);
void destroyStack(STACK *ps);