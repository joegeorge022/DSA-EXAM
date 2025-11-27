#include <stdio.h>

int main() {
    int a[10], b[10], sum[10];
    int degree1, degree2, sumdegree;

    printf("Enter the max power of the 1st polynomial: ");
    scanf("%d",&degree1);

    printf("Enter the max power of the 2nd polynomial: ");
    scanf("%d",&degree2);

    printf("Enter the 1st polynomial: ");
    for(int i=degree1; i>=0; i--){
        printf("Enter the coefficient of x^%d :",i);
        scanf("%d",&a[i]);
    }

    printf("Enter the 2nd polynomial: ");
    for(int i=degree2; i>=0; i--){
        printf("Enter the coefficient of x^%d :",i);
        scanf("%d",&b[i]);
    }

    sumdegree = (degree1 > degree2 ) ? degree1 : degree2;

    for(int i=sumdegree;i>=0;i--){
        if(i>degree1){a[i]=0;}
        if(i>degree2){b[i]=0;}
        sum[i] = a[i] + b[i];
    }

    for(int i=sumdegree; i>=0; i--){
        printf("%dx^%d ",sum[i],i);
        printf("+ ");
    }
    printf("\n");
}