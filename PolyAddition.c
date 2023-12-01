#include<stdio.h>
#include<stdlib.h>

struct node {
    int coeff;
    int expo;
    struct node *link;
};

struct node * create_poly(struct node *head, int n) {
    struct node *ptr, *temp;
    int coef, expon;
    head = NULL;
    for(int i = 0; i < n; i++) {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter the coefficient and exponent of term %d: ", i+1);
        scanf("%d%d", &coef, &expon);
        temp->coeff = coef;
        temp->expo = expon;
        temp->link = NULL;
        if(head == NULL) {
            head = temp;
            ptr = head;
        } else {
            ptr->link = temp;
            ptr = ptr->link;
        }
    }
    return head;
}

void display_poly(struct node *head) {
    struct node *ptr = head;
    while(ptr != NULL) {
        printf("(%dx^%d)", ptr->coeff, ptr->expo);
        if(ptr->link != NULL) {
            printf(" + ");
        }
        ptr = ptr->link;
    }
    printf("\n");
}
struct node * add_poly(struct node *poly1, struct node *poly2) {
    struct node *ptr1 = poly1, *ptr2 = poly2;
    struct node *poly = NULL, *ptr = NULL, *temp = NULL;

    while(ptr1 != NULL && ptr2 != NULL) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->link = NULL;

        if(ptr1->expo > ptr2->expo) {
            temp->coeff = ptr1->coeff;
            temp->expo = ptr1->expo;
            ptr1 = ptr1->link;
        } else if(ptr1->expo < ptr2->expo) {
            temp->coeff = ptr2->coeff;
            temp->expo = ptr2->expo;
            ptr2 = ptr2->link;
        } else {
            temp->coeff = ptr1->coeff + ptr2->coeff;
            temp->expo = ptr1->expo;
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }

        if(poly == NULL) {
            poly = temp;
            ptr = poly;
        } else {
            ptr->link = temp;
            ptr = ptr->link;
        }
    }

    while(ptr1 != NULL) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->coeff = ptr1->coeff;
        temp->expo = ptr1->expo;
        temp->link = NULL;
        ptr->link = temp;
        ptr = ptr->link;
        ptr1 = ptr1->link;
    }

    while(ptr2 != NULL) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->coeff = ptr2->coeff;
        temp->expo = ptr2->expo;
        temp->link = NULL;
        ptr->link = temp;
        ptr = ptr->link;
        ptr2 = ptr2->link;
    }

    return poly;
}

int main() {
    int n1, n2;
    struct node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
    printf("Enter the number of terms of the first polynomial: ");
    scanf("%d", &n1);
    poly1 = create_poly(poly1, n1);
    printf("Enter the number of terms of the second polynomial: ");
    scanf("%d", &n2);
    poly2 = create_poly(poly2, n2);
    if(poly2==NULL){
    printf("Sum of polynomial: ");
    display_poly(poly1);
    }
    else if(poly1==NULL){
    printf("Sum of polynomial: ");
    display_poly(poly2);
    }
    else{
    printf("First polynomial: ");
    display_poly(poly1);
    printf("Second polynomial: ");
    display_poly(poly2);
     poly3 = add_poly(poly1, poly2);
     
    printf("Sum of the polynomials: ");
    display_poly(poly3);
    return 0;
}
}










