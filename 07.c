#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int expo;
    struct Term *next;
};

struct Term* insertAtEnd(struct Term* head, int c, int e) {
    struct Term* newNode = (struct Term*)malloc(sizeof(struct Term));
    newNode->coeff = c;
    newNode->expo = e;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    // Traverse to end of list
    struct Term* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Term* createPolynomial(int degree, int sumdegree) {
    struct Term* head = NULL;
    int coeff;

    for(int i = sumdegree; i >= 0; i--) {
        if(i > degree) {
            coeff = 0;
        } else {
            printf("Enter coefficient of x^%d: ", i);
            scanf("%d", &coeff);
        }
        head = insertAtEnd(head, coeff, i);
    }
    return head;
}

struct Term* addPolynomials(struct Term* p1, struct Term* p2) {
    struct Term* sum = NULL;

    while(p1 != NULL && p2 != NULL) {
        sum = insertAtEnd(sum, p1->coeff + p2->coeff, p1->expo);
        p1 = p1->next;
        p2 = p2->next;
    }
    return sum;
}

void display(struct Term* head) {
    struct Term* temp = head;
    while(temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        if(temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int deg1, deg2, sumdeg;
    struct Term *p1 = NULL, *p2 = NULL, *res = NULL;

    printf("Enter max degree of 1st polynomial: ");
    scanf("%d", &deg1);

    printf("Enter max degree of 2nd polynomial: ");
    scanf("%d", &deg2);

    sumdeg = (deg1 > deg2) ? deg1 : deg2;

    printf("\nEnter 1st Polynomial:\n");
    p1 = createPolynomial(deg1, sumdeg);

    printf("\nEnter 2nd Polynomial:\n");
    p2 = createPolynomial(deg2, sumdeg);

    res = addPolynomials(p1, p2);

    printf("\nP1  = ");
    display(p1);

    printf("P2  = ");
    display(p2);

    printf("Sum = ");
    display(res);

    return 0;
}
