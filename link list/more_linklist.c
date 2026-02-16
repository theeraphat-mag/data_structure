#include<stdio.h>
#include<stdlib.h>                    

typedef struct node{
    int value;
    struct node *next;
}node;
node *head = NULL;
node *tail = NULL;
int count = 0;

void append_front(int data){
    node *n = malloc(sizeof(node));
    if(head == NULL){
        head = n;
        tail = n;
        n -> next = NULL;
    }
    else{
        n -> next = head;
        head = n;
    }
    n -> value = data;
    count++;
}
void append_list(int data){
    node *n = malloc(sizeof(node));
    n -> next = NULL;
    if(head == NULL){
        head = n; 
    }
    else{
        tail -> next = n;
    }
    tail = n;
    n -> value = data;
    count++;
}
void append_behindHead(int data){
    node *n = malloc(sizeof(node));
    if(head == NULL){
        head = n;
        tail = n;
        n -> next = NULL;
    }
    else if(head == tail){
        // tail -> next = n;
        // tail = n;
        // n -> next = NULL;
        n -> next = head -> next;
        head -> next = n;
        tail = n;
    }
    else{
        n -> next = head -> next;
        head -> next = n;
    }
    n ->value = data;
    count++;
}
void append_beforTail(int data){
    node *n = malloc(sizeof(node));
    if(head == NULL){
        head = n;
        tail = n;
        n -> next = NULL;
    }
    else if(head == tail){
        // tail -> next = n;
        // tail = n;
        // n -> next = NULL;
        n -> next = head -> next;
        head -> next = n;
        tail = n;
    }
    else if(count == 2){
        n -> next = head -> next;
        head -> next = n;
    }
    else{
        node *current = head;
        while(current -> next != tail){
            current = current -> next;
        }
        n -> next = current -> next;
        current -> next = n;
    }
    n -> value = data;
    count++;
}
void append_beforThreeTail(int data){
    node *n = malloc(sizeof(node));
    if(head == NULL){
        head = n;
        tail = n;
        n -> next = NULL;
    }
    else if(head == tail){
        n -> next = head -> next;
        head -> next = n;
        tail = n;
    }
    else if(count == 2){
        n -> next = head;
        head = n;
    }
    else{
        node *current,*prev;
        current = prev = head;
        while(current -> next -> next != tail){
            current = current -> next;
            prev = current;
        }
        n -> next = prev -> next;
        prev -> next = n;
        // n -> next = current -> next;
        // current -> next = n;
    }
    n -> value = data;
    count++;
}
void print_list(){
    node *current = head;
    while(current != NULL){
        printf("%d ",current -> value);
        current = current -> next;
    }
}
void main(){
    // append_front(); เพิ่มข้างหน้าเรื่อยๆ
    // append_list();   เพื่มต่อท้ายเรื่อยๆ
    // append_behindHead)();    เพิ่มต่อท้ายจากหัว
    // append_beforTail();  เพิ่มหน้าข้างหน้าหาง
    
    // append_front(5);
    // append_front(4);
    // append_front(3);
    // append_front(2);
    // append_front(1);
    // append_list(10);
    // append_list(20);
    // append_list(30);
    // append_list(40);
    // append_list(50);
    // append_behindHead(9);
    // append_behindHead(8);
    // append_behindHead(7);
    // append_behindHead(6);
    // append_behindHead(5);
    // append_beforTail(7);
    // append_beforTail(6);
    // append_beforTail(5);
    // append_beforTail(4);
    // append_beforTail(3);
    append_beforThreeTail(5);
    append_beforThreeTail(4);
    append_beforThreeTail(3);
    append_beforThreeTail(2);
    append_beforThreeTail(1);
    append_beforThreeTail(0);
    print_list();
    
    
}