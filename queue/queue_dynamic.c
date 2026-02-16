#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char c;
    struct node *next;
}node;

node *front = NULL;
node *rear = NULL;
int count = 0;

void enqueue(char ch){
    node *n = malloc(sizeof(node));
    n -> next = NULL;
    if(front == NULL){
        front = n;
    }
    else{
        rear -> next = n;
    }
    rear = n;
    n -> c = ch;
    count++;
}
char dequeue(){
    char ch;
    node *n = front;
    front = front -> next;
    ch = n -> c;
    free(n);
    count--;
    return ch;
}
char front_queue(){
    if(front == NULL){
        printf("EMPtY!");
    }
    else return front -> c;
}
void destroy(){
    node *n;
    while(front != NULL){
        n = front;
        front = front -> next;
        free(n);
        count--;
    }
}
void print_queue(){
    node *f = front;
    if(f == NULL){
        printf("EMPTY QUEUE!");
    }
    while(f != NULL){
        printf("%c ",f -> c);
        f = f -> next;
    }
    printf("\n");
}

void main(){
    enqueue('a');
    enqueue('b');
    enqueue('c');
    enqueue('d');
    enqueue('e');
    enqueue('f');
    enqueue('g');
    enqueue('h');
    print_queue();
    char c = dequeue();
    printf("front = %c\n",c);
    print_queue();
    destroy();
    print_queue();

}