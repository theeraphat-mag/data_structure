#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *left;
    int value;
    struct node *right;
}node;
node *root = NULL;
int count = 0;

void add(int data){
    int found;
    node *ptr = NULL;
    node *n = malloc(sizeof(node));
    n -> value = data;
    n -> left = NULL;
    n -> right = NULL;
    if(root == NULL){
        root = n;
        count++;
        found = 1;
    }
    else{
        ptr = root;
        found = -1;
        while(found == -1){
            if(data < ptr -> value){
                if(ptr -> left == NULL){
                    ptr -> left = n;
                    count++;
                    found = 1;
                }
                else{
                    ptr = ptr -> left;
                }
            }
            else if(data > ptr -> value){
                if(ptr -> right == NULL){
                    ptr -> right = n;
                    count++;
                    found = 1;
                }
                else{
                    ptr = ptr -> right;
                }
            }
            else{
                printf("\nThis item is already in the BTS.");
            }
        }
    }
}

void pre_traverse(node *ptr){
    if(ptr != NULL){
        printf("%d ",ptr -> value);
        pre_traverse(ptr -> left);
        pre_traverse(ptr -> right);
    }
}

void in_traverse(node *ptr){
    if(ptr != NULL){
        in_traverse(ptr -> left);
        printf("%d ",ptr -> value);
        in_traverse(ptr -> right);
    }
}

void post_traverse(node *ptr){
    if(ptr != NULL){
        post_traverse(ptr -> left);
        post_traverse(ptr -> right);
        printf("%d ",ptr -> value);
    }
}

void search(node *ptr, int target){
    if(ptr == NULL){
        printf("\nNot Found.");
    }
    else if(ptr -> value == target){
        printf("\n%d is found.",ptr -> value);
    }
    else if(ptr -> value > target){
        search(ptr -> left,target);
    }
    else if(ptr -> value < target){
        search(ptr -> right,target);
    }
}

void main(){
    int choice;
    do{
        printf("1. Add\n");
        printf("2. Pre oder\n");
        printf("3. In oder\n");
        printf("4. Post oder\n");
        printf("5. Exit\n");
        printf("Enter choice 1-5: ");
        scanf("%d",&choice);
        if(choice == 1){
            int size,data;
            printf("Enter size binary tree: ");
            scanf("%d",&size);
            for(int i = 0; i < size; i++){
                printf("Add tree: ");
                scanf("%d",&data);
                add(data);
            }
        }
        else if(choice == 2){
            printf("\nPre Order = "); pre_traverse(root);
        }
        else if(choice == 3){
            printf("\nIn Order = "); in_traverse(root);
        }
        else if(choice == 4){
             printf("\nPost Order = "); post_traverse(root);

        }
        printf("\n");

    }while(choice != 5);
}