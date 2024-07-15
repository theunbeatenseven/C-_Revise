#include <bits/stdc++.h>
using namespace std;


class Fraction{
int numerator;
int denominator;
public:
    Fraction(int numerator,int denominator){ //Parameterized constructor should always be in public in order access the object from main function
        this->numerator=numerator;
        this->denominator=denominator;
    }
    void printfraction(){
        cout<<"The fraction is : "<<this->numerator<<" / "<<this->denominator<<endl;
    }
    void addfraction(Fraction f2){ // object is passed as an argument when the function is called.
        int lcm_of_fractions=(this->denominator*f2.denominator)/__gcd(this->denominator,f2.denominator);
        int numerator1=(lcm_of_fractions/this->denominator)*this->numerator;
        int numerator2=(lcm_of_fractions/f2.denominator)*f2.numerator;
        this->numerator=numerator1+numerator2;
        this->denominator=lcm_of_fractions;
    }
    void simplify(){
        int gcd=__gcd(this->numerator,this->denominator);
        while(gcd!=1){
            this->numerator=this->numerator/gcd;
            this->denominator=this->denominator/gcd;
            gcd=__gcd(this->numerator,this->denominator);
        }
    }

};
int main(){
    Fraction a1(5,3);
    a1.printfraction();
    Fraction a2(5,5);
    a1.addfraction(a2);
    a1.printfraction();
    a1.simplify();
    a1.printfraction();

}
