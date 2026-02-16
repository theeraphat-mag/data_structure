#include<stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int push){
    if(top+1 != MAX){
        stack[++top] = push;
    }
}

int pop(){
    if(top != -1){
       return stack[top--];
    }
}

void print_stack(){
    int t = top;
    if(t == -1) printf("Empty stack!");
    else printf("Data = ");
    
    while(t != -1){ 
        printf("%d ",stack[t--]);
    
    }printf("\n");
}

void destroy(){
    while(top != -1){
        stack[top--];
    }
    printf("Destroy stack complete!\n");
}

void main(){
    int choice;
    do{
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Destroy\n");
        printf("5. Exit\n");
        printf("Enter choice 1-5: ");
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
    }while(choice != 5);
}