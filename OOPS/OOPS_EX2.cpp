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
    Fraction addfraction(Fraction f2){ // object is passed as an argument when the function is called.
        int lcm_of_fractions=(this->denominator*f2.denominator)/__gcd(this->denominator,f2.denominator);
        int numerator1=(lcm_of_fractions/this->denominator)*this->numerator;
        int numerator2=(lcm_of_fractions/f2.denominator)*f2.numerator;
        int newnumerator=numerator1+numerator2;
        int newdenominator=lcm_of_fractions;
        Fraction temp(newnumerator,newdenominator);
        temp.simplify();
        return temp;
    }
    void simplify(){
        int gcd=__gcd(this->numerator,this->denominator);
        while(gcd!=1){
            this->numerator=this->numerator/gcd;
            this->denominator=this->denominator/gcd;
            gcd=__gcd(this->numerator,this->denominator);
        }
    }
    Fraction operator+(Fraction f2){ // operator is keyword used to create F1=F2+F3 meaningful. It works similar to addfraction function,
                                    // - address of F2 is referenced and F3 is passed as an arguement then the result is returned to F1
        int lcm_of_fractions=(this->denominator*f2.denominator)/__gcd(this->denominator,f2.denominator);
        int numerator1=(lcm_of_fractions/this->denominator)*this->numerator;
        int numerator2=(lcm_of_fractions/f2.denominator)*f2.numerator;
        int newnumerator=numerator1+numerator2;
        int newdenominator=lcm_of_fractions;
        Fraction temp(newnumerator,newdenominator);
        temp.simplify();
        return temp;

    }
    Fraction operator-(Fraction f2){
        int lcm_of_fractions=(this->denominator*f2.denominator)/__gcd(this->denominator,f2.denominator);
        int numerator1=(lcm_of_fractions/this->denominator)*this->numerator;
        int numerator2=(lcm_of_fractions/f2.denominator)*f2.numerator;
        int newnumerator=numerator1-numerator2;
        int newdenominator=lcm_of_fractions;
        Fraction temp(newnumerator,newdenominator);
        temp.simplify();
        return temp;

    }
    Fraction operator*(Fraction f2){
        int newnumerator=this->numerator*f2.numerator;
        int newdenominator=this->denominator*f2.denominator;
        Fraction temp(newnumerator,newdenominator);
        temp.simplify();
        return temp;

    }
    Fraction operator /(Fraction f2){
        int newnumerator=this->numerator*f2.denominator;
        int newdenominator=this->denominator*f2.numerator;
        Fraction temp(newnumerator,newdenominator);
        temp.simplify();
        return temp;
    }
    bool operator ==(Fraction f2){
        this->simplify();
        f2.simplify();
        return (this->numerator==f2.numerator && this->denominator==f2.denominator);
    }

    Fraction& operator++(){// we have to pass fraction by reference because ++(++f1) doesn't affect f1 twice. i.e, if f1 is 1/1, f1 will not
                                    //- get the value 3 instead it will be 2. After increment, f1 increments to one and stores the value in buffer or temp
                                    //- memory. so, another increment acts only on the object present in buffer memory and not on the actual object.
                                    //In order to fix this we have to return fraction by reference to see the updation
    this->numerator=this->numerator+this->denominator;
    return *this;
    }
    Fraction operator++(int){ //syntax to differentiate post increment from pre-incremnt
        //you can't pass by reference fraction here
        Fraction temp(this->numerator,this->denominator);
        this->numerator=this->numerator+this->denominator;
        return temp;

    }
    Fraction operator+=(Fraction f2){
        int lcm_of_fractions=(this->denominator*f2.denominator)/__gcd(this->denominator,f2.denominator);
        int numerator1=(lcm_of_fractions/this->denominator)*this->numerator;
        int numerator2=(lcm_of_fractions/f2.denominator)*f2.numerator;
        this->numerator=numerator1+numerator2;
        this->denominator=lcm_of_fractions;
        this->simplify();
        return *this;
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
    Fraction a3=a1.addfraction(a2);
    Fraction a4=a1.addfraction(a3);
    a3.printfraction();
    a4.printfraction();
    Fraction a5=a3+a4;
    a4.printfraction();
    a3=a5-a4;
    a3.printfraction();
    a4=a5/a3;
    a4.printfraction();
    cout<<(a4==a4)<<endl;
    a4=a3++;
    a4.printfraction();
    a4+=a5;
    a4.printfraction();

}
