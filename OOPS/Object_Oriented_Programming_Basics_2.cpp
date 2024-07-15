#include <bits/stdc++.h>
using namespace std;
class sample{ //Class created to understand shallow copy and deep copy
public:
    int a;
    string name;
    sample(int a,string name){
    this->a=a;
    this->name=name;
    }
void print(){
    cout<<"Name inside object is : "<<name<<endl;
}

};

class inilistdemo{
public:
    int &x;
    const int number;
    //const and reference require initialization immediately after it's creation. This causes error, to avoid this and initialize even after this we have to
    //- initialize using initialization list by following syntax
    inilistdemo(int n,int y):x(y),number(n){// this line copies values of y to x and n to number variable even though they are of type const and reference

    }
    void print(){
        cout<<x<<endl;
        cout<<number<<endl;
    }

};

class constantdemo{
public:
    int num;
    constantdemo(int num){
        this->num=num;
    }
    void print()const {
    cout<<num<<endl;
    }
    //void changenum(int num)const{
    //cant do the above line because const function doesn't allow you to change the properties of the object
    void changenum(int num){
        this->num=num;
    }

};

class staticmemberdemo{
public:
    string name;
    int roll_no;
    static int total_student_count; // some members of the class should be available globally and should be same for all objects.
                                //updation should also reflect to all other objects so static keyword is used to give a solution.
    staticmemberdemo(string name, int roll_no){
        this->name=name;
        this->roll_no=roll_no;
        total_student_count++;
    }
    static int totalcount(){ // static function can only return static members
                           // static function can't access this keyword or can return any other non static member
        return total_student_count;
    }

};

int staticmemberdemo::total_student_count=0;// :: is scope resolution operator

int main(){
//Shallow copying is copying elements just by creating a reference. This can create conflicts as changing in one place can result in changing all places
//- where it is used as reference
//It is important to Deep copy in order to avoid such conflicts. Deep copying is copying all elements manually and not getting value by reference.
//Deep copy should be done in following scenarios:
//1.C styled arrays
//2.While using pointers
int* ptr1 = new int(10);
int* ptr2 = ptr1; // Shallow copy of the pointer


string somerandomname="Hari";
sample a1(1,somerandomname);
a1.print();
somerandomname=somerandomname+"Nandan";
sample a2(1,somerandomname);
a2.name=somerandomname;
a2.print();
a1.print();
a1=a2;
a2.name="NONE";
a1.print();

//create own copy constructor every time c styled arrays are used or pointers being used. By this we can avoid shallow copy.
//syntax to remember classname(const char &somerandommember){} "&" is used to avoid infinite loop of copy constructor."const" is used to avoid changing the
//- parameter in further code

//Initialization demo
inilistdemo ini1(5,6);
ini1.print();

//constant object demo
constantdemo const const1(10);
//const1.changenum(5); this can't be done because the object created his constant, so it's properties
const1.print();



staticmemberdemo s1("Hari",20);
staticmemberdemo s2("Shiva",22);
staticmemberdemo s3("Nirmala",48);
staticmemberdemo s4("Neethi", 54);
cout<<staticmemberdemo::total_student_count<<endl;
cout<<"Getting static count using a function inside a class : "<<s4.totalcount()<<endl;

}
