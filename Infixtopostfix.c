#include<stdio.h>
#include<ctype.h>

int top=-1;
char infix[50],postfix[50],stack[50];

void push(char item);
char pop();
int pFinder(char symbol);//to find the priority of operators

void main(){
int i,length=0,k=0;
printf("enter the infix expression:");
scanf("%s",infix);
for(length=0;infix[length]!='\0';length++);   //for finding length of infix expression
push('(');  //The program first pushes a ‘(’ onto the stack
infix[length]=')'; //appends ‘)’ to the end of the infix expression.
for(i=0;i<=length;i++){
  if(infix[i]=='('){
     push('(');
  }
  else if(isalnum(infix[i])) {
     postfix[k]=infix[i];
      k++;
  }
  else if(infix[i]==')'){
    while(stack[top]!='('){
       postfix[k++]=pop();
    }
    pop();//to pop'('from stack
 }
  else{
     while(pFinder(stack[top])>=pFinder(infix[i]))
     {
         postfix[k++]=pop();
     }
      push(infix[i]);//to push the remaining operator into the stack
    }
  }
 postfix[k]='\0';
 printf("postfix expression:%s\n",postfix);
}
 void push(char item){
     top=top+1;
     stack[top]=item;
 }
 char pop(){
    char item=stack[top];
     top--;
     return item;
 }
 int pFinder(char symbol){
     switch(symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
 }
