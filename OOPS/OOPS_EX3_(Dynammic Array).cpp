#include <bits/stdc++.h>
using namespace std;


//Dynamic array is same as vector
//If size are fixed it is better to use c styled array
//C styled also good in performance
//It is advised to use vector if the array size is dynamic
//Vectors are also convenient to use than c array because of its extensive inbuilt methods

template<typename t> class myvector{ //template is used follow similar template to different type variables
public:
    t element;
    t * arr;
    int currentindex;
    int capacity;
    myvector(){
        capacity=5;
        arr=new t[5];
        currentindex=0;
    }
    void push(t element){
        if(currentindex>=capacity){
            t * temp= new t[capacity*2];
            for(int i=0;i<capacity;i++){
                temp[i]=arr[i];
            }
            capacity=capacity*2;
            arr=new t[capacity*2];
            for(int i=0;i<capacity;i++){
                arr[i]=temp[i];
            }
            delete [] temp;
            arr[currentindex]=element;
            currentindex++;
        }
        else{
            arr[currentindex]=element;
            currentindex++;
        }
    }
    void pop(){
        if(currentindex<=0)return;
        else{
            currentindex--;
        }

    }
    t access(int index){
        return arr[index];
    }
    int len(){
        return currentindex;
    }


};
int main(){
    myvector<string>a1;
    a1.push("Hari");
    a1.push("Shiva");
    a1.push("Nirmala");
    a1.push("Neethi");

    while(a1.len()){
        cout<<a1.access(a1.len()-1)<<endl;
        a1.pop();
    }
}
