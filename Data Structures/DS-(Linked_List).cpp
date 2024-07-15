#include <bits/stdc++.h>
using namespace std;


//Data structures and algorithms are used to store, manage, access and manipulate data efficiently in memory and performance.
//Linked List is a data structures used to store data in a non contiguous memory allocation or random allocation.
//- It has a data element and a pointer to it's next element
//Array : Contiguous memory allocation. Access elements can be done in O(1) Time complexity, Insertion and deletion will take O(N) Time complexity
//Linked List: Accessing element would take O(N) Time complexity. Insertion and Deletion of elements can be done in O(1) Time complexity.

template <typename t> class linkedlist{
public:
    t data;
    linkedlist * next;
    linkedlist * tail;
    linkedlist(t data){
        this->data=data;
        this->next=nullptr;
    }

};

int main(){
    linkedlist<int>n1(1);
    linkedlist<int>n2(2);
    linkedlist<int>* na1=new linkedlist<int>(5);
    linkedlist<int> * na2= new linkedlist<int>(4);

    n1.next=&n2;       // & is used because n2 is just an object and we have to have the address of n2 in n1.next
    na1->next=na2;      // & is not used because na2 is already pointer while declaration , so no need for &
    na1->next->next=&n1;
    linkedlist<int> * head = na1;
    while(head!=nullptr){
        cout<<head->data<<endl;
        head=head->next;
    }

}
