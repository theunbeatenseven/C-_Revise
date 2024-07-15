#include <bits/stdc++.h>
using namespace std;

//Class contains blueprint from which the objects are created
//Class is also known as user defined data type
class student {                 // Class contains properties and functions that helps in creating and describing the object
                            // In c++ we have three access specifier. Private, Public and Protected
                            //Private(access specifier) - We can only access members and methods within the class
                            //Public (access specifier) - We can access members and methods both withing and outside the class
                            //Protected (access specifier ) - We can access members and methods using friend or derived class.
                            //- But you cannot access from main class
public:                     // Generally in c++ all members and methods are private. So it is necessary to mention it's Access Specifier
    int roll_no;                //Properties of student
    string name;
    string address;

    student() {                 //This syntax is used to create default constructors
                                //- , which are used for initializing a object during creation of it's object
                                // Syntax - No return type and same name as class name
        roll_no = -1;
        name = "NONE";
        address = "NONE";
    }
    //Each class also contains function which are common among these objects
    //The following function is also called as setters, since it can set the values of the members
    student(int roll_no , string name, string address) {
                                    //these are known as parameterized constructor, since it uses parameters values to initialize members of the object
                                    //this keyword is used to represent current memory address of the object referenced
        this->roll_no = roll_no;
        this->name = name;
        this->address = address;
    }
    //The following function is also called as getters, since it is used to get the values of the members
    void printstudentdetails() {
        cout << "Name of the student is " << this->name << endl;
        cout << "Roll No of the student is " << this->roll_no << endl;
        cout << "Address of the student is " << this->address << endl;
    }
    //destructor is used to delete the objects after end of the program. In static allocation destructor is called on its own. whereas in dynamic
    //- allocation delete keyword is used to erase the object
    ~student(){
    }

};
int main() {
    //Object can be created either statically or dynamically
    //When objects are created statically, the object is created before execution. These objects are much faster but the variables or objects is permanently
    // -allocated
    int a;
    student a1;
    //When objects are created dynamically, the object is created during execution. These objects are much slower but memory is utilized efficiently
    //It stores memory address of heap memory which contains objects in stack memory. Stack memory contains address which helps in retrieving the objects.
    int *a2 = new int;
    student *a3 = new student;

    //To assign statically created objects in c++
    a1.name = "Hari";
    a1.roll_no = 11;
    a1.address = "Coimbatore";

    a1.printstudentdetails();

    //To assign dynamically created objects
    (*a3).name = "Shiva"; // It is important to de-reference the stack memory to get the address of heap memory and get it's objects
    a3->roll_no = 18;   // Another syntax to create object dynamically in c++
    a3->address = "Chennai";

    a3->printstudentdetails();

    //copyconstructor is used to copy member values to another object's member
    // while creating a class the following things are created as default: default constructor, copy constructor,copy assignment operator
    //- ,destructor
    student *copystudentdetails= new student(*a3);// a3 values are copied to the "copystudentdetails"
    student * copystudentdetails2= new student(a1);
    copystudentdetails->printstudentdetails();
    copystudentdetails2->printstudentdetails();
    // to copy values from one object to another we can use copy assignment operator. copy constructor only can be used while creating an object
    // after creating an object, the values can only be transferred using copy assignment operator
    *copystudentdetails=*copystudentdetails2;
    copystudentdetails->printstudentdetails();
    copystudentdetails2->printstudentdetails();

    //calling destructor manually for dynamically allocated objects
    delete copystudentdetails;
    delete copystudentdetails2;
    delete a2;
    delete a3;

}
