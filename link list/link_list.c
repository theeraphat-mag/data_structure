#include<stdio.h>
#include<stdlib.h>

typedef struct node{        // โครงสร้างข้อมูล link list
    int value;           
    struct node *next;
}node;
node *head = NULL; 
node *tail = NULL;
int count = 0;


void append_list(int add){
    node *n = malloc(sizeof(node));
    n -> next = NULL;
    if(head == NULL) head = n;
    else tail -> next = n;       // เพิ่ม link list ต่อท้ายเรื่อยๆ
    tail = n;
    n -> value = add;
    count++;
}
void print_list(){
    node *current;
    current = head;
    if(current == NULL){
        printf("No data!!!");
    }
    while(current != NULL){
        printf("%d ",current -> value);      //แสดงช้อมูลทั้งหมดใน link list
        current = current -> next;
    }
}
int seach_list(int target){       //ค้นหาข้อมูลใน link list
    node *current;
    current = head;

    while(current != NULL){
        if(current -> value == target){
            return 1;
        }
        current = current -> next;
    }
    return 0;
}
void delete_node(int delete){
    node *prev, *current;
    current = prev = head;
    while((current != NULL) && (current -> value != delete)){
        prev = current;
        current = current -> next;
    }
    if(current == NULL) printf("Non data found!!!\n");

    else{
        if(current == head) head = head -> next;

        else if(current == tail){
            tail = prev;
            prev -> next = current -> next;
            current ->next = NULL;
        }
        else{
            prev -> next = current -> next;
        }
        count--;
        free(current);
        printf("Delete complete!!!\n");
    }
}

void destroy_list(){
    node *ptr;
    while(count > 0){
        ptr = head;
        head = head -> next;
        count--;
        free(ptr);
    }
}

void main(){
    int choice;
    do{
        int data;
        printf("1. Add data\n");       
        printf("2. Print data\n");  
        printf("3. Search data\n");  
        printf("4. Delete data\n");  
        printf("5. Destroy link list\n");  
        printf("6. Exit\n");  

        printf("Enter choice 1-6: ");
        scanf("%d",&choice);
        printf("\n");

        if(choice == 1){
            printf("Add data: ");
            scanf("%d",&data);
            append_list(data);

        }

        else if(choice == 2){
            printf("Data = ");
            print_list();
            printf("\n");
        }

        else if(choice == 3){
            int target;
            printf("Target for: ");
            scanf("%d",&target);

            int meet = seach_list(target);
            if(meet == 1){
                printf("Found data\n");
                printf("\n");
            }
            else{
                printf("Non data found!!!\n");
                printf("\n");
            }
        }

        else if(choice == 4){
            int delete;
            printf("Delete for: ");
            scanf("%d",&delete);
            delete_node(delete);
        }
        else if(choice == 5){
            destroy_list();
            printf("Destroy complete!!!\n");
        }
    }while(choice !=6);
}
