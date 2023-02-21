#include <iostream>
using namespace std;

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

typedef struct Node *nodePtr;

void insertLast(int coeff, int exp, nodePtr *headRef)
{
    nodePtr newNode = new Node;
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (*headRef == NULL)
    {
        *headRef = newNode;
    }
    else
    {
        nodePtr temp = *headRef;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addPoly(nodePtr poly1, nodePtr poly2, nodePtr *result)
{
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exp > poly2->exp)
        {
            insertLast(poly1->coeff, poly1->exp, result);
            poly1 = poly1->next;
        }
        else if (poly2->exp > poly1->exp)
        {
            insertLast(poly2->coeff, poly2->exp, result);
            poly2 = poly2->next;
        }
        else
        {
            insertLast(poly1->coeff + poly2->coeff, poly1->exp, result);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL)
    {
        insertLast(poly1->coeff, poly1->exp, result);
        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    {
        insertLast(poly2->coeff, poly2->exp, result);
        poly2 = poly2->next;
    }
}

void display(nodePtr poly)
{
    while (poly != NULL)
    {
        cout << poly->coeff << "x^" << poly->exp;
        poly = poly->next;
        if (poly != NULL)
            cout << " + ";
    }
    cout << endl;
}

int main()
{
    nodePtr poly1 = NULL, poly2 = NULL, result = NULL;
    int num1, num2;

    cout << "Enter the number of terms for the first polynomial: ";
    cin >> num1;

    for (int i = 0; i < num1; i++)
    {
        int coeff, exp;
        cout << "Enter the coefficient and exponent for term " << i + 1 << ": ";
        cin >> coeff >> exp;
        insertLast(coeff, exp, &poly1);
    }

    cout << "Enter the number of terms for the second polynomial: ";
    cin >> num2;

    for (int i = 0; i < num2; i++)
    {
        int coeff, exp;
        cout << "Enter the coefficient and exponent for term " << i + 1 << ": ";
        cin >> coeff >> exp;
        insertLast(coeff, exp, &poly2);
    }

    cout << "Polynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    addPoly(poly1, poly2, &result);

    cout << "Resultant polynomial: ";
    display(result);

    return 0;
}
