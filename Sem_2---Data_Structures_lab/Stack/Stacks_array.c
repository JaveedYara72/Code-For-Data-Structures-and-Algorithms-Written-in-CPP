#include<stdio.h>
#include<stdlib.h>

struct stack{
    unsigned c;
    int* arr;
    int top;
};

struct stack* createstack(unsigned c){
struct stack* s=(struct stack*)malloc(sizeof(struct stack));
s->c=c;
s->top=-1;
s->arr=(int*)malloc(sizeof(int)*s->c);
return s;
}

int isfull(struct stack* s){
    return s->c-1==s->top;
}

int isemp(struct stack* s){
    return s->top==-1;
}

void push(struct stack* s,int a){
    if(isfull(s)) return;
    s->arr[++(s->top)]=a;

}

int pop(struct stack* s){
    if(isemp(s)) return 0;
    return(s->arr[s->top--]);

}

int topp(struct stack* s){
    return s->arr[s->top];
}

void p(struct stack* s){
    for (int i=0;i<=s->top;i++){
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}

int main(){

struct stack* s=createstack(5);
push(s,1); p(s);
push(s,2);p(s);
push(s,3);p(s);
push(s,4);p(s);
push(s,5);p(s);
printf("%d\n",topp(s));
printf("%d\n",isfull(s));
printf("%d\n",isemp(s));
pop(s);p(s);
pop(s);p(s);
pop(s);p(s);
push(s,12);p(s);
printf("%d\n",topp(s));

}
