#include<iostream>
#include<cstdlib>
#include<cassert>
using namespace std;

class MyLinkedList
{
 private:
 struct Node
 {
 int data;
            Node *next;
 };
        Node *head;
 int size;
 public:
 MyLinkedList();
 MyLinkedList(int);
 MyLinkedList(int,int);
 MyLinkedList(const MyLinkedList&);
 ~MyLinkedList();
 void pushBack(int);
 int popBack();
 void insert(int,int);
 void remove(int);
 int operator[](int);
 friend ostream& operator<<(ostream&,const MyLinkedList&);
};

MyLinkedList::MyLinkedList()
{
    head=NULL;
    size=10;
 for(int i=0;i<size;i++)
 {
        Node *temp=new Node;
        temp->data=0;
        temp->next=head;
        head=temp;
 }
}

MyLinkedList::MyLinkedList(int n)
{
    head=NULL;
    size=n;
 // for(int i=0;i<size;i++)
 // {
 //     Node *temp=new Node;
 //     temp->data=0;
 //     temp->next=head;
 //     head=temp;
 // }
}

MyLinkedList::MyLinkedList(int n,int val)
{
    head=NULL;
    size=n;
 for(int i=0;i<size;i++)
 {
        Node *temp=new Node;
        temp->data=val;
        temp->next=head;
        head=temp;
 }
}

MyLinkedList::MyLinkedList(const MyLinkedList &obj)
{
    head=NULL;
    size=obj.size;
    Node *temp=obj.head;
 for(int i=0;i<size;i++)
 {
        Node *temp2=new Node;
        temp2->data=temp->data;
        temp2->next=head;
        head=temp2;
        temp=temp->next;
 }
}

MyLinkedList::~MyLinkedList()
{
    Node *temp=head;
 while(temp!=NULL)
 {
        Node *temp2=temp;
        temp=temp->next;
 delete temp2;
 }
}

void MyLinkedList::pushBack(int val)
{
    Node *temp=new Node;
    temp->data=val;
    temp->next=NULL;
 if(head==NULL)
 {
        head=temp;
 }
 else
 {
        Node *temp2=head;
 while(temp2->next!=NULL)
 {
            temp2=temp2->next;
 }
        temp2->next=temp;
 }
    size++;
}

int MyLinkedList::popBack()
{
 assert(head!=NULL);
    Node *temp=head;
    Node *temp2=head;
 while(temp->next!=NULL)
 {
        temp2=temp;
        temp=temp->next;
 }
 int val=temp->data;
    temp2->next=NULL;
 delete temp;
    size--;
 return val;
}

void MyLinkedList::insert(int val,int index)
{
 assert(index>=0 && index<=size);
    Node *temp=new Node;
    temp->data=val;
 if(index==0)
 {
        temp->next=head;
        head=temp;
 }
 else
 {
        Node *temp2=head;
 for(int i=0;i<index-1;i++)
 {
            temp2=temp2->next;
 }
        temp->next=temp2->next;
        temp2->next=temp;
 }
    size++;
}

void MyLinkedList::remove(int index)
{
 assert(index>=0 && index<size);
    Node *temp=head;
 if(index==0)
 {
        head=temp->next;
 delete temp;
 }
 else
 {
 for(int i=0;i<index-1;i++)
 {
            temp=temp->next;
 }
        Node *temp2=temp->next;
        temp->next=temp2->next;
 delete temp2;
 }
    size--;
}

int MyLinkedList::operator[](int index)
{
 assert(index>=0 && index<size);
    Node *temp=head;
 for(int i=0;i<index;i++)
 {
        temp=temp->next;
 }
 return temp->data;
}

ostream& operator<<(ostream &out,const MyLinkedList &obj)
{
    MyLinkedList::Node *temp=obj.head;
 while(temp!=NULL)
 {
        out<<temp->data<<" ";
        temp=temp->next;
 }
 return out;
}