#include <bits/stdc++.h>
using namespace std;

void toLearnStringStream(){
    string a;
    getline(cin,a); //This allows you to get string input with spaces.
    istringstream iss(a);
    string b,c,d;
    iss>>b;
    iss>>c;
    iss>>d;
    cout<<b<<" "<<c<<" "<<d<<endl;
    while(iss>>d){
        cout<<d<<endl;
    }
}
void StringStreamForParameterizedSeperation(){
    string a;
    getline(cin,a);
    istringstream iss(a);
    string b;
    while(getline(iss,b,',')){
        cout<<b<<endl;
    }
}
void learnTypeConversionForString(){
    int num=49;
    char a= char(num);  //Respective ascii character for the value num is stored in a
    cout<<a<<endl;
    char b='A';
    cout<<int(b)<<endl; // Respective ascii value of the character is printed

}
int main(){
    toLearnStringStream();
    StringStreamForParameterizedSeperation();
    learnTypeConversionForString();
}
