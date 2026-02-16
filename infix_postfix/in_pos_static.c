#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#define MAX 50

int stack[MAX];   // stack
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

int priority(char p){           //ตรวจสอบลำดับความสำคัญ ของ operator
    if(p == '^') return 3;
    else if(p == '*' || p == '/') return 2;
    else if(p == '+' || p == '-') return 1;
    return 0;
}

int calculate(int top2, int top1,char operator){     //คำนวน
    if(operator == '^') return pow(top1,top2);
    else if(operator == '*') return (top1 * top2);
    else if(operator == '/') return (top1 / top2);
    else if(operator == '+') return (top1 + top2);
    else if(operator == '-') return (top1 - top2);
    return 0;
}


int process(char output[]){      // เอาสมการ postfix แยกคำนวน
    //char filter[MAX];  //  
    //int index_f = 0;   // วิธีที่1

    int result = 0;     //
    char check = 'n';   // วิธีที่2

    for(int i = 0; output[i] != '\0' ; i++){
        char o = output[i];
        if(isdigit(o)) {        // รวม character ที่เป็นตัวเลข
            //filter[index_f++] = o;  // วิธีที่1
            
            
            result = result * 10 + (o - '0');   //
            check = 'y';                        //วิธีที่2
        }
        else {
            // if( index_f > 0){           //ถ้าเลขมากกว่า 2หลัก
            //     filter[index_f] = '\0';
            //     push(atoi(filter));     // รวมเสร็จแล้ว ถ้าเจอ operator ให้แปลงจาก char เป็น int ด้วยฟังก์ชัน atoi()  //วิธีที่1
            //     index_f=0;              // reset t = 0 
            // }
            
            if(check == 'y'){   //
                push(result);   //
                result = 0;     //
                check = 'n';    //
            }                   //วิธีที่2


            if(o == '^' || o == '*' || o == '/' || o == '+' || o == '-'){       //ถ้า  o = ^ * / + - ให้ pop ออกมา2ตัวแล้วส่งไปคำนวนกับ operator ที่เจอ
            int top2 = pop();               //ตัวบนสุด
            int top1 = pop();               //รองลงมา
            push(calculate(top2,top1,o));   //คำนวนเสร็จแล้ว เก็บลใน stack
            }
        }
        
    }
    return pop();     //ค่าที่คำนวนเสร็จจะอยู่ในstackตัวสุดท้าย pop ออก
}

void infix_to_postfix(char infix[]){        // แปลงจากสมการ infix เป็น postfix 
    char output[MAX];                       //array ouput ไว้เก็บสมการ postfix 
    int index_output = 0;     


    for(int i = 0; infix[i] != '\0'; i++){

        if(isdigit(infix[i]) || isalpha(infix[i])) output[index_output++] = infix[i];     //ถ้าเจอตัวเลขให้เก็บใน array output
         
        else  if(infix[i] == '(') push(infix[i]);   //ถ้าเจอ ( ให้เก็บใน stack

        else if(infix[i] == ')'){                   //ถ้าเจอ ) ให้ เอาทุกอย่างที่อยู่ใน stack ออกมาเก็บใน array
            while(top != -1 && stack[top] != '('){
                output[index_output++] = pop();       
            }
            pop(); // pop ( ทิ้ง
        }
        else if(infix[i] == '^' || infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-'){

            output[index_output++] = ' ';     //เว้นช่องว่าง
            while(top != -1 && stack[top] != '(' &&  priority(stack[top]) >= priority(infix[i])){     /*ตรวจสอบว่า operator ที่อยู่ในstack >= ตัวที่ กำลังจะใส่ในstack 
                                                                                                        ถ้า >= ให้ pop ออกเก็บใน array*/
                output[index_output++] = pop();
            }
            push(infix[i]);     // ถ้า < ให้เก็บลงใน stack
        }
    }
    
    while(top != -1 ){
        output[index_output++] = pop(); //เอาที่เหลือเก็บใน output
    }
    printf("Postfix = ");                   //แสดงสมการ postfix
    for(int i=0; i < index_output ;i++){
         printf("%c",output[i]);
   
    }

    int cal = process(output);      //ส่ง output ไปฟังก์ชันpostfix 
    printf("\nValue = %d",cal);
}

void main(){                        //Main function
    char infix[MAX];
    printf("Enter infix: ");
    scanf("%s",infix);
    infix_to_postfix(infix);
}