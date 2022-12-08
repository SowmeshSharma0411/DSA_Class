typedef struct node
{
    int coeff;
    int powx;
    struct node *next;
} NODE;

typedef struct plist
{
    struct node *head;
} POLYNOMIAL;

void initPolynomial(POLYNOMIAL *pl);
void createPolynomial(POLYNOMIAL *pl);
int addPolynomial(POLYNOMIAL *pl1, POLYNOMIAL *pl2, POLYNOMIAL *pl3);
void display(POLYNOMIAL *pl);
void destroyPolynomial(POLYNOMIAL *pl);