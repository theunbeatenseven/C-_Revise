#include <bits/stdc++.h>


using namespace std;

//Tree is a data structure which stores elements in form of relationship or in hierarchical model.
// It contains Root node, parent node, child nodes. It defines structure of relations of all nodes in form of hierarchical model.

template <typename t>class Tree{
public:
    t data;
    vector<Tree<t>*>childrenholder;
    Tree(t element){
        data=element;
    }
};
template <typename t> t tree(t name){
    cout<<name<<endl;

}
int main(){
    Tree<int> * newy=new Tree<int>(5);
    int num=5;
    tree<int>(num);


}
