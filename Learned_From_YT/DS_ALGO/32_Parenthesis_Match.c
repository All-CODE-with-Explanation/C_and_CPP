/*  Check If stack is empty or full 
    char *exp = "8*(9)"; Due to this
    This Program is not running properly in C++, but runs smoothly in C Language.

    This Below program is only for single parenthesis
    and the respective parenthesis is closed on respective time is Not Checked
    For this refer to Multi Parenthesis Match (Next Program)
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if(ptr->top == -1){
        return 1; // means Yes, the stack is Empty.
    }
    else{
        return 0; // means Stack is not empty
    }
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr, char val){
    if(isFull(ptr)){
        printf( "Stack Overflow. \nUnable to Push : %c",  val);
        // return true;
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
        // return false;
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf( "Stack Underflow. \nCan't POP from the stack.");
        return 'a';
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesisMatch(char * exp){
    // create and initialize the stack
    struct stack * sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for(int i=0; exp[i] != '\0'; i++ )
    {
        if(exp[i] == '(' ){
            push(sp, '(' );
        } else if(exp[i] == ')' ){

            if(isEmpty(sp)){
                return 0;
            }   
            else{
                pop(sp);
            }
        }
    }

    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    // char * exp = (char *)"8*(9)";
    char *exp = "8*(9)()((";

    // Check if stack is matching or not
    if(parenthesisMatch(exp)){
        printf("Parenthesis Matched Successfully.");
    }
    else{
        printf("Error! in Expression, Parenthesis don't Match.");
    }

    return 0;
}