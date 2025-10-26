#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char url[100];
    struct Node *prev, *next;
};

struct Node *current = NULL;

void visit(char *url){
    struct Node *newpage = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newpage->url,url);
    newpage->prev=current;
    newpage->next=NULL;

    if(current){
        struct Node *temp=current->next;
        while (temp){
            struct Node *del=temp;
            temp=temp->next;
            free(del);  
        }
        current->next=newpage;
    }
    current=newpage;
    printf("Visited: %s\n",url);
}

void back(){
    if(current && current->prev){
        current=current->prev;
        printf("Went back to %s\n",current->url);
    } else {
        printf("Nothing to go back to!\n");
    }
}

void forward(){
    if(current && current->next){
        current=current->next;
        printf("Went forward to %s\n",current->url);
    } else {
        printf("Nothing to go forward to\n");
    }
}

int main(){
    int choice;
    char url[100];
    while(1){
        printf(" \n 1.Visit \n 2.Back \n 3.Forward \n 4.Exit \n Enter a choice: ");
        scanf("%d",&choice);
        switch (choice){
        case 1: 
            printf("Enter url: ");
            scanf("%s",url);
            visit(url);
            break;
        case 2:
            back();
            break;
        case 3:
            forward();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Invalid Choice!\n");
            break;
        }
        
    }
    return 0;
}