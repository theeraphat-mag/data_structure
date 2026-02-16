#include<stdio.h>
#include<stdlib.h>

typedef struct node{    //สร้างโครงสร้างข้อมูล link list
    int value;
    struct node *next;
}node;
int count = 0;
node *top = NULL;

void push(int push){
    node *n = malloc(sizeof(node));     
    n -> next = top;
    top = n;
    n -> value = push;
    count++;
}
int pop(){
    int pop;
    node *n;
    n = top;
    top = top -> next;
    pop = n -> value;
    free(n);
    count--;
    return pop;
}
int stack_top(){
    if(top == NULL){
        printf("Empty!\n");
    }
    else return top -> value; 
}
void print_stack(){
    node *t;
    t = top;

    if(t == NULL) printf("Empty stack!");
    else printf("Data = ");

    while(t != NULL){
        printf("%d ",t -> value);
        t = t ->next;
    }
    printf("\n");
}
void destroy(){
    node *d;
    while(top != NULL){
        d = top;
        top = top -> next;
        free(d);
        count--;
    }printf("Destroy stack complete!\n");
}

void main(){
    int choice;
    do{
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Destroy\n");
        printf("5. Top stack\n");
        printf("6. Exit\n");
        printf("Enter choice 1-6: ");
        scanf("%d",&choice);

        if(choice == 1){
            int data;
            char exit = 'y';
            while(exit != 'n'){
                printf("Push data: ");
                scanf("%d",&data);
                printf("do you wont push data? (y/n): ");
                scanf(" %c",&exit);
                push(data);
            }
        }
        else if(choice == 2){
            int s_pop = pop();
            printf("Pop %d\n",s_pop);
        }
        else if(choice == 3){
            print_stack();
        }
        else if(choice == 4){
            char check;
            printf("You wont destroy to stack! (y/n): ");
            scanf(" %c",&check);
            if(check == 'y') destroy();
        }
        else if(choice == 5){
            int s_top = stack_top();
            printf("Top = %d\n",s_top);
        }
    }while(choice != 6);
}