typedef struct node
{
    int coeff;
    int px;
    int py;
    struct node *poly;
} NODE;
typedef struct plist
{
    NODE *head;
} POLYNOMIAL;

void initPolynomial(POLYNOMIAL *pl);
void createPolynomial(POLYNOMIAL *pl);
void addPolynomial(POLYNOMIAL *pl1, POLYNOMIAL *pl2, POLYNOMIAL *pl3);
void display(POLYNOMIAL *pl);
void destroyPolynomial(POLYNOMIAL *pl);