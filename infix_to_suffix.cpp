#include <iostream>

using namespace std;
#define MAXSIZE 512

int top = -1;
int stack[512];

void Push(int e)
{
    if (top >= MAXSIZE){
        cout<<"栈已满";
        exit(1);
    }
    stack[++top] = e;

}
int isEmpty()
{
    return top==-1?1:0;
}
int Pop(){
    if (top == -1){
        cout<<"这是一个空栈。";
        exit(1);
    }
    return stack[top--];
}

int getTop(){
    if (top < MAXSIZE)
    return stack[top];
    exit(1);
}

int judgePriority(char op1, char op2)
{
    
    if (op1=='(' || op2 == '(')
        return 0;
    if ((op1=='-'||op1=='+')&& (op2 =='*'||op2 =='/'))
        return 0;
    return 1;
}
void change(char *tmp, char *str)
{
    char *p = tmp;
    int i, j, k;
    char op1, op2;
    j = 0;
    for (i=0; p[i]; i++){
        
        if (p[i] >= '0' && p[i] <= '9')
            str[j++] = p[i];
        
        else{
            op1 = getTop();
            op2 = p[i];
            if (isEmpty())
                Push(op2);
            
            else{
                if (op2 == ')'){
                    while (getTop() != '(')
                        str[j++] = Pop();
                    Pop();
                    continue;
                }
                switch(judgePriority(op1, op2)){
                case  1: str[j++] = Pop(); 
                    for (k=0; k<=top; k++){
                        if (!judgePriority(op1, op2)) break;
                        str[j++] = Pop();
                    }
                    Push(op2);
                    break;
                case  0:  Push(op2); break;
                }
            }
        }
    }

    while (!isEmpty())
        str[j++] = Pop();
    str[j] = 0;
}


int main(){
    char tmp[512],str[512];
    cout<<"输入运算表达式：";
    cin>>tmp;
    change(tmp,str);
    cout<<"转换后结果："<<str;

}
