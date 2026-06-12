#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    double data;
    struct Node * next;
}Node;

Node* create()//创建链表
{
    Node* head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    return head;
}

void append(Node* L,double ele)//在表末尾添加元素
{
    Node* end=L;
    for (;end->next!=NULL;end=end->next);
    end->next=(Node*)malloc(sizeof(Node));
    (end->next)->data=ele;
    (end->next)->next=NULL;
}

Node* get(Node* L,int n)
{
    Node * ans=L;
    for (int i=0;(i<n)&&(ans->next!=NULL);i++)
    {
        ans=ans->next;
    }
    return ans;
}

double pop(Node* L,int n)//返回第n个元素并将其删除
{
    Node* ptr=get(L,n),*ptr1=get(L,n-1);
    double ans=ptr->data;
    ptr1->next=ptr->next;
    free(ptr);
    return ans;
}

double read(Node* L,int n)
{
    Node* ptr=get(L,n);
    return ptr->data;
}

void insert(Node* L,int n,double ele)//在第n个元素后添加节点
{
    Node* pt1=get(L,n);
    if (pt1->next==NULL)
    {
        append(L,ele);
    }
    else
    {
        Node*pt2=pt1->next;
        pt1->next=(Node*)malloc(sizeof(Node));
        (pt1->next)->data=ele;
        (pt1->next)->next=pt2;
    }
}

void disp(Node* L)
{
    Node*ptr=L;
    do
    {
        ptr=ptr->next;
        printf("%f\n",ptr->data);
    }
    while(ptr->next!=NULL);
}

int main()
{
    Node* L=create();
    append(L,1);
    append(L,1);
    append(L,4);
    append(L,5);
    append(L,1);
    append(L,4);
    disp(L);
    insert(L,3,1.14514);
    disp(L);
}
