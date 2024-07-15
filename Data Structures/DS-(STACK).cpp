#include <bits/stdc++.h>
using namespace std;
//Stack is abstract data type which follows LIFO(last in first out) model, i.e, elements will be inserted at last and last element which is inserted
//- will be removed first

int main(){
    stack<int>a;
    a.push(4);                                  //push(type element) function pushes elements at last
    a.push(5);
    int num=a.top();                            //top() function returns top most element of the stack
    a.pop();                                    //pop() function removes the element at top of the stack
    cout<<a.size()<<endl;                       //size() function returns the size of the stack
    if(a.empty()){                              //empty() function returns whether the stack is empty or not
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
}
