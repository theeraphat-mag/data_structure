#include<stdio.h>
#define SIZE 100

int front,rear;
char items[SIZE];

void create_queue(){
    front = 0;
    rear = -1;
}
void enqueue(char c){
    items[++rear] = c;
}
char dequeue(){
    char c = items[front];
    items[front] = '\0';
    front++;
    return c;
}
char front_queue(){
    char c;
    c = items[front];
    return c;
}
void destroy_queue(){
    while(front <= rear){
        items[front] = '0';
        front++;
    }
}
void print_queue(){
    int f = front;
    while(f <= rear){
        printf("%c ",items[f++]);
    }
    printf("\n");
}

void main(){
    create_queue();
    enqueue('c');
    enqueue('e');
    enqueue('b');
    enqueue('t');
    enqueue('w');
    print_queue();
    dequeue();
    print_queue();
}