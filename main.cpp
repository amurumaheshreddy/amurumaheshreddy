#include<iostream>
#include"MyLinkedList.h"
using namespace std;

int main()
{
    MyLinkedList obj(5);
    obj.pushBack(1);
    obj.pushBack(2);
    obj.pushBack(3);
    obj.pushBack(4);
    obj.pushBack(5);
    cout<<obj<<endl;
    cout<<obj.popBack()<<endl;
    cout<<obj<<endl;
    obj.insert(10,0);
    cout<<obj<<endl;
    obj.remove(0);
    cout<<obj<<endl;
    cout<<obj[0]<<endl;
    MyLinkedList obj2(obj);
    cout<<obj2<<endl;
    MyLinkedList obj3(3);
    cout<<obj3<<endl;
    MyLinkedList obj4(3,3);
    cout<<obj4<<endl;
 return 0;
}