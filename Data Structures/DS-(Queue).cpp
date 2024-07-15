#include <bits/stdc++.h>
using namespace std;

//Queue is a abstract data type which follows FIFO(First In First Out) model,i.e, data which enters first will exit first.
int main(){
    queue<int>a;                // Syntax to create queue data structure
    a.push(5);                  // Syntax to push elements in queue data structure
    a.pop();                    // Syntax to pop elements from front
    a.push(100);
    cout<<a.front()<<endl;      // Returns front element in queue
    cout<<a.size()<<endl;       // Returns size of the queue
    cout<<a.empty()<<endl;      // Returns whether the queue is empty or not
}
